#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

long long int a, b, c, d, x, y, m, n, k;
vector <int> final;


int main() {
    ifstream fin("smallsort.in");
    ofstream fout("smallsort.out");

    fin >> k;

    for (int i = 0; i < k; ++i){
        fin >> a;
        final.push_back(a);
    }

    for (int i = 0; i < (k-1); ++i){
        for (int j = i + 1; j < k; ++j){
            if (final[i] > final[j]){
                swap(final[i], final[j]);
            }
        }
    }

    for (int i = 0; i < k; ++i){
        fout << final[i];
        if (i != (k - 1)){
            fout << " ";
        }
    }
    
    fout.close();
    fin.close();
    return 0;
}
