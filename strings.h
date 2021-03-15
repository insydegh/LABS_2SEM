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


const int len=100; //max lenght of string


//STRING ARRAY CREATION FUNCTIONS

//copying string to the right address

void copyElement(dynArr * arr, int count, char* input) {
    void *pointer = (char *) arr->element + count * arr->elementSize;
    memcpy(pointer, input, arr->elementSize);
    free(input);
}

//input string

void setString(dynArr *arr, int i) {
    char* input = (char *) malloc(len * sizeof(char));
    printf("String %d:", i+1);
    gets(input);
    return copyElement(arr, i, input);
}

//allocating memory for an array

dynArr* arrayCreate(int size, int elemSize) {
    dynArr *arr = (dynArr *) malloc(sizeof(dynArr));
    arr->size = size;
    arr->elementSize = elemSize;
    arr->element = (char*)malloc(size * elemSize);
    for (int i = 0; i < size; i++) {
        setString(arr, i);
    }
    return arr;
}


//setting array and element size

dynArr* declareStrArray() {
    int size;
    printf("Set string array size:");
    scanf("%d", &size);
    getchar();
    int sizeElement = len*sizeof(char);
    return arrayCreate(size, sizeElement);
}

//PRINT STR ARRAY FUNC

void printStrArray(dynArr * array) {
    printf("---------------------------------\n");
    printf("Your string array size %d", array->size);
    printf("\n");
    for (int i = 0; i < array->size; i++) {
        printf("String %d:", i+1);
        puts((char*)(array->element + i*array->elementSize));
    }
    printf("---------------------------------\n");
}


//FUNCTIONS TO USE MAP WITH STRINGS

//func for map: reversing the string
void* reverseStr(void* elem) {
    char *string = (char*)elem;
    char *end = string + strlen(string)-1;
    char *begin = string;
    char temp;
    while(begin<end) {
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
    return string;
}

//func for where: checking if the length is more than 3

int stringLenght(void* elem) {
    char *string = (char*)elem;
    int lenght = strlen(string);
    return (lenght>3) ? 1 : 0;
}

