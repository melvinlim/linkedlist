#include"linkedlist.h"
#include<stdlib.h>
int main(){
	srand(1234);
	List *list=new List();
	int x;
	for(int i=0;i<10;i++){
		x=rand()%100;
		list->insertInt(x);
	}
	list->printInt();
	return 0;
}
