#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
int main ()
{
  List *listed = init_history();
  char curr_command[100];
  while(1) //while true
  {
      printf("History test (q to Quit)>> ");
      fgets(curr_command, 100, stdin);
      char t = curr_command[0];
      if (t == 'q')
      {
	free_history(listed);
        break;
      }
      else if (curr_command[0] != '!')
      {
        add_history(listed, curr_command);
      }
       else if(curr_command[0] == '!' && curr_command[1] != 'h')
       {
	 int a = (int)(curr_command[1]);
         char *s = get_history(listed, a);
         char **vec = tokenize(s);
	 print_tokens(vec);
	 free_tokens(vec);
       }
       else if (curr_command[0] == '!' && curr_command[1] == 'h')
       {
	 print_history(listed);
       }
  } 
  //printf("%s",buffer);
  //char *strin = "My dog has fleas.";
  //char **vec = tokenize(strin);
  //print_tokens(vec);
  //free_tokens(vec);
  return 0;
}
