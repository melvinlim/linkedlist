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
	List<int> *list1=new List<int>();
	List<int> *list2=new List<int>();
	for(int i=0;i<10;i++){
		x=new int;
		*x=rand()%100;
		list1->insert(x);
	}
	list2->copy(list1);
	print(list2);
	s=list2->atIndex(rand()%10);
	list2->remove(s);
	assert(list2->find(s)==0);
	print(list2);
	for(int i=0;i<10;i++){
		print(list1);
		s=list1->atIndex(0);
		t=list1->atIndex(1);
		list1->pop();
		assert(t==list1->atIndex(0));
	}
	list1->pop();
	delete list1;
}
int main(){
	srand(time(0));
	for(int t=0;t<TRIALS;t++){
		testInt();
	}
	return 0;
}
