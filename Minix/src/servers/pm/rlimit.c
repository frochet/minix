
#include "pm.h"
#include "proto.h"
#include <sys/resource.h>
#include <signal.h> /*Just because mproc.h need it*/
#include "mproc.h"
#include <minix/ipc.h>

/*do_gerlimit
 *
 * traite les cas RLIMIT_NICE et RLIMIT_NPROC 
 *
 * RLIMIT_NICE : Retourne les plafonds pour la nice value. Donne à mp_reply.m2_l1 la valeur de rlim_cur
 * 		 et a mp_reply.m2_l2 la valeur de rlim_max 
 * RLIMIT_NPROC : Retourne le plafond sur le nombre de process en utilisation.
 * 	          mp_reply.m2_l1 : la valeur rlim_cur et mp_reply.m2.l2 : la valeur de rlim_max 	 */

PUBLIC int do_getrlimit(message *m, struct mproc *mp){
	switch(m->m1_i1){
		case 0 : 	
		return 0;
		break;	
		case RLIMIT_NICE : printf("le plafond est de %d\n", get_nice_ceiling());
               			   mp->mp_reply.m2_l1 = mp->nice_cur_ceiling;
                		   mp->mp_reply.m2_l2 = mp->nice_ceiling;
				   break;
		case RLIMIT_NPROC : mp->mp_reply.m2_l1 = mp->nproc_cur_ceiling;
				    mp->mp_reply.m2_l2 = mp->nproc_ceiling;	 break;
		default : return -1; break;
	}
	return OK;

}

/*do_setrlimit
 * traite les cas RLIMIT_NICE et RLIMIT_NPROC
 *
 * RLIMIT_NICE : Set les plafonds pour la nice value
 *
 * RLIMIT_NPROC : Set les plafonds pour le nombre de process en utilisation.
 * */
PUBLIC int do_setrlimit(message *m,struct mproc *mp){
    	switch(m->m1_i1){
		case RLIMIT_NICE : printf("changement du plafond de la nice value \n");
				   mp->nice_cur_ceiling = m->m2_l1; /* passage de la valeure contenue dans la structure rlimit*/
 
				   if(m->m2_l2 < m->m2_l1 && mp->mp_effuid != SUPER_USER){
					return(EPERM);
				   }
				   else if(m->m2_l2 > PRIO_MAX && mp->mp_effuid !=SUPER_USER){
					return(EPERM);
				   }
				   else{
					 mp->nice_ceiling = m->m2_l2;
				   }
				   printf("le plafond est de %d\n", get_nice_ceiling());	break;
		case RLIMIT_NPROC : printf("changement du plafond de la valeur maximale de processus en utilisation \n ");
				    mp->nproc_cur_ceiling = m->m2_l1;
				    if(m->m2_l2 < m->m2_l1 && mp->mp_effuid != SUPER_USER)
                                        return(EPERM);
                                    else if(m->m2_l2 > NR_PROCS && mp->mp_effuid != SUPER_USER)
                                        return(EPERM);
                                    else
                                         mp->nproc_ceiling = m->m2_l2;
				    
				    break;
		default : return -1; break;
	}
	return OK;
}

/* Retourne le plafond correspondant a rlim_cur
 * */
PUBLIC int get_nice_ceiling(){
	mp = &mproc[who_p];
	return mp->nice_cur_ceiling;
}

int is_full_limit()
{
	int nbr_proc_limit;
	mp =  &mproc[who_p];
        nbr_proc_limit = mp->nproc_cur_ceiling;

        if( procs_in_use <= nbr_proc_limit)        return 0;
        else                                       return 1;

}

int rlimit_nice(int arg_pri, int arg_who){
	mp = &mproc[arg_who];
        if(arg_pri >= mp->nice_cur_ceiling)
                return(EINVAL);
	return 0;	
}
