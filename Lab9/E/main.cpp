#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
 
void dfs(int cur, vector <int> ve[], vector <bool>& used, vector <int>& orderness){
    used[cur] = 1;

    for (int i = 0; i < ve[cur].size(); ++i){
        if (!used[ve[cur][i]]){
            dfs(ve[cur][i], ve, used, orderness);
        }
    }

    orderness.push_back(cur);
}
 
bool ifHamiltonianPath(vector <int> ve[], vector <int> orderness){
    bool b;

    for (int i = 1; i < orderness.size(); ++i){
        b = 0;
        for (int j = 0; j < ve[orderness[i - 1]].size(); ++j){
            if (ve[orderness[i - 1]][j] == orderness[i]){
                b = 1;
                break;
            }
        }

        if (!b){
            return 0;
        }
    }

    return 1;
}


int main(){
   
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");
 
    int n, m, from, to;
 
    fin >> n >> m;
 
    vector <int> ve[n];
    vector <bool> used;
    vector <int> orderness;
 
    used.assign(n, 0);
   
    for (int i = 0; i < m; ++i){
        fin >> from >> to;
        ve[--from].push_back(--to);
    }
 

    for (int i = 0; i < n; ++i){
        if (!used[i]){
            dfs(i, ve, used, orderness);
        }
    }

    reverse(orderness.begin(), orderness.end());

    if (ifHamiltonianPath(ve, orderness)){
        fout << "YES";
    }
    else{
        fout << "NO";
    }
    
    return 0;
}