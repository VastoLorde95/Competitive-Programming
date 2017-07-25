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

string s1, s2;
int pos, cur;

map<int, double> prob[12];

int main(){
	cin >> s1;
	cin >> s2;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == '+') pos++; else pos--;
	}
	
	prob[0][0] = 1.0f;
	
	for(int i = 1; i <= s2.length(); i++){
		if(s2[i-1] == '+'){
			foreach(it, prob[i-1]){
				prob[i][it->fi + 1] =  it->se;
			}
		}
		else if(s2[i-1] == '-'){
			foreach(it, prob[i-1]){
				prob[i][it->fi - 1] =  it->se;
			}
		}
		else{
			foreach(it, prob[i-1]){
				prob[i][it->fi + 1] +=  it->se/2.0;
				prob[i][it->fi - 1] +=  it->se/2.0;
			}
		}
	}
	
	printf("%.10lf\n", prob[s2.length()][pos]);
	
	return 0;
}
