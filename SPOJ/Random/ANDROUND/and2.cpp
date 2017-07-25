#include<stdio.h>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);
#define int64  long long 
#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define F0(i,n) for (int i(0),_n(n); i < _n; ++i)
#define F1(i,n) for (int i(1),_n(n); i < =_n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()
#define PB(x) push_back(x)
// variabls
int64 const maxK=1000000000,maxN=20000;
int A[22000];
int Anew[22000];
int N,K;
int COUNT[32];
int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "rt", stdout);
	int T;sd(T);
	while(T--)
	{
		sd2(N,K);
		Fill(COUNT,0);
		F0(i,N)sd(A[i]);		
		if(K>=N/2)
		{
			int ans=A[0];
			F0(i,N)
				ans=ans&A[i];
			F0(i,N)
				printf("%d ",ans);//cout<<ans<<"";
			cout<<endl;	
			continue;
		}
		if(K==0)
		{
			F0(i,N)
				printf("%d ",A[i]);//cout<<A[i]<<" ";
			cout<<endl;	
			continue;
		}
		int ans=(1l<<32-1);
		For(i,-K,K)
		{
			int id=(N+i)%N;	
			ans=A[id]&ans;
			F0(j,32)
				if(A[id]&(1<<j))
						COUNT[j]++;
		}
		Anew[0]=ans;
		For(i,1,(N-1))
		{
			int next=(i+K)%N;	
			int prev=(N+i-K-1)%N;
			ans=0;
			F0(j,32)
			{
				if(A[prev]&(1<<j))
					COUNT[j]--;
				if(A[next]&(1<<j))
					COUNT[j]++;
				if(COUNT[j]==2*K+1)
					ans=ans|(1<<j);
			}
			Anew[i]=ans;
		}
		F0(i,N)
			printf("%d ",Anew[i]);//cout<<Anew[i]<<" ";
		cout<<endl;	
	}	
 
}
