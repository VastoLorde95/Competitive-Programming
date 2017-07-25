#include <bits/stdc++.h>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

const int N = 1000100;

stack<int> st;
char s[N];

bool isopen(char &c){
	return (c == '(' or c == '[' or c == '{' or c == '<');
}

bool match(char &x, char &y){
	if(x == '(' and y == ')') return true;
	if(x == '[' and y == ']') return true;
	if(x == '{' and y == '}') return true;
	if(x == '<' and y == '>') return true;
	return false;
}

int main(){
	scanf("%s", s);
	int l = strlen(s), cnt = 0;
	
	for(int i = 0; i < l; i++){
		if(isopen(s[i])){
			st.push(i);
		}
		else{
			if(st.empty()){
				puts("Impossible");
				return 0;
			}
			if(!match(s[st.top()], s[i])) cnt++;
			st.pop();
		}
	}
	
	if(!st.empty()){
		puts("Impossible");
		return 0;
	}
	printf("%d\n", cnt);
	
	return 0;
}
