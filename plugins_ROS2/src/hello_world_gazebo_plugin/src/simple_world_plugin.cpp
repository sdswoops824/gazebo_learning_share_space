#include <gazebo/common/Plugin.hh>
#include <rclcpp/rclcpp.hpp>
// #include <gazebo_ros/node.hpp>

namespace gazebo
{
class WorldPluginTutorial : public WorldPlugin
{
public:
  WorldPluginTutorial() : WorldPlugin()
  {
      
  }

  void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
  {
    const rclcpp::Logger LOGGER = rclcpp::get_logger("hello_world_gazebo_plugin");
    // Make sure the ROS node for Gazebo has already been initialized                                                                                    
    if (!rclcpp::ok())
    {
        std::string error = "A ROS node for Gazebo has not been initialized, unable to load plugin.";
        RCLCPP_FATAL_STREAM(LOGGER, error);
        return;
    }

    RCLCPP_WARN(LOGGER, "Hello Sue!");
  }

};
GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)
}