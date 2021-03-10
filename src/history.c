/* Incorporates my history.h files */
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/*initialize the linklist to keep the history.*/
List *init_history() {
  List *myList = (List*)malloc(sizeof(List));
  myList->root = NULL;
  return myList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store 
*/
void add_history(List *list, char *str) {
  int len = 0;
  char *temp_ref = str;
  while (*temp_ref != '\0')
    {
      len += 1;
      temp_ref++;
    }
  Item *new_item = (Item*)malloc(sizeof(Item));
  new_item->str = copy_str(str, len); //making sure str has it own space in memory
  int id = 0;
  new_item->id = id;
  if (!list->root)
    { //if there is nothing there, then add head
      list->root = new_item;
    }
  else
    {  //while there is something next
      Item *curr_item = list->root;
      while(curr_item->next)
      {
	curr_item = curr_item->next;
	id += 1;
      }//finally reached the tail
      new_item->id = id;
      curr_item->next = new_item;
    }
}
/* Retrieve the string stored in the node where item->id == id.
    List* list - the linked list
    int id - the id of the item to find */
char *get_history(List *list, int id) {
  Item *temp = list->root;
  
  while(temp->next)
  {
    if (temp->id == id)
    {
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;
}

/* Print the entire contents of the list. */
void print_history(List *list)
{
  Item *tmpHist = list->root;
  while(tmpHist)
  {
     printf("%s", tmpHist->str);
     tmpHist = tmpHist->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *temp = list->root;
  while(temp != NULL) 
  {
      Item *temp2 = temp->next; //since
      free(temp);
      temp = temp2;
  }
  free(list); //dont need to free temps' since memory wasn't malloc'ed for it!
}

