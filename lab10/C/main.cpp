#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;


long long findSet(long long cur, vector <long long>& ancestor){
    if (ancestor[cur] == cur){
        return cur;
    }

    ancestor[cur] = findSet(ancestor[cur], ancestor);
    return ancestor[cur];
}


int main() {
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");

    long long n, m, from, to, weight;
    long long minWeight = 0;

    fin >> n >> m;

    vector <pair <long long, pair<long long, long long> > > ve;
    vector <long long> ancestor;

    for (int i = 0; i < n + 1; ++i){
        ancestor.push_back(i);
    }

    for (int i = 0; i < m; ++i){
    	fin >> from >> to >> weight;

    	ve.push_back(make_pair(weight, make_pair(from, to)));
    }

    sort(ve.begin(), ve.end());

    for (int i = 0; i < m; ++i){

        if (findSet(ve[i].second.first - 1, ancestor) != findSet(ve[i].second.second - 1, ancestor)) {
            minWeight += ve[i].first;
            
            long long x = findSet(ve[i].second.first - 1, ancestor);
            long long y = findSet(ve[i].second.second - 1, ancestor);

            if (x != y){
                ancestor[y] = x;
            }
        }
    }

    fout << minWeight;
    
    return 0;
}

