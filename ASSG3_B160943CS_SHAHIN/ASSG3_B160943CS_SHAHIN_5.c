#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct node
{
    int data;
    struct node* next;
}*top,*ptr;
typedef struct node NODE;
main()
{
    int j=0,y=0,k,i,n1,n2,num=0;
    char out[1000],s[1000];
    top=NULL;
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            y=1;
            out[j]=s[i];
            j++;
        }
        else if(s[i]==' ')
        {
            num=0;
            if(y==1)
            {
                y=0;
                for( k=0;k<j;k++)
                {
                    if('0'<=out[k] || out[k]<='9')
                        num=num*10+(out[k]-'0');
                }
                j=0;
                if(top==NULL)
                {
                    top=(NODE*)(malloc(sizeof(NODE)));
                    top->data=num;
                    top->next=NULL;
                }
                else
                {
                    ptr=top;
                    top=(NODE*)(malloc(sizeof(NODE)));
                    top->data=num;
                    top->next=ptr;
                }
                num=0;
            }
        }
        else
        {
            n2=top->data;
            top=top->next;
            n1=top->data;
            top=top->next;
            switch(s[i])
            {
                case '+':
                    n1=n1+n2;
                    break;
                case '-':
                    n1=n1-n2;
                    break;
                case '*':
                    n1=n1*n2;
                    break;
                case '/':
                    n1=n1/n2;
                    break;
                case '^':
                    {
                        int t,x=1;
                        for(t=0;t<n2;t++)
                            x=x*n1;
                        n1=x;
                    }
                    break;
            }
            if(top==NULL)
            {
                top=(NODE*)(malloc(sizeof(NODE)));
                top->data=n1;
                top->next=NULL;
            }
            else
            {
                ptr=top;
                top=(NODE*)(malloc(sizeof(NODE)));
                top->data=n1;
                top->next=ptr;
            }
        }
    }
    n1=top->data;
    top=top->next;
    int f=0;
    char ch;
    for(i=0;s[i]!='\0';)
    {
        if(s[i]>='0' && s[i]<='9' || s[i]==' ')
        {
            i++;
            continue;
        }
        else
        {
            ch=s[i];
            for(j=i-1;j>=0;j--)
            {
                if(s[j]>='0' && s[j]<='9')
                    f=1;
                else if (s[j]==' ' && f==1)
                {
                    s[j]=ch;
                    break;
                }
            }
            for(j=i;s[j]!='\0';j++)
                s[j]=s[j+1];
            for(j=i;s[j]!='\0';j++)
                s[j]=s[j+1];
        f=0;
        }
    }
    printf("%s\n",s);
    printf("%d",n1);
}
