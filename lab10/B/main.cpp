#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#define SIZE 10e8

using namespace std;


double whatIsWeight(int beg, int end, vector <pair <int, int> > ve) {
    if (end == beg){
        return SIZE;
    }
    return sqrt((ve[end].first - ve[beg].first) * (ve[end].first - ve[beg].first) + (ve[end].second - ve[beg].second) * (ve[end].second - ve[beg].second));
}


int main() {
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");

    int n, from, to;
    double minWeight = 0, x;
    int cur;
    fin >> n;

    vector <pair <int, int> > ve;
    vector <double> dist, path;
    vector <bool> used;

    dist.assign(n, SIZE);
    dist[0] = 0;
    used.assign(n, 0);
    path.assign(n, -1);

    for (int i = 0; i < n; ++i){
        fin >> from >> to;

        ve.push_back(make_pair(from ,to));
    }

    for (int i = 0; i < n; ++i){
        cur = -1;

        for (int j = 0; j < n; ++j) {
            if (!used[j] && (cur == -1 || dist[j] < dist[cur])) {
                cur = j;
            }
        }

        used[cur] = 1;

        if (path[cur] != -1) {
            minWeight += whatIsWeight(cur, path[cur], ve);
        }

        for (int u = 0; u < n; ++u) {
            x = whatIsWeight(cur, u, ve);
            if (x < dist[u]) {
                dist[u] = x;
                path[u] = cur;
                break;
            }
        }
    }

    fout << setprecision(10) << minWeight;

    return 0;
}

