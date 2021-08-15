#include <iostream>
#include <ros/ros.h>
#include <string>
#include "geometry/line_segment.h"
using namespace common::geometry;

int main(int argc, char **argv) {
  ros::init(argc, argv, "hello_world");
  ros::NodeHandle nh("~");
  std::string message_str =
      nh.param<std::string>("message", "specify message in launch file!");
  std::shared_ptr<LineSegment> line_segment(new LineSegment());
  if (!line_segment->init()) {
    std::cout << "line_segment not init!";
    return -1;
  }
  SPointXYZ beg_pt(nh.param<double>("beg_x", 0.0),
                   nh.param<double>("beg_y", 0.0),
                   nh.param<double>("beg_z", 0.0));
  SPointXYZ end_pt(nh.param<double>("end_x", 0.0),
                   nh.param<double>("end_y", 0.0),
                   nh.param<double>("end_z", 0.0));
  line_segment->setBeg(beg_pt);
  line_segment->setEnd(end_pt);  
  std::cout << message_str << ", line_segment_len = " << std::setprecision(6) << line_segment->length()
            << std::endl;
  return 0;
}