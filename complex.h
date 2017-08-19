#ifndef _COMPLEX_H
#define _COMPLEX_H
#include<stdlib.h>
#include<stdio.h>
class Complex{
private:
public:
	float a;
	float b;
	Complex(float a,float b){
		this->a=a;
		this->b=b;
	}
	Complex(){
		a=b=0;
	}
	~Complex(){
	}
	void print(){
		printf("(%g,%g) ",a,b);
	}
};
#endif
