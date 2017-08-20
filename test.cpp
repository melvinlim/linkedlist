#include"linkedlist.h"
#include<stdlib.h>
#include<assert.h>
#include"complex.h"
#define TRIALS 10000000
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
	for(int i=1;i<10;i++){
		assert((*list)[i-1]<=(*list)[i]);
	}
	list->printInt();
	int *loc;
	for(int i=0;i<100;i++){
		if((loc=list->findInt(i))){
			printf("found %d at %lx\n",i,(unsigned long)loc);
		}
	}
	delete list;
}
int main(){
	srand(1234);
	for(int t=0;t<TRIALS;t++){
		testComplex();
		testInt();
	}
	return 0;
}
