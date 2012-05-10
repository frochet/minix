#include <sys/resource.h>
#include <lib.h>
#include <stdlib.h>
#include <stdio.h>
#include <minix/ipc.h>
int main(int argc, const char * argv){
	message *m = malloc(sizeof(message));
	m->m1_i1 = 8;
	_syscall(PM_PROC_NR,GET_RES_LIMIT,m);
	return 0;
}

