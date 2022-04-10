#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


void bfs(vector <vector <int> > ve, int destination[], int used[], int cur){
    if (used[cur] != 1){
        queue <int> q;

        q.push(cur);

        while (!q.empty()){

            for (int near:ve[q.front()]){
                if (!used[near]){
                    q.push(near);
                    used[near] = 1;
                    destination[near] = destination[q.front()] + 1;
                    destination[0] = 0;
                }
            }
            q.pop();
        }
    }
}


int main() {

    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");

    int n, m, from, to;

    fin >> n >> m;

    vector <vector <int> > ve;

    vector <int> ve1;

    int used[n];
    int destination[n];

    for (int i = 0; i < n; ++i){
        ve.push_back(ve1);
        destination[i] = 0;
        used[i] = 0;
    }

    for (int i = 0; i < m; ++i){
        fin >> from >> to;

        ve[--from].push_back(--to);
        ve[to].push_back(from);
    }

    for (int i = 0; i < n; ++i){
        bfs(ve, destination, used, i);
    }

    for (int i = 0; i < n; ++i){
        fout << destination[i];
        if (i != (n-1)){
            fout << " ";
        }
    }

    return 0;
}
