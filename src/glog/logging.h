#ifndef GLOGGING_SHIM
#define GLOGGING_SHIM

#include <iostream>
#include <gflags/gflags.h>

#define S2_DCHECK_GT(x, y) \
    if (false) {} \
        else std::cerr
#define S2_DCHECK_GE(x, y) \
    if (false) {} \
        else std::cerr
#define S2_DCHECK_LT(x, y) \
    if (false) {} \
        else std::cerr
#define S2_DCHECK_LE(x, y) \
    if (false) {} \
        else std::cerr
#define S2_DCHECK_EQ(x, y) \
    if (false) {} \
        else std::cerr
#define S2_DCHECK_NE(x, y) \
    if (false) {} \
        else std::cerr
#define S2_DCHECK(x) \
    if (false) {} \
        else std::cerr
#define S2_DLOG_IF(severity, condition) \
    if (false) {} \
        else std::cerr
#define S2_VLOG(severity) \
    if (false) {} \
        else std::cerr
#define S2_LOG(severity) \
    if (false) {} \
        else std::cerr
#define S2_LOG_IF(severity, code) \
    if (false) {} \
        else std::cerr

// Always-on checking
#define S2_CHECK(x)	if(x){} \
        else std::cerr
#define S2_CHECK_LT(x, y)	S2_CHECK((x) < (y))
#define S2_CHECK_GT(x, y)	S2_CHECK((x) > (y))
#define S2_CHECK_LE(x, y)	S2_CHECK((x) <= (y))
#define S2_CHECK_GE(x, y)	S2_CHECK((x) >= (y))
#define S2_CHECK_EQ(x, y)	S2_CHECK((x) == (y))
#define S2_CHECK_NE(x, y)	S2_CHECK((x) != (y))
#define S2_CHECK_NOTNULL(x) S2_CHECK((x) != NULL)


#endif // GLOGGING_SHIM
