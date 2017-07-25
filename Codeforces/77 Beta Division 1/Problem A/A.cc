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
#include<locale>
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

int n, m[100];
string f[100], w, o;

char c;

int main(){ _
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> f[i];
		for(int j = 0; j < f[i].length(); j++){
			if(f[i][j] <= 90) f[i][j] = (char)(f[i][j]+32);
		}
//		cout << f[i] << endl;
	}
	
	cin >> o;
	
	for(int i = 0; i < o.length(); i++){
		if(o[i] <= 90) w += (char)(o[i]+32);
		else w += o[i];
	}
	
//	cout << o << endl;
//	cout << w << endl;
	
	cin >> c;
	
	for(int i = 0; i < n; i++){
		if(f[i].length() > w.length()) continue;
		
		int l1 = f[i].length(), l2 = w.length();
		
		for(int j = 0; j <= l2-l1; j++){
			if(w.substr(j, l1) == f[i]){
				for(int k = 0; k < l1; k++){
					m[j+k] = 1;
				}
			}	
		}
		
	}
	
	for(int i = 0; i < w.length(); i++){
		if(m[i] == 1){
			if(w[i] != c) w[i] = c;
			else{
				for(int j = 0; j < 26; j++){
					if((char)(j+'a') != c){
						w[i] = (char)(j+'a');
						break;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < w.length(); i++){
		if(w[i] <= 90 and o[i] >= 97){
			w[i] = (char)(w[i]+32);
		}
		else if(w[i] >= 97 and o[i] <= 90){
			w[i] = (char)(w[i]-32);
		}
	}
	
	tr(w);
	
	return 0;
}
