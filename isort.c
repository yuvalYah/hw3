#include <stdio.h>
#include "isort.h"

int shift_element(int* arr, int i)
{
    int startindex=0;
  //  int* ptr = arr;
    int a =0 , b = *arr;
    while(startindex < i )
    {
        a = b;
        b=*(arr+1);
        arr++;
        *arr = a;
        startindex++;
    }
   // printf("\n%d\n",b);// b save here like the integet how delited
    return b;
}
void insertion_sort(int* arr , int len)
{

    int i=0 ,j=0;
 //   printf("was here\n");
    for(i=0 ; i < len-1 ; i++)
    {
      //  printf("%d , %d \n",*(arr +i) ,*(arr +i+1));
        if(*(arr +i) > *(arr+i+1)){
          //  printf("int tht first if : %d , %d \n",*(arr +i) ,*(arr +i+1));
            for(j=0 ; j < i+1 ; j++){
                if(*(arr+j) < *(arr +1+i) && *(arr +j+1)>*(arr +1+i)){
                 //   printf("int tht secound if : %d , %d, %d \n",*(arr +j) ,*(arr +j+1) ,*(arr +i+1));
                    int k = shift_element(arr+j , i+1-j);
                 //   printf("*(arr +j +1) befor : %d" , *(arr +j +1));
                    *(arr +j +1) = k;
                //    printf("*(arr +j +1) afterr : %d" , *(arr +j +1));

              /*      int index=0;
                    while (index <i+1){
                        printf("%d ,", arr[index]);
                        index++;
        
                    }
                    printf("\n");*/
                }
                else if(j==0 && *arr > *(arr+1+i) ){
                    int k = shift_element(arr+j , i+1);
                    *arr = k;
                 /*   int index=0;
                    while (index <i+1){
                        printf("%d ,", arr[index]);
                        index++;
        
                    }
                    printf("\n");*/
                }
                else if (*(arr+j) == *(arr +1+i)){
                    shift_element(arr+j , i+1-j);
                }
            }
           
        }
    }
}