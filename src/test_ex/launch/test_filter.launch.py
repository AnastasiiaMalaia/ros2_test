import os
import sys

import launch
import launch_ros
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    ld = launch.LaunchDescription([

        launch_ros.actions.Node(
            package='test_ex',
            executable='filter',
            name='filter',
            output='screen',
        ),

        launch_ros.actions.Node(
            package='test_ex',
            executable='testing',
            name='publisher',
            output='screen',
        ),
    ])
    return ld


if __name__ == '__main__':
    generate_launch_description()