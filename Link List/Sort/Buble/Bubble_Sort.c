#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node
{
  int data;
  struct Node* next; //tro sang phan tu ke tiep
};

struct Node* head = NULL;
char ans[0];

//chuong trinh con...
void khoitao()
{
  //cap phat vung nho cho node head
  head = (struct Node*) malloc (sizeof (struct Node)); //node head
  //nhap gia tri cho node head
  printf("\nNhap gia tri cho node head = ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=NULL;
}

void addnode()
{
  //khai bao bien
  struct Node* newNode = NULL;
  //cap phat vung nho cho newNode
  newNode = (struct Node*) malloc (sizeof(struct Node));
  printf("\nnhap gia tri cua Node = ");
  fflush(stdin);
  scanf("%d",&newNode->data);
  //chen vao dau danh sach
  newNode->next=head; //tro vao dau danh sach
  head=newNode;//thay the node head = newNode;
}

void indanhsach(struct Node* n)
{
  while(n!=NULL)
  {
    printf("%5d",n->data); 
    n=n->next; //tro sang node ke tiep
  }
}

void sapxep()
{
  //khai bao bien
  struct Node* nodetam = NULL;
  struct Node* nodep = NULL;
  struct Node* nodeq = NULL;
  //cap phat vung nho cho node tam
  nodetam= (struct Node*) malloc (sizeof(struct Node));
  nodep = (struct Node*) malloc (sizeof(struct Node));
  nodeq = (struct Node*) malloc (sizeof(struct Node));
  nodep=head;
  while(nodep!=NULL)
  {
  	nodeq=nodep->next;
  	while(nodeq!=NULL)
  	{
  		if(nodep->data > nodeq->data)
  		{
  		nodetam->data = nodep->data;
  		nodep->data = nodeq->data;
  		nodeq->data = nodetam->data;
		}
		nodeq=nodeq->next;	
	}
  	nodep=nodep->next;
  }
  indanhsach(head);
}

//chuong trinh chinh
int main()
{
  //khoi tao
  khoitao();
  printf("\nbam Enter de tiep tuc, n/N de thoat:  ");
  fflush(stdin);
  gets(ans); 
  while(strcmp(ans,"n")!=0)
  {
  	addnode();
  	printf("\nbam Enter de tiep tuc, n/N de thoat:  ");
    fflush(stdin);
    gets(ans);
  }
  //in danhsach
  printf("\nDanh sach sau khi khoi tao la:");
  indanhsach(head);
  //Sap xep
  printf("\nDanh sach sau sap xep la:\n");
  sapxep();
}
