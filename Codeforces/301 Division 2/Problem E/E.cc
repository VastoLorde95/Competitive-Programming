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

int n, cnt;
int tree[200100];
map<int, int> m, coord;
set<int> compress;
vector<int> arr;
vector<pair<int, int> > arr2;
long long res1, res2;

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx){
    while (idx <= cnt){
        tree[idx]++;
        idx += (idx & -idx);
    }
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int a, b; sd2(a,b);
		if(m[a] == 0) m[a] = a;
		if(m[b] == 0) m[b] = b;
		swap(m[a], m[b]);
	}
	
	foreach(it, m){
		compress.insert(it->se);
	}
	
	cnt = 1;
	foreach(it, compress){
		coord[*it] = cnt++;
	}
	
	foreach(it, m){
		arr.pb(coord[it->se]);
	}
	
	for(int i = arr.size()-1; i >= 0; i--){
		res1 += read(arr[i]);
		update(arr[i]);
	}
	
	foreach(it, m){
		arr2.pb(mp(it->fi, it->se));		
	}
	
	m.clear();
	
	for(int i = 0; i < arr2.size(); i++){
		m[arr2[i].fi] = i;
	}
	
	for(int i = 0; i < arr2.size(); i++){
		res2 += abs(arr2[i].fi-arr2[i].se) - abs(m[arr2[i].se]-i);
	}
	
	tr(res1+res2);
	
	return 0;
}
