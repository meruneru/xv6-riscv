#include "kernel/stat.h"
#include "user/user.h"
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(2, "arg error: trace <traceBit> <./bin args>\n");
        exit(0);
    }

    if(trace(atoi(argv[1]))){
        fprintf(2, "%s: trace failed.\n", argv[0]);
        exit(1);
    }
    char* argvNew[10];
    for(int i=2; i<argc; ++i){
        argvNew[i-2] = argv[i];
    }
    exec(argvNew[0], argvNew);
    exit(0);
}

