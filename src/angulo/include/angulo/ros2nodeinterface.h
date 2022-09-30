
//
// File ros2nodeinterface.h
//
// Code generated for Simulink model 'Angulo'.
//
// Model version                  : 1.27
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jun 09 17:14:45 2022
//
#ifndef _ROS2_MATLAB_NODEINTERFACE_
#define _ROS2_MATLAB_NODEINTERFACE_
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "rclcpp/rclcpp.hpp"
class Angulo;
#include "rtwtypes.h"
#include "Angulo_types.h"
#include "slros_busmsg_conversion.h"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_msgs/msg/temperature.hpp"
namespace ros2 {
namespace matlab {
  //Semaphore using std::CV and std::mutex
  class Semaphore {
  public:
    std::mutex mMutex;
    std::condition_variable mCV;
    std::atomic_uint mCount;
    //
    Semaphore(int count = 0)
      : mCount(count) {
      }
    //
    inline void notify() {
      std::unique_lock<std::mutex> lock(mMutex);
      mCount++;
      mCV.notify_all();
    }
    //
    inline void wait() {
      std::unique_lock<std::mutex> lock(mMutex);
      while (mCount == 0) {
        mCV.wait(lock);
      }
      if (mCount)
        mCount--;
    }
  };
  //NodeInterface
  class NodeInterface {
    NodeInterface(const NodeInterface& );
    NodeInterface& operator=(const NodeInterface& );
    //
    rclcpp::Node::SharedPtr mNode;
    std::shared_ptr<Angulo> mModel;
    rclcpp::executors::MultiThreadedExecutor::SharedPtr mExec;
    //
    Semaphore mBaseRateSem;
    std::shared_ptr<std::thread> mBaseRateThread;
    std::shared_ptr<std::thread> mSchedulerThread;
    //
    //
    Semaphore mStopSem;
    volatile boolean_T mRunModel;
    //
    // Angulo/Mandar giro/Publish1
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr mPub_Angulo_94;
    // Angulo/Medidas/Publish1
    rclcpp::Publisher<sensor_msgs::msg::Temperature>::SharedPtr mPub_Angulo_56;
    // Angulo/Medidas/Publish2
    rclcpp::Publisher<sensor_msgs::msg::Temperature>::SharedPtr mPub_Angulo_65;
    //
    // Angulo/Medidas/Subscribe
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr mSub_Angulo_1;
    sensor_msgs::msg::LaserScan::SharedPtr mLatestMsg_Sub_Angulo_1;
    std::mutex mtx_Sub_Angulo_1;
    // Angulo/R1/Subscribe2
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr mSub_Angulo_146;
    geometry_msgs::msg::Twist::SharedPtr mLatestMsg_Sub_Angulo_146;
    std::mutex mtx_Sub_Angulo_146;
    //
  public:
    NodeInterface();
    ~NodeInterface();
    //
    void initialize(int argc, char * const argv[]);
    int run();
    void stop(void);
    void terminate(void);
    //
    boolean_T getStopRequestedFlag(void);
    void schedulerThreadCallback(void);
    void baseRateTask(void);
    // Angulo/Mandar giro/Publish1
    void create_Pub_Angulo_94(const char *topicName, const rmw_qos_profile_t& qosProfile);
    void publish_Pub_Angulo_94(const SL_Bus_geometry_msgs_Twist* inBus);
    // Angulo/Medidas/Publish1
    void create_Pub_Angulo_56(const char *topicName, const rmw_qos_profile_t& qosProfile);
    void publish_Pub_Angulo_56(const SL_Bus_sensor_msgs_Temperature* inBus);
    // Angulo/Medidas/Publish2
    void create_Pub_Angulo_65(const char *topicName, const rmw_qos_profile_t& qosProfile);
    void publish_Pub_Angulo_65(const SL_Bus_sensor_msgs_Temperature* inBus);
    // Angulo/Medidas/Subscribe
    void create_Sub_Angulo_1(const char *topicName, const rmw_qos_profile_t& qosProfile);
    bool getLatestMessage_Sub_Angulo_1(SL_Bus_sensor_msgs_LaserScan* outBus);
    // Angulo/R1/Subscribe2
    void create_Sub_Angulo_146(const char *topicName, const rmw_qos_profile_t& qosProfile);
    bool getLatestMessage_Sub_Angulo_146(SL_Bus_geometry_msgs_Twist* outBus);
    //
    rclcpp::Node::SharedPtr getNode() {
      return mNode;
    }
    //
    std::shared_ptr<Angulo> getModel() {
      return mModel;
    }
  }; //class NodeInterface
  //
  std::shared_ptr<ros2::matlab::NodeInterface> getNodeInterface();
  // Helper for Angulo/Mandar giro/Publish1
  void create_Pub_Angulo_94(const char *topicName, const rmw_qos_profile_t& qosProfile = rmw_qos_profile_default);
  void publish_Pub_Angulo_94(const SL_Bus_geometry_msgs_Twist* inBus);
  // Helper for Angulo/Medidas/Publish1
  void create_Pub_Angulo_56(const char *topicName, const rmw_qos_profile_t& qosProfile = rmw_qos_profile_default);
  void publish_Pub_Angulo_56(const SL_Bus_sensor_msgs_Temperature* inBus);
  // Helper for Angulo/Medidas/Publish2
  void create_Pub_Angulo_65(const char *topicName, const rmw_qos_profile_t& qosProfile = rmw_qos_profile_default);
  void publish_Pub_Angulo_65(const SL_Bus_sensor_msgs_Temperature* inBus);
  // Helper for Angulo/Medidas/Subscribe
  void create_Sub_Angulo_1(const char *topicName, const rmw_qos_profile_t& qosProfile = rmw_qos_profile_default);
  bool getLatestMessage_Sub_Angulo_1(SL_Bus_sensor_msgs_LaserScan* outBus);
  // Helper for Angulo/R1/Subscribe2
  void create_Sub_Angulo_146(const char *topicName, const rmw_qos_profile_t& qosProfile = rmw_qos_profile_default);
  bool getLatestMessage_Sub_Angulo_146(SL_Bus_geometry_msgs_Twist* outBus);
  // Get QoS Settings from RMW
  inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
      rclcpp::QoS qos(rclcpp::QoSInitialization::from_rmw(qosProfile));
      if (RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL == qosProfile.durability) {
          qos.transient_local();
      } else {
          qos.durability_volatile();
      }
      if (RMW_QOS_POLICY_RELIABILITY_RELIABLE == qosProfile.reliability) {
          qos.reliable();
      } else {
          qos.best_effort();
      }
      return qos;
  }
}//namespace matlab
}//namespace ros2
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
#endif //_ROS2_MATLAB_ROS2CGEN_MULTIRATE_
