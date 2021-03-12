//
// Created by fokus on 12.03.2021.
//

#ifndef menu_h
#define menu_h


#include "array.h"
#include "strings.h"
#include "pointer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// MENU FUNCTIONS


int choose() {
    int choice;
    printf("Type your number here:");
    scanf("%d", &choice);
    return choice;
}

void menu() {
    printf("Choose data type\n");
    printf("1 - Strings\n");
    printf("2 - Functions Pointers\n");
    int c = choose();
    if (c==1) {
        dynArr* array1 = declareStrArray();
        printf("\n");
        printf("Choose funtion:\n");
        printf("1 - Map\n");
        printf("2 - Where\n");
        printf("3 - Concetenation\n");
        printf("\n");
        int b = choose();
        if (b==1) {
            printf("Map description: Reverse string\n");
            dynArr* array2 = mapArray(*reverseStr, array1);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1) {
                printStrArray(array2);
                printf("It is all done, if you want, try once again\n");
            }
            else {
                printf("OK, end\n");
            }
        }
        else if (b==2) {
            printf("Where description: Checks if string lenght more than 3\n");
            dynArr* array2 = whereArray(*stringLenght, array1);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1) {
                printStrArray(array2);
                printf("It is all done, if you want, try once again\n");
            }
            else {
                printf("OK, end\n");
            }
        }
        else if (b==3) {
            printf("Make another array for concatenation\n");
            dynArr* array2 = declareStrArray();
            printf("Starting concatenation...\n");
            dynArr* array3 = concatArray(array1, array2);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1) {
                printStrArray(array3);
                printf("It is all done, if you want, try once again\n");
            }
            else {
                printf("OK, end\n");
            }
        }
    }
    else if (c==2) {
        printf("Pointers from 3 int fuctions: Add, Sub, Multiply\n");

        dynArr* array1 = pointerArrayCreate3();
        printf("The array itself:\n");
        printPointerArray(array1);
        printf("\n");
        printf("Choose function:\n");
        printf("1 - Map\n");
        printf("2 - Where\n");
        printf("3 - Concetenation\n");
        printf("\n");
        int a = choose();
        if (a==1) {
            printf("Map description: Incrementing the pointer\n");
            dynArr* array2 = mapArray(*doNothing, array1);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1) {
                printPointerArray(array2);
                printf("It is all done, if you want, try once again\n");
            }
            else {
                printf("OK, end\n");
            }
        }
        else if (a==2) {
            printf("Where description: Checks if the result with 2 arguments - 1 and 3 more than 3\n");
            dynArr* array2 = whereArray(*checkResult, array1);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1) {
                printPointerArray(array2);
                printf("It is all done, if you want, try once again\n");
            }
            else {
                printf("OK, end\n");
            }
        }
        else if (a==3) {
            printf("Make another array for concatenation (same elements)\n");
            dynArr* array2 = pointerArrayCreate3();
            printf("Starting concatenation...\n");
            dynArr* array3 = concatArray(array1, array2);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1) {
                printPointerArray(array3);
                printf("It is all done, if you want, try once again\n");
            }
            else {
                printf("OK, end\n");
            }
        }
    }
    else {
        printf("You wrote wrong number, be caferul next time\n");
        printf("It is all done, if you want, try once again\n");
    }

}


#endif //UNTITLED1_MENU_H
