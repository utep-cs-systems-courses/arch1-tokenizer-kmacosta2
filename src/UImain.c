#include <stdio.h>

/* "echo"ing command-line */
int main ()
{
  printf(">> ");
  char buffer[100];
  
  fgets(buffer, 100, stdin);
  printf("%s", buffer);
    /* char buffer[100];   /* My reserved space for the strings*/
  return 0;
}
