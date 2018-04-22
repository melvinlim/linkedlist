#include"linkedlist.h"
#include<time.h>
#include<stdio.h>
#include<assert.h>
#define TRIALS 10
void printInt(int *x){
	printf("%d ",*x);
}
void print(List<int> *list){
	list->apply(printInt);
	printf("\n");
}
void testInt(){
	int *x,*t,*s;
	List<int> *list=new List<int>();
	for(int i=0;i<10;i++){
		x=new int;
		*x=rand()%100;
		list->insert(x);
	}
	for(int i=0;i<10;i++){
		print(list);
		s=list->atIndex(0);
		t=list->atIndex(1);
		list->pop();
		assert(t==list->atIndex(0));
	}
	list->pop();
	delete list;
}
int main(){
	srand(time(0));
	for(int t=0;t<TRIALS;t++){
		testInt();
	}
	return 0;
}
