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
  while(space_char(*str))
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
  
 return 'c';
}

