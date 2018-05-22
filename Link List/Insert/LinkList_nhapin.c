#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node
{
  int data; //du lieu la kieu integer
  struct Node *next; //phan next tro den node ke tiep
};

//khoi tao 1 danh sach co 3 node
struct Node* head = NULL;
struct Node* second = NULL;
struct Node* third = NULL;

//chuong trinh con
void khoitao()
{
  //cap phat vung nho cho cac node
  head = (struct Node*) malloc (sizeof (struct Node));
  second = (struct Node*) malloc (sizeof (struct Node));
  third = (struct Node*) malloc (sizeof (struct Node));

  //khai bao gia tri cho Node
  printf("Gia tri cua Node head = ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=second;

  printf("Gia tri cua Node second = ");
  fflush(stdin);
  scanf("%d",&second->data);
  second->next=third;

  printf("Gia tri cua Node third = ");
  fflush(stdin);
  scanf("%d",&third->data);
  third->next=NULL;
}

//chen 1 Node vao dau danh sach
void chendau()
{
  //khai bao bien
  struct Node* newfirstNode;
  int newfirstdata;

  printf("\nDanh sach sau khi chen 1 node vao dau:");
  //Buoc 1.khai bao vung nho cho Node can chen
  newfirstNode = (struct Node*) malloc (sizeof(struct Node));
  
  //Buoc 2. Nhap du lieu (data) cho Node
  printf("\nNhap gia tri can chen: ");
  fflush(stdin);
  scanf("%d",&newfirstdata);
  newfirstNode->data=newfirstdata;
  
  //Buoc 3. Phan next cua newfirstnode gan vao dau danh sach
  newfirstNode->next=head;

  //Buoc 4. Chuyen phan head tro sang newfirstNode
  head=newfirstNode;
}

//chuong trinh con In node
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
  //khoi tao Node
  khoitao();
  indanhsach(head);
  chendau();
  indanhsach(head);
}
