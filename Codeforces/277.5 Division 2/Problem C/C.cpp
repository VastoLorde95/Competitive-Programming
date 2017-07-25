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
	int m, s;
	cin >> m >> s;
	if(s == 0 and m == 1){
		cout<<"0 0"<<endl;
		return 0;
	}
	
	if(s >= 0 and s <= 9*m){
		string s1, s2, s3, s4;
		int sum = s;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < 10; j++){
				if ((i > 0 or j > 0 or (m == 1 and j == 0)) and ((sum - j) >= 0 and ((sum-j) <= 9*(m-i-1)))){
					s1 += (char)	('0' + j);
					sum -= j;
					break;
				}
			}
		}
		
		sum = s;
		for(int i = 0; i < m; i++){
			for(int j = 9; j >= 0; j--){
				if ((i > 0 or j > 0 or (m == 1 and j == 0)) and ((sum - j) >= 0 and ((sum-j) <= 9*(m-i-1)))){
					s2 += (char)('0' + j);
					sum -= j;
					break;
				}
			}
		}
		int i = 0;
		while(i < s1.length() and s1[i] == '0'){
			i++;
		}
		while(i < s1.length()){
			s3 += s1[i];
			i++;
		}
		
		i = 0;
		while(i < s2.length() and s2[i] == '0'){
			i++;
		}
		while(i < s2.length()){
			s4 += s2[i];
			i++;
		}
		
		if(s3.length() != m or s4.length() != m){
			cout<<"-1 -1"<<endl;
			return 0;
		}
		
		cout<<s3<<" "<<s4<<endl;
	}
	else{
		cout<<"-1 -1"<<endl;
	}
	return 0;
}
