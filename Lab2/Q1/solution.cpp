// Code for Lab2 - Q1
//menu driven progam to check if a number is palindrome, armstrong or perfect number
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int palindrome(int *num);
int countf(int *num, int *count);
int armstrong(int *num,int *count);
int perfect(int *num);
int main()
{
    int *num=(int *)malloc(sizeof(int));
    printf("Enter a number: ");
    scanf("%d",num);
    int *ch=(int *)malloc(sizeof(int));
    int *count=(int *)malloc(sizeof(int));
    *count=0;
    while(1)
    {
        printf("1-Palindrome\n2-Armstrong number\n3-Perfect number\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",ch);
        switch(*ch)
        {
            case 1:
                if(palindrome(num))
                {
                    printf("%d is a palindrome\n",*num);
                }
                else{
                    printf("%d is not a palindrome\n",*num);
                }
                break;
            case 2:
                if(armstrong(num,count))
                {
                    printf("%d is an armstrong number\n",*num);
                }
                else{
                    printf("%d is not an armstrong number\n",*num);
                }
                break;
            case 3:
                if(perfect(num))
                {
                    printf("%d is a perfect number\n",*num);
                }
                else{
                    printf("%d is not a perfect number\n",*num);
                }
                break;
            case 4:
                exit(0);
        }
    }
    free(num);
    free(ch);
    free(count);
}
//To count the no. of digits in the number
int countf(int *num, int *count)
{
    *count=0;
    int *temp=(int *)malloc(sizeof(int));
    *temp=(*num);
    while(*temp!=0)
    {
        *temp=(*temp)/10;
        (*count)++;
    }
    return (*count);
    free(temp);
}
//To check if the number is a palindrome
int palindrome(int *num)
{
    int *rev=(int *)malloc(sizeof(int));
    int *rem=(int *)malloc(sizeof(int));
    int *temp=(int *)malloc(sizeof(int));
    *temp=(*num);
    *rev=0;
    while(*temp>=1)
    {
        *rem=(*temp)%10;
        (*temp)=(*temp)/10;
        *rev=(*rev)*10+(*rem);
    }
    // printf("%d\n",*rev);
    free(rem);
    free(temp);
    return (*rev==*num);
    free(rev);
}
//To check if the number is an armstrong number
int armstrong(int *num, int *count)
{
    *count=countf(num,count);
    int *rem=(int *)malloc(sizeof(int));
    int *temp=(int *)malloc(sizeof(int));
    int *arm=(int *)malloc(sizeof(int));
    *temp=(*num);
    while(*temp!=0)
    {
        *rem=(*temp)%10;
        (*temp)=(*temp)/10;
        (*arm)+=pow(*rem,*count);
    }
    // printf("%d\n",*arm);
    return (*arm==*num);
    free(rem);
    free(temp);
    free(arm);
}
//To find the sum of factors
int perfect(int *num)
{
    int *i=(int *)malloc(sizeof(int));
    int *sum=(int *)malloc(sizeof(int));
    int *temp=(int *)malloc(sizeof(int));
    *sum=0;
    *i=1;
    *temp=(*num);
    while(*i<(*temp))
    {
        if((*temp)%(*i)==0)
        {
            *sum=(*sum)+(*i);
        }
        (*i)++;
    }
    // printf("%d\n",*sum);
    return(*sum==*num);
    free(i);
    free(sum);
    free(temp);
}