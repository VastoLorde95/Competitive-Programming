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

int n, k, p, x, y;
vector<int> a;
vector<int> res;

int main(){
	cin >> n >> k >> p >> x >> y;
	
	for(int i = 0; i < k; i++){
		int num; cin >> num;
		a.pb(num);
	}
	
	sort(a.begin(), a.end());
	int cnt = 0;
	for(int i = 0; i < k; i++){
		if(a[i] < y) cnt++;
	}
	
	
	int median = (n+1)/2;
	
//	tr2(cnt, median);
	
	while(cnt < median-1 and a.size() < n) a.pb(1), res.pb(1), cnt++;
	while(a.size() < n) a.pb(y), res.pb(y); 
	
	
	sort(a.begin(), a.end());
//	foreach(it, a) cout << *it << " "; cout << endl;
	
	int tot = 0;
	for(int i = 0; i < n; i++) tot += a[i];
	
//	tr2(tot,x);
	
	if(tot > x or a[median-1] < y){
		cout << -1 << endl; return 0;
	}
	
	foreach(it, res) cout << *it << " " ; cout << endl;
	
	
	return 0;
}
