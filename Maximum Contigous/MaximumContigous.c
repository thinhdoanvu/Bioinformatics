#include<stdio.h>

//khai bao bien dat o day
int N;
int A[10];

//chuong trinh con nhap mang
void nhapmang()
{
  int i;
  
  printf("Nhap so phan tu cua mang: ");
  scanf("%d",&N);
  
  for(i=0;i<N;i++)
  {
  	printf("A[%d]= ",i);
  	//fflush(stdin);
  	scanf("%d",&A[i]);
  }
}

//chuong trinh con in mang
void inmang()
{
  //khai bao bien
  int i;
  
  printf("\nMang sau khi nahap la:\n");
  for(i=0;i<N;i++)
  {
    printf("%5d",A[i]);
  }
}

//chuong trinh con tim day co tong lon nhat
void maxcontigous()
{
  //khai bao bien
  int i;
  int max_sum;
  int max_tam;
  
  max_tam=0;
  max_sum=0;
  
  for(i=0;i<N;i++)
  {
  	max_tam=max_tam+A[i];
  	if(max_tam < 0)
  	{
  	  max_tam=0;
	}
	if(max_sum<max_tam)
	{
	  max_sum=max_tam;
	}
	//in lai vet da duyet
	printf("\ni=%d -> max_tam=%d -> max_sum = %d\n",i,max_tam,max_sum);
  }
  //in ra gia tri max_sum
  printf("\nTong cua cac phan tu lien ke lon nhat trong day la: %d\n",max_sum);
}

//chuong trinh chinh
int main()
{
  printf("A[] = {-2, -3, 4, -1, -2, 1, 5, -3}\n");
  printf("N=8\n\n");
  nhapmang();
  inmang();
  maxcontigous();
}
