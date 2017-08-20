#include"linkedlist.h"
#include<stdlib.h>
#include"complex.h"
void printComplex(void *c){
	Complex *x=(Complex *)c;
	x->print();
}
void testComplex(){
	Complex *c;
	float a,b;
	List *list=new List();
	for(int i=0;i<10;i++){
		a=rand()%100/100.0;
		b=rand()%100/100.0;
		c=new Complex(a,b);
		c->print();
		list->insert(c);
	}
	printf("\n");
	list->printComplex();
	list->apply(printComplex);
	printf("\n");
	delete list;
}
void testInt(){
	int x;
	List *list=new List();
	for(int i=0;i<10;i++){
		x=rand()%100;
//		list->insertInt(x);
		list->insertIntInOrderAsc(x);
	}
	list->printInt();
	int *loc;
	for(int i=0;i<100;i++){
		if(loc=list->findInt(i)){
			printf("found %d at %x\n",i,loc);
		}
	}
	delete list;
}
int main(){
	srand(1234);
	testComplex();
	testInt();
	return 0;
}
