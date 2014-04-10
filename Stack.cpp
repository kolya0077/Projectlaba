// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	stack* next;
};

void Push(struct stack** headstack, int data) 
{
	struct stack* newstack=(struct stack*)malloc(sizeof(struct stack));
	newstack->data = data;
	newstack->next = *headstack;  
	*headstack = newstack;        
}

int Pop(struct stack** head)
{
	struct stack * temp = *head;
	int data=temp->data;
	*head = temp->next;
	free(temp);
	return data;
}
int _tmain(int argc, _TCHAR* argv[])
{	
	int i,a=1;
	stack* head=NULL;
	stack* f=NULL;
	while(a!=0)
	{
		for(i=0;a!=0;i++)
		{
			printf("Enter a value:");
			printf("\n");
			scanf("%d",&a);
			if (a>0) Push(&head,a);
			if (a<0) Pop(&head);
			printf("Stack:");
			f=head;
			while (f->next!=NULL)
			{
				printf("%d", f->data);
				f=f->next;
			}
			printf("%d", f->data);
		}
	}
	f=head;
	while (f->next!=NULL)
	{   
		Pop(&f);
	}
	printf("\n");
	free(f);
	return 0;
}

