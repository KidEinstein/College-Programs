/*
 ============================================================================
 Name        : Graph.c
 Author      : Anirudh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int vertex;
	struct node* link;
};

typedef struct node* nodeptr;

nodeptr graph[20]={NULL};
int visited[20]={0};
int n;

void attach(int v, nodeptr* head)
{
	nodeptr new;
	nodeptr temp;
	temp=*head;
	new = (nodeptr)malloc(sizeof(struct node));
	new->vertex=v;
	new->link=NULL;
	if(*head==NULL)
	{
		*head=new;
		return;
	}
	for(; temp->link; temp=temp->link); //Notice the semicolon
	temp->link=new;

}

void createGraph()
{
	int i,numcon,j,v;
	printf("Enter number of vertices: ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("Enter number of vertices connected to vertex %d",i);
		scanf("%d",&numcon);
		printf("Enter the vertices connected to vertex %d",i);
		for(j=0;j<numcon;j++)
		{
			scanf("%d",&v);
			attach(v, &graph[i]);
		}
	}

}

void displayAdjList()
{
	int i;
	nodeptr x;
	for(i=0; i<n; i++)
	{
		printf("%d\t",i);
		x=graph[i];
		for(;x;x=x->link)
		{
			printf("%d\t",x->vertex);
		}
		printf("\n");

	}
}

void dfs(int v)
{
	nodeptr w;
	visited[v]=1;
	printf("%d\t",v);
	for(w=graph[v]; w; w=w->link)
	{
		if(!visited[w->vertex])
			dfs(w->vertex);

	}

}
int front=0, rear=0;
int queue[20];

int deleteq()
{
	return queue[++front];
}

void addq(int v)
{
	queue[++rear]=v;
}
int queueEmpty()
{
	if(front==rear)
		return 1;
	return 0;
}
void bfs(int v)
{
	nodeptr w;
	front=rear=0;
	printf("%d\t",v);
	visited[v]=1;
	addq(v);
	while(!queueEmpty())
	{
		v=deleteq();
		for(w=graph[v];w;w=w->link)
		{
			if(!visited[w->vertex])
			{
				printf("%d\t", w->vertex);
				addq(w->vertex);
				visited[w->vertex]=1;
			}
		}

	}
}
int main()
{
	int choice,i;
	while(1)
	{
		printf("1. Create Graph \n2. Display Adjacency List \n3. DFS \n4. BFS");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			createGraph();
			break;
		case 2:
			displayAdjList();
			break;
		case 3:
			for(i=0;i<n;i++)
				visited[i]=0;
			dfs(0);
			printf("\n");
			break;
		case 4:
			for(i=0;i<n;i++)
				visited[i]=0;
			bfs(0);
			printf("\n");
			break;

		}
	}
}




