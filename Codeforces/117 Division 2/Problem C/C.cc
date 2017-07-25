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
#define _ ios_base::sync_with_stdio(false);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, len, k;
int a[100100];
long long sum, mx = -1e18;
multiset<int> s1, s2;

long long compute(){
	sum = 0;
	s1.clear(), s2.clear();
	
	for(int i = 0; i < n; i++){
	
		if(a[i] > 0) sum += a[i];
		else if(a[i] < 0){
			if(k == 0){
				s2.insert(-a[i]);
				sum += a[i];
			}
			else if(s1.size() < k){
				s1.insert(-a[i]);
				sum -= a[i];
			}		
			else if(-a[i] > *s1.begin()){
				sum -= (*s1.begin())*2;
				sum -= a[i];
				
				s2.insert(*s1.begin());
				s1.erase(s1.begin());
				s1.insert(-a[i]);
			}
			else{
				s2.insert(-a[i]);
				sum += a[i];
			}
		}
		
		if(i >= len){
			if(a[i-len] >= 0) sum -= a[i-len];
			else if(s2.find(-a[i-len]) != s2.end()){
				sum -= a[i-len];
				s2.erase(s2.find(-a[i-len]));
			}
			else{
			
				s1.erase(s1.find(-a[i-len]));
				sum += a[i-len];
				if(s2.size() > 0){
					sum += 2*(*s2.rbegin());
					s1.insert(*s2.rbegin());
					s2.erase(s2.find(*s2.rbegin()));
				}
			}
		}
		
//		tr(i);
		
		if(i >= len-1) mx = max(mx, sum);
		
	}
}

int main(){ _
	cin >> n >> len;
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cin >> k;
	
	compute();
	
	for(int i = 0; i < n; i++){
		a[i] *= -1;
	}
	
	compute();
	
	cout << mx << "\n";
	
	
	return 0;
}
