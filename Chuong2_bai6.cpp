#include"stdio.h"

struct Node{
	int data; ///value cua phan tu tiep theo 
	Node *next; ////cau truc tu tro luu dia chi phan tu tiep theo
};
typedef struct Node* node;

///caaps phat dong
node makeNode(int x){
	node tmp = new Node();
	tmp -> data = x; 
	tmp -> next = NULL;
	return tmp;
}

bool empty(node a){
	return a == NULL; 
}

int Size (node a){
	int cnt = 0; 
	while(a != NULL){
		cnt++;
		a = a->next;
	}
	return cnt; 
}
//// them phan tu dau tien ds lien ket don
void insertFirst(node &a, int x){
	 node tmp = makeNode(x);
	 if(a== NULL){
	 	a = tmp;
	 }else{
	 	tmp -> next = a;
	 	a = tmp;
	 }
}
/// then phan tu o cuoi
void insertLast(node &a, int x){
	node tmp = makeNode(x);
	if (a == NULL){
		a = tmp;
	}else{
		node p = a;
		while(p -> next != NULL){
			p = p -> next;
		}
		p -> next = tmp;
	}
}

void insertMiddle(node &a, int x, int pos){
	int n = Size(a);
	if(pos <= 0 || pos > n + 1){
		printf("vi tri chen k hop le\n");
	}
	if (n == 1){
		insertFirst(a, x);
		return;	
	}
	if(pos == n){
		insertLast(a, x);
		return;
	}
	node tmp = makeNode(x);
	node p = a;
	for(int i = 1; i < pos-1; i++){
		p = p->next;
	}
	tmp->next = p ->next;
	p->next = tmp;
}
//

///xoa phan tu o dau
void delFirst(node &a){
	if(a == NULL) return ;
	a = a->next;
}
///xoa cuoi
void delLast(node &a){
	if(a == NULL) return;
	node truoc= NULL, sau = a;
	while(sau -> next != NULL){
		truoc = sau;
		sau = sau->next;
	}
	if(truoc == NULL) a = NULL;
	else
		truoc->next = NULL;
}
//xoa giua

void delMiddle(node &a, int pos ){
	int n = Size(a);
	if(pos <= 0 || pos > n){
		return;
	}
	node truoc = NULL, sau = a; 
	for(int i = 1; i< pos ; i++){
		truoc = sau; 
		sau = sau -> next;
	}
	if(truoc == NULL) a = a -> next;
	else
		truoc -> next = sau ->next;
}
bool check(node a, int x){
	while(a!= NULL){
		if(a -> data == x)
			return false;
		a = a -> next;
	}
	return true;
}
void in(node a){
	printf("------------------------\n");
	
	while(a != NULL){
		printf("%d ", a->data);
		a = a -> next;
	}
	printf("\n-------------------------\n");
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
		printf("---------------------------\n");
		printf("\n nhap lua chon: ");
		int lc; scanf("%d", &lc);
		switch (lc) {
			case 1:{
					int x; printf("nhap gia tri can chen: "); scanf("%d", &x);
					if(check(head, x))
						insertFirst(head, x);
					else
						printf("\nPhan tu da ton tai trong ds\n");
					break;
			}
			 
			case 2: {
					int x; printf("nhap gia tri can chen: "); scanf("%d", &x);
					if(check(head, x))
						insertLast(head, x);
					else
						printf("\nPhan tu da ton tai trong ds\n"); 
					break;
			}
			case 3: {
					int x, y; printf("Nhap gia tri can chen: "); scanf("%d", &x);
					printf("Nhap vi tri can chen: ");scanf("%d", &y);
					if(check(head, x))
						insertMiddle(head, x, y); 
					else
						printf("\nPhan tu da ton tai trong ds\n");
					break;
			}
			case 4:delFirst(head); break;
			case 5:delLast(head); break;
			case 6: {
					int x; printf("Nhap vi tri can xoa: "); scanf("%d", &x);
					delMiddle(head, x); break;
			}
			case 7:in(head); break;
			case 0:break;
			
		}
	}
}
