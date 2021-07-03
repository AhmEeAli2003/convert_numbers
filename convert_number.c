#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int systemNumber[10],i,sum,temp;
void decimalToBinary(int number);
void decimalToOctal(int number);
void decimalToHexaDecimal(int number);
int binaryToDecimal(int number);
int octalToDecimal(int number);
int HexaToDecimal();
void choose(int op,int number);
void binaryToOctal(int number);
void octalToBinary(int number);
void binaryToHexa(int number);
void HexaToBinary();
void octalToHexa(int number);
void HexaToOctal();
void main(void)
{
    system("color 1e");
    int number,op;
    printf(" 1-decimal to Binary\n 2-decimal to Octal\n 3-decimal to Hexadecimal\n");
    printf(" 4-binary to decimal\n 5-octal to decimal\n 6-Hexadecimal to decimal\n");
    printf(" 7-binary to octal\n 8-octal to binary\n 9-binary to Hexadecimal\n");
    printf(" 10-Hexadecimal to binary\n 11-octal to Hexadecimal\n 12-Hexadecimal to octal\n");
    printf("Choose number >> ");
    scanf("%d",&op);
    if (op==6) printf("%d",HexaToDecimal());
    else if (op==10) HexaToBinary();
    else if (op==12) HexaToOctal();
    else
    {
        printf("Input Number: ");
        scanf("%d",&number);
        choose(op,number);
    }
}
void choose(int op,int number)
{
    if (op==1) decimalToBinary(number);
    else if (op==2) decimalToOctal(number);
    else if (op==3) decimalToHexaDecimal(number);
    else if (op==4) printf("%d",binaryToDecimal(number));
    else if (op==5) printf("%d",octalToDecimal(number));
    else if (op==7) binaryToOctal(number);
    else if (op==8) octalToBinary(number);
    else if (op==9) binaryToHexa(number);
    else if (op==11) octalToHexa(number);
    else printf("Something wrong...");
}
void decimalToBinary(int number)
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
void decimalToOctal(int number)
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
void decimalToHexaDecimal(int number)
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
int binaryToDecimal(int number)
{
    for(i=0;number>0;i++)
    {
        temp=(number%10)*pow(2,i);
        sum+=temp;
        number /=10;
    }
    return sum;
}
int octalToDecimal(int number)
{
    for(i=0;number>0;i++)
    {
       temp=(number%10)*pow(8,i);
       sum+=temp;
       number /=10;
    }
    return sum;
}
int HexaToDecimal()
{
    char Hexanumber[17];
    printf("character should be Uppercase\n");
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
    return sum;
}
void binaryToOctal(int number)
{
    binaryToDecimal(number);
    decimalToOctal(sum);
}
void octalToBinary(int number)
{
    octalToDecimal(number);
    decimalToBinary(sum);
}
void binaryToHexa(int number)
{
    binaryToDecimal(number);
    decimalToHexaDecimal(sum);
}
void HexaToBinary()
{
    HexaToDecimal();
    decimalToBinary(sum);
}
void octalToHexa(int number)
{
    octalToDecimal(number);
    decimalToHexaDecimal(sum);
}
void HexaToOctal()
{
    HexaToDecimal();
    decimalToOctal(sum);
}
