#include <lib.h>
#include <sys/resource.h>
#include <setrlimit.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char ** argv){
        struct rlimit *rlim  = malloc(sizeof(struct rlimit*));
        int test;
        int resource = atoi(argv[1]);
        switch(resource){
                case RLIMIT_NICE : rlim->rlim_cur = 20; rlim->rlim_max = 30;
				   setrlimit(resource,rlim);	 break;
		default : break;
     	

	}
	return 0;
}
