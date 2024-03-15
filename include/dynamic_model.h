#ifndef DYNAMIC_MODEL_
#define DYNAMIC_MODEL_

namespace models {

template<typename real>
class DynamicModel {
 public:
  DynamicModel() = default;
  ~DynamicModel() = default;

  inline void Initialize(const real init_state);

  virtual void Step(const real input, const real dt) = 0;
  
  virtual real Observe() const = 0;

 protected:
  real state_;

};

template<typename real>
inline void DynamicModel<real>::Initialize(const real init_state) {
  state_ = init_state;
}

} // namespace models

#endif