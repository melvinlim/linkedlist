#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include<stdlib.h>
#include<stdio.h>
#include"complex.h"
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
	void apply(void (*f)(void *)){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			f(ptr->item);
		}
	}
	void insertInt(int item){
		int *x=new int;
		*x=item;
		insert(x);
	}
	void printComplex(){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			((Complex *)ptr->item)->print();
		}
		printf("\n");
	}
	void printInt(){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			printf("%d ",*((int *)ptr->item));
		}
		printf("\n");
	}
	void insertIntInOrderAsc(int item){
		int *x=new int;
		*x=item;
		NODE *tmpPtr;
		NODE *ptr=root;
		if(root->next){
			while((ptr->next)&&( *((int *)ptr->next->item) < item)){
				ptr=ptr->next;
			}
			tmpPtr=ptr->next;
			ptr->next=new NODE;
			ptr->next->item=x;
			ptr->next->next=tmpPtr;
		}else{
			ptr->next=new NODE;
			ptr->next->item=x;
			ptr->next->next=0;
		}
	}
};
#endif
