#include <lib.h>
#include <getrlimit.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <stdio.h>

PUBLIC int getrlimit(int resource, struct rlimit *rlim){
	message m;
	if(rlim == NULL)
		return(EFAULT);
	if(sizeof(resource) != sizeof(int))
		return(EINVAL);
	m.m1_i1 = resource;
	switch (resource) {
		case RLIMIT_NICE :
				_syscall(PM_PROC_NR, GET_RES_LIMIT,&m);
				rlim->rlim_cur = m.m2_l1;
				rlim->rlim_max = m.m2_l2;	break;
				printf("resultat de getrlimit %d",m.m2_l1);
        default:
            break;
    }
   return 0;
}
