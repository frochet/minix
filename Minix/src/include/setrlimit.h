#ifndef minix_system_call_setrlimit_h
#define minix_system_call_setrlimit_h

#ifndef _ANSI_H
#include <ansi.h>
#endif


#include <sys/resource.h>

_PROTOTYPE( int setrlimit, (int resource,struct rlimit * rlim)          );

#endif

