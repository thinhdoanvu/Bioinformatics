#include<stdio.h>
#include<string.h>

//khai bao bien dat o day
char X[10];//chuoi X
char Y[10];//chuoi Y
int C[10][10];//mang C dung de tim Max
char B[10];//mang B dung de luu vet (so phan tu cua mang B = X*Y)

int m;//chieu dai cua choi X
int n;//chiue dai cua chuoi Y

//chuong trinh con
void nhapdulieu()
{
  //khai bao bien dat o day
  
  printf("Nhap du lieu cho chuoi X:\n");
  fflush(stdin);
  gets(X);
  
  printf("\nNhap du lieu cho chuoi Y:\n");
  fflush(stdin);
  gets(Y); 
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

//in ra danh sach cua mang C
void LCS()
{
  //khai bao bien
  int i;
  int j;
  
  m=strlen(X);
  printf("\nChuoi %s co do dai = %d",X,m);
  n=strlen(Y);
  printf("\nChuoi %s co do dai = %d",Y,n);
  
  //Xay dung bang de tim MAX
  //khoi tao ma tran B va C
  //chen them 1 cot theta va gan gia tri bang 0
  
  for(i=0;i<m;i++)
  {
  	for(j=0;j<n;j++)
  	{
  		printf("\nX[%d]=%c,Y[%d]=%c\n",i,X[i],j,Y[j]);
  		if(X[i]==Y[j])
  		{
		  C[i][j]=0;
		}
		else
		{
		  C[i][j]=1;
		}
	}
	
  }
  
}

void in()
{
  //khai bao bien
  int z1;
  int z2;
  
  for(z1=0;z1<m;z1++)
  {
  	for(z2=0;z2<n;z2++)
  	{
      printf("%d",C[z1][z2]);
    }
    printf("\n");
  }
}

//chuong trinh chinh
int main()
{
  nhapdulieu();
  LCS();
  in();
}

https://www.tutorialspoint.com//design_and_analysis_of_algorithms/design_and_analysis_of_algorithms_longest_common_subsequence.htm
http://www-igm.univ-mlv.fr/~lecroq/seqcomp/node4.html
https://www.geeksforgeeks.org/longest-common-subsequence/
https://www.ics.uci.edu/~eppstein/161/960229.html
https://github.com/thinhdoanvu/Bioinformatics
