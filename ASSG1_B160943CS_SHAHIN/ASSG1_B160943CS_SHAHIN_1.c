#include<stdio.h>
main()
{
    int n,i,k,r;
    char *s;
    scanf("%d",&r);
    scanf("%d",&n);
    s=(char*)malloc(n*sizeof(char));
    if(s==NULL)
    {
        printf("Insufficient Memory, Exiting... \n");
        return 0;
    }
    for(i=0;i<=n;i++)
        scanf("%c",(s+i));
    scanf("%d",&k);
    if (r==1)
    {
        for (i=0;i<=n;i++)
        {
            if ((*(s+i)<='z')&&(*(s+i)>='a'))
            {
                if((*(s+i)+k)>'z')
                    {*(s+i)=*(s+i)+k-26;}
                else
                    *(s+i)=*(s+i)+k;
            }
            else if((*(s+i)<='Z')&&(*(s+i)>='A'))
            {
                if((*(s+i)+k)>'Z')
                    {*(s+i)=*(s+i)+k-26;}
                else
                    *(s+i)=*(s+i)+k;
            }
            else
                *(s+i)=*(s+i);
        }
    }
    else
    {
        for (i=0;i<=n;i++)
        {
            if ((*(s+i)<='z')&&(*(s+i)>='a'))
            {
                if((*(s+i)-k)<'a')
                    {*(s+i)=*(s+i)-k+26;}
                else
                    *(s+i)=*(s+i)-k;
            }
            else if((*(s+i)<='Z')&&(*(s+i)>='A'))
            {
                if((*(s+i)-k)<'A')
                    {*(s+i)=*(s+i)-k+26;}
                else
                    *(s+i)=*(s+i)-k;
            }
            else
                *(s+i)=*(s+i);
        }
    }
    for(i=0; i<=n; i++)
        printf("%c",*(s+i));
    free(s);
}
