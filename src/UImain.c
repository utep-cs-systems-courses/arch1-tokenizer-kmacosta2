#include <stdio.h>

/* "echo"ing command-line */
main (int argc, char *argv[])
{
  printf("> ");
  while (--argc > 0)
    printf("%s,%s", *++argv, (argv > 1) ? " " : "");
  printf("\n");
  return 0;
}
