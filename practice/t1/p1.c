#include<stdio.h>
void p1(int *a,int n)
{
    int j=-1,i;
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            j++;
            a[i]+=a[j];
            a[j]=a[i]-a[j];
            a[i]-=a[j];
        }
    }
}
main()
{
    /*int *a,temp,i,n;
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
    p1(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
