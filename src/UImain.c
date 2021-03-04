#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

/* "echo"ing command-line */
int main ()
{
  List *listed = init_history();
  
  char currCommand[100];
  while(currCommand[0] != 'q')
    {
      printf("History test (q to Quit)>> ");
      fgets(currCommand, 100, stdin);
      if (currCommand[0] != '!')
	{
	  add_History(listed, currCommand);
	}
      else if (currCommand[1] == 'h')
	{//at index 1 expected to have the ID
	  print_history(listed);
	}
      else/*now it has to be !# <--some number*/
	printf("%s", get_history(listed, currCommand[1]));
    }
  free_history(listed);
  //printf("%s",buffer);
  //char *strin = "My dog has fleas.";
  //char **vec = tokenize(strin);
  //print_tokens(vec);
  //free_tokens(vec);
  
  return 0;
}
