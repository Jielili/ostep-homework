#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int rc = fork();
  if(rc < 0) {
    fprintf(stderr, "fork failed\n");
  } else if (rc == 0){
    printf("I'm child process pid: %d\n", getpid());
  } else {
    int wc = waitpid(rc, NULL, 0);
    printf("I'm parent process of %d, wait for %d, pid: %d\n", rc, wc, getpid());
  }
}