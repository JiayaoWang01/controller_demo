#ifndef SIMPLE_MODEL_
#define SIMPLE_MODEL_

#include<cmath>
#include "dynamic_model.h"

namespace models {

template<typename real>
class SimpleModel : public DynamicModel<real> {
 public:
  explicit SimpleModel(const real a, const real b) noexcept;
  SimpleModel() = delete;
  ~SimpleModel() = default;

  void Step(const real input, const real dt) override;
  real Observe() const override;

 private:
  real a_;
  real b_;

};

} // namespace models

#endif