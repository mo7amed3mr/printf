#include "main.h"

/**
 * Co_LoHex - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @arguments: A va_list pointing to the argument to be converted.
 * @buffer: A buf_t struct containing a character array.
 * @format_flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @size: A length modifier.
 *
 * Return: The number of byt stored to the buffer.
*/

unsigned int Co_LoHex(va_list arguments, buf_t *buffer,
unsigned char format_flags, int width, int precision, unsigned char size)
{
unsigned long int number;
unsigned int byt = 0;
char *pref = "0x";

if (size == LONG)
number = va_arg(arguments, unsigned long int);
else
number = va_arg(arguments, unsigned int);
if (size == SHORT)
number = (unsigned short)number;

if (HASH_FLAG == 1 && number != 0)
byt += _memcpy(buffer, pref, 2);

if (!(number == 0 && precision == 0))
byt += convert_ubase(buffer, number, "0123456789abcdef",
format_flags, width, precision);

byt += print_neg_width(buffer, byt, format_flags, width);

return (byt);
}

/**
 * Co_UpHex - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @arguments: A va_list pointing to the argument to be converted.
 * @buffer: A buf_t struct containing a character array.
 * @format_flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @size: A length modifier.
 *
 * Return: The number of byt stored to the buffer.
*/

unsigned int Co_UpHex(va_list arguments, buf_t *buffer,
unsigned char format_flags, int width, int precision, unsigned char size)
{
unsigned long int number;
unsigned int byt = 0;
char *pref = "0X";

if (size == LONG)
number = va_arg(arguments, unsigned long);
else
number = va_arg(arguments, unsigned int);
if (size == SHORT)
number = (unsigned short)number;

if (HASH_FLAG == 1 && number != 0)
byt += _memcpy(buffer, pref, 2);

if (!(number == 0 && precision == 0))
byt += convert_ubase(buffer, number, "0123456789ABCDEF",
format_flags, width, precision);

byt += print_neg_width(buffer, byt, format_flags, width);

return (byt);
}
