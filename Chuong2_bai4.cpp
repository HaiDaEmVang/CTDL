#include"stdio.h"
#include"string.h"

struct sinhvien{
	char msv[20];
	char tensv[50];
	char lop[5];
	float dtb;
};

struct Node{
	sinhvien data; ///value cua phan tu tiep theo 
	Node *next; ////cau truc tu tro luu dia chi phan tu tiep theo
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
///caaps phat dong
node makeNode(sinhvien x){
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
void insertF(node &a, sinhvien x){
	 node tmp;
	 node p;
	 p = makeNode(x);
	if(a == NULL)
	 	a = p;
	else{
		tmp = a;
		while(tmp -> next != NULL)
			tmp = tmp -> next;
		tmp -> next = p;
	}
}

///xoa phan tu o dau
void delWithClass(node &a, char clas[]){
	if(a == NULL) return ;
	node truoc = NULL, sau = a;
	while(sau != NULL){
		if(strcmp(clas, sau -> data.lop)!=0){
			truoc = sau;
			sau = sau -> next;
		}else{
			if(truoc == NULL){
				a = a -> next;
				sau = a;
			}else{
				truoc -> next = sau -> next;
				sau = sau -> next;
			}
		}
	}
}
void tach(node a, node &b, node &c){
	if(a == NULL) return;
	c = b = NULL;
	while(a != NULL){
		sinhvien x;
		node p = makeNode(x);
		p -> data = a -> data;
		p -> next = NULL;
		
		if(a -> data.dtb >=5){
			if(b == NULL)
				b = p;
			else{
				p -> next = b;
				b = p;
			}
		}else{
			if(c == NULL){
				c = p;
			}else{
				p -> next = c;
				c = p;
			}
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
