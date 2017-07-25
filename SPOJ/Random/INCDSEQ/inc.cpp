#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int K = 52, MOD = 5000000, N = 10001, f[52][10001], r[52][10001], INDEX = 0, seq[10001], v[10001], k, n, t, z, temp;
map <int, int> last;

int get(int *b, int indx){
    if(b == f[0]) return 1;
    int sum = 0;
    while(indx){
    	sum = (sum + b[indx] + MOD)%MOD;
    	indx -= (indx & -indx);
    }
    return sum;
}
void update(int *b, int indx, int v){
    while(indx < N){
    	b[indx] = (b[indx] + v + MOD)%MOD;
    	indx += (indx & -indx);
    }
    return;
}
int main(){
    sd2(n,k);
    
    for(int i = 0; i < n; ++i) scanf("%d", seq + i), v[i] = seq[i];
    sort(seq, seq + n);

    for(int i = 0; i < n; ++i) if(!last.count(seq[i])) last[seq[i]] = ++INDEX;

    for(int i = 0; i < n; ++i){
        z = last[v[i]];
        for(int L = 1; L <= k; ++L){
            int &x = r[L - 1][z - 1];	// The number of subsequences obtained on the previous occurence of the ith number
            t = get(f[L - 1], z - 1);	// The number obtained now
            if(t != x){					// If this is not equal, then we must modify t before updating the bit
                temp = t;
                if((t -= x) < 0) t += MOD;	
                x = temp;
                update(f[L], z, t);
            }
        }
    }
    printf("%d\n", get(f[k], N));
    return 0;
}

