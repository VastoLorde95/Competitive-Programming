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

const int N = 51;

int n;
ll l[N];

bool good(int l1, int l2, int l3){
	if(l1 < l2 + l3 and l2 < l1 + l3 and l3 < l1 + l2) return true;
	return false;
}

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> l[i];
	}
	
	sort(l, l+n);
	
	int l1 = -1, l2 = -1, l3 = -1, mx = -1;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k < n; k++){
				if(l[i]+l[j]+l[k] > mx){
					mx = l[i]+l[j]+l[k];
					l1 = l[i];
					l2 = l[j];
					l3 = l[k];
				}
				else if(l[i]+l[j]+l[k] == mx){
					if(l[k] > l3){
						l1 = l[i];
						l2 = l[j];
						l3 = l[k];
					}
					else if(k == l3 and i > l3){
						l1 = l[i];
						l2 = l[j];
						l3 = l[k];
					}
				}
			}
		}
	}
	
	if(mx == -1) cout << -1 << endl;
	else cout << l1 << ' ' << l2 << ' ' << l3 << endl;
	
	return 0;
}
