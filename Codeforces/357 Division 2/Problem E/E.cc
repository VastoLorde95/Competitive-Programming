#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
const double eps = 1e-9;
 
double sqrDist(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
 
double dist(double x1, double y1, double x2, double y2) {
    return sqrt(sqrDist(x1, y1, x2, y2));
}
 
const double PI = 3.1415926535897932384626433832795;
 
int main() {
    int x0, y0, v, t;
 
    scanf("%d%d%d%d", &x0, &y0, &v, &t);
 
    double r0 = 1.0 * v * t;
 
    int n;
    scanf("%d", &n);
 
    vector<pair<double, double> > a;
 
    for (int i = 0; i < n; i++) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        double d = sqrDist(x, y, x0, y0);
        if (d < 1.0 * r * r + eps) {
            printf("%.11f", 1.0);
            return 0;
        }
        d = sqrt(d);
        if (r + r0 < d - eps) {
            continue;
        }
 
        double angL, angR, ang;
        double angM = atan2(y - y0, x - x0);
        if (angM < 0) {
            angM += PI * 2;
        }
 
        double tLen = sqrt(d * d - 1.0 * r * r);
        if (tLen < r0 + eps) {
            ang = asin(r / d);
        } else {
            ang = acos((d * d + r0 * r0 - 1.0 * r * r) / (2 * d * r0));
        }
 
        angL = angM - ang;
        angR = angM + ang;
 
        if (angL < 0) {
            a.push_back(make_pair(angL + PI * 2, PI * 2));
            a.push_back(make_pair(0, angR));
//            a.push_back(make_pair(0.0, 1));
//            a.push_back(make_pair(angR, -1));
        } else if (angR > PI * 2) {
            a.push_back(make_pair(angL, PI * 2));
            a.push_back(make_pair(0 , angR - PI * 2));
//            a.push_back(make_pair(0.0, 1));
//            a.push_back(make_pair(angR - PI * 2, -1));
        } else {
            a.push_back(make_pair(angL, angR));
//            a.push_back(make_pair(angR, -1));
        }
    }
 
    sort(a.begin(), a.end());
 
    double last = 0;
    int c = 0;
    double ans = 0;

	n = a.size();
	for(int i = 0; i < n; i++){
		double s = a[i].first, e = a[i].second;
		i++;
		while(i < n and a[i].first <= e+eps){
			e = a[i].second;
			i++;
		}
		i--;
		
		ans += e-s;
	}
 
//    for (auto& p : a) {
//        if (c > 0) {
//            ans += p.first - last;
//        }
//        c += p.second;
//        last = p.first;
//    }
 
    ans /= PI * 2;
    printf("%.11f", ans);
 
    return 0;
}
