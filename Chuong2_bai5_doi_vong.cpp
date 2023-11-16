#include"stdio.h"
#include"string.h"

struct sinhvien{
	char msv[20];
	char tensv[50];
	char lop[5];
	float dtb;
};
struct Node {
	sinhvien data;
	Node* next;
	Node* pev;
};

typedef struct Node* node;

void makeSV(sinhvien &x){
	fflush(stdin);
	printf("\nNhap vao ma sinh vien: ");
	gets(x.msv);
	printf("\nNhap vao ten sinh vien: ");
	gets(x.tensv);
	printf("\nNhap vao lop cua sinh vien: ");
	gets(x.lop);
	printf("\nNhap vao diem tb: ");
	scanf("%f", &x.dtb);
}
node makeNode(sinhvien x){
	node tmp = new Node();
	tmp -> data = x; 
	tmp -> next = NULL;
	tmp -> pev = NULL;
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

int empty(node  a){
	return a == NULL;
}

void insertF(node &a, sinhvien x){
	node tmp = makeNode(x);
	if(a == NULL){
		tmp -> next = tmp;
		tmp -> pev = tmp;
		a = tmp;
	}
	else{
		node p = a -> pev;
		p -> next = tmp;
		tmp -> pev = p;
		tmp -> next = a;
		a -> pev = tmp;
		a = tmp;
	}
}

node search(node head, char clas[]){
	node p;
	if(head!= NULL){
		p = head;
		do{
			if(strcmp(p -> data.lop, clas) == 0)
				return p;
			p = p -> next;
		}while(p != head);
	}
	return NULL;
}
void delF(node &head){
	node p;
	if(head == NULL || size(head) == 1)
		head = NULL;
	else{
		p = head -> pev;
		head = head -> next;
		p -> next = head;
		head -> pev = p;
	}
}
void delWithClass(node &a, char clas[]){
	if(a == NULL) return ;
	node tmp;
	node p;
	p = search(a, clas);
	while(p != NULL){
		if(p == a)
			delF(a);
		else{
			tmp = p -> pev;
			p = p -> next;
			tmp -> next = p;
			p -> pev = tmp;
		}
		 p = search(a, clas);
	}
}
void tach(node a, node &b, node &c){
	if(a == NULL) return;
	c = b = NULL;
	int n = size(a);
	for(int i = 1; i<= n; i++){
		node p = makeNode(a -> data);
		
		if(p -> data.dtb >=5){
			insertF(b, p -> data);
		}else{
			insertF(c, p -> data);
		}
		a = a-> next;
	}	
}

void in(node a){
	if(a == NULL) {
		printf("\nDanh sach rong");
		return;
	}
	printf("\n----------------------");

	node p = a;
	do{
		printf("\nMa sinh vien: %s || Ten sinh vien: %s || Lop: %s || Diemtb: %f", a ->data.msv, a->data.tensv, a->data.lop, a->data.dtb);
		a = a-> next;
	}while(a -> next != p -> next);
	printf("\n-----------------------\n");
}

int main(){
	node head = NULL;
	while(1){
		printf("-------------MENU----------\n");
		printf("1. chen phan tu vao dau ds\n");
		printf("2. Duyet danh sach lien ket\n");
		printf("3. Xoa phan tu\n");
		printf("4. Tach danh sach\n");
		printf("5. Duyet nguoc danh sach b >= 5.5\n");
		printf("6. Duyet nguoc danh sach c < 5.5\n");
		printf("---------------------------\n");
		printf("\n nhap lua chon: ");
		int lc; 
		node c, b;
		scanf("%d", &lc);
		switch (lc) {
			case 1:{
					sinhvien x;
					makeSV(x);
					insertF(head, x); 
					printf("\nInsert thanh cong\n");
					break;
			}
			case 2: {
					in(head);
					printf("\nIn danh sach thanh cong\n");
					break; 
			}
			case 3: {
					char clas[100];
					printf("\nNhap vao ten lop can xoa: ");
					fflush(stdin);
					gets(clas);
					delWithClass(head, clas);
					printf("\nDa xoa thanh cong chon 2 de xem ds!!\n");
					break;
			}
			case 4:tach(head, b, c);
					printf("\nTach thanh cong\n");
					break;
			case 5:{
					in(b);
					printf("\nIn danh sach thanh cong\n");
					break;
			}
			case 6: {
					in(c);
					printf("\nIn danh sach thanh cong\n");
					break;
			}
		}
	}
}
 




