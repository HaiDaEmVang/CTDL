#include"stdio.h"
#include"string.h"
#include <stdlib.h>
struct hang{
	char tenhang[100];
	int soluong;
};
struct Node{
	hang data;
	Node* next;
};
typedef Node* node;
//ham tao 1 nut de luu du lieu vao ds 
node makeNode(hang x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> next = NULL;
	return tmp;
}
//ham tao 1 mat hang
hang makeHang(){
	fflush(stdin);
	hang tmp;
	printf("Nhap vao ten hang: ");
	gets(tmp.tenhang);
	do{
		printf("Nhap vao so luong (>0): ");
		scanf("%d", &tmp.soluong);
	}while(tmp.soluong<=0);
	return tmp;
}

//kiem tra phan tu co ton tai tron danh sach hay khong
node checkNode(node head, char nameHang[]){
	
	//kiem tra hang neu co trong danh sach thi tra ve dia chi cua node do
	while(head != NULL){
		if(strcmp(head->data.tenhang, nameHang) == 0)
			return head;
		head = head -> next;
	}
	
	//tra ve null khi khong tim thay
	return NULL;
}


//them mat hang x vao danh sach hang
node insertNode(node head, hang x){
	node tmp = makeNode(x);
	node p;
	
	///chen phan tu dau neu ds ban dau rong
	if(head == NULL)
		return tmp;
		
	//tim kiem phan tu x trong danh sach kho
	p = checkNode(head, x.tenhang);
	
	//kiem tra neu da ton tai thi tang so luong nguoc lai thi them hang vao kho
	if(p != NULL){
		p->data.soluong+= x.soluong;
	}else{
		p = head;
		while(p -> next != NULL)
			p = p-> next;
		p -> next = tmp;
	}
	return head;
}

//in thong tin hang trong kho
void print(node head){
	if(head == NULL){
		printf("\nDanh sach rong!!");
		return;
	}else{
		printf("   ten mat hang  ||  soluong   ||\n");
		while(head!= NULL){
			printf("%16s ||%11d ||\n", head->data.tenhang, head->data.soluong);
			head = head -> next;
		}
	}
}

//xoa hang x khoi kho
node delNode(node head, hang x){
	node tmp, p;
	tmp =checkNode(head, x.tenhang);
	
	///xoa phan tu dung dau can xoa
	if(tmp == head)
		return head -> next;
	
	//xoa phan tu dung sau
	if(tmp != NULL){
		p = head;
		while(p ->next != tmp)
			p  = p-> next;
		p -> next = tmp -> next;
	}
	return head;
}

//xuat nhung mat hang da duoc ban di
void xuat(node &head, hang x){
	node p;
	p = checkNode(head, x.tenhang);
	
	if(p!=NULL){
		
		///xoa hang khoi kho neu so luong xuat = so luong hang trong kho
		if(x.soluong == p->data.soluong){
			head = delNode(head, x);
			printf("\nxuat thanh cong mat hang\n ");
			return;
		}
		
		///giam so luong hang trong kho khi so luong xuat < so luong hang trong kho
		if(x.soluong < p->data.soluong){
			p ->data.soluong-= x.soluong;
			printf("\nxuat thanh cong mat hang\n ");
		}else printf("\nSo luong khong du de xuat\n");
	}else printf("\nKhong tim thay hang trong kho de xuat\n");
		
}

//trao doi giua 2 mat hang
void swap(hang &a, hang &b){
	hang c = a;
	a = b;
	b = c;
}

//sap xep danh sach hang theo so luong tang dan
void sort(node &head){
	for(node i = head; i->next!= NULL; i = i -> next){
		node k = i ;
		for(node j = i-> next; j!= NULL; j= j -> next){
			if(k->data.soluong < j->data.soluong)
				k = j;
		}
		swap(i->data, k->data);
	}
}

//xoa man hinh cmd
void cls(){
	printf("\nNhan enter de tiep tuc\n");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
	fflush(stdin);
}

//menu
void menu(node &head){
	bool flag = false;
	
	while(1){
		printf("\n================menu============");
		printf("\n1. Nhap thong tin kho");
		printf("\n2. xuat thong tin kho");
		printf("\n3. them hang vao danh sach hang");
		printf("\n4. xuat hang khoi danh sach hang");
		printf("\n5. sap xep hang");
		printf("\n6. kiem tra hang");
		printf("\n*. Nhan phim bat ki de thoat");
		printf("\n==================================\n");
		
		int lc;
		int n;
		printf("Nhap vao lua chon: ");
		scanf("%d", &lc);
		switch(lc){
			case 1:{
				printf("\nso luong hang can dien: ");
				scanf("%d", &n);
				for(int i = 0;i< n;i++){
					hang tmp = makeHang();
					head = insertNode(head, tmp);
				}
				printf("Tac vu thanh cong!!!\n");
				break;
			}
			case 2: {
				print(head);
				printf("Tac vu thanh cong!!!\n");
				
				break;
			}
			case 3:{
				hang tmp = makeHang();
				head = insertNode(head, tmp);
				printf("Tac vu thanh cong!!!\n");
				break;
			}
			case 4:{
				printf("\nDanh sach hang con trong kho:\n");
				print(head);
				printf("\n\nNhap so lung hang ban can xuat ban: ");
				scanf("%d", &n);
				for(int i = 0;i< n; i++){
					printf("\nMat hang thu %d can xuat \n", i+1);
					hang tmp = makeHang();
					xuat(head, tmp);
				}
				printf("\nHang con trong kho: \n");
				print(head);
				printf("Tac vu thanh cong!!!\n");
				break;
			}
			case 5:{
				sort(head);
				print(head);
				printf("Tac vu thanh cong!!!\n");
				break;
			}
			case 6:{
				fflush(stdin);
				printf("\nNhap vao hang can kiem tra: ");
				char name[100];
				gets(name);
				if(checkNode(head, name)!= NULL){
					printf("\nTon tai trong danh sach\n");
				}else
					printf("\nkHong ton tai trong danh sach\n");
				printf("Tac vu thanh cong!!!\n");
				break;
			}
			case 7:{
				flag = true;
				break;
			}
		}
		//goi ham xoa cmd
		cls();
		
		//thoat vong while ket thuc chuong tring
		if(flag)
			break;
	}
}

int main(){
	node head = NULL;
	menu(head);
}
