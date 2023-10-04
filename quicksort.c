#include <stdio.h>
#include <stdlib.h>
void swap(int *a ,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int partition(int array[], int low, int high) {
    int pivot=array[high],j;
    int i=low;
    for(j=low;j<high;j++){
        if(array[j]<=pivot){
        swap(&array[i],&array[j]);
        i++;
        }
    }
    swap(&array[i],&array[high]);
    return i;
}
void QuickSort(int array[],int low,int high){
    if(low<high){
    int pi_element= partition(array,low,high);
    QuickSort(array,low,pi_element-1);
    QuickSort(array,pi_element+1,high);
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int n,data[20],i;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    printf("\nNow,enter the elements(integer):\n");
    for(i=0;i<n;i++){
    scanf("%d",&data[i]);
    }
    printf("Unsorted Array\n");
    printArray(data, n);
    QuickSort(data,0,n-1);
    printf("Sorted array in ascending order: \n");
    printArray(data,n);
    return 0;
}