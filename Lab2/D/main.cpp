#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("antiqs.in");
    ofstream fout("antiqs.out");
    vector<long long int> vec;
    vector<long long int> ve;
    long long int n, q, suma;

    fin >> n;

    if (n == 1){
        fout << 1;
    }
    if (n == 2){
        fout << 2 << " " << 1;
    }
    else if (n > 2){
        for (int i = 1; i <= n; i+=2){
            fout << i;
            if (i != 2){
                fout << " ";
            }
        }
        for (int i = (int(n / 2) * 2); i >= 2; i-=2){
            fout << i << " ";
        }
    }
}
