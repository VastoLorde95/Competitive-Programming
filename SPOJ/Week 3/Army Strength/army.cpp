#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int NG, NM;
		cin>>NG>>NM;
		int G[NG], M[NM];
		int i = 0, j;
		while(i < NG){
			cin>>G[i];
			i++;
		}
		i = 0;
		while(i < NM){
			cin>>M[i];
			i++;
		}
		sort(G, G + NG);
		sort(M, M + NM);
		i = 0, j = 0;
		while(i < NG and j < NM){
			if(G[i] < M[j])
				i++;
			else if(G[i] >= M[j])
				j++;		
		}
		if(i == NG)
			cout<<"MechaGodzilla"<<endl;
		else
			cout<<"Godzilla"<<endl;
		
	}
	return 0;
}
