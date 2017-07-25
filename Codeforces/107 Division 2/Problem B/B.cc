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

int n, cnt[100][3], s, m1, m2, m3;
vector<int> i1, i2, i3;
string names[100], num;


int is_taxi(string t){
	if(t[0] == t[1] and t[1] == t[3] and t[3] == t[4] and t[4] == t[6] and t[6] == t[7]) return 1;
	return 0;
}

int is_pizza(string t){
	if(t[0] > t[1] and t[1] > t[3] and t[3] > t[4] and t[4] > t[6] and t[6] > t[7]) return 1;
	return 0;
}

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(s); cin >> names[i];
		for(int j = 0; j < s; j++){
			cin >> num;
			if(is_taxi(num)) cnt[i][0]++;
			else if(is_pizza(num)) cnt[i][1]++;
			else cnt[i][2]++;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(cnt[i][0] > m1){
			m1 = cnt[i][0];
			i1.clear();
			i1.push_back(i);
		}
		else if(cnt[i][0] == m1){
			i1.push_back(i);
		}
		if(cnt[i][1] > m2){
			m2 = cnt[i][1];
			i2.clear();
			i2.push_back(i);
		}
		else if(cnt[i][1] == m2){
			i2.push_back(i);
		}
		if(cnt[i][2] > m3){
			m3 = cnt[i][2];
			i3.clear();
			i3.push_back(i);
		}
		else if(cnt[i][2] == m3){
			i3.push_back(i);
		}
	}
	
	cout << "If you want to call a taxi, you should call: ";
	for(int i = 0; i < i1.size()-1; i++)
		cout << names[i1[i]] << ", ";
	cout<< names[i1[i1.size()-1]] << ".\n";
	
	cout << "If you want to order a pizza, you should call: ";
	for(int i = 0; i < i2.size()-1; i++)
		cout << names[i2[i]] << ", ";
	cout<< names[i2[i2.size()-1]] << ".\n";
	
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	for(int i = 0; i < i3.size()-1; i++)
		cout << names[i3[i]] << ", ";
	cout<< names[i3[i3.size()-1]] << ".\n";
	
	return 0;
}
