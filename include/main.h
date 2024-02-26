#ifndef MAIN_H

#include <stdio.h>

typedef char *String;

char * strchr(const char *s, int c);
String _strcpy(char * dest, const char * source);
char * _strncpy(char * dest, const char * source, size_t len);
size_t _strlen(String ptr);

#define MAIN_H
#endif //MAIN_H
