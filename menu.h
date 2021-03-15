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
    printf("3 - Check all\n");
    int c = choose();
    if (c==1) {
        dynArr* array1 = declareStrArray();
        printf("\n");
        printf("Choose function:\n");
        printf("1 - Map\n");
        printf("2 - Where\n");
        printf("3 - Concatenation\n");
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
            printf("Where description: Checks if string length more than 3\n");
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
        printf("Pointers from multiplication table functions:\n");

        dynArr* array1 = pointerArrayCreate();
        printf("The array itself:\n");
        printPointerArray(array1);
        printf("\n");
        printf("Choose function:\n");
        printf("1 - Map\n");
        printf("2 - Where\n");
        printf("3 - Concatenation\n");
        printf("\n");
        int a = choose();
        if (a==1) {
            printf("Map description: Multiplication table x6\n");
            dynArr* array2 = mapArray(*showResult, array1);
            printf("Done\n");
            printf("\n");
            printf("Do you want to print your array? 1 - Yes, 0 - No\n");
            if (choose()==1) {
                printIntArray(array2);
                printf("It is all done, if you want, try once again\n");
            }
            else {
                printf("OK, end\n");
            }
        }
        else if (a==2) {
            printf("Where description: Checks what funcs result is more than 20\n");
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
            printf("Make another array for concatenation (same funcs)\n");
            dynArr* array2 = pointerArrayCreate();
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
    else if(c==3){
        printf("\n");
        printf("Funcs pointers - type 6*X (X in range from 1 to 9)\n");
        printf("\n");
        dynArr *arr1 = pointerArrayCreate();

        printPointerArray(arr1);
        getchar();
        printf("Press any key to continue...");
        getchar();

        printf("\n");
        printf("Map - Show results of multiplication table:\n");
        printf("\n");
        dynArr *arr2 = mapArray(*showResult, arr1);
        printIntArray(arr2);

        printf("Press any key to continue...");
        getchar();


        printf("\n");
        printf("Where - Check what funcs result is more than 20:\n");
        printf("\n");
        arr2 = whereArray(*checkResult, arr1);
        printPointerArray(arr2);

        printf("Press any key to continue...");
        getchar();


        printf("\n");
        printf("Concat the array with itself:\n");
        printf("\n");
        arr2 = concatArray(arr1, arr1);
        printPointerArray(arr2);


        printf("Press any key to continue...");
        getchar();



        printf("\n");
        printf("Testing strings...");
        printf("\n");
        arr1 = declareStrArray();

        printf("Press any key to continue...");
        getchar();


        printf("\n");
        printf("Map - reversing the string:\n");
        printf("\n");
        dynArr *arr3= mapArray(*reverseStr, arr1);
        printStrArray(arr3);

        printf("Press any key to continue...");
        getchar();


        printf("\n");
        printf("Where - checking if array length is more than 3:\n");
        printf("\n");
        arr3 = whereArray(*stringLenght, arr1);
        printStrArray(arr3);


        printf("Press any key to continue...");
        getchar();


        printf("\n");
        printf("Concat - adding array to itself:\n");
        printf("\n");
        arr2 = declareStrArray();
        printf("\n");
        printf("Concatenation result:\n");
        arr3 = concatArray(arr1, arr2);
        printStrArray(arr3);
        printf("\n");

        printf("Press any key to continue...");
        getchar();


        printf("ENDED SUCCESSFULLY\n");

    }
    else {
        printf("You wrote wrong number, be careful next time\n");
        printf("It is all done, if you want, try once again\n");
    }

}


#endif //UNTITLED1_MENU_H
