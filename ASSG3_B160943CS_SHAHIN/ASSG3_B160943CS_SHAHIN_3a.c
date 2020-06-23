#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 100
long long int a[MAX];
int rear=-1;
int front=-2;
int n=0;
void enqueue()
{
    long long int num;
    if (rear==n-1)
        printf("-2");
    else
    {
        if (front==-2)
            front=0;
        scanf("%lld",&num);
        rear++;
        a[rear]=num;
    }
}
void dequeue()
{
    int r=0;
    if(front==-2)
        printf("-1");
    else
    {
        printf("%lld",a[front]);
        if(front==rear)
             front=-2;
        while(r<(n-1))
        {
            a[r]=a[r+1];
            r++;
        }
        rear--;
    }
}
void display()
{
    int i;
    if (front==-2)
        printf("-1");
    else
    {
        for(i=front;i<=rear;i++)
            printf("%lld ", a[i]);
    }
}
main()
{
    char choice;
    scanf("%d",&n);
    while(1)
    {
        scanf("%c",&choice);
        switch(choice)
        {
            case 'e':
            enqueue();
            break;
            case 'd':
            dequeue();
            break;
            case 'p':
            display();
            break;
            case 's':
            return;
        }
    }
}
