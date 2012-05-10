#ifndef minix_system_call_getrlimit_h
#define minix_system_call_getrlimit_h

#ifndef _ANSI_H
#include <ansi.h>
#endif


#include <sys/resource.h>

_PROTOTYPE( int getrlimit, (int resource,struct rlimit * rlim)		);

#endif
