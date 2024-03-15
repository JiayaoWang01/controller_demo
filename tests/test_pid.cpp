#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "pid.h"
#include "simple_model.h"

TEST(testCase, TestPid) {
  double a = 1.0, b = 1.0, x0 = 0.0;
  models::SimpleModel<double> plant(a, b);
  plant.Initialize(x0);

  double kp = 1.0, ki = 0.1, kd = 0.0, u_ub = 0.5, u_lb = -0.5;
  controllers::PID<double> pid_controller(kp, ki, kd, u_ub, u_lb);

  std::vector<double> ref_traj(100, 1.0);
  double dt = 0.1;
  std::vector<double> act_traj, meas_traj, err_traj;

  for (double r : ref_traj) {
    double y = plant.Observe();
    double e = r - y;
    double u = pid_controller.Update(e, dt);
    plant.Step(u, dt);

    meas_traj.push_back(y);
    err_traj.push_back(e);
    act_traj.push_back(u);
  }

  std::cout << "tracking error: ";
  for (double e : err_traj) {
    std::cout << e << ", " << std::endl;
  }

}