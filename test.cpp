#include"linkedlist.h"
#include<stdlib.h>
#include"complex.h"
void printComplex(void *c){
	Complex *x=(Complex *)c;
	x->print();
}
int main(){
	srand(1234);
	List *list=new List();
	int x;
	float a,b;
	Complex *c;
	for(int i=0;i<10;i++){
/*
		x=rand()%100;
//		list->insertInt(x);
		list->insertIntInOrderAsc(x);
*/
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
//	list->printInt();
	return 0;
}
