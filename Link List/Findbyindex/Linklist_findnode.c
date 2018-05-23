#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node
{
  int data;
  struct Node *next; //tro den node ke tiep
};

struct Node* head = NULL; //Node head

char ans[0];

//chuong trinh con
void khoitao()
{
  //cap phat vung nho cho head node
  head = (struct Node*) malloc (sizeof(struct Node)) ;
  
  printf("\nNhap gia tri cho head node = ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=NULL;
}

void indanhsach(struct Node* n)
{
  while(n!=NULL)
  {
    printf("%5d",n->data);
    n=n->next;
  }
}

void addnode()
{
  //khai bao bien
  struct Node* newnode = NULL;
  
  //cap phat vung nho cho newnode
  newnode = (struct Node*) malloc (sizeof(struct Node));
  
  printf("\ngia tri cua node = ");
  fflush(stdin);
  scanf("%d",&newnode->data);
  
  //chen vao dau danh sach
  newnode->next=head;//tro vao dau danh sach
  head=newnode;//head=newnode
}

void findbyindex()
{
  //khai  bao bien
  int index;
  int i;
  
  struct Node* tamnode  = NULL;
  
  //cap phat vung nho cho Node tam
  tamnode = (struct Node*) malloc (sizeof(struct Node));
  
  printf("\nNhap node can tim kiem theo chi so: ");
  fflush(stdin);
  scanf("%d",&index);
  
  i=0;
  tamnode=head;//node dau tien
  while(i<index)
  {
  	i++;
  	tamnode=tamnode->next;//tro qua node ke tiep
  }
  
  //in node tam
  printf("\nNode thu %d can tim kiem la: ",index);
  printf("%d",tamnode->data);
}

//chuong trinh chinh
int main()
{
  khoitao();
   
  printf("\nBam Enter de tiep tuc, n/N de thoat: ");
  fflush(stdin);
  gets(ans);
  while(strcmp(ans,"n")!=0)
  {
  	addnode();
  	printf("\nBam Enter de tiep tuc, n/N de thoat: ");
    fflush(stdin);
    gets(ans);
  }
  
  printf("\nDanh sach Node sau khi khoi tao la:");
  indanhsach(head);
  
  findbyindex();
}
