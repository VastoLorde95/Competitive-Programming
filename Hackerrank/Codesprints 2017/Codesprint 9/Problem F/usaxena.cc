#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("in.txt","r",stdin);//freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define LL signed long long int
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define rep(i,from,to) for(int i=(from);i <= (to); ++i)
#define pii pair<int,int>
#define TOT 820
vector<int> G[2*100000+5];
int take[TOT+5];
int C[TOT+5];
int A[200000+5];
pii P[200000+5];
int M[200000+5][19];
int lg[200000+5];
void process2(int N)
{
  int i, j;

//initialize M for the intervals with length 1
  for (i = 0; i < N; i++)
      M[i][0] = i+1;
//compute values from smaller to bigger intervals
  for (j = 1; 1 << j <= N; j++)
      for (i = 0; i + (1 << j) - 1 < N; i++)
          if (P[M[i][j - 1]] < P[M[i + (1 << (j - 1))][j - 1]])
              M[i][j] = M[i][j - 1];
          else
              M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
int query(int l,int r){
    l--;
    r--;
    int LOG = lg[r-l+1];
    int x = M[l][LOG];
    int y = M[r-(1<<LOG)+1][LOG];
    return min(P[x], P[y]).second * -1;
}
int sum[200000+5];
#define MAX_N 40
int tree[TOT+2][MAX_N+5];
int read(int *bit,int idx){
    int sum = 0;
    if(idx==0)
		return 0;
    while (idx > 0){
    	sum = max(sum, bit[idx]);
        idx -= (idx & -idx);
    }
    return sum;
}
void update(int *bit,int idx ,int val){
    while (idx <= MAX_N){
        bit[idx] = max(bit[idx], val);
        idx += (idx & -idx);
    }
}
int main(){
    int N;
    cin>>N;
    rep(i,1,N)cin>>A[i];
    int s = 0;
    P[1] = {0,0};
    rep(i,1,N){
        s += A[i];
        P[i+1] = {s,-i};
        sum[i] = s;
    }
    for(int i=1;i<=N+1;i*=2){
        static int p = 0;
        for(int j=i;j<2*i and j<=N+1;++j)
            lg[j] = p;
        p++;
    }
    process2(N+1);
    int l,r,j,g = 0, curl = 1,curf = 0;
    pii V[TOT+5];
    for(int i=1;i<=N;++i){
        if(A[i] > 0){
            take[A[i]] = i;
        }
        int st = 0;
        int last = 0;
        for(int s=TOT;s>=1;--s){
            if(A[i] > 0 and A[i] < s ){
                take[s] =  read(tree[s-A[i]], A[i]-1);
            }
            if(A[i] > 0)
                update(tree[s], A[i], take[s]);
            C[s] = max(C[s], take[s]);
            if(C[s] > 0 and C[s] > last)last = C[s], V[++st] = {C[s], s};
        }
        V[++st] = {0,MOD};
        V[++st] = {i,A[i]};
        sort(V+1,V+st+1);
        int cur = -MOD;
        for(int x=st-1;x>=1;x--){
            l = V[x].first+1;
            r = V[x+1].first;
            cur = max(cur, V[x+1].second);
            if(l>r)continue;
            j = query(l,r);
            int temp = sum[i] - sum[j] - cur;
            if(temp > g){
                g = temp;
                curl = i-j;
                curf = 1;
            }
            else if (g==temp){
                if(curl == i-j)curf++;
            }
        }
    }
    cout<<g<<' '<<curf;
}

