#include <bits/stdc++.h>

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second

typedef long long LL;

using namespace std;

const int MOD = 1e9+7;
const int SIZE = 100500;
const int SEG_SIZE = 500;
const int REG_SIZE = SIZE / SEG_SIZE;
int a[SIZE];
LL seg_sum[REG_SIZE];
int seg_cnt[REG_SIZE][SIZE],L[SIZE],R[SIZE];
LL seg_sum2[REG_SIZE],b[SIZE];
LL tmp[SIZE];

LL get2(int x){
    if(x<0)return 0;
    x++;
    LL res=0;
    if(x/SEG_SIZE>0)res+=seg_sum2[x/SEG_SIZE-1];
    if(x%SEG_SIZE)res+=b[x-1];
    return res;
}

LL get(int x){
    if(x<0)return 0;
    x++;
    LL res=0;
    for(int i=x/SEG_SIZE-1;i>=0;i--)res+=seg_sum[i];
    while(x%SEG_SIZE){
        x--;
        res+=get2(R[x])-get2(L[x]-1);
    }
    return res;
}

int main(){
    DRI(N);
    REP(i,N)
        RI(a[i]);
    REP(i,N){
        RII(L[i],R[i]);
        L[i]--;
        R[i]--;
    }
    int it=0;
    while(it*SEG_SIZE<N){
        int ll=it*SEG_SIZE;
        int rr=min((it+1)*SEG_SIZE,N);
        MS0(tmp);
        REPP(i,ll,rr){
            tmp[L[i]]++;
            tmp[R[i]+1]--;
        }
        REP(i,N){
            if(i)tmp[i]+=tmp[i-1];
            seg_sum[it]+=tmp[i]*a[i];
            seg_cnt[it][i]=tmp[i];
        }
        it++;
    }
    REP(i,N){
        seg_sum2[i/SEG_SIZE]+=a[i];
        if(i%SEG_SIZE)b[i]=b[i-1]+a[i];
        else b[i]=a[i];
    }
    for(int i=1;i*SEG_SIZE<N;i++)seg_sum2[i]+=seg_sum2[i-1];
    DRI(Q);
    while(Q--){
        DRI(ty);
        if(ty==1){
            DRII(x,y);
            x--;
            LL dif=y-a[x];
            a[x]=y;
            REP(i,REG_SIZE){
                seg_sum[i]+=(LL)dif*seg_cnt[i][x];
            }
            it=x;
            b[it]+=dif;
            for(it++;it%SEG_SIZE;it++)b[it]+=dif;
 
            for(it=x/SEG_SIZE;it*SEG_SIZE<N;it++)seg_sum2[it]+=dif;
            a[x]=y;
        }
        else{
            DRII(m,n);
            m--;n--;
            printf("%llu\n",(unsigned long long)(get(n)-get(m-1)));
        }
    }
    return 0;
}
