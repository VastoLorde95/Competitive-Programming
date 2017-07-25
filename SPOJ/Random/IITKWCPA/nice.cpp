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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	string input, s;
	set<string> d;
	int t, flag = 0;
	sd(t);
	while(t--){
		s = "";
		d.clear();
		getline(cin, input);
		for(int i = 0; i < input.length(); i++){
			if(input[i] != ' ')
				s += input[i];
			else if(s != ""){
				d.insert(s);
				s = "";
			}
		}
		if(s != "")
			d.insert(s);
		if(flag == 1)
			cout<<d.size()<<endl;
		else{
			flag = 1;
			t++;
		}
	}
	return 0;
}
