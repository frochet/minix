#include <lib.h>
#include <setrlimit.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

PUBLIC int setrlimit(int resource, struct rlimit *rlimit){
	int r = 0;
        message m;
        if(rlimit == NULL)
                return(EFAULT);
        if(sizeof(resource) != sizeof(int) || rlimit->rlim_max <= rlimit->rlim_cur)
                return(EINVAL);
	/* Appel systemes */
        m.m1_i1 = resource;
        m.m2_l1 = rlimit->rlim_cur; 
	m.m2_l2 = rlimit->rlim_max;
	switch(resource){
		case RLIMIT_NICE   : r = _syscall(PM_PROC_NR,SET_RES_LIMIT,&m);	 break;
		case RLIMIT_NPROC  : r = _syscall(PM_PROC_NR,SET_RES_LIMIT,&m);	 break;
		case RLIMIT_FSIZE  : r = _syscall(VFS_PROC_NR,SET_RES_LIMIT,&m); break;
		case RLIMIT_NOFILE : r = _syscall(VFS_PROC_NR,SET_RES_LIMIT,&m); break;
		default		   : r = -1; 					 break;
	}
	return(r);
}
