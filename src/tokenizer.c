#include <stdlib.h>
#include <stdio.h>
/* Here I will define my five functions */

int space_char (char c) /* return true if c is a whitepsace character, false otherwise*/
{
  if((c == ' ' || c == '\t') && c != '\0')
    return 1;
  else
    return 0;
}

int non_space_char (char c)/*return true if c is a non-whitespace character*/
{
  if (c != ' ' && c != '\t' && c != '\0')
    return 1;
  else
    return 0;
}

char *word_start (char *str) /*Returns a pointer to the first character of the next space-separated word in zero-terminated str. Return a zero pointer if str does not contain any words.*/
{
  while(space_char(*str)) /*checks and makes a method call for every character Not word.*/
  {
    *str++;
  }
  return str;
}

/*Returns a pointer terminator char following *word  */
char *word_terminator (char *word)
{
  while(non_space_char(*word))
  {
    *word++;
  }
  return word;
}

/* Counts the number of words in the string argument */
int count_words (char *str)
{
  char *clone = str;
  int counter = 0;
   while(*clone)
   {
    counter++;
    clone = word_start(clone);
    clone = word_terminator(clone);
    clone = word_start(clone);
   }
  return counter;
}

/* Returns a freshly allocated new zero-terminated string containing <len> chars from <inStr> */
char *copy_str (char *inStr, short len)
{
  char *newPtr = (char*)malloc(len*sizeof(char)+1); /*sizeof is for getting the # of bytes needed*/

   for(int i = 0; i < len; i++)
     {
    newPtr[i] = inStr[i];
     }
    newPtr[len] = '\0';
    return newPtr;
}
/*
returns a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-terminated str.
 */
char **tokenize (char *str)
{
  int words = count_words(str);
  char **vector = (char**)malloc((words+1)*sizeof(char*)); /*allocating for the size of character pointers*/
  char *endOfWord;
  char *beginWord= word_start(str);
  for (int i= 0; i < words; i++)
      {
	endOfWord = word_terminator(beginWord);
	vector[i] = copy_str(beginWord, endOfWord-beginWord); 
	beginWord = word_start(endOfWord); 
      }
  vector[words] = 0; 
  return vector;
}

void print_tokens(char **tokens)
{//referencing one word at a time.
  for (int i = 0; *(tokens+i) != 0; i++)
      {
	printf("%s\n", *(tokens+i));
      }
}

void free_tokens(char **tokens)
{
  for (int i = 0; *(tokens+i) != 0; i++)
    {
      free(*(tokens+i));
    }
  free(tokens);/* freeing the malloc space that was originally set aside.*/
}

