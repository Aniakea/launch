#include <array>
#include <memory>
#include <iostream>
#include <utility>
#include <thread>
//#include <experimental/reflect>

class tr {
 public:
  tr() = default;
  
  ~tr() = default;
};

class Test {
  int a{};
  
  char b{};
  
  double c{};
  
  ::std::shared_ptr<tr> d;
 
 public:
  void set(
      int v) {
    a = v;
  }
  
  void set(
      char v) {
    b = v;
  }
  
  void set(
      double v) {
    c = v;
  }
  
  void set(
      ::std::shared_ptr<tr> v) {
    d = std::move(v);
  }
};

#include "include/launch.hpp"

namespace launcher {
  namespace trait {
    template<>
    struct bundle<int> {
      constexpr static auto name = "int";
      
      using type = int;
    };
    
    template<>
    struct bundle<char> {
      constexpr static auto name = "char";
      
      using type = char;
    };
    
    template<>
    struct bundle<double> {
      constexpr static auto name = "double";
      
      using type = double;
    };
    
    template<>
    struct bundle<tr> {
      constexpr static auto name = "test_class";
      
      using type = typename ::std::shared_ptr<tr>;
    };
  }  // namespace trait
}  // namespace launcher

using current_launcher = launcher::launch<int, char/*, double, tr*/>;

#include "include/framework.hpp"

using loder = launcher::core::framework;

int main() {
  ::std::thread t();
  Test  rt{};
  loder framework{};
  current_launcher::load(framework);
  current_launcher::instance().to(rt);
}
