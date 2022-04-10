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
    bool b = 1;

    fin >> n;

    int matrix[n][n];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            fin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i == j){
                if (matrix[i][j] == 1){
                    b = 0;
                }
            }
            if (matrix[i][j] != matrix[j][i]){
                b = 0;
            }
        }
    }

    (b && fout << "YES") || (fout << "NO");

    return 0;
}
