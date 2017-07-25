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

int n, s1, s2, mx, x;
vector<int> t1, t2;
pair<int, int> a[100000];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(x);
		mx = max(mx, x);
		a[i] = mp(x, i);
	}
	
	sort(a, a+n);
	
	int indx = 0;
	for(int i = 0; i < n; i++){
		indx = 1-indx;
		if(indx){
			t1.pb(a[i].se);
			s1 += a[i].fi;
		}
		else{
			t2.pb(a[i].se);
			s2 += a[i].fi;
		}
	}
	
	if(abs(s1-s2) <= mx){
		cout << t1.size() << endl;
		for(int i = 0; i < t1.size(); i++)
			cout << t1[i]+1 << " ";
		cout << endl;
		cout << t2.size() << endl;
		for(int i = 0; i < t2.size(); i++)
			cout << t2[i]+1 << " ";
	}
	
	return 0;
}
