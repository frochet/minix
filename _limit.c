
//
//  limit.c
//  minix_system_call
//
//  Created by Florentin Rochet on 4/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

int getrlimit(int resource, struct rlimit *rlim){
    message m = malloc(sizeof(message));
    m.m1_i1 = resource;
    switch (resource) {
        case 0:
                _SYSCALL(PM_PROC_LIMIT,RES_LIMIT,&m);
            break;
            
        default:
            break;
    }
    
}
int setrlimit(int resource, const struct rlimit *rlim){
    
}