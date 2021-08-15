#include "geometry/line_segment.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include <ros/ros.h>
#include <string>
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
  auto time = ros::Time::now();
  std::cout << "current timestamp = " << std::setprecision(19) << time.toSec()
            << ", message = " << message_str
            << ", line_segment_len = " << std::setprecision(6)
            << line_segment->length() << std::endl;
  // manipulate file/folder by boost::filesystem
  {
    std::string file_str = nh.param<std::string>("file_name", " ");
    boost::filesystem::path file_path(file_str);
    std::cout << "file_name = " << file_path.stem()
              << ", extension = " << file_path.extension()
              << ", parent_folder = " << file_path.parent_path() << std::endl;
    if (boost::filesystem::exists(file_path)) {
      std::cout << "file not exist! file = " << file_path.string();
      return -1;
    }
  }
  return 0;
}