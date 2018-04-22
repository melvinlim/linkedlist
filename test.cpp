#include"linkedlist.h"
#include<time.h>
#include<stdio.h>
#define TRIALS 100000000000
void printInt(int *x){
	printf("%d ",*x);
}
void testInt(){
	int *x;
	List<int> *list=new List<int>();
	for(int i=0;i<10;i++){
		x=new int;
		*x=rand()%100;
		list->insert(x);
	}
	list->apply(printInt);
	//list->print();
	delete list;
}
int main(){
	srand(time(0));
	for(int t=0;t<TRIALS;t++){
		testInt();
	}
	return 0;
}
