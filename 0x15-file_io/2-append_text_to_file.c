#include "main.h"
#include "stdlib.h"

/*
 *append_text_to_file - appending the text to the existing file. 
 *@file_D - a method used to read only file and append.
 *text_content - checking each letter by using a loop.
 * Return - The logic returns 1 if the code appends and 0 if the code has an error.
 * */

int append_text_to_file(const char *filename, char *text_content)
{
  int file_D, a, b = 0;

  if (!filename)
	  return (-1);
  file_D = open(filename, O_WRONLY | O_APPEND);
  if (file_D < 0)
	  return (-1);
  if (text_content)
  {
    while (text_content[b])
	    b++;
    a = write(file_D, text_content, b);
    if (a != b)
	    return (-1);
  }
   close(file_D);

   return (1);
}
