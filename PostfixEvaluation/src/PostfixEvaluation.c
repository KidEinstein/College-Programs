/*
 ============================================================================
 Name        : PostfixEvaluation.c
 Author      : Anirudh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int top;
int stack[20];
char expr[20];
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
precedence getToken(char* symbol, int* n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '-': return minus;
	case '+': return plus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;


	}
}
void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	return stack[top--];
}
int eval()
{
	precedence token;
	char symbol;
	int op1,op2;
	int n=0;
	top=-1;
	token=getToken(&symbol, &n);
	while(token != eos)
	{
		if ( token == operand )
		{
			push(symbol-'0');

		}
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
			case plus:
				push(op1+op2);
				break;
			case minus:
				push(op1-op2);
				break;
			case times:
				push(op1*op2);
				break;
			case divide:
				push(op1/op2);
				break;
			case mod:
				push(op1%op2);
				break;

			}
		}
		token=getToken(&symbol, &n);
	}
	return pop();
}

int main()
{

	printf("Enter expression: ");
	scanf("%s",expr);
	printf("Result: %d",eval());
}

