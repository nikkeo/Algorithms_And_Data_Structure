#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

int a, b, c, d, x, y, m, n, k;

int main() {

    ifstream fin("turtle.in");
    ofstream fout("turtle.out");
    vector <vector <int> > vec;
    vector <int> ve;
    long long int h, w, q, suma;
    suma = 0;

    fin >> h >> w;

    for (int i = 0; i < h; ++i){
        ve.clear();
        for (int j = 0; j < w; ++j){
            fin >> q;
            ve.push_back(q);
        }
        vec.push_back(ve);
    }

    for (int i = (h-1); i >= 0; --i){
        for (int j = 0; j < w; ++j){
            if (i != (h - 1)){
                if (j != 0){
                    vec[i][j] += max(vec[i + 1][j], vec[i][j - 1]);
                }
                else{
                    vec[i][j] += vec[i + 1][j];
                }
            }
            else{
                if (j != 0){
                    vec[i][j] += vec[i][j - 1];
                }
            }
        }
    }

    fout << vec[0][w-1];

    return 0;
}
