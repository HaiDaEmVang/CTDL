#include"stdio.h"

struct Node {
	char data;
	Node* next;
};

typedef struct Node* node;

node makeNode(char x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = NULL;
	return tmp;
}

int size(node a){
	if(a == NULL) return 0;
	int cnt = 0;
	while( a!= NULL){
		cnt++;
		a = a-> next;
	}
	return cnt;
}

int empty(node a){
	return a == NULL;
}

void insertF(node &a, char x){
	node tmp = makeNode(x);
	node p;
	if(a == NULL)
		a = tmp;
	else{
		p = a;
		while(p -> next != NULL)
			p = p -> next;
		p ->next = tmp;
	}
	
}

void in(node a){
	printf("\n----------------------\n");
	if(a == NULL) return;
	while(a != NULL){
		printf("%d ", a -> data);
		a = a-> next;
	}
	printf("\n-----------------------\n");
}


int main(){
	node head = NULL;
	while(1){
		printf("\n-------------MENU----------\n");
		printf("1. chen phan tu vao dau ds\n");
		printf("2. Duyet danh sach lien ket\n");
		printf("---------------------------\n");
		printf("\n nhap lua chon: ");
		int lc; 
		scanf("%d", &lc);
		fflush(stdin);
		switch (lc) {
			case 1:{
					char x; printf("nhap gia tri can chen: "); scanf("%c", &x);
					insertF(head, x); break;
			}
			case 2:in(head); break;
			
		}
	}
}
 




