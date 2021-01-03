#include <stdio.h>
#include "isort.h"
#define SIZE 50

/*
    The function will get a pointer to the array 
    (not necessarily to the beginning of the array) and a number. 
    The function will move the i members
    Following in one cell array to the right
*/
int shift_element(int* arr, int i)
{
    int startindex=0;
    int a =0 , b = *arr;
    while(startindex < i )
    {
        a = b;
        b=*(arr+1);
        arr++;
        *arr = a;
        startindex++;
    }
    return b;
}

//this func sort the array 
void insertion_sort(int* arr , int len)
{

    int i=0 ,j=0;
    for(i=0 ; i < len-1 ; i++)
    {
        if(*(arr +i) > *(arr+i+1)){
            for(j=0 ; j < i+1 ; j++){
                if(*(arr+j) < *(arr +1+i) && *(arr +j+1)>*(arr +1+i)){//found the place arr +1+i shold be
                    int k = shift_element(arr+j , i+1-j);
                    *(arr +j +1) = k;
                }
                else if(j==0 && *arr > *(arr+1+i) ){//if itsh the smallest number
                    int k = shift_element(arr+j , i+1);
                    *arr = k;
                }
                else if (*(arr+j) == *(arr +1+i)){//if exists some equals numbers 
                    shift_element(arr+j , i+1-j);
                }
            }
           
        }
    }
}

/*  the main func how ran the pogram */
int main(){
    int arr[SIZE]={0};
    int index = 0;
    while(index < SIZE){
        int k;
        scanf("%d" , &k);//get from the user number to array
        *(arr+index) = k;
        index++;
    }
    insertion_sort(arr , SIZE); //sort
    index = 0;
    //print the arr 
    while(index < SIZE){
        printf("%d," ,*(arr+index));
        index++;
    }
    printf("\n");
}