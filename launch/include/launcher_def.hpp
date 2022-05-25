#pragma once
#ifndef LAUNCHER_DEF_HPP
#define LAUNCHER_DEF_HPP

#include <type_traits>

namespace launcher { namespace trait {
    template<typename B>
    struct bundle {};
    
    template<typename T,
             typename B, T B::* f>
    struct Field {
        friend T& access(B &instance) {
          return instance.*f;
        }
    };
}}  // namespace launcher

#endif  // !LAUNCHER_DEF_HPP
