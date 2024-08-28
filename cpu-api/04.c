#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
  int rc =fork();
  if(rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // printf("execl:\n");
    // execl("/bin/ls", "ls", "-l", (char *)NULL);
    // printf("execle:\n");
    // execl("/bin/ls", "ls", "-l", (char *)NULL, NULL);
    // printf("execlp:\n");
    // execlp("ls", "ls", "-l", (char *)NULL);
    char *myargs[3];
    myargs[0] = strdup("ls");
    myargs[1] = strdup("-l");
    myargs[2] = NULL;
    // printf("execv:\n");
    // execv("/bin/ls", myargs);
    printf("execvp:\n");
    execvp("ls", myargs);
  } else {
    printf("execl:\n");
    execl("/bin/ls", "ls", (char *)NULL);
  }
  return 0; 
}

 