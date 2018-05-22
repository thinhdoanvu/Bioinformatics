#include<stdio.h>
#include<stdlib.h>
//khai bao bien
struct Node
{
  int data;
  struct Node *next;//con tro tro den phan tu ke tiep
};

//khoi tao cac Node
struct Node* head = NULL; //Node head
struct Node* second = NULL;//Node second
struct Node* third  = NULL;//Node third

//chuong trinh con
void khoitao()
{
  //khai bao bien
  //cap phat vung nho cho cac NODE
  head=(struct Node*) malloc (sizeof(struct Node));
  second=(struct Node*) malloc (sizeof(struct Node));
  third=(struct Node*) malloc (sizeof(struct Node));  

  //gan gia tri cho cac Node
  printf("\nGia tri cua Node head = ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=second;//tro den Node 2
  
  printf("\nGia tri cua Node second = ");
  fflush(stdin);
  scanf("%d",&second->data);
  second->next=third;//tro den Node 3

  printf("\nGia tri cua Node third = ");
  fflush(stdin);
  scanf("%d",&third->data);
  third->next=NULL;
}

void indanhsach(struct Node* n)
{
  while(n!=NULL)
  {
    printf("%5d",n->data);
    n=n->next;
  }
}

void chencuoi()
{
  //khai bao bien
  struct Node* newlast;
  //cap phat vung nho cho newlast Node
  newlast = (struct Node*) malloc (sizeof(struct Node));
  
  printf("\nNhap gia tri cua Node can chen: ");
  fflush(stdin);
  scanf("%d",&newlast->data);

  //Buoc 1. Gan gia tri third->next=newlast;
  third->next=newlast;

  //Buoc 2. Gan newlast->next=NULL
  newlast->next=NULL;
}

//chuong trinh chinh
int main()
{
  khoitao();
  printf("\nDanh sach vua nhap la:");
  indanhsach(head);
  chencuoi();
  printf("\nDanh sach sau khi chen vao cuoi la: ");
  indanhsach(head);
}
