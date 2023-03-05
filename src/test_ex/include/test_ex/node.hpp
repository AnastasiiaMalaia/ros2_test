#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int16.hpp>

class TestNode : public rclcpp::Node {
public:
    TestNode() ;
private:
    void publish_to_topic();
    void cmd_vel1_callback(const std_msgs::msg::Int16::SharedPtr msg);
    void cmd_vel2_callback(const std_msgs::msg::Int16::SharedPtr msg);
private:
    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr cmd_vel1_subscriber_;
    rclcpp::Subscription<std_msgs::msg::Int16>::SharedPtr cmd_vel2_subscriber_;

    rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr cmd_vel_publisher_;

    std_msgs::msg::Int16::SharedPtr cmd_vel1_msgs_ptr_ = std::make_shared<std_msgs::msg::Int16>();
    std_msgs::msg::Int16::SharedPtr cmd_vel2_msgs_ptr_ = std::make_shared<std_msgs::msg::Int16>();

};