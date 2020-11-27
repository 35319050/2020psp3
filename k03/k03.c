#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start;
    int pos;
    int len1;
    int len2;

    len1 = strlen(text);
    len2 = strlen(key);
    for(start=0;start<(len1-len2);start++){
        for (pos=0;pos<len2;pos++){
            if(text[start+pos]==key[pos]){
                if (len2==pos+1){
                    return &text[start];
                }
                
            }else
            {
                break;
            }  
        }
        
    }
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int start,pos;
    char table[256];
    int len1 = strlen(text);
    int len2 = strlen(key);
    int i,j = 0;

    for(int i; i<256; i++){
        table[i] = len2;
    }

    for(i = len2-1; i >= 0; i--){
        table[key[i]] = j;
        j++;
    }

    start = len2-1;
    while(start <= len1){
        
        printf("%s\n",text);
        for(i=0;i<start-len2+1;i++){
            printf(" ");
        }
        printf("%s\n",key);

        for(pos = len2-1; pos >= 0; pos--){
            if(text[start] == key[pos]){
                if(pos == 0){
                    return &text[start];
                }
                start = start - 1;
            }else{
                break;
            }
        }

        start = start + table[text[start]];

    }

    return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}