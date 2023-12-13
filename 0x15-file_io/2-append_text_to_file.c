#include "main.h"
#include "stdlib.h"

/**
 * append_text_to_file - Appends text to an existing file.
 * @filename: The name of the file to which text will be appended.
 * @text_content: The text to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
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

