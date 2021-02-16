/* Here I will define my five functions */

int space_char (char c)
{
  if(c == ' ' || '/t')
    return 1;
  else
    return 0;
}

int non_space_char (char c)
{
  if (!space_char)
    {
      return 1;
    }
  else
    return 0;
}

char *word_start (char *str)
{
  while(space_char(*str))
    {
    str++;
    }
  else
    return str;
}

char *word_terminator (char *word)
{
  while(non_space_char(*word))
    {
      word++;
    }
  else
     return word;
}

int count_words (char *str)
{
  return 0;
}

char *copy_str (char *inStr, short len)
{
  return 'c';
}
