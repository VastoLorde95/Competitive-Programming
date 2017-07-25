#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

const long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int cnt = 0;
	int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	int ok[4] = {0,0,0,0};
	string s;
	
	for(int i = 0; i < 4; i++){
		cout << p[i] << endl;
		cin >> s;
		if(s == "yes"){
			cnt++;
			ok[i] = 1;
		}
	}
	
	if(!cnt){
		cout << "prime" << endl;
		return 0;
	}
	
	if(cnt > 1){
		cout << "composite" << endl;
		return 0;
	}
	
	int pr = -1;
	for(int i = 0; i < 4; i++){
		if(ok[i]) pr = p[i];
	}
	
	cout << pr*pr << endl;
	cin >> s;
	if(s == "yes"){
		cout << "composite" << endl;
		return 0;
	}
	
	for(int i = 4; i < 15; i++){
		cout << p[i] << endl;
		cin >> s;
		if(s == "yes"){
			cout << "composite" << endl;
			return 0;
		}
	}
	
	cout << "prime" << endl;
	
	
	
	
	return 0;
}
