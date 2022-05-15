#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, from, to;

    fin >> n >> m;

    vector <int> ve[n];
    int cnt[n];

    for (int i = 0; i < m; ++i){
    	fin >> from >> to;
    	ve[--from].push_back(--to);
    	ve[to].push_back(from);
    }

    for (int i = 0; i < n; ++i){
    	fout << ve[i].size();
    	if (i != n - 1){
    		fout << " ";
    	}
    }
    
    return 0;
}
