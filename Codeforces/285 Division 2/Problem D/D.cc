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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n;
int p[200001], q[200001], res[200001], l1[200001], l2[200001];
int tree[1<<18];

int get(int indx){
	int cnt = 0;
	while(indx){
		cnt += tree[indx];
		indx -= (indx&(-indx));
	}
	return cnt;
}

void setit(int indx, int v){
	while(indx <= n){
		tree[indx] += v;
		indx += (indx&(-indx));
	}
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(p[i]);
	for(int i = 0; i < n; i++) sd(q[i]);
	
	for(int i = 0; i < n; i++){
		l1[i] = get(p[i]+1);
		setit(p[i]+1,1);
	}
	
	memset(tree, 0, sizeof tree);

	for(int i = 0; i < n; i++){
		l2[i] = get(q[i]+1);
		setit(q[i]+1,1);
	}
	
	memset(tree, 0, sizeof tree);
	
	for(int i = 0; i < n; i++) res[i] = (p[i]-l1[i] + q[i]-l2[i]);
	for(int i = n-2; i > 0; i--){
		if(res[i] > n-i-1){
			res[i-1] += res[i]/(n-(i-1)-1);
			res[i] %= (n-(i-1)-1);
		}
	}
	res[0] %= n;

	for(int i = 0; i < n; i++) setit(i+1, 1);
	
	for(int i = 0; i < n; i++){
		int lo = 0, hi = n-1, mid;
		while(lo < hi){
			mid = (lo+hi)/2;
			
			if(get(mid+1)-1 >= res[i]) hi = mid;
			else lo = mid+1;
		}
		
		cout << lo << " ";
		setit(lo+1, -1);
	}
	
	cout << "\n";
	return 0;
}
