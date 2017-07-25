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

string n;
int l;

int main(){
	cin >> n;
	l = n.length();
	
	int tmp;
	for(int i = 0; i < l; i++){
		if(n[i] == '0' or n[i] == '8'){
			cout << "YES\n" << n[i] << "\n";
			return 0;
		}
	}
	
	for(int i = 0; i < l; i++){
		if(n[i] == '0') continue;
		tmp = (n[i]-'0')*10;
		
		for(int j = i+1; j < l; j++){
			if((tmp + (n[j]-'0'))%8 == 0){
				cout << "YES\n" << tmp+(n[j]-'0') << "\n";
				return 0;
			}
		}
	}
	
	for(int i = 0; i < l; i++){
		if(n[i] == '0') continue;
		tmp = (n[i]-'0')*100;
		for(int j = i+1; j < l; j++){
			int tmp2 = tmp + (n[j]-'0')*10;
			for(int k = j+1; k < l; k++){
				int tmp3 = tmp2 + (n[k]-'0');
				if(tmp3%8 ==0){
					cout << "YES\n" << tmp3 << "\n";
					return 0;
				}
			}
		}
	}
	
	cout << "NO\n";
	return 0;
}
