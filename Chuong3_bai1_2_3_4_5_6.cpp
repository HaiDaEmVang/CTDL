#include"stdio.h"
#include"string.h"

struct Node{
	char  data[100];
	Node* left;
	Node* right;
};

typedef struct Node* node;

node makeNode(char x[]){
	node tmp = new Node();
	strcpy(tmp -> data , x);
	tmp -> left = NULL;
	tmp -> right = NULL;
	return tmp;
}

void insert(node &a, char x[]){
	node tmp = makeNode(x);
	if(a == NULL){
		a = tmp;
	}else{
		if(strcmp(a -> data, x)< 0){
			insert(a -> right, x);
		}else{
			if(strcmp(a -> data, x)> 0){
				insert(a -> left, x);
			}
		}
	}
}
//

//bai 2
void inNRL(node a){
	if(a!= NULL){
		printf("%s ", a -> data);
		inNRL(a -> right);
		inNRL(a -> left);
	}
}
///bai 3
void inLRN(node a){
	if(a!= NULL){
		inLRN(a -> left);
		inLRN(a -> right);
		printf("%s ", a -> data);
	}
}
//bai 4
void dem(node a, int &cnt){
	if(a != NULL){
		cnt++;
		dem(a -> right, cnt);
		dem(a -> left, cnt);
	}
} 
//bai 5
void countif(node a, int &cnt, char name[]){
	if(a != NULL){
		if(strcmp(a -> data, name) == 0)
			cnt++;
		countif(a -> right, cnt, name);
		countif(a -> left, cnt, name);
	}
}
//bai 6

void del(node &a, char x[]){
	if(a == NULL)
		return;
	//tim x trong cay
 	node truoc = NULL, sau = a;
 	while(sau != NULL && strcmp(sau -> data, x)!= 0){
 		truoc = sau;
 		if(strcmp(sau -> data, x)< 0)
 			sau = sau -> right;
 		else 
		 sau = sau -> left;
	}
	if(sau == NULL){
		return;
	}
	//del 1 nhanh
	if(sau -> right == NULL && sau -> left == NULL){
		if(truoc == NULL){
			a = NULL;
		}else{
			if(strcmp(truoc -> data, x)< 0){
				truoc -> right = NULL;
			}else truoc -> left = NULL;
		}
		return;
	}
	//del 1 la
	if(sau -> right != NULL && sau -> left == NULL){
		if(truoc == NULL){
			a = a -> right;
		}else{
			if(strcmp(truoc -> data, x)< 0)
				truoc -> right = sau -> right;
			else
				truoc -> left = sau -> right;
		}
		return;
	}else{
		if(sau -> right == NULL && sau -> left != NULL){
			if(truoc == NULL){
				a = a -> left;
			}else{
				if(strcmp(truoc -> data, x)< 0)
					truoc -> right = sau -> left;
				else truoc -> left = sau -> left;
			}
			return;
		}	
	}
	//del 2 la
	if(sau -> right != NULL && sau -> left != NULL){
		if(truoc == NULL){
			node p = sau -> right;
			while(p -> left != NULL){
				p = p -> left;
			}
			p -> left = sau -> left;
			a = sau -> right;
		}else{
			node p = sau -> right;
			while(p -> left != NULL){
				p = p -> left;
			}
			p -> left = sau -> left;
			if(strcmp(truoc -> data, x)< 0)
				truoc -> right = sau -> right;
			else
				truoc -> left = sau -> right;
		}
	}
}
int main(){
	node head = NULL;
	while(1){
		printf("\n-------------MENU----------\n");
		printf("1. chen ten vao tree\n");
		printf("2. Dem so phan tu trong cay\n");
		printf("3. Dem phan tu co dieu kien\n");
		printf("4. Xoa theo yeu cau\n");
		printf("5. In NRL\n");
		printf("6. IN LRN\n");
		printf("---------------------------\n");
		printf("\n nhap lua chon: ");
		int lc; scanf("%d", &lc);
		switch (lc) {
			case 1:{
					fflush(stdin);
					char x[100]; printf("nhap gia tri can chen: "); gets(x);
					insert(head, x);
					break;
			}
			 
			case 2: {
					int cnt = 0;
					dem(head, cnt);
					printf("\nSo phan tu: %d\n", cnt);
					break;
			}
			case 3: {
					fflush(stdin);
					char x[100]; printf("nhap vao ten can dem: "); gets(x);
					int cnt =0;
					countif(head, cnt, x);
					printf("\nSo phan tu: %d\n", cnt);
					break;
			}
			case 4:	{
					fflush(stdin);
					char x[100]; printf("nhap vao ten can dem: "); gets(x);
					del(head, x);
					printf("\nDel thanh cong\n");
					break;
			}
			case 5:{
					inNRL(head);
					printf("\nIn thanh cong\n");
					break;
			}
			case 6: {
					inLRN(head);
					printf("\nIn thanh cong\n");
					break;
			}
			case 0:break;
			
		}
	}
}
