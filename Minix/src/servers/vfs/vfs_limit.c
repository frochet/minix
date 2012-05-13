#include <stdlib.h>
#include <stdio.h>
#include "fs.h"
#include "fproc.h"
#include <signal.h>
int add_open_file(struct fproc* fp)
{
	/* SYSCALL */
	int open_file_limit = 14;	
	fp->nbr_open_file++;
	
	if(fp->nbr_open_file <= open_file_limit)	return 1;	
	else 						return 0;
	
}

void rm_open_file(struct fproc* fp) 
{

	fp->nbr_open_file--;

}

int is_too_big(int fsize, int nbr_byts) {

	int pid;
	int fsize_max = 50000000;
	fp = &fproc[who_p];
	pid = fp->fp_pid;
	if(fsize % 1000000 == 17) printf("fsize : %d , nbr_byts %d \n",fsize,nbr_byts);
	if((fsize + nbr_byts) >= fsize_max){ 
		printf("trying to kill proc no %d ",pid);
		kill(pid,SIGXFSZ);
		return 1;
	}	
	else return 0;

}
