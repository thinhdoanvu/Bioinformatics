#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node
{
  int data;
  struct Node *next;
};

struct Node* head = NULL; //Khoi tao Node head = NULL
struct Node* second = NULL; //khoi tao Node second = NULL
struct Node* third = NULL; //khoi tao Node third = NULL;

//chuong trinh con
void khoitao()
{
  head = (struct Node*) malloc (sizeof (struct Node));
  second = (struct Node*) malloc (sizeof (struct Node));
  third = (struct Node*) malloc (sizeof (struct Node));

  //nhap gia tri cho cac Node
  printf("\nNhap gia tri cho Node head: ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=second;//tro den Node thu 2

  printf("\nNhap gia tri cho Node second: ");
  fflush(stdin);
  scanf("%d",&second->data);
  second->next=third;//tro den Node thu 3

  printf("\nNhap gia tri cho Node third: ");
  fflush(stdin);
  scanf("%d",&third->data);
  third->next=NULL;//tro den NULL (het danh sach)
}

void chensauhead()
{
  //khai bao bien
  struct Node* newnode;

  //khoi tao vung nho cho newnode
  newnode = (struct Node*) malloc (sizeof(struct Node));

  printf("\nNhap gia tri cho node can chen: ");
  fflush(stdin);
  scanf("%d",&newnode->data);

  //Buoc 1. Chuyen head->next tro den newnode
  head->next=newnode;
  
  //Buoc 2. newnode -> tro den second
  newnode->next=second;
}

void indanhsach(struct Node* n)
{
  while(n!=NULL)
  {
    printf("%5d",n->data);
    n=n->next;
  }
}

//chuong trinh chinh
int main()
{
  khoitao();
  printf("\nDanh sach sau khi khoi tao la: ");
  indanhsach(head);
  chensauhead();
  indanhsach(head);
}
