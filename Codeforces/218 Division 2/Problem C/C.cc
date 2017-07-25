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

string s;

long long a, b, c;

long long n1, n2, n3;
long long p1, p2, p3;
long long r;

long long t1, t2, t3;

long long cost;

int main(){
	
	cin >> s;
	int l = s.length();
	
	for(int i = 0; i < l; i++){
		if(s[i] == 'B') a++;
		else if(s[i] == 'S') b++;
		else c++;
	}
	
	cin >> n1 >> n2 >> n3;
	cin >> p1 >> p2 >> p3;
	cin >> r;
	
	long long low = 0, hi = 1e13l, mid;
	
	while(low + 1 < hi){
		mid = (low+hi)/2;
		
		t1 = mid*a;
		t2 = mid*b;
		t3 = mid*c;
		
		if(t1 >= n1) t1 -= n1; else t1 = 0;
		if(t2 >= n2) t2 -= n2; else t2 = 0;
		if(t3 >= n3) t3 -= n3; else t3 = 0;
		
		cost = (t1)*p1 + (t2)*p2 + (t3)*p3;
		if(cost > r){
			hi = mid;
		}
		else{
			low = mid;
		}
	}
	
	cout << low << endl;
	
	return 0;
}
