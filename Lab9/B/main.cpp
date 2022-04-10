#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void dfs(int &cicle, int cur, vector <int> ve[], vector <int> &used, vector <int> &path){
 
    if (cicle != -1){
        return;
    }
 
    used[cur] = 1;
    path.push_back(cur);

    for (int i = 0; i < ve[cur].size(); ++i){
        if (used[ve[cur][i]] == 1){
            path.push_back(ve[cur][i]);
            cicle = ve[cur][i];
            return;
        }
        else if (used[ve[cur][i]] == 0){
            dfs(cicle, ve[cur][i], ve, used, path);
        }
        if (cicle != -1){
            return;
        }
    }

    used[cur] = 2;
    path.pop_back();
}
 
 
int main(){
 
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");
 
    int n, m, from, to, cicle = -1;
 
    fin >> n >> m;;
 
    vector <int> ve[n];
    vector <int> used;
    vector <int> path;
 
 
 
    for (int i = 0; i < m; ++i){
        fin >> from >> to;
        ve[--from].push_back(--to);
    }
 
    for (int i = 0; i < n; ++i){
        used.push_back(0);
    }
 
    for (int i = 0; i < n; ++i){
        if (cicle != -1){
            break;
        }
        if (used[i] == 0){
            dfs(cicle, i, ve, used, path);
        }
    }
    
    //cout << cicle;

    if (cicle == -1){
        fout << "NO";
        return 0;
    }

    fout << "YES" << endl;

    int cnt = 0;
    while (path[cnt] != cicle){
        cnt++;
    }

    for (;cnt < path.size() - 1; ++cnt){
        fout << path[cnt] + 1;
        if (cnt != path.size() - 2){
            fout << " ";
        }
    }

    // for (int i = 0; i < n; ++i){
    //     cout << used[i] << " ";
    // }

    return 0;
}