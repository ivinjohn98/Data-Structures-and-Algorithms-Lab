#include<stdio.h>
void p2(int *a,int n)
{
    int j=-1,i,k;
    for(i=0;i<n;i++)
    {
        if(a[i]%3==0)
        {
            j++;
            a[i]+=a[j];
            a[j]=a[i]-a[j];
            a[i]-=a[j];
        }
    }
    for(i=j+1;i<n;i++)
    {
        if(a[i]%3==1)
        {
            j++;
            if(i!=j)
            {
                a[i]+=a[j];
                a[j]=a[i]-a[j];
                a[i]-=a[j];
            }
        }
    }
}
main()
{
    /*int *a,temp,i,n;7
    FILE *fin,*fout;
    fin=fopen("in","rb");
    fout=fopen("out","wb");
    if (fin==NULL)
        printf("cannot open");
    if (fout==NULL)
        printf("cannot open");
    while(1)
    {
        fscanf(fin,"%d",&temp);
        if (feof(fin))
            break;
        a=realloc(a,sizeof(int)*(n+1));
        a[n]=temp;
        n++;
    }*/
    int *a,n,i;
    printf("Enter the size of the string");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    p2(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
