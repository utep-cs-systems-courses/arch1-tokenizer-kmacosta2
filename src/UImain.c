#include <stdio.h>
#include "tokenizer.h"

/* "echo"ing command-line */
int main ()
{
  printf("  >> ");
  //char buffer[100];
  //fgets(buffer, 100, stdin);
  //printf("%s",buffer);
  char *strin = "My dog dog has fleas.";
  
  char **vec = tokenize(strin);

  //print_tokens(vec);
  //free_tokens(vec);
  
  //printf("%s", strin);
  
  //strin = "The world is green ";
  
  //printf("%s", strin);
 
  // printf("%s", otherStr);
  
  return 0;
}
