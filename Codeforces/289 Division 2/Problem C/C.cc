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

int n, b[300];
vector<string> a;

string get(int num){
	string ret = "";
	if(num == 0) return ret;
	
	while(num >= 9){
		num -= 9;
		ret += '9';
	}
	
	if(num == 0) return ret;
	
	ret = char(num+'0') + ret;
	
	return ret;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(b[i]);
	
	a.pb(get(b[0]));
	
	for(int i = 1; i < n; i++){
		a.pb(a.back());
		
		int sum = 0;
		for(int j = 0; j < a[i].length(); j++){
			sum += a[i][j] - '0';
		}
		
		int j = a[i].length()-1, l = a[i].length(); bool ok = false;
		
		while(j >= 0){
			sum -= (a[i][j]-'0');
			
			int digit = int(a[i][j]-'0')+1;
			
			while(digit < 10 and !ok){
			
				if(sum+digit <= b[i] and b[i] <= sum + digit + 9*(l-j-1)){
					ok = true;
					
					string tmp = get(b[i]-sum-digit);
					while(tmp.length() < l-1-j) tmp = '0' + tmp;
					
					a[i][j] = char(digit+'0');
					
					for(int k = j+1; k < l; k++) a[i][k] = tmp[k-j-1];
				}
				digit++;
			}
			j--;
		}
		
		if(!ok){
			j = a[i].length();
			while(!ok){
				int digit = 1;
				while(digit < 10 and !ok){
					if(digit + (9*j) >= b[i]){
						string t1, t2 = get(b[i]-digit);
						t1 += char(digit + '0');
						while(t1.length() + t2.length() < j+1) t1 += '0';
						a[i] = t1+t2;
						ok = true;
					}
					digit++;
				}
				j++;
			}
		}
	}
	
	foreach(it, a) tr(*it);
	
	return 0;
}
