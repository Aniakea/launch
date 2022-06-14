#pragma once
#ifndef LAUNCHER_DEF_HPP
#define LAUNCHER_DEF_HPP

#include <type_traits>

#if __cplusplus >= 201703L
#define INLINE_CONSTEXPR constexpr
#else
#define INLINE_CONSTEXPR inline constexpr
#endif

namespace launcher { namespace trait {
  template<typename B>
  struct bundle {};
  
  template<typename T,
           typename B, T B::* f>
  struct Field {
    template<::std::size_t>
    friend T& access(B& instance) {
      return instance.*f;
    }
    
    friend void direct_set() {
    
    }
  };
}}  // namespace launcher

#endif  // !LAUNCHER_DEF_HPP
