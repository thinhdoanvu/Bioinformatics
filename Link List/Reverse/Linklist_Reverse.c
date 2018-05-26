#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node
{
  int data;
  struct Node *next;
};

struct Node* head = NULL;

//chuong trinh con
void khoitao()
{
  //cap phat vung nho cho head
  head = (struct Node*) malloc (sizeof(struct Node));
  
  printf("\nNhap gia tri cua node head = ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=NULL;
}

void indanhsach(struct Node* n)
{
  while (n!=NULL)
  {
    printf("%5d",n->data);
    n=n->next;
  }
}

void addnode()
{
  struct Node* newnode = NULL;
  
  //cap phat vug nho cho newnode
  newnode = (struct Node*) malloc (sizeof(struct Node)) ;
  
  printf("Gia tri cua node = ");
  fflush(stdin);
  scanf("%d",&newnode->data);
  //chen vao dau danh sach
  newnode->next=head;//gan vao head
  head=newnode;
}

void nhapdanhsach()
{
  char ans[0];
  
  printf("\nEnter de nhap, (n/N) de thoat: ");
  fflush(stdin);
  gets(ans);
  
  while(strcmp(ans,"n")!=0)
  {
  	addnode();
	printf("\nEnter de nhap, (n/N) de thoat: ");
    fflush(stdin);
    gets(ans);
  };
}

void inthutunhap()
{
  //khai ba bien
  struct Node* prev = NULL;
  struct Node* curr = NULL;
  struct Node* next = NULL;
  
  //cap phat vung nho cho NODE
  prev = (struct Node*) malloc (sizeof(struct Node));
  curr = (struct Node*) malloc (sizeof(struct Node));
  next = (struct Node*) malloc (sizeof(struct Node));
  
  prev=NULL;
  curr=head;
  next=NULL;
  
  while(curr!=NULL)
  {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  head=prev;
  
  //in danh sach
  indanhsach(head);
}

//chuong trinh chinh
int main()
{
  khoitao();
  nhapdanhsach();
  //indanhsach(head);
  printf("\nDanh sach sau khi nhap la:");
  inthutunhap();
  
}
