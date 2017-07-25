#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int main(){
	string s;
	int a = 0, l, x, y, ind;
	vector<int> res;
	
	cin>>s;
	l = s.length();
	if(s[l-1] == '('){
		cout<<-1<<endl;
		return 0;
	}
	for(int i = 0; i < l; i++){
		if(s[i] == '(')
			a++;
		else if(s[i] == ')'){
			a--;
			if(a < 0){
				cout<<-1<<endl;
				return 0;
			}
		}
		else{
			if(a <= 0){
				cout<<-1<<endl;
				return 0;
			}
			else{
				x = a;
				ind = i;
				res.push_back(1);
				a--;
			}
		}
	}
	if(a < 0){
		cout<<-1<<endl;
		return 0;
	}
	else if(a > 0){
		//cout<<"A is "<<a<<endl;
		if(a <= x){
			res[res.size()-1] += a;
		}
		else{
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i = 0; i < res.size(); i++){
		cout<<res[i]<<endl;
	}
	
	
	return 0;
}
