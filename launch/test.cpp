#include <array>
#include <memory>
#include <iostream>
#include <utility>

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
//
//    template<>
//    struct bundle<double>{
//        constexpr static auto name = "double";
//
//        using type = double;
//    };
//
//    template<>
//    struct bundle<tr>{
//        constexpr static auto name = "test_class";
//
//        using type = typename ::std::shared_ptr<tr>;
//    };
    }  // namespace trait
}  // namespace launcher

using current_launcher = launcher::launch<int, char/*, double, tr*/>;

#include "include/framework.hpp"

using loder = launcher::core::framework;

struct sub : private loder {
    int a;
    int b;
};

struct virtual_test {
    virtual ~virtual_test() = 0;
    
    virtual void test() = 0;
};

template<typename T>
struct load_polic : private T {
  
};

namespace Database {
    template<typename t, template<class>
             class invoke>
    struct _interface {
        using query_r_t = typename invoke<t>::query_return_t;
        
        virtual query_r_t Query() = 0;
    };
}

int main() {
  ::std::cout << sizeof(virtual_test) << "\n";
  ::std::cout << sizeof(loder) << "\n";
  ::std::cout << sizeof(sub) << "\n";
  Test rt{};
  loder framework{};
  current_launcher::load(framework);
  current_launcher::instance().to(rt);
}
