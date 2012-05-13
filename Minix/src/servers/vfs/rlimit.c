#include <stdlib.h>
#include <stdio.h>
#include "fs.h"
#include "fproc.h"
#include <sys/resource.h>
#include <minix/ipc.h>

int add_open_file(struct fproc* fp)
{
	int open_file_limit = fp->fopen_cur_ceiling;	
	fp->nbr_open_file++;
	
	if(fp->nbr_open_file <= open_file_limit)	return 1;	
	else 						return 0;
	
}

void rm_open_file(struct fproc* fp) 
{

	fp->nbr_open_file--;

}

PUBLIC int do_getrlimit(){
	struct fproc *fp = &fproc[who_p];
	int r = 0;
	switch(m_in.m1_i1){
		case RLIMIT_NOFILE : m_out.m2_l1 = fp->fopen_cur_ceiling;
				     m_out.m2_l2 = fp->fopen_hard_ceiling; 
				     printf("Récupération des limites effectuées\n");	
				     r = OK; break;
		case RLIMIT_FSIZE : m_out.m2_l1 = fp->fsize_cur_ceiling;
				    m_out.m2_l2 = fp->fsize_hard_ceiling;
				    printf("Récupération des limitest : rlim_cur : %d, rlim_max %d",fp->fsize_cur_ceiling,fp->fsize_hard_ceiling); 
				    r = OK;		break;	
		default : r = -1; break;
	}
	return r;
}
PUBLIC int do_setrlimit(){
	struct fproc *fp = &fproc[who_p];
	int r = 0;
	if(m_in.m2_l1 >= m_in.m2_l2 && fp->fp_effuid != SUPER_USER )
         	return(EPERM);
    	switch(m_in.m1_i1){
		case RLIMIT_NOFILE : 
				     fp->fopen_cur_ceiling = m_in.m2_l1;
				     fp->fopen_hard_ceiling = m_in.m2_l2;
				     printf("nouvelle limite poir NOFILE : cur %d et max %d",fp->fopen_cur_ceiling,fp->fopen_hard_ceiling);
				     r = OK;	 break;
		case RLIMIT_FSIZE :  fp->fsize_cur_ceiling = m_in.m2_l1;
				     fp->fsize_hard_ceiling = m_in.m2_l2;
			      	     printf("nouvelle limite poir FSIZE : cur %d et max %d",fp->fsize_cur_ceiling,fp->fsize_hard_ceiling);  break;
					
				     
		default : r = -1; break;
	}
	return r;
}

