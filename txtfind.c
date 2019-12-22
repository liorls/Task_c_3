#include <stdio.h>
#include "txtfind.h"
#include <string.h>

int getLine(char s[])
{
    char c;
    int i = 0;
    scanf("%c", &c);
    while ((c != '\n') && (c != '\0') && (i < LINE))
    {
        *(s + i) = c;
        i++;
        scanf("%c", &c);
    }
    return i;
}

int getWord(char w[])
{
    char c;
    int i = 0;
    scanf("%c", &c);
    while ((c != '\n') && (c != '\t') && (c != ' ') && (i < WORD))
    {
        *(w + i) = c;
        i++;
        scanf("%c", &c);
    }
    return i;
}

char upCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 'A';
    }
    return c;
}

int isEqualStringN(char s1[], char s2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (upCase(s1[i]) != upCase(s2[i]))
        {
            return 0;
        }
    }
    return 1;
}

int substring(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int count = 0;
    for (int i = 0; i <= (len2 - len1); i++)
    {
        if (isEqualStringN(str1, str2 + i, len1))
        {
            count++;
        }
    }
    if (count > 0)
        return 1;
    return 0;
}

int similar(char *s, char *t, int n){
    int i;
    for (i = 0; ((i <= n) && (*s != '\0'));)
    {
        if (*s != *t){
            i++;
        }
        else{
            t++;
        }
        s++;
    }
    if (i <= n)
        return 1;
    else
        return 0;
    }

void print_lines(char *str){
    char line[LINE];
    while(getLine(line)){
        if (substring(str,line))
       printf("%s", line);
    }
}

void print_similar_words(char *str){
     char word[WORD];
    while(getLine(word)){
        if (similar(word,str,1))
       printf("%s", word);
    }
}

