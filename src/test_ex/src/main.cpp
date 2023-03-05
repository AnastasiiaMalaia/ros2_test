#include "test_ex/node.hpp"

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TestNode>());
  rclcpp::shutdown();
  return 0;
}