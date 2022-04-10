#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
 
void auxiliary_dfs(int cur, vector <int> ve[], vector <bool> &used, vector <int> &orderness){
 
    used[cur] = 1; 
 
 
    for (int i = 0; i < ve[cur].size(); ++i){
        if (!used[ve[cur][i]]){
            auxiliary_dfs(ve[cur][i], ve, used, orderness);
        }
    }
 
    orderness.push_back(cur); 
}
  
 void dfs(int cur, vector <int> reversed_ve[], vector <bool> &used, vector <int> &strong_components){
    used[cur] = 1;
 
    strong_components.push_back(cur);
 
    for (int i = 0; i < reversed_ve[cur].size(); ++i){
        if (!used[reversed_ve[cur][i]]){
            dfs(reversed_ve[cur][i], reversed_ve, used, strong_components);
        }
    }
 }
  
 
int main(){
  
    ifstream fin("cond.in");
    ofstream fout("cond.out");
  
    int n, m, from, to, num = 1;
  
    fin >> n >> m;;
 
    vector <int> ve[n], reversed_ve[n];
    vector <int> strong_components;
    vector <int> orderness;
    vector <bool> used;

    int result[n];
 
    for (int i = 0; i < m; ++i){
        fin >> from >> to;
        ve[--from].push_back(--to);
        reversed_ve[to].push_back(from);
    }

    used.assign(n, 0);
    for (int i = 0; i < n; ++i){
        if (!used[i]){
            auxiliary_dfs(i, ve, used, orderness);
        }
    }

    used.assign(n, 0);
    for (int i = 0; i < n; ++i){

        if (!used[orderness[n - i - 1]]){
            dfs(orderness[n - i - 1], reversed_ve, used, strong_components);

            for(int i = 0; i < strong_components.size(); ++i){
                result[strong_components[i]] = num;
            }
            num++;

            strong_components.clear();
        }
    }

    fout << num - 1 << endl;
    for(int i = 0; i < n; ++i){
        fout<<result[i]<<" ";
    }

    return 0;
}