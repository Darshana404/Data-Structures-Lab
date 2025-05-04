// Code for Lab1 - Q1
//menu driven program to sort a given array
#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int arr[], int num);
void sel_sort(int arr[], int num);
void ins_sort(int arr[], int num);
int main()
{
    int num,ch;
    printf("Enter the no. of elements: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter the elements: ");
    for(int i=0; i<num; i++)
    {
        scanf("%d", &arr[i]);
    }
    while(1)
    {
        printf("1-Bubble sort\n2-Selection sort\n3-Insertion sort\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                bubble_sort(arr, num);
                for(int i=0; i<num; i++)
                {
                    printf("%d\n",arr[i]);
                }
                break;
            case 2:
                sel_sort(arr,num);
                for(int i=0; i<num; i++)
                {
                    printf("%d\n",arr[i]);
                }
                break;
            case 3:
                ins_sort(arr,num);
                for(int i=0; i<num; i++)
                {
                    printf("%d\n",arr[i]);
                }
                break;
            case 4:
                exit(0);
        }
    }
}
//bubble sort
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
//selection sort
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
//insertion sort
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