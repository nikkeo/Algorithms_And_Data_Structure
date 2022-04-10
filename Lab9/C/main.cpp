#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


void dfs(int cur, vector <int> ve[], vector <int> &color, int colour){
    
    color[cur] = colour;

    for (int i = 0; i < ve[cur].size(); ++i){
        if (color[ve[cur][i]] == 0){
            dfs(ve[cur][i], ve, color, 3 - colour);
        }
        else if (color[ve[cur][i]] == colour){
            cout << "NO";
            exit(0);
        }
    }
}
 
 

int main(){
 
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");
 
    int n, m, from, to;
 
    fin >> n >> m;;
 
    vector <int> ve[n];
    vector <int> color;
 
 
 
    for (int i = 0; i < m; ++i){
        fin >> from >> to;
        ve[--from].push_back(--to);
        ve[to].push_back(from);
    }
 
    for (int i = 0; i < n; ++i){
        color.push_back(0);
    }
 
    for (int i = 0; i < n; ++i){
        if (color[i] == 0){
            dfs(i, ve, color, 1);
        }
    }

    
    cout << "YES";

    return 0;
}