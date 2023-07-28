#include "main.h"
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
int y;
int width = 0;
for (y = *i + 1; format[y] != '\0'; curr_i++)
{
if (is_digit(format[y]))
{
width *= 10;
width += format[y] - '0';
}
else if (format[y] == '*')
{
y++;
width = va_arg(list, int);
break;
}
else
break;
}
*i = y - 1;
return (width);
}
