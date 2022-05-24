//
// Created by Ania-Lain on 2022/5/11 0011.
//
#ifndef LAUNCH_FRAMEWORK_HPP
#define LAUNCH_FRAMEWORK_HPP
namespace launcher{ namespace core{
    struct framework{
        template<::std::size_t size>
        void install(
            std::array<char const *const, size> const name_list) const noexcept{
          for (auto &&name : name_list) {
            ::std::cout << name << "\n";
          }
        }
        
        template<typename t>
        typename launcher::trait::bundle<t>::type load(){
          using return_t = typename launcher::trait::bundle<t>::type;
          return_t ret{};
          return ret;
        }
    };
}}
#endif //LAUNCH_FRAMEWORK_HPP
