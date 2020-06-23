#include<stdio.h>
#include<string.h>
void rev(char* s,int i)
{
    if(i<((strlen(s)/2)))
    {
        *(s+i)=*(s+i)+*(s+strlen(s)-1-i);
        *(s+strlen(s)-1-i)=*(s+i)-*(s+strlen(s)-1-i);
        *(s+i)=*(s+i)-*(s+strlen(s)-1-i);
        rev(s,i+1);
    }
    else
        return;
}
main()
{
    char s[50];
    gets(s);
    rev(s,0);
    printf("%s",s);
}
