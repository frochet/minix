
#include "pm.h"
#include "proto.h"
#include <sys/resource.h>
#include <signal.h> /*Just because mproc.h need it*/
#include "mproc.h"
#include <minix/ipc.h>

PUBLIC int do_getrlimit(message *m, struct mproc *mp){
	switch(m->m1_i1){
		case 0 : 	
		return 0;
		break;	
		case RLIMIT_NICE : printf("le plafond est de %d\n", get_nice_ceiling());
			           nc = &nceiling[who_p];
               			   mp->mp_reply.m2_l1 = *(nc->cur_ceiling);
                		   mp->mp_reply.m2_l2 = *(nc->ceiling);
				   break;
		default : break;
	}
	return OK;
}
PUBLIC int do_setrlimit(message *m,struct mproc *mp){
    	switch(m->m1_i1){
		case RLIMIT_NICE : printf("changement du plafond de la nice value \n");
				   nc = &nceiling[who_p];
				   *(nc->cur_ceiling) = m->m2_l1; /* passage de la valeure contenue dans la structure rlimit*/
		     		   if(m->m2_l2 < PRIO_MAX || mp->mp_effuid == SUPER_USER)
				   	*(nc->ceiling) = m->m2_l2;
				   else
					return(EPERM);
				   printf("le plafond est de %d\n", get_nice_ceiling());
			break;
		default : break;
	}
	return OK;
}

PUBLIC int get_nice_ceiling(){
	struct nice_ceiling *nc = &nceiling[who_p];
	return *(nc->cur_ceiling);
}
