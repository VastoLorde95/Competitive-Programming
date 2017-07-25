#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperator(char token){	
	if(token == '+' || token == '-' || token == '/' || token == '*' || token == '^'){
		return true;
	}
	return false;
}

int cmpPrec(char token1, char token2){
	int val1, val2;
	switch(token1){
		case '+':
			val1 = 0;
			break;
		case '-':
			val1 = 0;
			break;
		case '/':
			val1 = 5;
			break;
		case '*':
			val1 = 5;
			break;
		case '^':
			val1 = 10;
			break;	
	}
	switch(token2){
		case '+':
			val2 = 0;
			break;
		case '-':
			val2 = 0;
			break;
		case '/':
			val2 = 5;
			break;
		case '*':
			val2 = 5;
			break;
		case '^':
			val2 = 10;
			break;	
	}
	return val1 - val2;
}

int main(){
	int n, i = 0, j, l;
	string expr;
	char temp;
	cin>>n;
	while(i<n){
		cin>>expr;
		l = expr.length();
		j = 0;
		string rpn;
		stack<char> stck;
		while(j<l){
			temp = expr[j];
			if(temp == '('){
				stck.push(temp);
			}
			else if(temp == ')'){
				while(stck.size() != 0 && stck.top() != '('){
					rpn += stck.top();
					stck.pop();
				}
				stck.pop();
			}
			else if(isOperator(temp)){
				while(stck.size() != 0 && isOperator(stck.top()) ){
					if( temp == '^' && cmpPrec(temp, stck.top()) < 0 ){
						rpn += stck.top();
						
						stck.pop();
					}
					else if(temp != '^' && cmpPrec(temp, stck.top()) <= 0){
						rpn += stck.top();
						stck.pop();
					}
					else{
						break;
					}	
				}
				stck.push(temp);
			}
			else{
				rpn += temp;
			}
			++j;
		}
		while(stck.size() != 0){
			rpn += stck.top();
			stck.pop();
		}
		++i;
		cout<<rpn<<endl;
	}
	
	return 0;
}

