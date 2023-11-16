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

int size(node a){
	if(a == NULL) return 0;
	int cnt = 0;
	node tmp = a;
	do{ 
		cnt++;
		a = a -> next;
	}while(tmp -> next != a -> next); 
	return cnt;
}

int empty(node a){
	return a == NULL;
}

void insertF(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL){
		tmp -> next = tmp;
		a = tmp;
	}
	else{
		node p = a;
		do
			p = p -> next;
		while(p -> next != a);
		p -> next = tmp;
		tmp -> next = a;
		a = tmp;
	}
}
void insertL(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL) a = tmp;
	else{
		node p = a;
		do{
			p = p -> next;
		}while(p -> next != a);
		tmp -> next = a;
		p -> next = tmp;
	}
}

void insertM(node &a, int x, int k){
	int n = size(a);
	if(k< 0 || k > n+1) {
		printf("\nVi tri chen khong hop le!!");
		return;
	}
	if(a == NULL || k == 1){
		insertF(a, x);
		return;
	}
	if(k == n+1){
		insertL(a, x);
		return;
	}
	node tmp = makeNode(x);
	node p = a;
	for(int i = 1; i< k - 1; i++){
		p = p -> next;
	}
	tmp -> next = p -> next;
	p -> next = tmp;
}

void delF(node &a){
	if(a == NULL|| size(a) == 1) {
		a = NULL;
		return;
	}
	node p = a;
	do{
		p = p -> next;
	}while(p -> next != a);
	a = a -> next;
	p -> next = a;
}
void delL(node &a){
	if(a == NULL || size(a) == 1) {
		a =NULL;
		return;
	}
	node truoc = NULL, sau = a;
	do{
		truoc = sau;
		sau = sau -> next;
	}while(sau -> next != a);
	truoc -> next = a;
}

void delM(node &a, int k){
	int n = size(a);
	if(k < 0 || k > n){
		printf("\nVi tri chen ko hop le!!");
		return;
	}
	if(k == 1){
		delF(a);
		return;
	}
	if(k == n){
		delL(a);
		return;
	}
	node truoc = NULL, sau = a;
	for(int i = 1; i< k; i++){
		truoc = sau;
		sau = sau -> next;
	}
	truoc -> next = sau -> next;
}
int search(node head, int x){
	node p; 
	if(head != NULL){
		p = head;
		do{
			if(p -> data == x)
				return p;
			p = p -> next;
		}while(p != head);
	}
	return -1;
}

void delvt(node &head, int x){
	int vt = search(head, x);
	int n = size(head);
	if(vt == 1){
		
	}
}

void in(node a){
	printf("\n----------------------");
	if(a == NULL) return;
	node p = a;
	do{
		printf("%d ", a -> data);
		a = a-> next;
	}while(a -> next != p -> next);
	printf("\n-----------------------\n");
}


int main(){
	node head = NULL;
	while(1){
		printf("-------------MENU----------\n");
		printf("1. chen phan tu vao dau ds\n");
		printf("2. Chen phan tu vao coi danh sach\n");
		printf("3. Chen phan tu vao giua danh sach\n");
		printf("4. Xoa phan tu o dau danh sach\n");
		printf("5. Xoa phan tu o cuoi danh sach\n");
		printf("6. Xoa phan tu o giua danh sach\n");
		printf("7. Duyet danh sach lien ket\n");
		printf("9. size:\n");
		printf("---------------------------\n");
		printf("\n nhap lua chon: ");
		int lc; 
		scanf("%d", &lc);
		switch (lc) {
			case 1:{
					int x; printf("nhap gia tri can chen: "); scanf("%d", &x);
					insertF(head, x); break;
			}
			 
			case 2: {
					int x; printf("nhap gia tri can chen: "); scanf("%d", &x);
					insertL(head, x); break;
			}
			case 3: {
					int x, y; printf("Nhap gia tri can chen: "); scanf("%d", &x); 
					printf("Nhap vi tri can chen: "); scanf("%d", &y);
					insertM(head, x, y); break;
			}
			case 4:delF(head); break;
			case 5:delL(head); break;
			case 6: {
					int x; printf("Nhap vi tri can xoa: "); scanf("%d", &x);
					delM(head, x); break;
			}
			case 7:in(head); break;
			
		}
	}
}
 




