#include<stdio.h>
main()
{
    FILE *fpt,*fptr;
    char c;
    int flag=1;

    fpt= fopen("in.txt", "r");
    if (fpt == NULL)
    {
        printf("Cannot open file\n");
        return 0;
    }
    fptr=fopen("out.txt", "w");
    c = fgetc(fpt);
    while (c != EOF)
    {
        if (c==' ')
            {if (flag)
            {fputc(c, fptr);
            flag=0;}}
        else    {
            fputc(c, fptr);
            flag=1;
            }
        c = fgetc(fpt);
    }
    fclose(fptr);
    fclose(fpt);
}
