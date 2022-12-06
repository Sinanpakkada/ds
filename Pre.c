
#include <stdio.h>
#include<string.h>
#include<ctype.h>
char infix[80],stack[80],inf[80],prefix[80],item,x;
int top=-1,i=-1;
void PUSH(char x)
{
    stack[++top]=x;
}
int POP()
{
   return stack[top--];
}
void output(char x)
{
    prefix[++i]=x;
    
}
int ISP(char x)
{
    if(x=='+'||x=='-')
        return 2;
    if(x=='*'||x=='/')
        return 4;
    if(x=='^')
        return 5;
    if(x>='A'&&x<='Z'||x>='a'&&x<='z')
        return 8;
    if(x=='(')
        return 0;
}

int ICP(char x)
{
    if(x=='+'||x=='-')
        return 1;
    if(x=='*'||x=='/')
        return 3;
    if(x=='^')
        return 6;
    if(x>='A'&&x<='Z'||x>='a'&&x<='z')
        return 7;
    if(x=='(')
        return 9;
    if(x==')')
        return 0;
}
void main()
{
    printf("Enter the infix expression\n");
    gets(infix);
    for(int k=0;k<strlen(infix);k++)
    {
        if(infix[strlen(infix)-k-1]=='(')
        inf[k]=')';
        else if(infix[strlen(infix)-k-1]==')')
        inf[k]='(';
        else
        inf[k]=infix[strlen(infix)-k-1];
    }
    inf[strlen(inf)]=')';
    PUSH('(');
    int j=0;
    while(j<strlen(inf))
    {
        item=inf[j];
        if(isalnum(item))
        {
            output(item);
        }
        else if(item==')')
        {
            while(stack[top]!='(')
            {
                output(stack[top]);
                POP();
            }
            POP();
        }
        else if(ISP(stack[top])>ICP(item))
        {
            while(ISP(stack[top])>ICP(item))
            {
                output(stack[top]);
                POP();
            }
                PUSH(item);
        }
        else if(ISP(stack[top])<ICP(item))
        {
            PUSH(item);
        }
        else 
            PUSH(item);
        j++;
    }
    for(int k=0;k<j;k++)
    {
        printf("%c",prefix[j-k-1]);
    }
}
