#include <machine/asm.h>

IMPORT(_setrlimit)
ENTRY(setrlimit)
        jmp     _C_LABEL(_setrlimit)

