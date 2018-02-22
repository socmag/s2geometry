#ifndef GLOGGING_SHIM
#define GLOGGING_SHIM

#include <iostream>
#include <gflags/gflags.h>

#define DCHECK_GT(x, y) \
    if (false) {} \
        else std::cerr
#define DCHECK_GE(x, y) \
    if (false) {} \
        else std::cerr
#define DCHECK_LT(x, y) \
    if (false) {} \
        else std::cerr
#define DCHECK_LE(x, y) \
    if (false) {} \
        else std::cerr
#define DCHECK_EQ(x, y) \
    if (false) {} \
        else std::cerr
#define DCHECK_NE(x, y) \
    if (false) {} \
        else std::cerr
#define DCHECK(x) \
    if (false) {} \
        else std::cerr
#define DLOG_IF(severity, condition) \
    if (false) {} \
        else std::cerr
#define VLOG(severity) \
    if (false) {} \
        else std::cerr
#define LOG(severity) \
    if (false) {} \
        else std::cerr
#define LOG_IF(severity, code) \
    if (false) {} \
        else std::cerr

// Always-on checking
#define CHECK(x)	if(x){} \
        else std::cerr
#define CHECK_LT(x, y)	CHECK((x) < (y))
#define CHECK_GT(x, y)	CHECK((x) > (y))
#define CHECK_LE(x, y)	CHECK((x) <= (y))
#define CHECK_GE(x, y)	CHECK((x) >= (y))
#define CHECK_EQ(x, y)	CHECK((x) == (y))
#define CHECK_NE(x, y)	CHECK((x) != (y))
#define CHECK_NOTNULL(x) CHECK((x) != NULL)


#endif // GLOGGING_SHIM
