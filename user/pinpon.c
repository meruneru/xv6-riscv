#include "kernel/stat.h"
#include "kernel/types.h"
#include "user/user.h"

const int MAX_COUNT = 10;
int main(int argc, char *argv[]) {
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);
    int pid = fork();
    int ppid = getpid();
    if (pid == 0) {
        // child
        close(p1[1]);
        close(p2[0]);
        char ping[1];
        for (int i = 0; i < MAX_COUNT; i++) {
            read(p1[0], ping, sizeof(ping));
            printf("%d: %s\n", ppid, ping);
            write(p2[1], ping, sizeof(ping));
        }
        close(p1[0]);
        close(p2[1]);
        exit(0);
    } else {
        // parent
        close(p1[0]);
        close(p2[1]);
        char ping[1] = "A";
        for (int i = 0; i < MAX_COUNT; i++) {
            printf("%d: %s\n", ppid, ping);
            write(p1[1], ping, sizeof(ping));
            read(p2[0], ping, sizeof(ping));
        }
        wait(0);
        close(p1[1]);
        close(p2[0]);
        exit(0);
    }
}
