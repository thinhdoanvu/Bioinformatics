//Khoi tao 1 danh sach lien ket don va in danh sach 
#include<stdio.h>
#include<stdlib.h>

//khai bao bien
struct Node 
{
  int data;
  struct Node *next; //next la 1 con tro de tro sang Node ke tiep
};

struct Node* head = NULL; //Node thu 1 == head
struct Node* second = NULL; //Node thu 2
struct Node* third = NULL; //Node thu 3

void khoitao()
{
  //cap phat vung nho cho 3 Node
  head = (struct Node*) malloc (sizeof(struct Node));
  second = (struct Node*) malloc (sizeof(struct Node));
  third = (struct Node*) malloc (sizeof(struct Node));

  head->data = 1; //gan gia tri cho Node head
  head->next = second; // phan next tro den Node thu 2

  second->data = 2; //gan gia tri cho node thu 2
  second->next = third; //tro den node thu 3

  third->data = 3; //gan gia tri cho node thu 3
  third->next = NULL;//phan next tro NULL (ket thuc)

}

void indanhsach(struct Node* n)
{
  while(n!=NULL)
  {
    printf("%d",n->data);
    n=n->next;
  }
}

int main()
{

khoitao();
printf("\nDanh sach duoc khoi tao la: ");
indanhsach(head);
}

