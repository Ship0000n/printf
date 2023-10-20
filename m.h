#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUFF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2
/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: 0n if _flag specified
 * @minus_flag: 0n if _flag specified
 *
 * @width: field width specified
 * @precision: field width specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
*/


struct fmt
{
 char fmt;
 int (*fn)(va_list, char[], int, int, int, int);
};


typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


int print_char(va_list types, char buffer[],
 int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
 int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
 int flags, int width, int precision, int size);

int print_int(va_list types, char buffer[],
 int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
 int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
 int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
 int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
 int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
 int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


int print_non_printable(va_list types, char buffer[],
 int flags, int width, int precision, int size);

int print_pointer(va_list types, char buffer[],
 int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_reverse(va_list types, char buffer[],
 int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[],
 int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
 int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
 int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
 int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
 int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
