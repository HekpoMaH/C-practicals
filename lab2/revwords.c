#include <ctype.h>
#include<stdio.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
    for(;start<end;start++,end--){
        char t=str[start];
        str[start]=str[end];
        str[end]=t;
    }
}


int find_next_start(char str[], int len, int i) { 
    i++;
    for(;i<len;i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            if(i-1<0){
                return i;
            }
            if(!((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z'))){
                return i;
            }
        }
    }
    return -1;
}

int find_next_end(char str[], int len, int i) {
    i++;
    for(;i<len;i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            if(i+1>=len){
                return i;
            }
            if(!((str[i+1]>='a'&&str[i+1]<='z')||(str[i+1]>='A'&&str[i+1]<='Z'))){
                return i;
            }
        }
    }
    return -1;
}

void reverse_words(char s[]) { 
    int len=strlen(s),start=find_next_start(s,len,-1);
    int end=find_next_end(s,len,0);
    while(end!=-1){
        reverse_substring(s,start,end);
        int nstart=find_next_start(s,len,start);
        int nend=find_next_end(s,len,end);
        start=nstart;
        end=nend;
    }
}
//int main(void){
//    char str[]="  ibaneee, kuchki-mrasni! IBANEE kovri mrasni";
//    printf("%c %c\n",str[find_next_start(str,strlen(str),strlen(str)-9)],str[find_next_end(str,strlen(str),strlen(str)-9)]);
//    reverse_words(str);
//    printf("%s\n",str);
//}
