
//
// File ros2nodeinterface.cpp
//
// Code generated for Simulink model 'Angulo'.
//
// Model version                  : 1.27
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jun 09 17:14:45 2022
//
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
#include "Angulo.h"
#include "ros2nodeinterface.h"
#include <thread>
#include <chrono>
#include <utility>
const std::string SLROSNodeName("Angulo");
namespace ros2 {
namespace matlab {
NodeInterface::NodeInterface()
    : mNode()
    , mModel()
    , mExec()
    , mBaseRateSem()
    , mBaseRateThread()
    , mSchedulerThread()
    , mStopSem()
    , mRunModel(true){
  }
NodeInterface::~NodeInterface() {
    terminate();
  }
void NodeInterface::initialize(int argc, char * const argv[]) {
    try {
        //initialize ros2
        // Workaround to disable /rosout topic until rmw_fastrtps supports
        // multiple typesupport implementations for the same topic (https://github.com/ros2/rmw_fastrtps/issues/265)
        std::vector<char *> args(argv, argv + argc);
        char log_disable_rosout[] = "__log_disable_rosout:=true";
        args.push_back(log_disable_rosout);
        rclcpp::init(static_cast<int>(args.size()), args.data());
        //create the Node specified in Model
        std::string NodeName("Angulo");
        mNode = std::make_shared<rclcpp::Node>(NodeName);
        mExec = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
        mExec->add_node(mNode);
        //initialize the model which will initialize the publishers and subscribers
        mModel = std::make_shared<Angulo>(
        );
		rtmSetErrorStatus(mModel->getRTM(), (NULL));
        mModel->initialize();
        //create the threads for the rates in the Model
        mBaseRateThread = std::make_shared<std::thread>(&NodeInterface::baseRateTask, this);
		mSchedulerThread = std::make_shared<std::thread>(&NodeInterface::schedulerThreadCallback, this);
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        throw ex;
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
        throw;
    }
}
int NodeInterface::run() {
  if (mExec) {
    mExec->spin();
  }
  mRunModel = false;
  return 0;
}
boolean_T NodeInterface::getStopRequestedFlag(void) {
    #ifndef rtmGetStopRequested
    return (!(rtmGetErrorStatus(mModel->getRTM())
        == (NULL)));
    #else
    return (!(rtmGetErrorStatus(mModel->getRTM())
        == (NULL)) || rtmGetStopRequested(mModel->getRTM()));
    #endif
}
void NodeInterface::stop(void) {
  if (mExec.get()) {
    mExec->cancel();
    if (mNode) {
      mExec->remove_node(mNode);
    }
    while (mExec.use_count() > 1);
  }
}
void NodeInterface::terminate(void) {
    if (mBaseRateThread.get()) {
        mRunModel = false;
        mBaseRateSem.notify(); // break out wait
        mBaseRateThread->join();
        if (mSchedulerThread.get()) {
            mSchedulerThread->join();
            mSchedulerThread.reset();
        }
        mBaseRateThread.reset();
        if (mModel.get()) {
            mModel->terminate();
        }
        // Release publisher Angulo/Mandar giro/Publish1
        mPub_Angulo_94.reset();
        // Release publisher Angulo/Medidas/Publish1
        mPub_Angulo_56.reset();
        // Release publisher Angulo/Medidas/Publish2
        mPub_Angulo_65.reset();
        // Release subscriber Angulo/Medidas/Subscribe
        mSub_Angulo_1.reset();
        // Release subscriber Angulo/R1/Subscribe2
        mSub_Angulo_146.reset();
        mModel.reset();
        mExec.reset();
        mNode.reset();
        rclcpp::shutdown();
    }
}
//
void NodeInterface::schedulerThreadCallback(void)
{
  while (mRunModel) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(2777778));
        mBaseRateSem.notify();
    }
}
//Model specific
void NodeInterface::baseRateTask(void) {
  mRunModel = (rtmGetErrorStatus(mModel->getRTM()) ==
              (NULL));
  while (mRunModel) {
    mBaseRateSem.wait();
    if (!mRunModel) break;
    mModel->step();
    mRunModel &= !NodeInterface::getStopRequestedFlag(); //If RunModel and not stop requested
  }
  NodeInterface::stop();
}
// Angulo/Mandar giro/Publish1
void NodeInterface::create_Pub_Angulo_94(const char *topicName, const rmw_qos_profile_t& qosProfile){
  mPub_Angulo_94 = mNode->create_publisher<geometry_msgs::msg::Twist>(topicName, ros2::matlab::getQOSSettingsFromRMW(qosProfile));
}
void NodeInterface::publish_Pub_Angulo_94(const SL_Bus_geometry_msgs_Twist* inBus) {
  auto msg = std::make_unique<geometry_msgs::msg::Twist>();
  convertFromBus(*msg, inBus);
  mPub_Angulo_94->publish(std::move(msg));
}
// Angulo/Medidas/Publish1
void NodeInterface::create_Pub_Angulo_56(const char *topicName, const rmw_qos_profile_t& qosProfile){
  mPub_Angulo_56 = mNode->create_publisher<sensor_msgs::msg::Temperature>(topicName, ros2::matlab::getQOSSettingsFromRMW(qosProfile));
}
void NodeInterface::publish_Pub_Angulo_56(const SL_Bus_sensor_msgs_Temperature* inBus) {
  auto msg = std::make_unique<sensor_msgs::msg::Temperature>();
  convertFromBus(*msg, inBus);
  mPub_Angulo_56->publish(std::move(msg));
}
// Angulo/Medidas/Publish2
void NodeInterface::create_Pub_Angulo_65(const char *topicName, const rmw_qos_profile_t& qosProfile){
  mPub_Angulo_65 = mNode->create_publisher<sensor_msgs::msg::Temperature>(topicName, ros2::matlab::getQOSSettingsFromRMW(qosProfile));
}
void NodeInterface::publish_Pub_Angulo_65(const SL_Bus_sensor_msgs_Temperature* inBus) {
  auto msg = std::make_unique<sensor_msgs::msg::Temperature>();
  convertFromBus(*msg, inBus);
  mPub_Angulo_65->publish(std::move(msg));
}
// Angulo/Medidas/Subscribe
void NodeInterface::create_Sub_Angulo_1(const char *topicName, const rmw_qos_profile_t& qosProfile){
    auto callback = [this](sensor_msgs::msg::LaserScan::SharedPtr msg) {
        std::lock_guard<std::mutex> lockMsg(mtx_Sub_Angulo_1);
        mLatestMsg_Sub_Angulo_1 = msg;
    };
    mSub_Angulo_1 = mNode->create_subscription<sensor_msgs::msg::LaserScan>(topicName, ros2::matlab::getQOSSettingsFromRMW(qosProfile), callback);
}
bool NodeInterface::getLatestMessage_Sub_Angulo_1(SL_Bus_sensor_msgs_LaserScan* outBus) {
    if (mLatestMsg_Sub_Angulo_1.get()) {
        std::lock_guard<std::mutex> lockMsg(mtx_Sub_Angulo_1);
        convertToBus(outBus, *mLatestMsg_Sub_Angulo_1);
        return true;
    }
    return false;
}
// Angulo/R1/Subscribe2
void NodeInterface::create_Sub_Angulo_146(const char *topicName, const rmw_qos_profile_t& qosProfile){
    auto callback = [this](geometry_msgs::msg::Twist::SharedPtr msg) {
        std::lock_guard<std::mutex> lockMsg(mtx_Sub_Angulo_146);
        mLatestMsg_Sub_Angulo_146 = msg;
    };
    mSub_Angulo_146 = mNode->create_subscription<geometry_msgs::msg::Twist>(topicName, ros2::matlab::getQOSSettingsFromRMW(qosProfile), callback);
}
bool NodeInterface::getLatestMessage_Sub_Angulo_146(SL_Bus_geometry_msgs_Twist* outBus) {
    if (mLatestMsg_Sub_Angulo_146.get()) {
        std::lock_guard<std::mutex> lockMsg(mtx_Sub_Angulo_146);
        convertToBus(outBus, *mLatestMsg_Sub_Angulo_146);
        return true;
    }
    return false;
}
// Helper for Angulo/Mandar giro/Publish1
void create_Pub_Angulo_94(const char *topicName, const rmw_qos_profile_t& qosProfile){
  ros2::matlab::getNodeInterface()->create_Pub_Angulo_94(topicName, qosProfile);
}
void publish_Pub_Angulo_94(const SL_Bus_geometry_msgs_Twist* inBus) {
  ros2::matlab::getNodeInterface()->publish_Pub_Angulo_94(inBus);
}
// Helper for Angulo/Medidas/Publish1
void create_Pub_Angulo_56(const char *topicName, const rmw_qos_profile_t& qosProfile){
  ros2::matlab::getNodeInterface()->create_Pub_Angulo_56(topicName, qosProfile);
}
void publish_Pub_Angulo_56(const SL_Bus_sensor_msgs_Temperature* inBus) {
  ros2::matlab::getNodeInterface()->publish_Pub_Angulo_56(inBus);
}
// Helper for Angulo/Medidas/Publish2
void create_Pub_Angulo_65(const char *topicName, const rmw_qos_profile_t& qosProfile){
  ros2::matlab::getNodeInterface()->create_Pub_Angulo_65(topicName, qosProfile);
}
void publish_Pub_Angulo_65(const SL_Bus_sensor_msgs_Temperature* inBus) {
  ros2::matlab::getNodeInterface()->publish_Pub_Angulo_65(inBus);
}
// Helper for Angulo/Medidas/Subscribe
void create_Sub_Angulo_1(const char *topicName, const rmw_qos_profile_t& qosProfile){
  ros2::matlab::getNodeInterface()->create_Sub_Angulo_1(topicName, qosProfile);
}
bool getLatestMessage_Sub_Angulo_1(SL_Bus_sensor_msgs_LaserScan* outBus) {
  return ros2::matlab::getNodeInterface()->getLatestMessage_Sub_Angulo_1(outBus);
}
// Helper for Angulo/R1/Subscribe2
void create_Sub_Angulo_146(const char *topicName, const rmw_qos_profile_t& qosProfile){
  ros2::matlab::getNodeInterface()->create_Sub_Angulo_146(topicName, qosProfile);
}
bool getLatestMessage_Sub_Angulo_146(SL_Bus_geometry_msgs_Twist* outBus) {
  return ros2::matlab::getNodeInterface()->getLatestMessage_Sub_Angulo_146(outBus);
}
}//namespace matlab
}//namespace ros2
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
