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

long double PI = 3.1415926535897932384626433832795;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

#define eps 1e-9

bool found;

bool fits(ld a,ld b,ld c,ld d)
{
	return (a<c+eps&&b<d+eps);
}

void check(ld a1,ld b1,ld a2,ld b2)
{	
	for (ld ang=0;ang<=M_PI/2;ang+=1e-5)
	{
		ld side1=a1*cos(ang)+b1*sin(ang);
		ld side2=a1*sin(ang)+b1*cos(ang);
		if (fits(side1,side2,a2,b2))
			found=1;
		if (fits(side1,side2,b2,a2))
			found=1;
	}
}

int main(){ _
	int w, h, n;
	cin >> w >> h >> n;
	
	PI = acos(-1);
	
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(c == 'C'){
			int r;
			cin >> r;
			if(2*r <= w and 2*r <= h){
				puts("YES");
			}			
			else{
				puts("NO");
			}
		}
		else{
			int x, y;
			cin >> x >> y;
			found = false;
			check(x,y,w,h);
			if(found) puts("YES");
			else puts("NO");
		}
	}
	
	return 0;
}
