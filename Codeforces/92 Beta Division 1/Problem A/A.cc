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

string s;
int n, up, cnt;
map<char, int> m;
vector<int> primes;
int mark[1001];
char res[1001], c;

int main(){
	cin >> s;
	n = s.length();
	
	if(n <= 3){
		puts("YES");
		puts(s.c_str());
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		m[s[i]]++;
	}
	
	primes.pb(2);
	for(int i = 3; i <= 1000; i += 2){
		bool flag = true;
		for(int j = 0; j < primes.size(); j++){
			if(i%primes[j] == 0) flag = false;
		}
		if(flag){
			primes.pb(i);
		}
	}
	
	up = 0;
	while(up < primes.size() and primes[up] <= n/2) up++;

	for(int i = 0; i < up; i++){
		for(int j = primes[i]-1; j < n; j += primes[i]) mark[j] = 1;
	}
	
	for(int i = 0; i < n; i++) cnt += mark[i];
	
	c = '.';
	
	for(map<char, int>::iterator it = m.begin(); it != m.end(); it++){
		if(it->second >= cnt){
			c = it->first;
			break;
		}
	}
	
	
	if(c == '.'){
		puts("NO");
		return 0;
	}
	
	res[n] = '\0';
	
	for(int i = 0; i < up; i++){
		for(int j = primes[i]-1; j < n; j += primes[i]) res[j] = c;
	}
	
	m[c] -= cnt;
	
	map<char, int>::iterator it = m.begin();
	
	for(int i = 0; i < n; i++){
		if(mark[i] == 0){
			while(it->second == 0) it++;
			res[i] = it->first;
			m[it->first]--;
		}	
	}
	
	puts("YES");
	puts(res);
	
	return 0;
}
