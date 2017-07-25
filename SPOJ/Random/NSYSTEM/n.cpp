#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;
int convert(string x){
	int l = x.length(), i, result = 0, mult = 1;
	char c;
	for(i = 0; i < l; i++){
		c = x[i];
		if((int)c > 48 and (int)c < 58){
			mult = c - 48;
			}
		else{
			if(c == 'm'){
				result += 1000 * mult;
				mult = 1;
			}
			else if( c == 'c'){
				result += 100 * mult;
				mult = 1;
			}
			else if( c == 'x'){
				result += 10 * mult;
				mult = 1;
			}
			else if( c == 'i'){
				result += 1 * mult;
				mult = 1;
			}		
		}
	}
	return result;
}

string revert(int a){
	string result;
	int d1 = a % 10;
	a = a/10;
	int d2 = a % 10;
	a = a/10;
	int d3 = a % 10;
	a = a/10;
	int d4 = a % 10;
	//cout<<d4<<d3<<d2<<d1<<endl;
	if(d4 == 1)
		result += 'm';
	else if(d4 > 1){
		result += (char)(d4 + 48);
		result += 'm'; 
		}
	if(d3 == 1)
		result += 'c';
	else if(d3 > 1){
		result += (char)(d3 + 48);
		result += 'c';}
	if(d2 == 1)
		result += 'x';
	else if(d2 > 1){
		result += (char)(d2 + 48);
		result += 'x';}
	if(d1 == 1)
		result += 'i';
	else if(d1 > 1){
		result += (char)(d1 + 48);
		result += 'i'; }
	return result;
}


int main(){
	string x, y;
	int t, a, b;
	sd(t);
	while(t--){
		cin>>x>>y;
		a = convert(x);
		b = convert(y);
		cout<<revert(a+b)<<endl;
	}
	return 0;
}
