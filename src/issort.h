#include <stdlib.h>
#include <string.h>

int issort(void * data, int size, int esize, int (*match)(void *key1, void* key2)){
    int i,j;
    void *key;

    // Allocate storage for key element
    if ( (key = (char*)malloc(esize)) == NULL )
        return -1;

    for(i = 0; i < size; i++){
        memcpy(key, &data[ (i+1) * esize ], esize);
        j = i;
        while(i > 0 && match(key, &data[ (j+1) * esize]) )
            j--;
        memcpy(&data[ (j+1) * esize], key, esize);
    }

    free(key);
    return 0;
}
