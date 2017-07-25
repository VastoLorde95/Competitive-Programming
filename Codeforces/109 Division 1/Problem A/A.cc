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

int k, N, n;
string s, t, res, tmp;


string process(string tmp){
	string ret;
	int c1 = 0, c2 = 0;
	for(int i = 0; i < tmp.size(); i++){
		if(tmp[i] == t[0]) c1++; else c2++;
	}
	
//	cout << c1 << " " << c2 << " " << t[0] << " " << t[1] << endl;
	
	if(c1 > 0 and c2 > 0){
		if(c1 >= c2){
			for(int i = 0; i < tmp.size(); i++){
				if(tmp[i] == t[0]) ret += tmp[i];
			}
		}
		else{
			for(int i = 0; i < tmp.size(); i++){
				if(tmp[i] != t[0]) ret += tmp[i];
			}
		}
		
		return ret;
	}
	else{
		return tmp;
	}
}


int main(){
	cin >> s;
	N = s.length();
	
	sd(k);
	for(int j = 0; j < k; j++){
		cin >> t;
		n = s.length();
		res = "";
		for(int i = 0; i < n; i++){
			if(s[i] != t[0] and s[i] != t[1]){
				res += process(tmp);
				res += s[i];
				tmp = "";
			}
			else{
				tmp += s[i];
			}
		}
		
		if(tmp.length()){
			res += process(tmp);
			tmp = "";
		}
		
		s = res;
		
//		cout << s << endl;
		
	}
	
	cout << N - (s.length()) << endl;
	
	return 0;
}
