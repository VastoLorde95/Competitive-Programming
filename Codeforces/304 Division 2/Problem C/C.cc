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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, k1, k2, mx, x, flag = 1;
queue<int> m1, m2;



int main(){
	cin >> n;
	cin >> k1;
	
	for(int i = 0; i < k1; i++){
		cin >> x;
		m1.push(x);
		mx = max(mx, x);
	}
	
	cin >> k2;
	
	for(int i = 0; i < k2; i++){
		cin >> x;
		m2.push(x);
		if(x > mx){
			mx = x;
			flag = 2;
		}	
	}
	
	int v1, v2;	
		
	for(int i = 1; i <= 10000000; i++){
		
		if(m1.size() == 0 or m2.size() == 0){
			cout << i-1 << " " << flag << endl;
			return 0;
		}
		
		v1 = m1.front(); m1.pop();
		v2 = m2.front(); m2.pop();
		
		if(v1 > v2){
			m1.push(v2);
			m1.push(v1);
		}
		else{
			m2.push(v1);
			m2.push(v2);
		}
		
	}
	
	
	cout << -1 << endl;
	
	return 0;
}
