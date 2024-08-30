#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fd = open("./p2.txt", O_RDWR|O_CREAT);
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    write(fd, "I'm child!\n", 12);
  } else {
    write(fd, "I'm parent!\n", 13);
  }
}