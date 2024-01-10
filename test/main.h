#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#define ZERO 0
#define NULL ((void *)0)
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int print_integer(int n);
int _printf(const char *format, ...);
int _fputchar(int c);
int print_character(char ch);
int print_string(char *str);
int print_s2(char *cust_str);
int format_spec(const char **format, va_list king);
int print_binary(unsigned int z);
int unsigned_spec(va_list king);
int print_unsign(unsigned int n);
int print_oct(unsigned int v);
int oct_spec(va_list king);
int print_hexadecimal(unsigned int decim, int up_case);
int hex_spec(va_list king, char spec);
int ch_spec(va_list king);
int str_spec(va_list king);
int cust_strpec(va_list king);
int int_spec(va_list king);
int bin_spec(va_list king);
int print_address(unsigned long addr_king);
int p_spec(va_list king);

#endif /* MAIN_H */
