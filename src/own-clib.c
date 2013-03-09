
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

typedef struct Int_{
    int key;
}Int;

int Intcompare(void *key1, void *key2){
    if( ((Int*)key1)->key == ((Int*)key2)->key )
        return 0;
    else if ( (*(Int*)key1).key > (*(Int*)key2).key )
        return 1;
    else return -1;
}

int main(void) {
    int array[10], i;
    Int array2[10];

    for(i=0; i < 10; i++){
        array[i] = 10-i;
        array2[i].key = 10-i;
    }

//    issort((void*)array, 10, sizeof(int), intcompare);
    issort((void*)array2, 10, sizeof(Int), Intcompare);

    for(i=0; i < 10; i++){
//        printf("%d", array[i]);
        printf("%d", array2[i].key);
    }

	return EXIT_SUCCESS;
}
