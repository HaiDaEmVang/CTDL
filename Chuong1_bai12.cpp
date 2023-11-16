#include"stdio.h"
int ucln(int a, int b){
	if(a == b)
		return a;
	else{
		a>b ? ucln(a-b, b): ucln(b - a, a);
	}
}
int main(){
	int a, b;
	printf("\nNhap vao gia tri a va b: ");
	scanf("%d%d", &a, &b);
	printf("\nUoc chung lon nhat: %d", ucln(a, b));
}
