#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


void bfs(vector <vector <int> > &ve, int color, int current){
    if (ve[current][0] != 0){
        return;
    }
    ve[current][0] = color;
    //cout << current + 1 << endl;
    for (int i = 1; i < ve[current].size(); ++i) {
        bfs(ve, color, ve[current][i]);
    }
    //cout << "end" << endl;
}


int main() {

    ifstream fin("components.in");
    ofstream fout("components.out");

    vector <vector <int> > ve;
    vector <int> ve1;
    ve1.push_back(0);
    int n, m, from, to, color = 0;

    fin >> n >> m;

    for (int i = 0; i < n; ++i){
        ve.push_back(ve1);
    }

    for (int i = 0; i < m; ++i){
        fin >> from >> to;

        ve[--from].push_back(--to);
        ve[to].push_back(from);
    }

    for (int i = 0; i < n; ++i){
        if (ve[i][0] == 0){
            color++;
            bfs(ve, color, i);
        }
        else{
            bfs(ve, ve[i][0], i);
        }
    }
    fout << color << endl;
    for (int i = 0; i < n; ++i){
        fout << ve[i][0] << " ";
    }
    return 0;
}
