#include <stdio.h>
#include "txtfind.h"
#define false 0
#define true 1

int length(char str[]){
    int lenght = 0;
    while(str[lenght] != '\0'){
        lenght++;
    }
    return lenght;
}
int get_line(char s[]){
    int countOfWord=0;
    char c = *s;
    while(scanf("%c" ,&c) == 1){
        if(countOfWord == LINE){
            break;
        }
        if(c =='\n') break;
        *(s+countOfWord)=c;
        countOfWord++;
    }
    return countOfWord;
}
int getword(char w[]){
    int countWord=0;
    char wo;
    while(scanf("%c", &wo) >0 && wo!='\0' && wo != '\t' && wo != ' ' && wo != '\n'){
        if(countWord == WORD) break;
        *(w+countWord)=wo;
        countWord++;

    }
    *(w+countWord)='\0';
    return countWord;
}
int substring( char * str1, char * str2){

    int i1=0 , i2=0;
    int len1=length(str1);
    int len2=length(str2);
    int ans=false;
    int temp=0;
    while(i1<len1 && i2<len2 && ans == false){
        if(*(str1+i1)==*(str2+i2)){
            temp = i1;
            while(temp < len1 && i2 < len2 && *(str1+temp)==*(str2+i2)){
                temp++;
                i2++;
            }
            if(i2 == len2) ans=true;
            i2=0;   
        }
        i1++;
    }

    return ans;


}
int similar(char *s, char *t, int n){
    int lens=length(s);
    int lent =length(t);
    int is=0 ,it=0;
    int ans = false;
    while(it<lent && is < lens ){
        if(*(s+is) == *(t + it)) {it++; is++;}
        else {is++;}
    }
    if(it == lent) ans = true;
    int k = false; 
    if(ans==true ) k =((lens-n) ==lent )? true : false ;
    return k;
}
void print_lines(char * str){
    int n;
    char line[LINE];
    get_line(line);
    while ((n = get_line(line)) > 0){   
        if (substring(line, str) == 1)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%c", line[i]);
            }
            printf("\n");
        }
    }
}
void print_similar_words(char * str){
    int n;
    char word[WORD];
    getword(word);
    while ((n = getword(word)) > 0){
        if (similar(word, str, 0) == 1 || similar(word, str, 1) == 1){
            for (int i = 0; i < n; i++)
            {
                printf("%c", *(word+i));
            }
            printf("\n");
        }
    }
}