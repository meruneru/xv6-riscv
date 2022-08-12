#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  printf("%d\n", ugetpid());
  exit(0);
}
