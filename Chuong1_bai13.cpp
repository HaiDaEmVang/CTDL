#include"stdio.h"
int ucln(int a, int b){
	if(a %b ==0)
		return b;
	else 
		return ucln(b, a%b);
}
int ucln1(int a, int b){
	if(a == b)
		return a;
	else{
		if(a> b)
			return ucln1(a-b, b);
		else
			return ucln1(a, b-a);
	}
}
int main(){
	int a, b;
	printf("\nNhap vao gia tri a va b: ");
	scanf("%d%d", &a, &b);
	printf("\nUoc chung lon nhat: %d", ucln1(a, b));
}
