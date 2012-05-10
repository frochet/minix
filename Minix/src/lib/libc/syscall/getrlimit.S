#include <machine/asm.h>

IMPORT(_getrlimit)
ENTRY(getrlimit)
	jmp	_C_LABEL(_getrlimit)

