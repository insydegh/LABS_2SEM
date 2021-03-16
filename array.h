#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
// Created by fokus on 12.03.2021.
//

#ifndef array_h
#define array_h
#pragma once

typedef struct dynamicArray{
    int size; //size of array
    void *element;
    int elementSize;
} dynArr;


// GENERAL ARRAY FUNCTIONS: CONCAT, MAP, WHERE

//concatenation - making a single array from two

dynArr* concatArray(dynArr *arr1, dynArr *arr2 );

//map - making an array from results of using some function for original one's elements

dynArr* mapArray(void* (*function)(void*), dynArr *arr1);

//where - making an array with "true" filter

dynArr* whereArray(int (*condition)(void*), dynArr *arr1);

#endif //UNTITLED1_ARRAY_H
