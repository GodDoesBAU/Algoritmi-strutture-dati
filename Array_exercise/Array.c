#include "Array.h"

void initialize_Array(C_Array* to_initialize, int lenght){
    to_initialize->length = lenght;
    to_initialize->Array = malloc(sizeof(int) * lenght);

    for (int i = 0; i < lenght; i++)
    {
        to_initialize->Array[i] =  rand() % MAX_VALUE + MIN_VALUE;
    }   
}


int greaterThan(int value, C_Array* to_scan){
    int greater_elements = 0;
    for (int i = 0; i < to_scan->length; i++)
    {
        if (to_scan->Array[i] > value)
            greater_elements++;
        
    }
    
    return greater_elements;
}

bool member(int value, C_Array* to_scan){
    for (int i = 0; i < to_scan->length; i++)
    {
        if (to_scan->Array[i] == value)
            return true;
        
    }
    return false;
}

int * largest(C_Array* to_scan){
    int max = MIN_VALUE - 1;
    int * pointer_to_max = NULL;

    for (int i = 0; i < to_scan->length; i++)
    {
        if (to_scan->Array[i] > max)
            pointer_to_max = to_scan->Array + i;
    }

    return pointer_to_max;
}
//
    //subfunction
    void shift_array(int * arr, int length, int startIndex){
        for (int i = startIndex; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
    
        arr[length - 1] = 0;  
    }

void remove(C_Array* to_scan, int to_remove){
    for (int i = 0; i < to_scan->length; i++)
    {
        if (to_scan->Array[i] == to_remove){
            shift_array(to_scan->Array, to_scan->length, i);
            break;
        }
    }
}
//


int ordering(C_Array* to_scan){
    bool flags[3] = {true , true, true};

    for (int i = 0; i < to_scan->length-1 && (flags[0] || flags[1] || flags[2]); i++)
    {
        //not minor case
        if (to_scan->Array[i] > to_scan->Array[i+1] && flags[0])
        {
            //increasing flag
            flags[0] = false;
        }
        
        //not greater case
         if (to_scan->Array[i] < to_scan->Array[i+1] && flags[1])
        {
            //decreasing flag
            flags[1] = false;
        }

        //not equal case
        if (to_scan->Array[i] != to_scan->Array[i+1] && flags[2])
        {
            //constant flag
            flags[2] = false;
        }
    }

    if(!flags[0] && !flags[1] && !flags[2]){
        return 0;
    }else if(flags[0]){
        return 1;
    }else if(flags[1]){
        return 2;
    }else
        return 3;
}


//
    //subfunction
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

void reverse(C_Array* to_invert){
    for (int i = 0, i2 = to_invert->length-1; i < to_invert->length / 2; i++, i2--)
    {
        swap(to_invert->Array+i, to_invert->Array+i2);
    }
    
}
//  



