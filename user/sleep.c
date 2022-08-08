#include "kernel/stat.h"

#include "user/user.h"
int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(2, "arg error: ./sleep <sec number>\n");
        exit(0);
    }

    sleep(atoi(argv[1]));
    exit(0);
}
