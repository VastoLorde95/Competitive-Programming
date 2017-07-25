#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 1010
#define int64 long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	string a;
	int ty;
	int64 x,y,b,s;
	inline void print() {
		cout<<a;
		printf(" %I64d %I64d\n",x,y);
	}
} a[N];
int i,j,k,n,m,t,l,r;
int f[N][N],in[N],g[N],s[N];
char p[N];
inline int find(string b) {
	int i;
	For(i,1,t) if (a[i].a==b) return i;
	a[++t].a=b;
	return t;
}
inline void Widget() {
	scanf("%s",p+1);
	string b;
	int i,j,n=strlen(p+1),lx=0,ly=0;
	For(i,1,n) if (p[i]=='(') break;
	else b+=p[i];
	For(j,i+1,n) if (p[j]==',') break;
	else lx=lx*10+p[j]-'0';
	For(i,j+1,n-1) ly=ly*10+p[i]-'0';
	int A=find(b);
	a[A].x=lx,a[A].y=ly;
}
inline void HBox() {
	string b;
	cin>>b;
	int A=find(b);
	a[A].ty=1;
}
inline void VBox() {
	string b;
	cin>>b;
	int A=find(b);
	a[A].ty=2;
}
inline bool cc1(const ww &A,const ww &B) {
	return A.a<B.a;
}
void bfs() {
	int l=1,r=0,i,j,k;
	For(i,1,t) if (!in[i]) g[++r]=i;
	for (;l<=r;l++) {
		int A=g[l];
		For(i,1,t) if (f[A][i]) {
			in[i]-=f[A][i];
			if (!in[i]) g[++r]=i;
		}
	}
	for (i=r;i;i--) {
		int A=g[i];
		if (!a[A].ty) continue;
		For(j,1,t)For(k,1,f[A][j]) {
			s[A]++;
			if (a[A].ty==1) {
				a[A].x+=a[j].x;
				a[A].y=max(a[A].y,a[j].y);
			} else {
				a[A].y+=a[j].y;
				a[A].x=max(a[A].x,a[j].x);
			}
		}
		if (!s[A]) a[A].x=a[A].y=0;
		else if (a[A].ty==1) a[A].x+=2*a[A].b+(s[A]-1)*a[A].s,a[A].y+=2*a[A].b;
		else a[A].y+=2*a[A].b+(s[A]-1)*a[A].s,a[A].x+=2*a[A].b;
	}
}
int main() {
	scanf("%d",&n);
	For(i,1,n) {
		scanf("%s",p+1);
		m=strlen(p+1);
		For(j,1,m) if (p[j]=='.') break;
		if (j<=m) {
			string s;
			For(k,1,j-1) s+=p[k];
			int A=find(s);
			if (p[j+1]=='p') {
				For(k,j+1,m) if (p[k]=='(') break;
				string w;
				int u;
				For(u,k+1,m-1) w+=p[u];
				int B=find(w);
				f[A][B]++,in[B]++;
			} else {
				For(k,j+1,m) if (p[k]=='(') break;
				int B=0,u;
				For(u,k+1,m-1) B=B*10+p[u]-'0';
				if (p[j+5]=='b') a[A].b=B;
				else a[A].s=B;
			}
		} else if (p[1]=='W') Widget();
		else if (p[1]=='H') HBox();
		else VBox();
	}
	bfs();
	sort(a+1,a+t+1,cc1);
	For(i,1,t) a[i].print();
	return 0;
}
