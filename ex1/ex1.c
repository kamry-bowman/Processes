// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int x = 100;

  int rc = fork();

  if (rc == 0)
  {
    printf("child value of x before: %d\n", x);
    x = 5;
    printf("child value of x after: %d\n", x);
  }
  else
  {
    printf("parent value of x before: %d\n", x);
    x = 8;
    printf("parent value of x after: %d\n", x);
  }
  return 0;
}
