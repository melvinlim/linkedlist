#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include<stdlib.h>
#include<stdio.h>
#define NODE struct Node
NODE{
	NODE *next;
	void *item;
};
class List{
private:
	NODE *root;
public:
	List(){
		root=new NODE;
		root->next=0;
		root->item=0;
	}
	~List(){
	}
	void insert(void *item){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
		}
		ptr->next=new NODE;
		ptr->next->item=item;
		ptr->next->next=0;
	}
	void insertInt(int item){
		int *x=new int;
		*x=item;
		insert(x);
	}
	void printInt(){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			printf("%d ",*((int *)ptr->item));
		}
		printf("\n");
	}
};
#endif
