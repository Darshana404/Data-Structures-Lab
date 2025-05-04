#include<stdio.h>
#include<stdlib.h>
//Bubble sort
void bubble_sort(int arr[], int num)
{
    int temp;
    for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<num-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//Selection sort
void sel_sort(int arr[], int num)
{
    for(int i=0;i<num-1;i++){
        int min=i;
        for(int j=i+1;j<num;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
//Insertion sort
void ins_sort(int arr[], int num)
{
    for(int i=0; i<num; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}