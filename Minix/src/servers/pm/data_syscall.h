
#include <sys/resource.h>
#include <minix/config.h>

EXTERN struct nice_ceiling{
	int *cur_ceiling;
	int *ceiling;
}nceiling[NR_PROCS];
