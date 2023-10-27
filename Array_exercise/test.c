#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include "Array.h"


//subfunction
    void print_array(C_Array* to_print){
        printf("l'Array contiene i seguenti elementi:\n");
        int i;
        for (i = 0; i < to_print->length - 1; i++)
        {
            printf(" %d -",to_print->Array[i]);
        }
        printf(" %d ",to_print->Array[i++]);
    }
    
int main(){
    srand(time(NULL));
    C_Array test_array;
    initialize_Array(&test_array, 8);
    print_array(&test_array);

    return 1;
}

void test_greatertthan(){
    C_Array testArray;
    testArray.length = 5;
    int testValues[] = {1, 2, 3, 4, 5};
    testArray.Array = testValues;

    // Esegui i test
    assert(greaterThan(3, &testArray) == 2); // Dovrebbe restituire 2 (4 e 5 sono maggiori di 3)
    assert(greaterThan(0, &testArray) == 5); // Dovrebbe restituire 5 (tutti gli elementi sono maggiori di 0)
    assert(greaterThan(6, &testArray) == 0); // Dovrebbe restituire 0 (nessun elemento è maggiore di 6)

    printf("greaterThan function testing complete with success");
}

void test_member() {
    // Definire un array di test
    C_Array testArray;
    testArray.length = 5;
    int testValues[] = {1, 2, 3, 4, 5};
    testArray.Array = testValues;

    // Esegui i test
    assert(member(3, &testArray) == true);  // Dovrebbe restituire true (3 è presente nell'array)
    assert(member(0, &testArray) == false); // Dovrebbe restituire false (0 non è presente nell'array)
    assert(member(6, &testArray) == false); // Dovrebbe restituire false (6 non è presente nell'array)
    
    printf("member function testing complete with success");
}