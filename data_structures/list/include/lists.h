#ifndef _LISTS_H
#define _LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct student
{
    char * name;
    int age;
    struct student *next;
}student;
//extern student *head;
extern unsigned int count;

extern unsigned int count;
student * createNode(char * name, int age);
bool isEmpty(student * ptr);
unsigned int size(/*student *ptr*/);
int initializeNode(student *ptr, char * name, int age);
void addFirst(student **ptr, char * name, int age);
void addLast(student **ptr, char * name, int age);
void addAt(student **ptr, char * name, int age, int position);
void display_(student *ptr);
void deleteFirst(student **ptr);
void deleteLast(student **ptr);
void deleteAt(student **ptr, unsigned int position);
#endif //lists_h