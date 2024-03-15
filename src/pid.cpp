#include "pid.h"

namespace controllers {

template<typename T>
PID<T>::PID(const T kp, const T ki, const T kd, const T output_ub, const T output_lb) noexcept
    : kp_(kp), ki_(ki), kd_(kd), output_ub_(output_ub), output_lb_(output_lb) {
  ClearAll();
}

template<typename T>
T PID<T>::Update(const T curr_err, const T dt) {
  
  T dot_err = T(0);
  if (dt != T(0)) {
    dot_err = (curr_err - prev_err_) / dt;
  }

  T output = kp_ * curr_err + ki_ * integral_ + kd_ * dot_err;

  T d_integral = (curr_err + prev_err_) / T(2) * dt;

  if (!((output >= output_ub_ && ki_ * d_integral > T(0)) || 
      output <= output_lb_ && ki_ * d_integral < T(0))) {
    output += ki_ * d_integral;
    integral_ += d_integral;
  }

  prev_err_ = curr_err;

  return std::min(std::max(output_lb_, output), output_ub_);
}

template<typename T>
inline void PID<T>::ClearAll() noexcept {
  integral_ = T(0);
  prev_err_ = T(0);
}


} // namespace controllers