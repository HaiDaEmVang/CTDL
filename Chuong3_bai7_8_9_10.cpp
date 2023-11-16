#include"stdio.h"
#include"string.h"

struct sinhvien{
	char masv[10];
	char tensv[100];
	char lop[10];
	float dtb;
};
struct Node{
	sinhvien  data;
	Node* left;
	Node* right;
};

typedef struct Node* node;

void makeSV(sinhvien &x){
	fflush(stdin);
	printf("\nNhap vao masv: ");
	gets(x.masv);
	printf("\nNhap vao Tensv: ");
	gets(x.tensv);
	printf("\nNhap vao lop cua sinh vien: ");
	gets(x.lop);
	printf("\nNhap vao diem trung binh cua sinh vien: ");
	scanf("%f", &x.dtb);
}
node makeNode(sinhvien &x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> left = NULL;
	tmp -> right = NULL;
	return tmp;
}

void insert(node &a, sinhvien x){
	node tmp = makeNode(x);
	if(a == NULL){
		a = tmp;
	}else{
		if(a -> data.dtb < x.dtb){
			insert(a -> right, x);
		}else{
			if(a -> data.dtb > x.dtb){
				insert(a -> left, x);
			}
		}
	}
}

void in(node a){
	if(a!= NULL){
		printf("\nMa sinh vien: %s ||Ten sinh vien: %s || lop sinh vien: %s || dtb: %.2f", a -> data.masv, a->data.tensv, a->data.lop, a->data.dtb);
		in(a -> right);
		in(a -> left);
	}
}

//bai 8
void countif(node a, int &cnt){
	if(a != NULL){
		if(a -> data.dtb >= 5.5)
			cnt++;
		countif(a -> right, cnt);
		countif(a -> left, cnt);
	}
} 
//bai 9
void inif(node a){
	if(a!= NULL){
		if(a -> data.dtb < 5.5){
			inif(a -> right);
		}else{
			printf("\nMa sinh vien: %s ||Ten sinh vien: %s || lop sinh vien: %s || dtb: %.2f", a -> data.masv, a->data.tensv, a->data.lop, a->data.dtb);
			inif(a -> left);
			inif(a -> right);
		}
	}
}

void del(node &a){
	if(a == NULL)
		return;
	//tim x trong cay
 	while(a != NULL && a -> data.dtb < 5){
 		a = a -> right;
	}
}
int main(){
	node head = NULL;
	while(1){
		printf("\n-------------MENU----------\n");
		printf("1. Chen sinh vien vao tree\n");
		printf("2. Dem so phan tu trong cay co dtb >= 5.5\n");
		printf("3. In sinh vien co diem trung binh >= 5.5\n");
		printf("4. Xoa sinh vien co diem trung binh <= 5.5\n");
		printf("5. In NRL\n");
		printf("---------------------------\n");
		printf("\n nhap lua chon: ");
		int lc; scanf("%d", &lc);
		switch (lc) {
			case 1:{
					sinhvien x;
					makeSV(x);
					insert(head, x);
					break;
			}
			case 2: {
					int cnt = 0;
					countif(head, cnt);
					printf("\nso phan tu trong cay co dtb >= 5.5: %d\n", cnt);
					break;
			}
			case 3: {
					inif(head);
					break;
			}
			case 4:	{
					del(head);
					break;
			}
			case 5:{
					in(head);
					printf("\nIn thanh cong\n");
					break;
			}
			
			case 0:break;
			
		}
	}
}
