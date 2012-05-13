#include "pm.h"
#include "mproc.h"

int is_full_limit()
{
        /* SYSCALL */
        int nbr_proc_limit = 100;
	mp = &mproc[who_p];
	nbr_proc[mp->mp_realuid]++;
        if( nbr_proc[mp->mp_realuid] <= nbr_proc_limit)        	return 0;
        else                                       		return 1;

}

void rm_nbr_proc() {

	mp = &mproc[who_p];
        nbr_proc[mp->mp_realuid]--;

}

