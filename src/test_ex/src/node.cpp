#include "test_ex/node.hpp"


TestNode::TestNode() : Node("TestNode"), cmd_vel1_msgs_ptr_ (nullptr), cmd_vel2_msgs_ptr_ (nullptr)  {
       cmd_vel_publisher_ = create_publisher<std_msgs::msg::Int16>("/cmd_vel", 1);

       cmd_vel1_subscriber_ = create_subscription<std_msgs::msg::Int16>(
        "/cmd_vel1", 1, std::bind(&TestNode::cmd_vel1_callback, this, std::placeholders::_1));
       cmd_vel2_subscriber_ = create_subscription<std_msgs::msg::Int16>(
        "/cmd_vel2", 1, std::bind(&TestNode::cmd_vel2_callback, this, std::placeholders::_1));
}


void TestNode::publish_to_topic(){

       if (cmd_vel1_msgs_ptr_ != nullptr && cmd_vel2_msgs_ptr_ != nullptr){
              if (cmd_vel1_msgs_ptr_->data != 0){
                     RCLCPP_INFO(get_logger(), "cmd_vel1 %d cmd_vel2 %d result %d", cmd_vel1_msgs_ptr_->data, 
                     cmd_vel2_msgs_ptr_->data, cmd_vel1_msgs_ptr_->data);

                     cmd_vel_publisher_->publish(*cmd_vel1_msgs_ptr_); 
              } else {
                     RCLCPP_INFO(get_logger(), "cmd_vel1 %d cmd_vel2 %d result %d", cmd_vel1_msgs_ptr_->data, 
                     cmd_vel2_msgs_ptr_->data, cmd_vel2_msgs_ptr_->data);

                     cmd_vel_publisher_->publish(*cmd_vel2_msgs_ptr_);
              } 
              cmd_vel1_msgs_ptr_ = nullptr;
              cmd_vel2_msgs_ptr_ = nullptr;
       } else {
              RCLCPP_INFO(get_logger(), "nullptr");
       }
       
}

void TestNode::cmd_vel1_callback(const std_msgs::msg::Int16::SharedPtr msg){
       cmd_vel1_msgs_ptr_ = msg;
       publish_to_topic();
}

void TestNode::cmd_vel2_callback(const std_msgs::msg::Int16::SharedPtr msg){
       cmd_vel2_msgs_ptr_ = msg;
       publish_to_topic();
}
