#include <functional>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <ignition/math/Vector3.hh>
#include <rclcpp/rclcpp.hpp>

namespace gazebo
{
  class ModelPush : public ModelPlugin
  {
    public: 
    ModelPush() : ModelPlugin()
    {
        
    }
    
    void Load(physics::ModelPtr _parent, sdf::ElementPtr /*_sdf*/)
    {

      const rclcpp::Logger LOGGER = rclcpp::get_logger("hello_world_gazebo_plugin");
      // Store the pointer to the model
      this->model = _parent;

      // Listen to the update event. This event is broadcast every
      // simulation iteration.
      this->updateConnection = event::Events::ConnectWorldUpdateBegin(
          std::bind(&ModelPush::OnUpdate, this));
      
      RCLCPP_WARN(LOGGER, "Loaded ModelPush Plugin with parent...%s", this->model->GetName().c_str());
    }

    // Called by the world update start event
    public: void OnUpdate()
    {
      // Apply a small linear velocity to the model.
      this->model->SetLinearVel(ignition::math::Vector3d(0.05, 0, 0));
    }

    // Pointer to the model
    private: physics::ModelPtr model;

    // Pointer to the update event connection
    private: event::ConnectionPtr updateConnection;
  };

  // Register this plugin with the simulator
  GZ_REGISTER_MODEL_PLUGIN(ModelPush)
}