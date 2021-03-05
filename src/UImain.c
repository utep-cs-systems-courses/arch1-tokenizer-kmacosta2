#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/* "echo"ing command-line */
int main ()
{
  List *listed = init_history();
  
  char currCommand[100];
  while(1) //while true
  {
      printf("History test (q to Quit)>> ");
      fgets(currCommand, 100, stdin);
      if (currCommand[0] != '!')
	{
	  add_history(listed, currCommand);
	}
      else if (currCommand[1] == 'h')
	{//at index 1 expected to have the ID
	  print_history(listed);
	}
      else if (currCommand[0] == 'q')
	{
	  free_history(listed);
	  break;
	}
      else/*now it has to be !# <--some number*/
	printf("%s", get_history(listed, currCommand[1]));
  } 
  //printf("%s",buffer);
  //char *strin = "My dog has fleas.";
  //char **vec = tokenize(strin);
  //print_tokens(vec);
  //free_tokens(vec);
  return 0;
}
