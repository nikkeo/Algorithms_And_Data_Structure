#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;

vector <long long int> merge_sort(vector <long long int> ved){

    long long int id, jd, kd, le, m, n;
    vector <long long int> lef, rig, suma;
    le = ved.size();

    if (le == 1 or le == 0){
        return ved;
    }

    for (int i = 0; i < le; ++i){
        if (i < (le/2)){
            lef.push_back(ved[i]);
        }
        else{
            rig.push_back(ved[i]);
        }
    }

    lef = merge_sort(lef);
    rig = merge_sort(rig);

    for (int i = 0; i < (lef.size() + rig.size()); ++i){
        suma.push_back(0);
    }

    n = lef.size();
    m = rig.size();
    id = 0;
    jd = 0;
    kd = 0;

    while (id < n or jd < m){
        if (id == n){
            suma[kd++] = rig[jd++];
        }
        else if ((jd == m) or (lef[id] <= rig[jd])){
            suma[kd++] = lef[id++];
        }
        else{
            suma[kd++] = rig[jd++];
            cnt += (n - id);
        }
    }

    for (int i = 0; i < ved.size(); ++i){
        ved[i] = suma[i];
    }

    return ved;
}

int main() {
    ifstream fin("inversions.in");
    ofstream fout("inversions.out");

    long long int n, left, right, chislo;
    vector <long long int> vec;
    vector <long long int> ve;

    fin >> n;

    for (int i = 1; i <= n; ++i) {
        fin >> chislo;
        ve.push_back(chislo);
    }
    merge_sort(ve);

    fout << cnt;
    return 0;
}
