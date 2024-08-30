#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  printf("hello world (pid:%d)\n", (int) getpid());
  int var = 100;
  int rc = fork();
  if(rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    var = 200;
    printf("hello, I am child (pid:%d) and var is %d\n", (int) getpid(), var);
  } else {
    var = 300;
    printf("hello, I am parent of %d (pid:%d) and var is %d\n", rc, (int) getpid(), var);
  }
  printf("var is %d\n", var);
  return 0;
}