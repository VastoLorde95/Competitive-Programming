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
#define fi first
#define se second

using namespace std;

int n, d, l, cards[100], s;

int main(){
	sd3(n,d,l);
	if(d == 0){
		if(n == 1){
			cout<< -1 << endl;
			return 0;
		}
		if(n%2 == 0){
			for(int i = 0; i < n; i++){
				cout<< 1 << " " ;
			}
		}
		else{
			cout<<"1 2 ";
			for(int i = 2; i < n; i++){
				cout<< 1 << " ";
			}
		}
		
		cout<< endl;
		return 0;
	}
	if(d < 0){
		for(int i = 0; i < n; i++){
			if(i%2 == 0){
				cards[i] = 1;
				s += 1;
			}
			else{
				cards[i] = l;
				s -= l;
			}
		}
		
		
		if(d < s){
			cout<< -1 << endl;
			return 0;
		}
		//for(int i = 0; i < n; i++){
		//	cout<< cards[i] << " ";
		//}
		//cout<<endl;
		
		for(int i = 0; i < n; i += 2){
			if( s+l-1 < d){
				cards[i] = l;
				s = s+l-1;
			}
			else{
				cards[i] += (d-s);
				s = d;
				break;
			}
		}
		
		if(s != d){
			cout<< -1 << endl;
			return 0;
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(i%2 == 0){
				cards[i] = l;
				s += l;
			}
			else{
				cards[i] = 1;
				s -= 1;
			}
		}
		if(d > s){
			cout<< -1 <<endl;
			return 0;
		}
		//for(int i = 0; i < n; i++){
		//	cout<< cards[i] << " ";
		//}
		//cout<<endl;
		
		for(int i = 0; i < n; i += 2){
			if( s-l+1 > d){
				cards[i] = 1;
				s = s-l+1;
			}
			else{
				cards[i] -= (s-d);
				s = d;
				break;
			}
		}
		
		if(s != d){
			cout<< -1 << endl;
			return 0;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout<< cards[i] << " ";
	}
	cout<<endl;
	return 0;
}
