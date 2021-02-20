#include <stdio.h>
#include "tokenizer.h"


/* "echo"ing command-line */
int main ()
{
  //printf(">> ");
  //char buffer[100];
  char *strin = " My dog has fleas but not for long ";
  //char a[100] = ' ';
  //fgets(buffer, 100, stdin);
  //printf("%s", buffer);

  //strin = word_start(strin);
  // printf("%d\n", non_space_char(' '));

  //printf("%s\n", strin);
  //printf("%s\n", strin)

  //strin = word_terminator(strin);
  // printf("%s\n", strin);

  printf("%d\n", count_words(strin));
  return 0;
}
