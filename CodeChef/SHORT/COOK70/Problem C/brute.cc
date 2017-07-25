#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> pt;
vector<int> parent;
typedef map<pt,int> indexer;
vector<pt> pts;
indexer indices;
set< pair<pt,pt> > edges;
int r, c;
int index(int i, int j, bool make = true) {
    if (i == 0 or i == r or j == 0 or j == c) {
        i = j = 0;
    }
    pair<int,int> ij = make_pair(i, j);
    indexer::iterator it = indices.find(ij);
    if (it == indices.end()) {
        if (make) {
            int idx = parent.size();
            parent.push_back(-1);
            pts.push_back(ij);
            return indices[ij] = idx;
        } else {
            return -1;
        }
    } else {
        return it->second;
    }
}

int find(int n) {
    return parent[n] < 0 ? n : parent[n] = find(parent[n]);
}

int di[5] = {0, 1, 0, -1, 0};
int *dj = di + 1;

int main() {
    int z;
    scanf("%d", &z);
    while (z--) {
        int w;
        scanf("%d%d%d", &r, &c, &w);
        if (r == 1 or c == 1) {
            if (r == 1 && c == 1) {
                printf("Chefland is doomed\n");
            } else {
                printf("%d\n", !w);
            }
            while (w--) scanf("%*d%*d%*d%*d");
        } else {
            parent.clear();
            indices.clear();
            pts.clear();

            int res = 2;
            edges.clear();
            int zero = index(0, 0);
            while (w--) {
                int i1, j1, i2, j2;
                scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
                i1--, j1--, i2--, j2--;
                if (i1 == i2) {
                    i1 = i2++;
                    j1 = j2;
                } else {
                    i1 = i2;
                    j1 = j2++;
                }
                pt p1 = make_pair(i1, j1);
                pt p2 = make_pair(i2, j2);
                edges.insert(make_pair(p1, p2));
                edges.insert(make_pair(p2, p1));
                int x1 = find(index(i1, j1));
                int x2 = find(index(i2, j2));
                if (x1 == x2) {
                    res = 0;
                } else {
                    if (parent[x1] == parent[x2]) parent[x2]--;
                    if (parent[x1] > parent[x2]) {
                        parent[x1] = x2;
                    } else {
                        parent[x2] = x1;
                    }
                }
            }

            if (res) {
                for (int idx = 0; idx < pts.size(); idx++) {
                    pt ij = pts[idx];
                    #define i first
                    #define j second
                    int x = index(ij.i, ij.j);
                    for (int d = 0; d < 4; d++) {
                        int ni = ij.i + di[d];
                        int nj = ij.j + dj[d];
                        pt nij = make_pair(ni, nj);
                        int nx = index(ni, nj, false);
                        if (nx >= 0 && !(x == nx && x == zero) && edges.find(make_pair(ij, nij)) == edges.end()) {
                            if (find(x) == find(nx)) {
                                res = 1;
                                break;
                            }
                        }
                    }
                    #undef i
                    #undef j
                    if (res == 1) {
                        break;
                    }
                }
            }

            printf("%d\n", res);
        }
    }
}
