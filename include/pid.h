#ifndef PID_H_
#define PID_H_

#include<limits>
#include<algorithm>

namespace controllers {

template<typename T>
class PID final {
 public:

  explicit PID(const T kp, const T ki, const T kd, const T output_ub = std::numeric_limits<T>::max(), 
      const T output_lb = std::numeric_limits<T>::lowerst()) noexcept;

  PID() = delete;
  
  PID(const PID &rhs) = delete;
  PID(PID &&rhs) = delete;

  PID &operator=(const PID &rhs) = delete;
  PID &operator=(PID &rhs) = delete;

  ~PID() = default;

  T Update(const T curr_err, const T dt);

  inline void ClearAll() noexcept;

 private:
  
  T kp_;
  T ki_;
  T kd_;

  T output_ub_;
  T output_lb_;

  T integral_{T(0)};
  T prev_err_{T(0)};

};


} // namespace controllers

#endif