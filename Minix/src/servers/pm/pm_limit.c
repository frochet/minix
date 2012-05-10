#include "pm.h"

int is_full_limit()
{
        /* SYSCALL */
        int nbr_proc_limit = 255;

        if( procs_in_use <= nbr_proc_limit)        return 0;
        else                                       return 1;

}


