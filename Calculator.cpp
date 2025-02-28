#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

float Add(float a,float b) {
	float res = a + b;
	return res;
}
float Sub(float a, float b) {
	float res = a - b;
	return res;
}
float Mil(float a, float b) {
	float res = a * b;
	return res;
}
float Div(float a, float b) {
	float res = a / b;
	return res;
}

void Calculators(float a,char s,float b) {
		char flag = 1;
		float res=1;
		switch (s) {
			case '+':res=Add(a,b);break;
			case '-':res=Sub(a,b);break;
			case '*':res=Mil(a,b);break;
			case '/':res=Div(a,b);break;
			default:flag = 0; printf(" ‰»Î¥ÌŒÛ!\n"); break;
		}
		if(flag)
		printf("Reslut:%f\n",res);
}



int main() {
	float a,b;
	char s;
	printf("Calculators:\n");
	scanf("%f%c%f",&a,&s,&b);

	Calculators(a,s,b);
	return 0;
}