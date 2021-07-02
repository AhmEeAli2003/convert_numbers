#include<stdio.h>
#include<math.h>
#include<string.h>
int systemNumber[10],i,sum,temp;
void binary(int number);
void octal(int number);
void HexaDecimal(int number);
void binaryToDecimal(int number);
void octalToDecimal(int number);
void HexaToDecimal();
void choose(int op,int number);
void main(void)
{
    int number,op;
    printf(" 1-convert to Binary\n 2-convert to Octal\n 3-convert to Hexadecimal\n");
    printf(" 4-binary to decimal\n 5-octal to decimal\n 6-Hexadecimal to decimal\n");
    printf("Choose number >> ");
    scanf("%d",&op);
    if (op==6) HexaToDecimal();
    else
    {
        printf("Input Number: ");
        scanf("%d",&number);
        choose(op,number);
    }

}
void choose(int op,int number)
{
    if (op==1) binary(number);
    else if (op==2) octal(number);
    else if (op==3) HexaDecimal(number);
    else if (op==4) binaryToDecimal(number);
    else if (op==5) octalToDecimal(number);
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
void binaryToDecimal(int number)
{
    for(i=0;number>0;i++)
    {
        temp=(number%10)*pow(2,i);
        sum+=temp;
        number /=10;
    }
    printf("%d",sum);
}
void octalToDecimal(int number)
{
    for(i=0;number>0;i++)
    {
       temp=(number%10)*pow(8,i);
       sum+=temp;
       number /=10;
    }
    printf("%d",sum);
}
void HexaToDecimal()
{
    char Hexanumber[17];
    printf("Input number: ");
    scanf("%s",&Hexanumber);
    int base=1;
    int len=strlen(Hexanumber);
    for (i=len-1;i>=0;i--)
    {
        if (Hexanumber[i] >= '0' && Hexanumber[i]<= '9')
        {
            sum +=(Hexanumber[i] - 48)*base;
            base*=16;
        }
        else if (Hexanumber[i] >= 'A' && Hexanumber[i] <= 'F')
        {
            sum+=(Hexanumber[i] - 55)*base;
            base*= 16;
        }
    }
    printf("%d",sum);
}
