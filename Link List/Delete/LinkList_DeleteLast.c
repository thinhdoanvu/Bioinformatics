#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node
{
  int data;
  struct Node *next; //tro den Node ke tiep
};

struct Node* head = NULL; //khai bao 1 Node co ten la head

char ans[0]; //bien tra loi cau hoi

//chuong trinh con...
void khoitao()
{
  //khai bao bien
  //cap phat vung nho cho Node
  head = (struct Node*) malloc (sizeof(struct Node));
  
  printf("\nGia tri cua head node = ");
  fflush(stdin);
  scanf("%d",&head->data);
  head->next=NULL;
  //xong head node
}

void indanhsach(struct Node* n)
{
  while(n!=NULL)
  { 
    printf("%5d",n->data);
    n=n->next; //gan sang Node ke tiep
  }
}

void Addnode()
{
  //khai bao bien
  struct Node* newnode = NULL;

  //cap phat vung nho cho newnode
  newnode = (struct Node*) malloc (sizeof(struct Node));
  
  printf("\nGia tri cua Node moi = ");
  scanf("%d",&newnode->data);
  
  //Chen vao dau danh sach
  newnode->next=head; //tro vao node head
  head=newnode;
}

void Delete()
{
  //khai bao bien
  struct Node *deleteNode = NULL;
  //su dung 1 prevNode de luu lai Node vua duyet qua
  struct Node* prevNode = NULL;
  //su dung 1 forwNode de luu lai Node ke tiep
  struct Node* forwNode = NULL;

  int K;

  //cap phat vung nho cho deleteNode
  deleteNode = (struct Node*) malloc (sizeof(struct Node));
  prevNode = (struct Node*) malloc (sizeof(struct Node));
  forwNode = (struct Node*) malloc (sizeof(struct Node));

  printf("\nNhap gia tri can xoa: ");
  scanf("%d",&K);

  if(head->data == K)
  {
    printf("\nNode can xoa nam o dau danh sach, xem bai DeleteFirst.c");
    deleteNode=head->next;
    head=deleteNode;
    //giai phong vung nho cho deleteNode
    //free(deleteNode);
  }
  else
  {
    //Khong phai Node head, gan Node can xoa = head
    deleteNode=head;

    while(deleteNode!=NULL && deleteNode->data!=K)
    {
      prevNode=deleteNode; // Node lien truoc
      deleteNode=deleteNode->next; // chuyen qua Node ke tiep
      forwNode=deleteNode->next; // Node lien sau
    }
    //khi ket thuc vong lap nay se: hoac la NULL (khong co de xoa) hoac la tim thay tai vi tri deleteNode->next

    if(deleteNode==NULL)
    {
      printf("\nKhong ton tai gia tri de xoa");
    }
    else
    {
      if(deleteNode->next == NULL)
      {
        printf("\nNode can xoa nam o cuoi danh sach");
        //gan prevNode->next = NULL (tro den cuoi danh sach)
        prevNode->next=NULL; 
        //giai phong vung nho cua deleteNode (Node cuoi cung)
        free(deleteNode);
      }
      else
      {
        printf("\nNode can xoa nam o giua danh sach");
        //gan prevNode->next = deleteNode
        prevNode->next=forwNode;
        //giai phong vung nho deleteNode
        free(deleteNode);
      }
    }
  }
}

//chuong trinh chinh
int main()
{
  //khoi tao
  khoitao();

  printf("\nBam Enter de tiep tuc, N de thoat: ");
  fflush(stdin);
  gets(ans);
  //kiem tra bien tra loi
  while(strcmp(ans,"n")!=0)
  {
    Addnode();
    printf("\nBam Enter de tiep tuc, N de thoat: ");
    fflush(stdin);
    gets(ans);
  }
  printf("\nDanh sach sau khi them Node la: ");
  indanhsach(head);

  //xoa Node bat ky
  Delete();
  printf("\nDanh sach sau khi xoa 1 Node la: ");
  indanhsach(head);

}
