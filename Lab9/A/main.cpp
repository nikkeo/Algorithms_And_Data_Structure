#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


void dfs(int &cicle, int cur, vector <int> ve[], vector <int> &used, vector <int> &sorted_ve){

	if (cicle){
		return;
	}

	used[cur] = 1;

	for (int i = 0; i < ve[cur].size(); ++i){
		if (used[ve[cur][i]] == 1){
			cicle = 1;
			return;
		}
		else if(used[ve[cur][i]] == 0){
			dfs(cicle, ve[cur][i], ve, used, sorted_ve);
		}
	
	}
	sorted_ve.push_back(cur);
	used[cur] = 2;
}


int main(){

	ifstream fin("topsort.in");
    ofstream fout("topsort.out");

    int n, m, from, to, cicle = 0;

    fin >> n >> m;;

    vector <int> ve[n];
    vector <int> used;
    vector <int> sorted_ve;



    for (int i = 0; i < m; ++i){
    	fin >> from >> to;
    	ve[--from].push_back(--to);
    }

    for (int i = 0; i < n; ++i){
    	used.push_back(0);
    }

    for (int i = 0; i < n; ++i){
    	if (!used[i]){
    		dfs(cicle, i, ve, used, sorted_ve);
    	}
    }

    if (cicle || sorted_ve.size() != n){
    	fout << -1;
    	return 0;
    }

    for (int i = sorted_ve.size() - 1; i >= 0; --i){
    	cout << sorted_ve[i] + 1;
    	if (i != 0){
    		cout << " ";
    	}
    }

	return 0;
}