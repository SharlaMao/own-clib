/*
 ============================================================================
 Name        : my_clib.c
 Author      : shibo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "issort.h"

int intcompare(void *key1, void* key2){
    if( *(int*)key1 == *(int*)key2 )
        return 0;
    else if( *(int*)key1 > *(int*)key2 )
        return 1;
    else return -1;
}

int main(void) {
    int array[10], i;

    for(i=0; i < 10; i++)
        array[i] = i;
    int a = 1, b = 2;

    i = intcompare( (void*)&a, (void*)&b);

    issort((void*)array, 10, sizeof(int), intcompare);
	return EXIT_SUCCESS;
}
