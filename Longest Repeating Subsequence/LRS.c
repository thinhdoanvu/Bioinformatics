#include<stdio.h>
#include<string.h>

//khai bao bien dat o day
char X[255];//chuoi X
char Y[255];//chuoi Y
int C[255][255];//mang C dung de tim Max
int B[255][255];//mang B dung de luu vet (so phan tu cua mang B = X*Y)

int m;//chieu dai cua choi X
int n;//chieu dai cua chuoi Y

//chuong trinh con
void nhapdulieu()
{
  //khai bao bien dat o day
  
  printf("Nhap du lieu cho chuoi X:\n");
  fflush(stdin);
  gets(X);
  
  //printf("\nNhap du lieu cho chuoi Y:\n");
  //fflush(stdin);
  //gets(Y); 
  //khoi tao chuoi Y
  int i;
  for(i=0;i<strlen(X);i++)
  {
    Y[i]=X[i];
  }
  //printf("%s",Y);
}

//tim max cua 2 so a va b
int max(int a, int b)
{
  if(a>b)
  {
  	return a;
  }
  else
  {
  	return b;
  }
}

//khoi tao 2 mang C(ma tran trong so) va B(luu vet)
void khoitao()
{
  //khai bao bien
  int i;
  int j;

  //tao ra ma tran B va C co so phan tu m+1 hang va n+1 cot  
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      C[i][j]=0;
      B[i][j]=0;
    }
  }
}

//in ra ma tran B va C
void inmatran()
{
  //khai bao bien
  int i;
  int j;
  
  //in ma tran trong so
  printf("\nMa tran trong so:\n");
  for(i=0;i<=m;i++)
  {
  	for(j=0;j<=n;j++)
  	{
      printf("%d",C[i][j]);
    }
    printf("\n");
  }

  //in ma tran luu vet
  printf("\nMa tran luu vet:\n");
  for(i=0;i<=m;i++)
  {
  	for(j=0;j<=n;j++)
  	{
      printf("%d",B[i][j]);
    }
    printf("\n");
  }
}

//in ra danh sach cua mang C
void LCS()
{
  //khai bao bien
  int i;
  int j;
  
  m=strlen(X);
  printf("\nChuoi %s co do dai = %d",X,m);
  n=strlen(Y);
  //printf("\nChuoi %s co do dai = %d",Y,n);
  
  //Xay dung bang de tim MAX
  //khoi tao ma tran B va C
  //chen them 1 cot theta va gan gia tri bang 0
  
  for(i=0;i<m;i++)
  {
  	 for(j=0;j<n;j++)
  	 {
  		  if(X[i]==Y[j] && i!=j)
  		  {
        C[i+1][j+1]=C[i][j]+1;
		      B[i+1][j+1]=0;//phan tu ve phia tren ben trai (cheo)
		    }
	  	  else
		    {
        if((X[i]==Y[j] && i==j) || C[i+1][j]>=C[i][j+1])
        {
          C[i+1][j+1]=C[i+1][j];
          B[i+1][j+1]=1;//gan phan tu ben trai
        }
        else
        {
          C[i+1][j+1]=C[i][j+1];
          B[i+1][j+1]=2;//gan phan tu ben tren
        }
		    }
	   }
  }
  //in ra ma tran B va C
  inmatran();
}

//in ra chuoi chung co do dai lon nhat
void inketquaMAX()
{
  //khai bao bien
  int i;
  int j;
  int MAX;

  //tim max
  MAX=C[0][0];

  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      if(MAX<max(MAX,C[i][j]))
      {
        MAX=C[i][j];
      }
    }
  }
  printf("\nChuoi lap lai dai nhat la: %d",MAX);
}

//in ra chuoi tim duoc
void inchuoiketqua()
{
  //khai bao bien
  int i;
  int j;

  char tam[10]; //chuoi dung de luu ket qua
  int itam; 
 
  i=m;
  j=n;
  itam=0;
 
  printf("\nChuoi tim duoc la: ");

  while(i>0 && j>0)
  {
    //in ra nhung vi tri match voi nhau (B[i][j]=0)
    if(B[i][j]==0)
    {
      //printf("%c",X[i-1]);//hoac Y[j-1];in nhu the nay se ra chuoi bi nguoc
      tam[itam]=X[i-1];
      itam++;
      i--;
      j--;
    }
    else
    {
       //nhung vi tri duoc tinh toan tu ben trai (B[i][j]=1)
      if(B[i][j]==1)
      {
        j--;
      }
      else
      {
        //nhung vi tri duoc tinh toan tu ben tren (B[i][j]=2)
       i--;
      }
    }
  }
  //in ra chuoi ket qua thuan chieu
  for (i=itam-1;i>=0; i--)
  {
    printf("%c",tam[i]);
  }
}

//chuong trinh chinh
int main()
{
  nhapdulieu();
  khoitao();
  LCS();
  inketquaMAX();
  inchuoiketqua();
}

//https://www.tutorialspoint.com//design_and_analysis_of_algorithms/design_and_analysis_of_algorithms_longest_common_subsequence.htm
//http://www-igm.univ-mlv.fr/~lecroq/seqcomp/node4.html
//https://www.geeksforgeeks.org/longest-common-subsequence/
//https://www.ics.uci.edu/~eppstein/161/960229.html
//https://github.com/thinhdoanvu/Bioinformatics
