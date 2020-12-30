#include <stdio.h>
#include <stdlib.h>
#include "isort.h"
#include "txtfind.h"

#define SIZE 50
int main(){

    
    int arr[SIZE]={0};
    int index = 0;
    while(index < SIZE){
        int k;
        scanf("%d" , &k);
        *(arr+index) = k;
        index++;
    }
    insertion_sort(arr , SIZE);
    index = 0;
    while(index < SIZE){
        printf("%d," ,*(arr+index));
        index++;
    }
    printf("\n");
//     char c[]= "this is a text file\nlooking for the word cat\nthe program should print also cats\nand crat and lcat but it shouldn’t\nprint the word caats";
//    // scanf("%s", c);
//     int k = get_line(c);
//     printf("%d\n", k);
    // char test;
//    char* a ="cat";
//    char* b="cat";
//    printf("%d\n",similar( a, b ,0)); 
    // if( scanf("%c", & test) == 0) printf("test == 0");
    // if( scanf("%c", & test) == 1 ) printf("test == 1");
    char word[WORD];
    char option[WORD];
    getword(word);
    getword(option);
    if(*option == 'a')
    {
        print_lines(word);
    } else if(*option == 'b') {
        print_similar_words(word);
    }
    return 0;
}
