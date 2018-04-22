#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include<assert.h>
template<typename T>
class Node{
public:
	Node *next;
	T *item;
	Node()	{
		next=0;
		item=0;
	};
	Node(T *item){
		this->item=item;
		this->next=0;
	}
	~Node(){
		delete item;
	}
};
template<typename T>
class List{
private:
	Node<T> *root;
	int size;
public:
	List(){
		root=new Node<T>();
		size=0;
	}
	~List(){
		Node<T> *ptr=root;
		Node<T> *tmp;
		while(ptr->next){
			tmp=ptr->next;
			delete ptr;
			ptr=tmp;
		}
		delete ptr;
	}
	T &operator[](int n){
		if(n>=size){
			assert(0);
		}
		Node<T> *ptr=root;
		for(int i=0;i<=n;i++){
			ptr=ptr->next;
		}
		return ptr->item;
	}
	void insert(T *item){
		Node<T> *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
		}
		ptr->next=new Node<T>(item);
		++size;
	}
	void apply(void (*f)(T *)){
		Node<T> *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			f(ptr->item);
		}
	}
	T *find(T *item){
		Node<T> *ptr=root;
		while(ptr->next){
			ptr=ptr->next;
			if((ptr->item)==item){
				return ptr->item;
			}
		}
		return 0;
	}
};
#endif
