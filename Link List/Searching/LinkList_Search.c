#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//khai bao bien
struct Node
{
  int data;
  struct Node *next; //tro sang phan tu ke tiep
};

//khoi tao gia tri cho head NODE
struct Node* head = NULL;

char ans[0];

//chuong trinh con...
void khoitao()
{
  //khai bao bien
  //cap phat vung nho cho head node
  head = (struct Node*) malloc (sizeof(struct Node));

  //khoi tao HEAD NODE
  printf("\nNhap gia tri cho head node: ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=NULL;
}

void indanhsach(struct Node* n)
{
  while(n!=NULL)
  {
    printf("%5d",n->data);
    n=n->next;//tro sang Node ke tiep
  }
}

void AddNode()
{
  //khai bao bien
  struct Node* newNode = NULL;
  
  //cap phat vung nho cho newNode
  newNode = (struct Node*) malloc (sizeof(struct Node));

  printf("\nGia tri can them: ");
  fflush(stdin);
  scanf("%d",&newNode->data);

  //chen vao dau danh sach
  newNode->next=head; //newNode tro den head
  head=newNode;
}

void lenlist()
{
   //khai bao bien
   struct Node *tamNode = NULL;

  //cap phat vung nho cho NODE TAM
  tamNode = (struct Node*) malloc (sizeof(struct Node));

  int len; //chieu dai cua danh sach
  len=0;

  //xac dinh chieu dai cua danh sach
  tamNode=head;
  while(tamNode!=NULL) //chua phai la ket thuc danh sach
  {
    tamNode=tamNode->next;//tro den Node ke tiep
    len++;
  }
  printf("\nDanh sach co do dai = %d",len);  
}


void search()
{
   //khai bao bien
   struct Node *tamNode = NULL;

  //cap phat vung nho cho NODE TAM
  tamNode = (struct Node*) malloc (sizeof(struct Node));

  int K;

  printf("\nNhap gia tri can tim: ");
  fflush(stdin);
  scanf("%d",&K);

  int count;
  count=0;

  //kiem tra Node co phai gia tri di tim? 
  tamNode=head;
  while(tamNode!=NULL && tamNode->data!=K)
  {
    tamNode=tamNode->next;//tro den Node ke tiep
    count++;
  }
    
  if(tamNode==NULL)
  {
    printf("\nKhong tim thay gia tri yeu cau!");
  }
  else
  {
    printf("\nTim thay %d tai vi tri %d cua danh sach!",K,count);    
  }
  
}


//chuong trinh chinh
int main()
{
  khoitao();
 
  printf("\nEnter de tiep tuc, N de thoat: ");
  fflush(stdin);
  gets(ans);
  while(strcmp(ans,"n")!=0)
  {
    AddNode();
    printf("\nEnter de tiep tuc, N de thoat: ");
    fflush(stdin);
    gets(ans);
  }
  printf("\nDanh sach sau khi chen la: ");
  indanhsach(head);
  
  //xac dinh do dai cua danh sach
  lenlist();

  //tim kiem
  search();  
}
