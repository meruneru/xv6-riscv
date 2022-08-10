#ifndef H_KERNEL_SYSINFO
#define H_KERNEL_SYSINFO

#include "types.h"
#include "riscv.h"
struct sysinfo {
    uint64 freemem;   /* Available memory size */
    uint16 nproc;    /* Number of current processes */
};


#endif
