#include <stdio.h>
void SelectionS(int A[], int N);
int Factorial (int A[], int N);
void Permutations(int A[], int N, int pe[]);
int Combineall(int A[], int N);
int plcx(int c[], int i);
int combinex(int c[], int plc, int N, int x1, int x2, int x);
int sumy(int c[], int i);
int combiney(int c[],int sum,int i,int y1,int y2,int y);
float Frequency(int c[],int i,int a);
int main()
{
	int N,i,A[45],x1,x2,y1,y2,pe[45],c[45],x=0,y=0,a=0,plc,sum,plcall;
	float fre;
	for (i=0; i<=45; i++)
	pe[i]=0;
	do
	{
	printf("Tell me how many intergers you'd like\n");
	scanf("%d", &N);
}
while (N<=4 || N>45);
do
{
for (i=N; i<N; i++)
{
	printf("tell me the numbers\n");
	scanf("%d", &A[i]);
}
}
while (A[i]<1 || A[i]>45);
do
{
	printf("Give 2 intengers\n");
	scanf("%d, %d", &x1, &x2);
}
while (0>x1 || x1>x2 || x2>5);
do
{
	printf("Give 2 intengers\n");
	scanf("%d, %d", &y1, &y2);
}
while (15>y1 || y1>y2 || y2>215);
SelectionS(A,N);
Factorial(A, N);
Permutations(A, N, pe);
plcall=Combineall(A,N);
printf("%d", &plcall);
for (i=0; i<N; i++)
{
plc= plcx(c, i);
combinex(c, plc, i, x1, x2, x);
sum=sumy(c, i);
combiney(c, sum, i, y1,y2,y);
}
for (i=0; i<N; i++)
{
printf("%d", &c[i]);
printf("%d", &x);
printf("%d", &y);
if (c[i]!=" ")
a+=1;
}
printf("%d", &a);
for (i=0; i<N; i++)
{
fre = Frequency(c, i, a);
printf("%f", &fre);
}
}

void SelectionS(int A[], int N)
{
	int k, temp,q,w;
	for (q=1; q<N; q++)
	{
		k=q;
		for (w=q+1; w<=N; w++)
		if (A[w]<A[q])
		k=w;
		temp=A[q];
		A[q]=A[w];
		A[k]=temp;
	}
}

int Factorial (int *pi, int N)
{
	int r, f=1;
	for (r=1; r<=N; r++)
	{
		f=f*r;
	}
	return f;
}

void Permutations(int A[], int N, int pe[])
{
	int z;
	for (z=0; z<N; z++)
	pe[z]=Factorial(A,N)/Factorial(A,N-5);
}

int Combineall(int A[], int N)
{
	int co[N],g,plc;
	for (g=0; g<N; g++)
	{
	co[g]=Factorial(A,N)/Factorial(A,N-5) * Factorial(A,5);
	plc+=1;
}
return plc;
}

 int plcx(int c[], int i)
{
	int l=0;
		if ((c[i]/10000) % 2 ==0 )
		l+=1;
		if ((c[i]/10000/1000)%2==0)
		l+=1;
		if ((c[i]/10000/1000/100)%2==0)
		l+=1;
		if ((c[i]/10000/1000/100/10)%2==0)
		l+=1;
		if ((c[i]/10000/1000/100/10%10)%2==0)
		l+=1;
		return l;
	}

int combinex(int c[], int plc, int i, int x1, int x2, int x)
{
	if (plc<x1 || plc>x2)
	c[i]=" ";
	else
	x+=1;
	return x;
}

int sumy(int c[], int i)
{
	int h=0;
	h=c[i]/10000+c[i]/10000/1000+c[i]/10000/1000/100+c[i]/10000/1000/100/10%10;
	return h;
}

int combiney(int c[],int sum,int i,int y1,int y2,int y)
{
	if (sum<y1 || sum>y2)
	c[i]=" ";
	else
	y+=1;
	return y;
}

float Frequency(int c[],int i,int a)
{
	int b=0,freq,n;
	for (n=5; n<=45; n++)
	{
		if (c[i]/10000==n)
		b+=1;
		if (c[i]/10000/1000==n)
		b+=1;
		if (c[i]/10000/1000/100==n)
		b+=1;
		if (c[i]/10000/1000/100/10==n)
		b+=1;
		if (c[i]/10000/1000/100/10%10==n)
		b+=1;
	}
	freq=b/5;
	return freq;
}
