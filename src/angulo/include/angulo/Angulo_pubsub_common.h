
//
// Code generated for Simulink model 'Angulo'.
//
// Model version                  : 1.27
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Thu Jun 09 17:14:46 2022
//
#ifndef _SLROS2_COMMON_H_
#define _SLROS2_COMMON_H_
#include "Angulo_types.h"
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, hist, dep, dur, rel)  \
    {                                                   \
        qosStruct.history = hist;                       \
        qosStruct.depth = dep;                          \
        qosStruct.durability = dur;                     \
        qosStruct.reliability = rel;                    \
    }
#endif
namespace ros2 {
    namespace matlab {
        // Angulo/Mandar giro/Publish1
        extern void create_Pub_Angulo_94(const char *topicName, const rmw_qos_profile_t& qosProfile);
        extern void publish_Pub_Angulo_94(const SL_Bus_geometry_msgs_Twist* inBus);
        // Angulo/Medidas/Publish1
        extern void create_Pub_Angulo_56(const char *topicName, const rmw_qos_profile_t& qosProfile);
        extern void publish_Pub_Angulo_56(const SL_Bus_sensor_msgs_Temperature* inBus);
        // Angulo/Medidas/Publish2
        extern void create_Pub_Angulo_65(const char *topicName, const rmw_qos_profile_t& qosProfile);
        extern void publish_Pub_Angulo_65(const SL_Bus_sensor_msgs_Temperature* inBus);
        // Angulo/Medidas/Subscribe
        extern void create_Sub_Angulo_1(const char *topicName, const rmw_qos_profile_t& qosProfile);
        extern bool getLatestMessage_Sub_Angulo_1(SL_Bus_sensor_msgs_LaserScan* outBus);
        // Angulo/R1/Subscribe2
        extern void create_Sub_Angulo_146(const char *topicName, const rmw_qos_profile_t& qosProfile);
        extern bool getLatestMessage_Sub_Angulo_146(SL_Bus_geometry_msgs_Twist* outBus);
    }
}
#endif // _SLROS2_COMMON_H_
