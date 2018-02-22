#ifndef GLOGGING_SHIM
#define GLOGGING_SHIM

#include <iostream>
#include <gflags/gflags.h>

// #define S2_ENABLE_LOGGING

#ifdef S2_ENABLE_LOGGING
#define S2_LOGGING_BLOCK \
    if (false) {} \
        else std::cerr
#else
#define S2_LOGGING_BLOCK \
    if (true) {} \
        else std::cerr
#endif

#define S2_DCHECK_GT(x, y)                  S2_LOGGING_BLOCK
#define S2_DCHECK_GE(x, y)                  S2_LOGGING_BLOCK
#define S2_DCHECK_LT(x, y)                  S2_LOGGING_BLOCK
#define S2_DCHECK_LE(x, y)                  S2_LOGGING_BLOCK
#define S2_DCHECK_EQ(x, y)                  S2_LOGGING_BLOCK
#define S2_DCHECK_NE(x, y)                  S2_LOGGING_BLOCK
#define S2_DCHECK(x)                        S2_LOGGING_BLOCK
#define S2_DLOG_IF(severity, condition)     S2_LOGGING_BLOCK
#define S2_VLOG(severity)                   S2_LOGGING_BLOCK
#define S2_LOG(severity)                    S2_LOGGING_BLOCK
#define S2_LOG_IF(severity, code)           S2_LOGGING_BLOCK

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
