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


//RANDOM FUNCTIONS TO MAKE ARRAY FROM POINTERS
int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int mult(int a, int b) {
    return a*b;
}

typedef int (**f)(int, int);

void* makeList(void) {
    int (**funcs)(int,int)= malloc(3*sizeof(int(*)(int,int)));
    funcs[0] = &add;

    funcs[1] = &sub;

    funcs[2]=&mult;

    return funcs;
}

// FUNCTIONS WITH POINTERS ARRAY

dynArr* pointerArrayCreate3() {
    dynArr *array = malloc(sizeof(dynArr));
    array->size = 3;
    array->elementSize = sizeof(int(**)(int, int));
    array->element =(int(**)(int,int))malloc(array->size*array->elementSize);

    int (**funcs)(int,int)= malloc(3*sizeof(int(**)(int,int)));
    funcs[0] = &add;
    funcs[1] = &sub;
    funcs[2]=  &mult;

    for (int i =0; i<3; i++) {
        *(int(**)(int,int))(array->element+i*array->elementSize) = **(funcs+i);
    }
    return array;
}

void printPointerArray(dynArr *array) {
    printf("---------------------------------\n");
    printf("Your pointers array size %d", array->size);
    printf("\n");
    for (int i = 0; i < array->size; i++) {
        printf("Element %d:%p\n", i+1, *(int(**)(int,int))(array->element+i*array->elementSize));
    }
    printf("---------------------------------\n");
}

void* doNothing(void* elem) {
    int (*f)(int,int) = (int(*)(int,int))elem;


    return f;
}

int checkResult(void* elem) {
    int (**f)(int,int) = (int(**)(int,int))elem;
    return (*f)(1,3)>=3 ? 1 : 0;
}





#endif //UNTITLED1_POINTER_H
