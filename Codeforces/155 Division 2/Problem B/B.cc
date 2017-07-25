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
#include<fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, v[30][32];
int m, d, p, t, mx;

int main(){
	fin >> n;
	for(int i = 0; i < n; i++){
		fin >> m >> d >> p >> t;
		
		m--;
		m += 12;
		
		for(int j = 0; j < t; j++){
			d--;
			if(d == 0){
				m--;
				d = days[m%12];
			}
			v[m][d] += p;
		}
	}
	
	for(int i = 0; i < 30; i++){
		for(int j = 0; j < 32; j++){
			mx = max(mx, v[i][j]);
		}
	}	
	
	fout<< mx << endl;
	
	return 0;
}
