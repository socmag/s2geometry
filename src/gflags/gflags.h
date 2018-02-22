#ifndef GFLAGS_SHIM
#define GFLAGS_SHIM

#include <cstdint>

namespace google
{
    using int32 = std::int32_t;
    constexpr int32 DEBUG_MODE = false;

};


#define DEFINE_int32(flag_name, default_value, description) \
  std::int32_t FLAGS_ ## flag_name = default_value
#define DECLARE_int32(flag_name) \
  extern std::int32_t FLAGS_ ## flag_name

#define DEFINE_bool(flag_name, default_value, description) \
  bool FLAGS_ ## flag_name = default_value
#define DECLARE_bool(flag_name) \
  extern bool FLAGS_ ## flag_name

#define DEFINE_double(flag_name, default_value, description) \
  double FLAGS_ ## flag_name = default_value
#define DECLARE_double(flag_name) \
  extern double FLAGS_ ## flag_name

// Special case for string, because we have to specify the namespace
// std::string, which doesn't play nicely with our FLAG__namespace hackery.
#define DECLARE_string(name)                                            \
  namespace fLS {                                                       \
    extern GOOGLE_GLOG_DLL_DECL std::string& FLAGS_##name;              \
  }                                                                     \
  using fLS::FLAGS_##name

#endif // GFLAGS_SHIM
