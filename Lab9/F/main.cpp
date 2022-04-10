#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
 
using namespace std;
 
 //just modified dfs
void Game(int s, vector <int> ve[], vector <bool>& used, vector <bool>& game){
    used[s] = 1;

    for (int i = 0; i < ve[s].size(); ++i){
        if (!used[ve[s][i]]){
            Game(ve[s][i], ve, used, game);
        }

        if (!game[s] && !game[ve[s][i]]){
            game[s] = 1;
        }
    }

    if (ve[s].empty()){
        game[s] = 0;
        return;
    }
}


int main(){
   
    ifstream fin("game.in");
    ofstream fout("game.out");
 
    int n, m, s, from, to;
 
    fin >> n >> m >> s;
 
    vector <int> ve[n];
    vector <bool> used;
    vector <bool> game;
 
    used.assign(n, 0);
    game.assign(n, 0);
   
    for (int i = 0; i < m; ++i){
        fin >> from >> to;
        ve[--from].push_back(--to);
    }
 

    Game(s, ve, used, game);

    if (game[s]){
        fout << "First player wins";
    }
    else{
        fout << "Second player wins";
    }

    return 0;
}