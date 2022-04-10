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
    bool b = 0;

    fin >> n >> m;

    int matrix[n][n];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i){
        fin >> from >> to;
        matrix[--from][--to]++;
        matrix[to][from]++;
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (matrix[i][j] > 1){
                b = 1;
            }
        }
    }

    (b && fout << "YES") || (fout << "NO");

    return 0;
}
