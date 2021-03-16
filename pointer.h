//
// Created by fokus on 12.03.2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "array.h"
#ifndef pointer_h
#define pointer_h


//func for testing
int inc1(int a);
int inc2(int a);
int inc3(int a);
int inc4(int a);
int inc5(int a);
int inc6(int a);
int inc7(int a);
int inc8(int a);
int inc9(int a);

void* makeFuncsList(void); // to make a funcs list

dynArr* pointerArrayCreate(); // to create a pointers array

void printPointerArray(dynArr *array); //to print pointer array

void printIntArray(dynArr * array); //to print int array

void* showResult(void* elem); //func for map

int checkResult(void* elem); //func for where






#endif //UNTITLED1_POINTER_H
