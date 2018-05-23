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

void swap()
{
  //khai bao bien
  int X;
  int Y;
  
  struct Node* nodetam = NULL;
  struct Node* nodesearch = NULL;
  struct Node* nodereplace = NULL;
  
  //cap phat vung nho cho node tam
  nodetam= (struct Node*) malloc (sizeof(struct Node));
  nodesearch = (struct Node*) malloc (sizeof(struct Node));
  nodereplace = (struct Node*) malloc (sizeof(struct Node));
  
  //Buoc 1. tim kiem gia tri can thay the
  printf("\nNhap gia tri cua Node search: X= ");
  fflush(stdin);
  scanf("%d",&X);
  nodetam=head;
  while(nodetam!=NULL && nodetam->data != X)
  {
  	nodetam=nodetam->next;
  }
  if(nodetam==NULL)
  {
    printf("\nKhong tim thay Node co gia tri %d",X);
  }
  else
  {
	nodesearch = nodetam;
	//Buoc 2. tim kiem gia tri thay the boi
    printf("\nNhap gia tri cua Node replace: Y= ");
    fflush(stdin);
    scanf("%d",&Y);
    nodetam=head;
    while(nodetam!=NULL && nodetam->data != Y)
    {
  	  nodetam=nodetam->next;
    }
    if(nodetam==NULL)
    {
      printf("\nKhong tim thay Node co gia tri %d",Y);
    }
    else
    {
	  nodereplace = nodetam;
	  //Buoc 3. Doi cho 2 Node cho nhau
	  nodesearch->data=Y;
	  nodereplace->data=X;
    }
  }
  
  printf("\nDanh sach sau khi hoan vi 2 gia tri %d va %d la: \n",X,Y);
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
  
  //tim kiem va thay the
  swap();
}
