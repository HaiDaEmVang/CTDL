#include"stdio.h"
struct ptu{
	int coso;
	int mu;
};
struct Node{
	ptu data;
	Node *next;
};

typedef Node* node;

node makeNode(ptu x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = NULL;
	return tmp;
}

ptu makePtu(int x, int y){
	ptu a;
	a.coso = x;
	a.mu = y;
	return a;
}
node insertfifo(node head, ptu x){
	node tmp = makeNode(x);
	node p;
	if(head == NULL)
		return tmp;
	p = head;
	while(p -> next != NULL)
		p = p -> next;
	p -> next = tmp;
	return head;
}

void prin(node head){
	node tmp = head;
	while(tmp -> next != NULL){
		printf("%dX^%d + ", tmp ->data.coso, tmp -> data.mu);
		tmp = tmp -> next;
	}
	printf("%dX^%d", tmp ->data.coso, tmp -> data.mu);
}
int main(){
	node head;
	head = NULL;
	
	while(1){
		printf("1. nhap");
		printf("\n2. in");
		
		int luachon;
		scanf("%d", &luachon);
		switch(luachon){
			case 1: {
				printf("\nNhap vao co so va mu: ");
				int x, y;
				scanf("%d%d", &x, &y);
				ptu a;
				a = makePtu(x, y);
				head = insertfifo(head, a);
				break;
			}
			case 2:{
				prin(head);
				break;
			}
				
		}
	}
	
}
