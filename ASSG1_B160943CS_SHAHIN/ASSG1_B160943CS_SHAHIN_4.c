#include<stdio.h>
int max(int x,int y)
{
    int a;
    if (x<0)
        x=-x;
    if (y<0)
        y=-y;
    if (x>y)
        max(y,x);
    a=x;
    while((x%a!=0)||(y%a!=0))
    {
        a--;
    }
    return a;
}
struct ratio
{
    int x;
    int y;
}c[10];
main()
{
    int o,i,n,j;
    scanf("%d",&o);
    if (o==1)
    {
        scanf("%d %d",&c[0].x,&c[0].y);
        if((c[0].x<0)&&(c[0].y<0))
        {
            c[0].x=-c[0].x;
            c[0].y=-c[0].y;
        }
        else if((c[0].x>0)&&(c[0].y<0))
        {
            c[0].x=-c[0].x;
            c[0].y=-c[0].y;
        }
        printf("%d/%d",c[0].x/max(c[0].x,c[0].y),c[0].y/max(c[0].x,c[0].y));
    }
    else if (o==2)
    {
        scanf("%d %d",&c[0].x,&c[0].y);
        scanf("%d %d",&c[1].x,&c[1].y);
        for(i=0;i<2;++i)
        {
            if((c[i].x<0)&&(c[i].y<0))
            {
                c[i].x=-c[i].x;
                c[i].y=-c[i].y;
            }
            else if((c[i].x>0)&&(c[i].y<0))
            {
                c[i].x=-c[i].x;
                c[i].y=-c[i].y;
            }
        }
        printf("%d/%d",((c[0].x)*(c[1].y)+(c[1].x)*(c[0].y))/max(((c[0].x)*(c[1].y)+(c[1].x)*(c[0].y)),((c[0].y)*(c[1].y))),((c[0].y)*(c[1].y))/max(((c[0].x)*(c[1].y)+(c[1].x)*(c[0].y)),((c[0].y)*(c[1].y))));
    }
    else if (o==3)
    {
        scanf("%d %d",&c[0].x,&c[0].y);
        scanf("%d %d",&c[1].x,&c[1].y);
        for(i=0;i<2;++i)
        {
            if((c[i].x<0)&&(c[i].y<0))
            {
                c[i].x=-c[i].x;
                c[i].y=-c[i].y;
            }
            else if((c[i].x>0)&&(c[i].y<0))
            {
                c[i].x=-c[i].x;
                c[i].y=-c[i].y;
            }
        }
        printf("%d/%d",((c[0].x)*(c[1].x))/max(((c[0].x)*(c[1].x)),((c[1].y)*(c[0].y))),((c[1].y)*(c[0].y))/max(((c[0].x)*(c[1].x)),((c[1].y)*(c[0].y))));
    }
    else if (o==4)
    {
        scanf("%d",&n);
        struct ratio* r;
        r= (struct ratio*)malloc(n*sizeof(struct ratio));
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&r[i].x,&r[i].y);
            {
                if((r[i].x<0)&&(r[i].y<0))
                {
                    r[i].x=-r[i].x;
                    r[i].y=-r[i].y;
                }
                else if((r[i].x>0)&&(r[i].y<0))
                {
                    r[i].x=-r[i].x;
                    r[i].y=-r[i].y;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if ((r[i].x)*(r[j].y)>(r[j].x)*(r[i].y))
                {
                    o=r[i].x;
                    r[i].x=r[j].x;
                    r[j].x=o;
                    o=r[i].y;
                    r[i].y=r[j].y;
                    r[j].y=o;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d/%d ",r[i].x,r[i].y);
        }
        free(r);
    }
    else if (o==5)
    {
        scanf("%d %d",&c[0].x,&c[0].y);
        if((c[0].x<0)&&(c[0].y<0))
        {
            c[0].x=-c[0].x;
            c[0].y=-c[0].y;
        }
        else if((c[0].x>0)&&(c[0].y<0))
        {
            c[0].x=-c[0].x;
            c[0].y=-c[0].y;
        }
        printf("%d/%d",(c[0].x)/max(c[0].x,c[0].y),(c[0].y)/max(c[0].x,c[0].y));
    }
}
