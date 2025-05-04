// Code for Lab1 - Q2
#include<stdio.h>
#include<stdlib.h>
#include "sort.h"
int linear_search(int arr[], int num, int key);
int bin_search(int arr[], int num, int key);
int main()
{
    int num,ch,key,ind=-1;
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
        printf("1-Linear Search\n2-Binary search\n3-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element to be searched: ");
                scanf("%d",&key);
                ind=linear_search(arr,num,key);
                if(ind==-1)
                {
                    printf("No element found\n");
                }
                else{
                    printf("The position of the element is %d\n",ind+1);
                }
                ind=-1;
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d",&key);
                bubble_sort(arr,num);
                for(int i=0; i<num; i++)
                {
                    printf("%d\n",arr[i]);
                }
                ind=bin_search(arr,num,key);
                if(ind==-1)
                {
                    printf("No element found\n");
                }
                else{
                    printf("The position of the element is %d\n",ind);
                }
                ind=-1;
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}
//linear search
int linear_search(int arr[], int num, int key)
{
    for(int i=0; i<num; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return 0;
}
//binary search
int bin_search(int arr[], int num, int key)
{
    int low=0;
    int high=num-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            low=mid-1;
        }
    }
    return 0;
}