#include "main.h"
#include "stdlib.h"

/**
 *read_textfile - reads a text file and prints it to the standard output
 *@filename - reads the existing file
 *@letters - implifies the number of ltters that needs to be read
 *Return - The number of letters read or 0 if there's an error
 * */

ssize_t read_textfile(const char *filename, size_t letters)
{
  int file_D;
  int i, y;
  char *buf;
  if(!filename)
	  return (0);
  file_D = open(filename, O_RDONLY);
  if (file_D < 0)
	  return (0);
  buf = malloc(sizeof(char) * letters);
  if (!buf)
	  return (0);
  i = read(file_D, buf, letters);
  if(i < 0)
  {
    free(buf);
    return (0);
  }
  buf[i] = '\0';
  close(file_D);
  y = write(STDOUT_FILENO, buf, i);
  if (y < 0)
  {
    free(buf);
    return (0);
  
  }
  free(buf);
  return (y);






}
