#include"stdio.h"
void  tongsonguyen(int a, int &s){
	if(a == 0 ) return;
	if(a % 2 == 0){
		s+=a%10;
		tongsonguyen(a/10, s);
	}else{
		tongsonguyen(a/10, s);
	}
}

int main(){
	int a, s = 0;
	printf("\nNhap vao gia tri nguyen: ");
	scanf("%d", &a);
	tongsonguyen(a, s);
	printf("\nTong cac chu so chan cua so nguyen: %d", s);
}
