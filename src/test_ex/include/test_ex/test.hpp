#pragma once

#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <std_msgs/msg/int16.hpp>

using namespace std::chrono_literals;

class PublishNode : public rclcpp::Node {
public:
    PublishNode();
private:
    void callback();
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr cmd_vel1_publisher_;
    rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr cmd_vel2_publisher_;
};