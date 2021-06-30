#include<stdio.h>
int systemNumber[10],i;
void binary(int number);
void octal(int number);
void HexaDecimal(int number);
void main(void)
{
    int number,op;
    printf("Input Number: ");
    scanf("%d",&number);
    printf("1-convert to Binary\n2-convert to Octal\n3-convert to Hexadecimal\n choose number\n");
    printf("Convert To>> ");
    scanf("%d",&op);
    if (op==1) binary(number);
    else if (op==2) octal(number);
    else if (op==3) HexaDecimal(number);
    else printf("Something wrong...");
}
void binary(int number)
{
        for (i=0;number>0;i++)
        {
            systemNumber[i]=number%2;
            number /=2;
        }
        for (i=i-1;i>=0;i--)
        {
            printf("%d",systemNumber[i]);
        }
}
void octal(int number)
{
    for (i=0;number>0;i++)
    {
        systemNumber[i]=number%8;
        number /=8;
    }
    for (i=i-1;i>=0;i--)
    {
        printf("%d",systemNumber[i]);
    }
}
void HexaDecimal(int number)
{
    char Hexanumber[10];
    for (i=0;number>0;i++)
    {
        if (number%16 >= 10) Hexanumber[i]= (number%16) + 55;
        else Hexanumber[i]=(number%16) + 48;
        number /=16;
    }
    for (i=i-1;i>=0;i--)
    {
        printf("%c",Hexanumber[i]);
    }
}
