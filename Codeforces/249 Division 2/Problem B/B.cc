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

string a;
int k;

int main(){
	cin >> a >> k;
	
	for(int i = 0; i < a.length() and k > 0; i++){
		int mx = a[i]-'0', indx = i;
		for(int j = i+1; j < a.length(); j++){
			if(a[j]-'0' > mx and j-i <= k){
				mx = a[j]-'0';
				indx = j;
			}
		}
		for(int j = indx; j > i; j--)
			swap(a[j], a[j-1]);
		k -= indx-i;
	}
	cout << a << endl;
		
	return 0;
}
