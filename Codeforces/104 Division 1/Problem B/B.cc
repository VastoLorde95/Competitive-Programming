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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

using namespace std;

string res;
int a1, a2, a3, a4;

void fail(){
	puts("-1");
}

int main(){
	sd2(a1,a2); sd2(a3,a4);

	if(abs(a3-a4) > 1){
		fail(); return 0;
	}	
	
	if(a1 < max(a3,a4) or a2 < max(a3,a4)){
		fail();
		return 0;
	}
	else{
		a1 -= a3; a2 -= a3;
	}
	
	for(int i = 0; i < a3; i++){
		res += "47";
	}
	
	if(a4 > 0 and a4 >= a3){
		if(a1){
			res += "4";
			a1--;
		}
		else if(a2){
			res = "7" + res;
			a2--;
			a4--;
		}
		else{
			a1 = -1;
			a2 = -1;
		}
	}
	if(a4 > a3){
		res = "7" + res;
		a2--;
	}
	
	if(a1 < 0 or a2 < 0){
		fail();
		return 0;
	}
	
	int l = res.length();
	
	if(l > 0){
		if(res[0] == '4' and res[l-1] == '7'){
			string pre;
			for(int i = 0; i < a1; i++) pre += "4";
			res = pre + res;
			
			for(int i = 0; i < a2; i++) res += "7";
		}
		else if(res[0] == '4' and res[l-1] == '4'){
			string pre;
			for(int i = 0; i < a1; i++) pre += "4";
			res = pre + res;
			
			l = res.length();
			if(a2){
				res[l-1] = '7'; a2--;
				for(int i = 0; i < a2; i++) res += "7";
				res += "4";
			}
		}
		else if(res[0] == '7' and res[l-1] == '4'){
			if(a1){
				res[0] = '4'; a1--;
				string pre = "7";
				for(int i = 0; i < a1; i++) pre += "4";
				res = pre + res;
			}
			l = res.length();
			if(a2){
				res[l-1] = '7'; a2--;
				for(int i = 0; i < a2; i++) res += "7";
				res += "4";
			}
		}
		else{
			for(int i = 0; i < a2; i++) res += '7';
		}
	}
	else{
		for(int i = 0; i < a1; i++) res += "4";
		for(int i = 0; i < a2; i++) res += "7";
	}
	
	printf("%s\n",res.c_str());	
			
	return 0;
}
