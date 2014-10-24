/*
 ============================================================================
 Name        : Temp.c
 Author      : Anirudh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#define MAX 20
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;
precedence stack[30];
int top=-1;
char EXPR[MAX];
int isp[]={20,19,12,12,13,13,13,0};
int icp[]={0,19,12,12,13,13,13,0};
void push(precedence token)
{
	stack[++top]=token;
}
precedence pop()
{
	return stack[top--];
}
precedence get_token(char *symbol,int *n)
{
	*symbol=EXPR[(*n)++];
	switch(*symbol)
	{
		case '(':return lparen;
		case ')':return rparen;
		case '+':return plus;
		case '-':return minus;
		case '*':return times;
		case '/':return divide;
		case '%':return mod;
		case '\0':return eos;
		default:return operand;
	}
}
void print_token(precedence token)
{
	switch(token)
	{
		case plus:printf("+");break;
		case minus:printf("-");break;
		case times:printf("*");break;
		case divide:printf("/");break;
		case mod:printf("%");break;
	}
}
void postfix()
{
	char symbol;
	precedence token;
	int n=0;
	top=0;
	stack[0]=eos;
	for(token=get_token(&symbol,&n);token!=eos;token=get_token(&symbol,&n))
	{
		if(token==operand)
			printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				print_token(pop());
			pop();
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
				print_token(pop());
			push(token);
		}
	}
	while((token=pop())!=eos)
		print_token(token);
	printf("\n");
}
void main()
{
	printf("\nEnter the infix expression\n");
	scanf("%s",EXPR);
	postfix();
}
