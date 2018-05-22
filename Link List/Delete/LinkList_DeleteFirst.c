#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node
{
  int data;
  struct Node *next; //tro den Node ke tiep
};

struct Node* head = NULL;//khoi tao Node head
char ans[0];

//chuong trinh con
void khoitao()
{
  //khai bao bien
  //cap phat vung nho cho NODE
  head = (struct Node*) malloc (sizeof(struct Node));
  
  printf("\nNhap gia tri cho Node head= ");
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

void Addnode()
{
  //khai bao bien
  struct Node *newnode;

  //cap phat vung nho cho Node new
  newnode = (struct Node*) malloc (sizeof(struct Node));
  //chen node vao dau danh sach
  printf("\nNhap gia tri cua node moi = ");
  scanf("%d",&newnode->data);
  //gan newnode->next = head;
  newnode->next=head;
  head=newnode;
}

void Delete()
{
  //khai bao bien
  struct Node* deleteNode;
  int K;

  //cap phat vung nho cho deleteNode
  deleteNode = (struct Node*) malloc (sizeof(struct Node));

  printf("\nNhap gia tri can xoa: ");
  fflush(stdin);
  scanf("%d",&K);

  //xoa Node o dau danh sach
  if(K== head->data)
  {
    printf("\nNode can xoa nam o dau danh sach\n");
    deleteNode=head->next;
    head=deleteNode;
  }
}

//chuong trinh chinh
int main()
{
  //khoi tao NODE
  khoitao();

  //them node moi
  printf("\nBan co muon them Node? N de thoat, Enter de tiep tuc: ");
  fflush(stdin);
  gets(ans);  
  while((strcmp(ans,"n")!=0))
  {
    Addnode();
    //hoi lai de thoat
    printf("\nBan co muon them Node? N de thoat, Enter de tiep tuc: ");
    fflush(stdin);
    gets(ans);
  }
  
  //in danh sach
  printf("\nDanh sach sau khi them Node la: ");
  indanhsach(head);
  
  //Xoa Node
  Delete();
  indanhsach(head);
}
