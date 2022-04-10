#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void sortirovka(string *arr, int n, int key){
    int cnt[n];
    int cntmin[n];
    string final[n];

    for (int i = 0; i < n; ++i){
        cnt[i] = 0;
        cntmin[i] = 0;
    }

    for (int i = 0; i < n; ++i){
        cntmin[(arr[i][key] - '0') - 49]++;
        cnt[(arr[i][key] - '0') - 49]++;
    }
    for (int i = 1; i < n; ++i){
        cntmin[i] += cntmin[i - 1];
    }


    for (int i = 0; i < n; ++i){
        int curkey = (arr[i][key] - '0') - 49;
        final[cntmin[curkey] - cnt[curkey]] = arr[i];
        cnt[curkey]--;
    }

    for (int i = 0; i < n; ++i){
        arr[i] = final[i];
    }
}

int main() {

    int n, m, k, num;
    string str;

    ifstream fin("radixsort.in");
    ofstream fout("radixsort.out");

    fin >> n >> m >> k;
    string arr[n];
    //vector <string> ve;

    for(int i = 0; i < n; ++i){
        fin >> str;
        arr[i] = str;
        //ve.push_back(str);
    }

    for (int i = m - 1; i >= m - k; --i){
        sortirovka(arr, n, i);
    }

    for (int i = 0; i < n; ++i){
        if (i != 0){
            fout << '\n';
        }
        fout << arr[i];
    }
    return 0;
}