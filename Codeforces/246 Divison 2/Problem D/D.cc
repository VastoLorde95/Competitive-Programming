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

// z[i] = the length of the longest substring of 's' starting at index 'i' which is at the same time a prefix of the string 's'
int z[1000001], cnt, n;
map<int, int> res;
vector<int> m;
string s;

void build_z(){					// l, r are the invariant variables => [l,r] is the maximum interval such that s[l,r] is a prefix substring
	int len = s.length(), l = 0, r = 0, k;
	z[0] = len;
	
	for(int i = 1; i < len; i++){
		if(r < i){				// make a new interval l,r and find the substring starting at i which is a prefix substring
			l = r = i; 
			while(r < n and s[r-l] == s[r]) r++;
			z[i] = r-l; r--;
		}
		else{					// try to expand the current interval by observing the value of z[k]
			k = i-l;
			if(z[k] < r-i+1){		// can't be more than z[k] since s[i..R] matches with s[k...z[k]]
				z[i] = z[k];
			}
			else{				// we can expand the current r since z[k] allows us to do so
				l = i;
				while(r < n and s[r-l] == s[r]) r++;
				z[i] = r-l; r--;
			}
		}
	}
	
	return;	
}

int main(){
	cin >> s;
	
	n = s.length();
	
	build_z();
	
	for(int i = 0; i < n; i++){
		m.pb(z[i]);
	}
	
	sort(m.begin(), m.end());
	
	int j = 0;
	
//	for(int i = 0; i < n; i++){
//		tr2(i,z[i]);
//	}
	
	for(int i = n-1; i >= 0; i--){
		if(z[i] < n-i) continue;
		
		while(j < m.size() and m[j] < z[i]) j++;
		
		res[z[i]] += m.size()-j;
	}
	
	cout << res.size() << endl;
	
	for(map<int,int>::iterator it = res.begin(); it != res.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
		
	return 0;
}
