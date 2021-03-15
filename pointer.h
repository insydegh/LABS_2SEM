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
int inc1(int a) {
    return a*1;
}
int inc2(int a) {
    return a*2;
}
int inc3(int a) {
    return a*3;
}
int inc4(int a) {
    return a*4;
}
int inc5(int a) {
    return a*5;
}
int inc6(int a) {
    return a*6;
}
int inc7(int a) {
    return a*7;
}
int inc8(int a) {
    return a*8;
}
int inc9(int a) {
    return a*9;
}


//Function to make a list of functions pointers

void* makeList(void) {
    int (**funcs)(int)= malloc(9*sizeof(int(*)(int)));
    funcs[0] = &inc1;
    funcs[1] = &inc2;
    funcs[2] = &inc3;
    funcs[3] = &inc4;
    funcs[4] = &inc5;
    funcs[5] = &inc6;
    funcs[6] = &inc7;
    funcs[7] = &inc8;
    funcs[8] = &inc9;

    return funcs;
}

// CREATING AN ARRAY FROM FUNCTIONS LIST

dynArr* pointerArrayCreate() {
    dynArr *array = malloc(sizeof(dynArr));
    array->size = 9;
    array->elementSize = sizeof(int(**)(int));
    array->element =(int(**)(int))malloc(array->size*array->elementSize);

    int (**funcs)(int) = makeList();


    for (int i =0; i<9; i++) {
        *(int(**)(int))(array->element+i*array->elementSize) = **(funcs+i);
    }
    return array;
}

//PRINTING A POINTERS ARRAY

void printPointerArray(dynArr *array) {
    printf("---------------------------------\n");
    printf("Your pointers array size %d", array->size);
    printf("\n");
    for (int i = 0; i < array->size; i++) {
        printf("Element %d:%p\n", i+1, *(int(**)(int))(array->element+i*array->elementSize));
    }
    printf("---------------------------------\n");
}

void printIntArray(dynArr * array) {
    printf("---------------------------------\n");
    printf("Your int array size %d", array->size);
    printf("\n");
    for (int i = 0; i < array->size; i++) {
        printf("Element %d:%d\n", i+1, *(int*)(array->element+i*array->elementSize));
    }
    printf("---------------------------------\n");

}

//func for map

void* showResult(void* elem) {
    int (**f)(int) = (int(**)(int))elem;
    int k = (*f)(6);
    int *c = &k;
    return c;
}

//func for where
int checkResult(void* elem) {
    int (**f)(int) = (int(**)(int))elem;
    return (*f)(6)>=20 ? 1 : 0;
}



#endif //UNTITLED1_POINTER_H
