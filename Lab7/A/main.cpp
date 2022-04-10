#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

void treeBalance(int arr[][5], int cur){
    if (cur != -1){
        treeBalance(arr, arr[cur][2]);
        treeBalance(arr, arr[cur][1]);

        arr[cur][3] = 1 + max(arr[arr[cur][2]][3], arr[arr[cur][1]][3]);
        arr[cur][4] = arr[arr[cur][2]][3] - arr[arr[cur][1]][3];
    }
}


int main() {

    int n, k, l, r, x;

    ifstream fin("balance.in");
    ofstream fout("balance.out");

    fin >> n;
    int arr[n][5];
    //arr[i][0] - key
    //arr[i][1] - left
    //arr[i][2] - right
    //arr[i][3] - hight
    //arr[i][4] - balance

    for (int i = 0; i < n; ++i){
        fin >> k >> l >> r;
        arr[i][0] = k;
        arr[i][1] = --l;
        arr[i][2] = --r;
        arr[i][3] = 1;
        arr[i][4] = 0;
    }

    treeBalance(arr, 0);

    for (int i = 0; i < n; ++i){
        if (i != 0){
            fout << endl;
        }
        fout << arr[i][4];
    }
    return 0;
}