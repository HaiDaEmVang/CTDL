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
typedef struct Node* node;

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
	while(a != NULL){
		cnt++;
		a = a -> next;
	}
	return cnt;
}

int empty(node a){
	return a == NULL;
}

void insertF(node &a, sinhvien  x){
	node tmp = makeNode(x);
	node p;
	if(a == NULL)
		a = tmp;
	else{
		p = a;
		while(p -> next != NULL)
			p = p -> next;
		p -> next = tmp;
		tmp -> pev = p;
	}
}

node search(node head, char clas[]){
	while(head != NULL){
		if(strcmp(head -> data.lop, clas)== 0)
			return head;
		head = head -> next;
	}
	return NULL;
}


///xoa phan tu o dau
void delWithClass(node &a, char clas[]){
	if(a == NULL) return ;
	node tmp;
	node p = search(a, clas);
	while(p != NULL){
		if(p == a){
			a = a -> next;
			if(a != NULL)
				a -> pev = NULL;
		}else{
			tmp = p -> pev;
			p = p -> next;
			if(p != NULL){
				p -> pev = tmp;
			}
			tmp -> next = p;
		}
		p = search(a, clas);
	}
}
void tach(node a, node &b, node &c){
	if(a == NULL) return;
	c = b = NULL;
	while(a != NULL){
		node p = makeNode(a -> data);
		
		if(p -> data.dtb >=5){
			insertF(b, p->data);
		}else{
			insertF(c, p -> data);
		}
		a = a -> next;
	}	
}

void in(node a){
	if(a == NULL){
		printf("\nDanh sach rong!");
		return;
	}
	printf("\n-------------------------\n");
	
	while(a != NULL){
		printf("\nMa sinh vien: %s || Ten sinh vien: %s || Lop: %s || Diemtb: %f", a ->data.msv, a->data.tensv, a->data.lop, a->data.dtb);
		a = a -> next;
	}
	printf("\n-------------------------\n");
}
void innguoc(node a){
	if(a == NULL){
		printf("\nDanh sach rong!");
		return;
	}
	printf("\n-------------------------\n");
	while(a -> next != NULL){
		a = a -> next;
	}
	while(a != NULL){
		printf("\nMa sinh vien: %s || Ten sinh vien: %s || Lop: %s || Diemtb: %f", a ->data.msv, a->data.tensv, a->data.lop, a->data.dtb);
		a = a -> pev;
	}
	printf("\n-------------------------\n");
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
 




