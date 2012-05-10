#include <stdlib.h>
#include <stdio.h>
#include "fs.h"
#include "fproc.h"

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
