#include "simple_model.h"

namespace models {

template<typename real>
SimpleModel<real>::SimpleModel(const real a, const real b) noexcept : a_(a), b_(b) {}

template<typename real>
void SimpleModel<real>::Step(const real input, const real dt) {

  real ad = std::exp(a_ * dt);
  real bd = real(1) / a_ * (ad - real(1)) * b_;

  this->state_ = ad * this->state_ + bd * input;
}

template<typename real>
real SimpleModel<real>::Observe() const {
  return this->state_;
}

template class SimpleModel<double>;
template class SimpleModel<int>;
template class SimpleModel<float>;

} // namespace models