#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct  
{
	int data;
	struct Node *next;
}Node;
/*ͷ�巨*/
void createlistHead(Node **P,int n)
{
	int i=0;
	Node *new_list=NULL;
	/*����ͷ�ڵ�     */
	*P=(Node*)malloc(sizeof(Node));
	(*P)->next=NULL;
	/*******************************/
	/*����ͷ�ڵ� */
	//*P=NULL;

	for(i=0;i<n;i++)
	{

		if(*P==NULL)
		{
			new_list=(Node *)malloc(sizeof(Node));

			new_list->data=i;
			new_list->next=*P;
			*P=new_list;
		}
		else
		{
			new_list=(Node *)malloc(sizeof(Node));
			new_list->data=i;
			new_list->next=(*P)->next;
			(*P)->next=new_list;
		}
	}
}
/* β�巨 */
void createlistend(Node **P,int n)
{
	int i=0;
	Node *endNode =NULL;
	(*P)=(Node *)malloc(sizeof(Node));
	(*P)->next=NULL;
	endNode=*P;
	for(i=0;i<n;i++)
	{
		Node *NewNode=(Node *)malloc(sizeof(Node));
		NewNode->data=i;
		NewNode->next=NULL;
		endNode->next=NewNode;
		endNode=NewNode;

	}
}
/* ��ӡ���� */
void printlist(Node *P)
{
	Node *Pmove =P;
	while(P->next != NULL)
	{
		Pmove=P->next;
		printf("%d\n",Pmove->data);
		P=P->next;
	}
}

/*ɾ������*/
void dele_list(Node **P,int i)
{
	int j =0;
	Node *P_move=*P;
	Node *P_f=P_move;
	while(P_move->next!=NULL)
	{
		P_f=P_move;
		j++;
		P_move=P_move->next;
		if(j==i)
		{
			P_f->next=P_move->next;
			free(P_move);
			break;
		}

	}
}

int main_me_list() 
{
	Node *inlist=(Node *)malloc(sizeof(Node));
	createlistend(&inlist,5);
	printlist(inlist);
	dele_list(&inlist,1);
	printlist(inlist);
}
