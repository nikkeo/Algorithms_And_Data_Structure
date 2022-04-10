#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;



vector <double> merge_sort(vector <double> ved){

    long long int id, jd, kd, le, m, n;
    vector <double> lef, rig, suma;
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

    while (id < n and jd < m){
        if (lef[id] >= rig[jd]){
            suma[kd++] = rig[jd++];
        }
        else{
            suma[kd++] = lef[id++];
        }
    }
    while (id < n){
        suma[kd++] = lef[id++];
    }
    while (jd < m){
        suma[kd++] = rig[jd++];
    }


    for (int i = 0; i < ved.size(); ++i){
        ved[i] = suma[i];
    }

    return ved;
}


double finder(vector <double> ve, double xer){
    for (int i = 0; i < ve.size(); ++i){
        if (ve[i] == xer){
            return (i + 1);
        }
    }
}

int main() {

    ifstream fin("sortland.in");
    ofstream fout("sortland.out");
    vector <double> vec;
    vector <double> ve;
    double n, q, suma;
    long long int min, max, mid;

    fin >> n;

    for (int i = 0; i < n; ++i){
        fin >> q;
        vec.push_back(q);
    }

    ve = merge_sort(vec);

    min = finder(vec, ve[0]);
    max = finder(vec, ve[n - 1]);
    mid = finder(vec, ve[n/2]);

    fout << min << " " << mid << " " << max;

    return 0;
}
