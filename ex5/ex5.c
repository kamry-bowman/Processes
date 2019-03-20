// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 15

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
  char buf[MSGSIZE];
  int pipefd[2];
  if (pipe(pipefd) == -1)
  {
    printf("Pipe attempt failed");
    exit(1);
  }
  int cpid = fork();
  if (cpid == 0)
  {
    close(pipefd[0]);
    write(pipefd[1], msg1, MSGSIZE);
    write(pipefd[1], msg2, MSGSIZE);
    write(pipefd[1], msg3, MSGSIZE);
  }
  else
  {
    for (int i = 0; i < 3; i++)
    {
      close(pipefd[1]);
      read(pipefd[0], buf, MSGSIZE);
      write(STDOUT_FILENO, buf, MSGSIZE);
    }
    write(STDOUT_FILENO, "\n", 1);
  }

  return 0;
}
