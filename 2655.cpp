#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

unsigned long long int vet[MAXN];
unsigned long long int st[4*MAXN];


void build(int no,int l,int r)
{
	if(l == r)
	{
		st [no] = vet[l];
		return;
	}
	int noL = 2*no, noR = 2*no+1;
	int mid = (l+r)/2;
	build(noL, l, mid);
	build(noR, mid+1, r);
	st[no] = st[noL] | st[noR];
}

void update(int no , int l, int r, int pos, unsigned long long int valor)
{
	if(pos < l || pos > r )return;
	if(l == r)
	{
		st[no] = valor; 
		return;
	}
	
	int noL = 2*no, noR = 2*no+1;
	update(noL , l , (l+r)/2 , pos , valor );
	update(noR , (l+r)/2+1 , r, pos , valor );
	st[no] = st[noL] | st[noR];
}

unsigned long long int Find(int no, int ini , int fim, int l ,int r)
{
	if(r < ini || l > fim)return 0;
	if(l >= ini && r <= fim)return st[no];
	
	int noL = 2*no, noR = 2*+1;
	int meio = (l+r)/2;
	return Find(noL,ini,fim,l,meio) | Find(noR,ini,fim,meio+1,r);
}

int main()
{
	int A,B,C;
	int Ch,Aux,Aux1;
	int AUX;
	
	scanf("%d %d %d",&A,&B,&C);
	
	for (int i = 0; i < A; i++)
	{
		scanf("%d",&AUX);
		vet[i] = 1LL<<(AUX-1);
	}
	for (int i = 0; i < B; i++)
	{
		scanf("%d %d %d",&Ch,&Aux,&Aux1);
		if(Ch == 1)
		{
			unsigned long long int A = __builtin_popcountll(  Find(1,Aux-1,Aux1-1,0 , B-1 ) );
			printf("%lld\n",A);
		
		}
		else update(1,0,B-1,Aux-1,1LL<<(Aux1-1));
	}
}
