#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/sysinfo.h"

int main(int argc, char *argv[]) {
    struct sysinfo info;
    int ret = sysinfo(&info);
    
    if(ret==0){
        printf("freemem: %d\n",info.freemem);
        printf("nproc: %d\n",info.nproc);
        exit(0);
    }else{
        printf("Error: sysinfo\n");
        exit(1);
    }
}
