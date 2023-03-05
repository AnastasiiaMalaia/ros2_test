#include "test_ex/test.hpp"

PublishNode::PublishNode() : Node("PublishNode"){
    timer_= create_wall_timer(500ms, std::bind(&PublishNode::callback, this)); 
    cmd_vel1_publisher_ = create_publisher<std_msgs::msg::Int16>("/cmd_vel1", 1);
    cmd_vel2_publisher_ = create_publisher<std_msgs::msg::Int16>("/cmd_vel2", 1);
    // void publish_to_topic();
}

void PublishNode::callback(){
    std_msgs::msg::Int16 cmd_vel1_msg;
    std_msgs::msg::Int16 cmd_vel2_msg;


    cmd_vel1_msg.data = round((double) rand()/RAND_MAX);
    cmd_vel2_msg.data = round((double) rand()/RAND_MAX);
    cmd_vel1_publisher_->publish(cmd_vel1_msg);
    cmd_vel2_publisher_->publish(cmd_vel2_msg);
}


int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PublishNode>());
  rclcpp::shutdown();
  return 0;
}

// void PublishNode::publish_to_topic(rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr publisher){
    
//     RCLCPP_INFO(this->get_logger(), "Publishing message");
//     publisher->publish(msg);
// }