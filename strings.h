//
// Created by fokus on 09.03.2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "array.h"

#ifndef strings_h
#define strings_h

#endif //UNTITLED1_STRINGS_H

//funcs for creating a string array with user's input
void copyElement(dynArr * arr, int count, char* input);
void setString(dynArr *arr, int i);
dynArr* arrayCreate(int size, int elemSize);
dynArr* declareStrArray();


//funcs to print str array
void printStrArray(dynArr * array);

//func to use with map
void* reverseStr(void* elem);

//func to use with where
int stringLength(void* elem);

