#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include<stdlib.h>
#include<stdio.h>
#include"complex.h"
#include<assert.h>
#define NODE struct Node
#define NEW(x) (x *)malloc(sizeof(x))
NODE{
	NODE *next;
	void *item;
};
class List{
private:
	NODE *root;
	int size;
public:
	List(){
		root=NEW(NODE);
		root->next=0;
		root->item=0;
		size=0;
	}
	~List(){
		NODE *ptr=root;
		NODE *tmp;
		while(ptr->next){
			tmp=ptr->next;
			free(ptr->item);
			free(ptr);
			ptr=tmp;
		}
		free(ptr->item);
		free(ptr);
	}
	int &operator[](int n){
		if(n>=size){
			assert(0);
		}
		NODE *ptr=root;
		for(int i=0;i<=n;i++){
			ptr=ptr->next;
		}
		return *(int *)ptr->item;
	}
	void insert(void *item){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
		}
		ptr->next=NEW(NODE);
		ptr->next->item=item;
		ptr->next->next=0;
		++size;
	}
	void apply(void (*f)(void *)){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			f(ptr->item);
		}
	}
	void insertInt(int item){
		int *x=NEW(int);
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
		int *x=NEW(int);
		*x=item;
		NODE *tmpPtr;
		NODE *ptr=root;
		if(root->next){
			while((ptr->next)&&( *((int *)ptr->next->item) < item)){
				ptr=ptr->next;
			}
			tmpPtr=ptr->next;
			ptr->next=NEW(NODE);
			ptr->next->item=x;
			ptr->next->next=tmpPtr;
		}else{
			ptr->next=NEW(NODE);
			ptr->next->item=x;
			ptr->next->next=0;
		}
		++size;
	}
	int *findInt(int item){
		NODE *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			if(*((int *)ptr->item)==item){
				return (int *)ptr->item;
			}
		}
		return 0;
	}
};
#endif
