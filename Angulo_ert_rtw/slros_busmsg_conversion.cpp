#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_builtin_interfaces_Time and builtin_interfaces::msg::Time

void convertFromBus(builtin_interfaces::msg::Time& msgPtr, SL_Bus_builtin_interfaces_Time const* busPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  msgPtr.nanosec =  busPtr->nanosec;
  msgPtr.sec =  busPtr->sec;
}

void convertToBus(SL_Bus_builtin_interfaces_Time* busPtr, const builtin_interfaces::msg::Time& msgPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  busPtr->nanosec =  msgPtr.nanosec;
  busPtr->sec =  msgPtr.sec;
}


// Conversions between SL_Bus_geometry_msgs_Twist and geometry_msgs::msg::Twist

void convertFromBus(geometry_msgs::msg::Twist& msgPtr, SL_Bus_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(msgPtr.angular, &busPtr->angular);
  convertFromBus(msgPtr.linear, &busPtr->linear);
}

void convertToBus(SL_Bus_geometry_msgs_Twist* busPtr, const geometry_msgs::msg::Twist& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->angular, msgPtr.angular);
  convertToBus(&busPtr->linear, msgPtr.linear);
}


// Conversions between SL_Bus_geometry_msgs_Vector3 and geometry_msgs::msg::Vector3

void convertFromBus(geometry_msgs::msg::Vector3& msgPtr, SL_Bus_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr.x =  busPtr->x;
  msgPtr.y =  busPtr->y;
  msgPtr.z =  busPtr->z;
}

void convertToBus(SL_Bus_geometry_msgs_Vector3* busPtr, const geometry_msgs::msg::Vector3& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->x =  msgPtr.x;
  busPtr->y =  msgPtr.y;
  busPtr->z =  msgPtr.z;
}


// Conversions between SL_Bus_sensor_msgs_LaserScan and sensor_msgs::msg::LaserScan

void convertFromBus(sensor_msgs::msg::LaserScan& msgPtr, SL_Bus_sensor_msgs_LaserScan const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  msgPtr.angle_increment =  busPtr->angle_increment;
  msgPtr.angle_max =  busPtr->angle_max;
  msgPtr.angle_min =  busPtr->angle_min;
  convertFromBus(msgPtr.header, &busPtr->header);
  convertFromBusVariablePrimitiveArray(msgPtr.intensities, busPtr->intensities, busPtr->intensities_SL_Info);
  msgPtr.range_max =  busPtr->range_max;
  msgPtr.range_min =  busPtr->range_min;
  convertFromBusVariablePrimitiveArray(msgPtr.ranges, busPtr->ranges, busPtr->ranges_SL_Info);
  msgPtr.scan_time =  busPtr->scan_time;
  msgPtr.time_increment =  busPtr->time_increment;
}

void convertToBus(SL_Bus_sensor_msgs_LaserScan* busPtr, const sensor_msgs::msg::LaserScan& msgPtr)
{
  const std::string rosMessageType("sensor_msgs/LaserScan");

  busPtr->angle_increment =  msgPtr.angle_increment;
  busPtr->angle_max =  msgPtr.angle_max;
  busPtr->angle_min =  msgPtr.angle_min;
  convertToBus(&busPtr->header, msgPtr.header);
  convertToBusVariablePrimitiveArray(busPtr->intensities, busPtr->intensities_SL_Info, msgPtr.intensities, slros::EnabledWarning(rosMessageType, "intensities"));
  busPtr->range_max =  msgPtr.range_max;
  busPtr->range_min =  msgPtr.range_min;
  convertToBusVariablePrimitiveArray(busPtr->ranges, busPtr->ranges_SL_Info, msgPtr.ranges, slros::EnabledWarning(rosMessageType, "ranges"));
  busPtr->scan_time =  msgPtr.scan_time;
  busPtr->time_increment =  msgPtr.time_increment;
}


// Conversions between SL_Bus_sensor_msgs_Temperature and sensor_msgs::msg::Temperature

void convertFromBus(sensor_msgs::msg::Temperature& msgPtr, SL_Bus_sensor_msgs_Temperature const* busPtr)
{
  const std::string rosMessageType("sensor_msgs/Temperature");

  convertFromBus(msgPtr.header, &busPtr->header);
  msgPtr.temperature =  busPtr->temperature;
  msgPtr.variance =  busPtr->variance;
}

void convertToBus(SL_Bus_sensor_msgs_Temperature* busPtr, const sensor_msgs::msg::Temperature& msgPtr)
{
  const std::string rosMessageType("sensor_msgs/Temperature");

  convertToBus(&busPtr->header, msgPtr.header);
  busPtr->temperature =  msgPtr.temperature;
  busPtr->variance =  msgPtr.variance;
}


// Conversions between SL_Bus_std_msgs_Header and std_msgs::msg::Header

void convertFromBus(std_msgs::msg::Header& msgPtr, SL_Bus_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr.frame_id, busPtr->frame_id, busPtr->frame_id_SL_Info);
  convertFromBus(msgPtr.stamp, &busPtr->stamp);
}

void convertToBus(SL_Bus_std_msgs_Header* busPtr, const std_msgs::msg::Header& msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->frame_id, busPtr->frame_id_SL_Info, msgPtr.frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  convertToBus(&busPtr->stamp, msgPtr.stamp);
}

