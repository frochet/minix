#include <lib.h>
#include <setrlimit.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

PUBLIC int setrlimit(int resource, struct rlimit *rlimit){
        message m;
        if(rlimit == NULL)
                return(EFAULT);
        if(sizeof(resource) != sizeof(int))
                return(EINVAL);
        m.m1_i1 = resource;
	switch(resource){
		case RLIMIT_NICE : m.m2_l1 = rlimit->rlim_cur; m.m2_l2 = rlimit->rlim_max;
				   _syscall(PM_PROC_NR,SET_RES_LIMIT,&m);
				   	 break;
		default : break;
	}
}
