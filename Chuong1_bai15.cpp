#include"stdio.h"
int fibonaci(int a){
	if(a == 0 || a == 1)
		return a;
	else{
		return fibonaci(a -1) + fibonaci(a -2);
	}
}

int main(){
	int a;
	printf("\nNhap vao gia tri nguyen: ");
	scanf("%d", &a);
	printf("\nPibonaci thu n: %d", fibonaci(a));
}
