function rosmsgOut = Temperature(slBusIn, rosmsgOut)
%#codegen
%   Copyright 2021 The MathWorks, Inc.
    rosmsgOut.header = bus_conv_fcns.ros2.busToMsg.std_msgs.Header(slBusIn.header,rosmsgOut.header(1));
    rosmsgOut.temperature = double(slBusIn.temperature);
    rosmsgOut.variance = double(slBusIn.variance);
end
