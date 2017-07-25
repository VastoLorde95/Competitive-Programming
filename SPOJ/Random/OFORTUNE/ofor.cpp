#include<stdio.h>
#include<stdlib.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);
#define max(x,y) ((x) > (y))? (x):(y);

int main(){
	int m, p, y, n, type, charge, res, p_temp, interest, i, j;
	double rate;
	sd(m);
	while(m--){
		sd(p);
		sd(y);
		sd(n);
		res = 0;
		for(i = 0; i < n; i++){
			scanf("%d %lf %d",&type, &rate, &charge);	
			p_temp = p, interest = 0;
			if(type == 0){
				for(j = 0; j < y; j++){
					interest += (p_temp * rate);
					p_temp -= charge;
				}
				res = max(res, p_temp + interest);
			}
			else{
				for(j = 0; j < y; j++){
					interest = p_temp * rate;
					p_temp = p_temp + interest - charge;
				}
				res = max(res, p_temp);
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
