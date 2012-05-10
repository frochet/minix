#include <lib.h>
#include <sys/resource.h>
#include <getrlimit.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char ** argv){
	struct rlimit *rlim  = malloc(sizeof(struct rlimit*));
	int test;
	int resource = atoi(argv[1]);
	printf("fonctionne\n");
	switch(resource){
		case RLIMIT_NICE :
			test = getrlimit(resource,rlim);
			printf("resultat : %d\n",test);
			printf("limit %d ",rlim->rlim_cur); break;
		default : break;
	}
	return test;	
}
