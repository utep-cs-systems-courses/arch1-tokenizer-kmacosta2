/* Incorporates my history.h files */
#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/*initialize the linklist to keep the history.*/
List *init_history() {
  List *myList = (List*)malloc(sizeof(List));
  return myList;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store 
*/
void add_history(List *list, char *str) {
  Item *new_item = (Item*)malloc(sizeof(Item));
  new_item->str = str;
  new_item->id += 1;
  list->root = new_item;
}

/* Retrieve the string stored in the node where item->id == id.
    List* list - the linked list
    int id - the id of the item to find */
char *get_history(List *list, int id) {
  Item *temp = list->root;
  
  while(temp && (temp->id != id))
    {
      temp = temp->next;
    }
  char *found = temp->str;
  return found;
}


/* Print the entire contents of the list. */
void print_history(List *list) {
  Item *tmpHist = list->root;
  while(tmpHist)
    {
      printf("%s", tmpHist->str);
    }
}

/* Free the history list and the strings it references. */
void free_history(List *list) {
  Item *temp = list->root;
  while(temp != NULL) //particularly for linkedList
    {
      Item *temp2 = temp->next; //since
      free(temp);
      temp = temp2;
    }
  free(list); //dont need to free temps' since memory wasn't malloc'ed for it!
}

