#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, from, to;

    fin >> n >> m;

    int matrix[n][n];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i){
        fin >> from >> to;
        matrix[--from][--to] = 1;
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (matrix[i][j] == 1){
                fout << 1;
            }
            else{
                fout << 0;
            }
            if (j != (n - 1)){
                fout << " ";
            }
        }
        if (i != (n - 1)){
            fout << endl;
        }
    }
    return 0;
}
