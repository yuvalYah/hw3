#include <stdio.h>
#include "txtfind.h"
#define false 0
#define true 1
#define LINE 256
#define WORD 30

/* this class is repesent the part 2 in hw3
   in main we get option a or b
   and get word to look on text 
*/
int main(){
    char word[WORD];
    char op[WORD];
    getword(word);
    getword(op);
    if(*op == 'a')
    {
        print_lines(word);
    } else if(*op == 'b') {
        print_similar_words(word);
    }
    return 0;

}
//help me to find the len of string
int length(char str[]){
    int lenght = 0;
    while(str[lenght] != '\0'){
        lenght++;
    }
    return lenght;
}

//return the number of char's on s string
int get_line(char s[]){
    int countOfWord=0;
    char c = *s;
    while(scanf("%c" ,&c) == 1){
        if(countOfWord == LINE){//can be line more then 256 chars
            break;
        }
        if(c =='\n') break;//thats mean the line is over
        *(s+countOfWord)=c;
        countOfWord++;
    }
    return countOfWord;
}

//return the namber of the chars word
int getword(char w[]){
    int countWord=0;
    char wo;
    //if char = '\0' or ='\t' or = ' ' or = '\n' this mean that the word in the text is over
    while(scanf("%c", &wo) > 0 && wo!='\0' && wo != '\t' && wo != ' ' && wo != '\n'){
        if(countWord == WORD) break; //max char in word is 30
        *(w+countWord)=wo;
        countWord++;

    }
    *(w+countWord)='\0';// to reset the string from previous run
    return countWord;
}

// check if str2 substring of str1
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
            if(i2 == len2) ans=true; // out from the while loop
            i2=0;   
        }
        i1++;
    }
    return ans;
}

// check if t is similar to s 
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
    if(ans==true ) k =((lens-n) ==lent )? true : false ; // if ans is true so with short if check if t similar to s
    return k;
}

//option a : print the line from the text that str string is in it
void print_lines(char * str){
    int n;
    char line[LINE];//max char in the line
    get_line(line);
    while ((n = get_line(line)) > 0){   
        if (substring(line, str) == true){
            for (int i = 0; i < n; i++){
                printf("%c", line[i]);//print the line
            }
            printf("\n");
        }
    }
}

//option b : print the similar words from the text
void print_similar_words(char * str){
    int n;
    char word[WORD];//max char in word
    getword(word);
    while ((n = getword(word)) > 0){
        //Max omit one letter
        if (similar(word, str, 0) == true || similar(word, str, 1) == true){
            for (int i = 0; i < n; i++){
                printf("%c", *(word+i));
            }
            printf("\n");
        }
    }
}