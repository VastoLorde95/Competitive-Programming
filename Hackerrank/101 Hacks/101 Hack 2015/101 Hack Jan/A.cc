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
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int n, a[500000], tree[4001], l[500000], m[500000], q, x, sum = 0, lo, hi, mid, ind1, ind2;

void update(int x){
	x += 2000;
	while(x <= 4000){
		tree[x] += 1;
		x += (x & -x);
	}
	return;
}

int get(int x){
	x += 2000-1;
	int res = 0;
	while(x > 0){
		res += tree[x];
		x -= (x & -x);
	}
	return res;
	
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    sd(n);
    for(int i = 0; i < n; i++){
        sd(a[i]);
        update(a[i]);
    }
    l[0] = a[0];
    m[0] = abs(a[0]);
    for(int i = 0; i < n; i++){
        l[i] = l[i-1] + a[i];
        m[i] = m[i-1] + abs(a[i]);
    }
    sd(q);
    for(int i = 0; i < q; i++){
        sd(x);
        int v1 = get(-sum);
        int v2 = get(-x-sum);
        int v3;
        if(-sum > -x-sum){
        	v3 = get(-sum) - get(-x-sum);
        }
        else{
        	v3 = get(-x-sum) - get(-sum);
        }
        cout<<-sum<<" "<<-x-sum<<endl;
        cout<<v1<<" "<<v2<<" "<<v3<<endl;
        sum += x;
        if(-sum > -x-sum){
        	cout<<l[
        }
        cout<<l[v1] 
    }
    
    
    return 0;
}

