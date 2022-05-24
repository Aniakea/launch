#pragma once
#ifndef LAUNCH_HPP
#define LAUNCH_HPP

#include <tuple>
#include "launcher_def.hpp"

namespace launcher {
    template<typename...t>
    struct launch final {
        enum {
            size = sizeof...(t)
        };
        using list_t = ::std::array<const char *const, size>;
    private:
        using idx_t = ::std::index_sequence_for<t...>;
        
        using container_t = ::std::tuple<typename trait::bundle<t>::type...>;
        
        constexpr static list_t name_list{trait::bundle<t>::name...};
        
        mutable container_t bundles{};
        
        launch() = default;
        
        ~launch() = default;
    
    public:
        launch(
            launch const &) = delete;
        
        launch(
            launch &&) = delete;
        
        launch &operator=(
            launch const &) = delete;
        
        launch &operator=(
            launch &&) = delete;
    
    private:
        template<typename u, ::std::size_t...idx>
        void _to_help(
            u &user_instance,
            ::std::index_sequence<idx...>) const noexcept {
          [[maybe_unused]]int a[size]{(user_instance.set(::std::get<idx>(bundles)), 0)...};
        }
        
        template<typename rt,
                 typename framework>
        static typename trait::bundle<rt>::type _load_help(
            framework &&instance) noexcept {
          return instance.template load<rt>();
        }
    
    public:
        static launch<t...> const &instance() {
          static const launch<t...> instance{};
          return instance;
        }
        
        template<typename framework>
        static void load(
            framework &&instance) noexcept {
          instance.install(name_list);
          launch::instance().bundles =
              ::std::make_tuple(_load_help<t>(::std::forward<framework>(instance))...);
        }
        
        template<typename U>
        void to(
            U &user_instance) const noexcept {
          _to_help(user_instance, idx_t{});
        }
    };
}  // namespace launcher

#endif  // !LAUNCH_HPP
