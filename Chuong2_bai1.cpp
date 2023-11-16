#include"stdio.h"

struct Node {
	int data;
	Node* next;
};

typedef struct Node* node;

node makeNode(int x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = NULL;
	return tmp;
}

void insertF(node &a, int x){
	node tmp = makeNode(x);
	node p;
	if(a == NULL){
		a = tmp;
	}
	else{
		p = a;
		while(p -> next != NULL)
			p = p -> next;
		p -> next = tmp;
	}
}


void in(node a){
	if(a == NULL) return;
	while(a != NULL){
		printf("%d \n", a -> data);
		a = a -> next;
	}
}

int check(int x){
	return x > 0;
}

int main(){
	node head = NULL;
	while(1){
		int n;
		printf("Nhap phan tu can chen: ");
		scanf("%d", &n);
		if(check(n)){
			insertF(head, n);
			printf("\nDanh sach sau khi chen:\n");
			in(head);
		}else break;
	}
}
 




