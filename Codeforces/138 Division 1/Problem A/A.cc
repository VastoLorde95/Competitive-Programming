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
int n, mx, l, r, i;

int open(int t){
	i++;
	if(i >= n) return -1;
	
	int cnt = 0, tmp = 0, x = -1;
	for(; i < n; i++){
		if(s[i] == '('){
			if(x == -1) x = i;
			tmp = open(2);
			if(tmp == -1) return -1;
			
			cnt += tmp;
			
			if(cnt > mx){
				l = x, r = i, mx = cnt;
			}
		}
		else if(s[i] == '['){
			if(x == -1) x = i;
			tmp = open(1);
			if(tmp == -1) return -1;
			
			cnt += tmp;
			
			if(cnt > mx){
				l = x, r = i, mx = cnt;
			}
		}
		else if(s[i] == ')'){
			if(t == 1) return -1;
			else return cnt;
		}
		else{
			if(t == 1) return cnt+1;
			else return -1;
		}
	}
	
	return -1;
}

int main(){ _
	cin >> s;
	n = s.length();
	
	int x = 0, cnt = 0, fail = 1;
	
	for(i = 0; i < n; i++){
		if(s[i] == '['){
			if(fail == 1) x = i;
			
			int tmp = open(1);
			
			if(tmp == -1){
				fail = 1;
				cnt = 0;
				continue;
			}
			else{
				fail = 0;
				cnt += tmp;
			
//				tr3(i, cnt, fail);
			
				if(cnt > mx){
					l = x, r = i, mx = cnt;
				}
			}
		}
		else if(s[i] == '('){
			if(fail == 1) x = i;
			int tmp = open(2);
//			tr2("check",tmp);
			if(tmp == -1){
				fail = 1;
				cnt = 0;
				continue;
			}
			else{
				fail = 0;
				cnt += tmp;
			
//				tr4(i, cnt, fail, tmp);
			
				if(cnt > mx){
					l = x, r = i, mx = cnt;
				}
			}
		}
		else{
			fail = 1;
			cnt = 0;
		}
	}
	
	
//	tr2(l,r);
	
	printf("%d\n",mx);
	
	if(mx > 0){
		for(int i = l; i <= r; i++){
			printf("%c",s[i]);
		}
		printf("\n");
	}
	
	return 0;
}
