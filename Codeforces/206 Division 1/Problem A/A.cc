#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, l, r, q1, q2, w[100000], LEFT[100000], RIGHT[100000], cost = 2000000000;

int main(){
	sd(n);
	sd2(l,r);
	sd2(q1,q2);
	
	for(int i = 0; i < n; i++){
		sd(w[i]);
		LEFT[i] = l*w[i];
		RIGHT[i] = r*w[i];
	}
	
	for(int i = 1; i < n; i++){
		LEFT[i] += LEFT[i-1];
		RIGHT[n-i-1] += RIGHT[n-i];
	}
	
	cost = min(RIGHT[0] + q2*(n-1), cost);
	cost = min(LEFT[n-1] + q1*(n-1), cost);
	
	for(int i = 0; i < n; i++){
		int mul;
		if(i+1 > n-i-1) mul = q1;
		else mul = q2;		
			
		cost = min(cost, LEFT[i] + RIGHT[i+1] + max(((max(i+1, n-i-1) - min(i+1, n-i-1)-1)*mul),0) );
		
//		cout << cost << " " << LEFT[i] << " " << RIGHT[i+1] << " " << i << endl;
	}
	
	cout << cost << endl;
	
	return 0;
}
