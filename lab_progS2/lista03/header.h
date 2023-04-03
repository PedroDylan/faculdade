void troca(int *a, int *b){
    int dummy = *a;
    *a = *b;
    *b = dummy;
}

void ref_sort(int array[], int size){
    int i,j,dummy;

    for (j = 0; j < size-1; j++)
    {
        for (i = j+1; i < size ; i++)
        {
            if (array[i] < array[j])
            {
                troca(&array[i],&array[j]);
            }
        }
    }
}



void bubbleSort(int array[],int size){
    int dummy;
    
    for(int pass = 0; pass <size-1 ; pass++){
        for(int i = 0; i < size-1; i++){
            if(array[i] > array[i+1]){
                troca(&array[i], &array[i+1]);
            }
        }
    }
}

void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        printf("%i\n",array[i]);
    }    
}

int find_max(int array[], int size){
    int max = 0;

    for(int i = 0; i <size ; i++){
        if(array[i]>max){
            max=array[i];
        }
    }
    return max;
}

int find_min(int array[], int size){
    int min = sizeof(int);

    for(int i = 0; i<size; i++){
        if(array[i]<min){
            min = array[i];
        }
    }
    return min;
}

