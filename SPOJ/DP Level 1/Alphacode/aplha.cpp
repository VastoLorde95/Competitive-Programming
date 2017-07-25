#include<iostream>
#include<string>
#include<map>
using namespace std;
map<std::string, long long> a;
long long decode(string num){
	int l = num.length();
	long long total = 0;
	if(l == 0 or num[0] == '0'){
		return 0;
	}
	else if(l == 1){
		return a[num];
	}
	else if(a.find(num) == a.end()){
		total = decode(num.substr(1));
		if(num.substr(0,2) <= "26"){
			total += decode(num.substr(2));
			}
		a[num] = total;
		return a[num];
		}
	else{
	
		return a[num];
	}
}
int main(){
	string number;
	a["0"] = 0;
	a["1"] = 1;
	a["2"] = 1;
	a["3"] = 1;
	a["4"] = 1;
	a["5"] = 1;
	a["6"] = 1;
	a["7"] = 1;
	a["8"] = 1;
	a["9"] = 1;
	a["10"] = 1;
	a["11"] = 2;
	a["12"] = 2;
	a["13"] = 2;
	a["14"] = 2;
	a["15"] = 2;
	a["16"] = 2;
	a["17"] = 2;
	a["18"] = 2;
	a["19"] = 2;
	a["20"] = 1;
	a["21"] = 2;
	a["22"] = 2;
	a["23"] = 2;
	a["24"] = 2;
	a["25"] = 2;
	a["26"] = 2;
	a["30"] = 0;
	a["40"] = 0;
	a["50"] = 0;
	a["60"] = 0;
	a["70"] = 0;
	a["80"] = 0;
	a["90"] = 0;
	cin>>number;
	while(number != "0"){
		cout<<decode(number)<<endl;
		cin>>number;
	}
	return 0;
}
