//
// Created by Ania-Lain on 2022/5/11 0011.
//
#ifndef LAUNCH_FRAMEWORK_HPP
#define LAUNCH_FRAMEWORK_HPP
namespace launcher {
  namespace core {
    // TODO : 修改为template使加载逻辑能够具备弹性变化,需要完成policy类的初步编写
    template<typename tag, template<class> class policy>
    struct framework {
      using current_policy = policy<tag>;
      template<::std::size_t size>
      void install(
          std::array<char const *const, size> const& name_list) const noexcept {
       current_policy::template install(name_list);
      }
      
      template<typename t>
      typename launcher::trait::bundle<t>::type load() {
        using return_t = typename launcher::trait::bundle<t>::type;
        return_t ret{};
        return ret;
      }
    };
  }
}
#endif //LAUNCH_FRAMEWORK_HPP
