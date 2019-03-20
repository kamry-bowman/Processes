// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  int rc = fork();
  if (rc < 0)
  {
    printf("Fork failed");
    exit(1);
  }
  else if (rc == 0)
  {
    char *myargs[3];
    myargs[0] = "/bin/ls";
    myargs[1] = "-l";
    myargs[2] = NULL;
    // execvp(myargs[0], myargs);
    execlp("ls", myargs[0], myargs[1], NULL);
  }
  else
  {
    waitpid(rc, NULL, 0);
    printf("Exiting...");
  }
  return 0;
}
