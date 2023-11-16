#include"stdio.h"

struct Node{
	int data;
	Node* left;
	Node* right;
};

typedef struct Node* node;

node makeNode(int x){
	node tmp = new Node();
	tmp -> data = x;
	tmp -> left = NULL;
	tmp -> right = NULL;
	return tmp;
}

void insert(node &a, int x){
	node tmp = makeNode(x);
	if(a == NULL){
		a = tmp;
	}else{
		if(a -> data < x){
			insert(a -> right, x);
		}else{
			if(a -> data > x){
				insert(a -> left, x);
			}
		}
	}
}
void size(node a, int x){
	if(a != NULL){
		x++;
		size(a -> left, x);
		size(a -> right, x);
	}
}
int max(node a){
	while(a -> right!= NULL){
		a = a-> right;
	}
	return a ->data;
} 

int min(node a){
	while(a -> left !=NULL){
		a = a -> left;
	}
	return a -> data;
}

int search(node a, int n){
	if(a != NULL){
		if(a -> data == n)
			return 1;
		if(a -> data < n){
			search(a->right, n);
		}else{
			search(a -> left, n);
		}
	}
}
void del(node &a, int x){
	if(a == NULL)
		return;
	//tim x trong cay
 	node truoc = NULL, sau = a;
 	while(sau != NULL && sau -> data != x){
 		truoc = sau;
 		if(sau -> data < x)
 			sau = sau -> right;
 		else sau = sau -> left;
	}
	if(sau == NULL) return;
	//del 1 nhanh
	if(sau -> right == NULL && sau -> left == NULL){
		if(truoc == NULL){
			a = NULL;
		}else{
			if(truoc -> data < x){
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
			if(truoc -> data < x)
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
				if(truoc -> data < x)
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
			if(truoc -> data < x)
				truoc -> right = sau -> right;
			else
				truoc -> left = sau -> right;
		}
	}
}

void in(node a){
	if(a!= NULL){
		printf("%d ", a -> data);
		in(a -> right);
		in(a -> left);
	}
}
int main(){
	node head = NULL;
	while(1){
		printf("-------------MENU----------\n");
		printf("1. chen phan tu vao tree\n");
		printf("2. Max tree\n");
		printf("3. Min tree\n");
		printf("4. search\n");
		printf("5. delete\n");
		printf("7. Duyet danh sach lien ket\n");
		printf("---------------------------\n");
		printf("\n nhap lua chon: ");
		int lc; scanf("%d", &lc);
		switch (lc) {
			case 1:{
					int x; printf("nhap gia tri can chen: "); scanf("%d", &x);
					insert(head, x);
					break;
			}
			 
			case 2: {
					printf("%d\n", max(head));
					break;
			}
			case 3: {
					printf("%d\n", min(head));
					break;
			}
			case 4:	int x; printf("nhap gia tri can search: "); scanf("%d", &x);
					if(search(head, x))
						printf("Yes\n");
					else printf("No\n");
					break;
			case 5:{
					int x; printf("nhap gia tri can xoa: "); scanf("%d", &x);
					del(head, x);
				   	break;
			}
			case 6: break;
			case 7:in(head); break;
			case 0:break;
			
		}
	}
}
