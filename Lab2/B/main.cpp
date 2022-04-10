#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;

vector<vector<string> > mergesort(vector<vector<string> > ved){
    if (ved.size() == 1 or ved.size() == 0){
        return ved;
    }
    long long int midle = ved.size() / 2;
    vector<vector<string> > left, right, suma;

    for (int i = 0; i < ved.size(); ++i){
        if (i < midle){
            left.push_back(ved[i]);
        }
        else{
            right.push_back(ved[i]);
        }
    }

    left = mergesort(left);
    right = mergesort(right);

    long long int id = 0, jd = 0, sd = 0;

    while (id < left.size() and jd < right.size()){
        if (left[id][0] > right[jd][0]){
            suma.push_back(right[jd++]);
        }
        else{
            suma.push_back(left[id++]);
        }
    }
    while (id < left.size()){
        suma.push_back(left[id++]);
    }
    while (jd < right.size()){
        suma.push_back(right[jd++]);
    }

    return suma;
}


int main() {

    ifstream fin("race.in");
    ofstream fout("race.out");

    vector<vector<string> > vec, ve;

    long long int n, q, suma;
    long long int min, max, mid;
    string vvod_strana, vvod_familia;

    fin >> n;

    for (int i = 0; i < n; ++i){
        fin >> vvod_strana >> vvod_familia;
        bool b = 1;
        for (int u = 0; u < vec.size(); ++u){
            if (vec[u][0] == vvod_strana) {

                vec[u].push_back(vvod_familia);

                b = 0;
                break;
            }
        }

        if (b){
            vector <string> ve;
            ve.push_back(vvod_strana);
            ve.push_back(vvod_familia);
            vec.push_back(ve);
        }
    }

    vec = mergesort(vec);

    for (int i = 0; i < vec.size(); ++i){
        fout << "=== " << vec[i][0] << " ===" << endl;

        for (int z = 1; z < vec[i].size(); ++z){
            fout << vec[i][z] << endl;
        }
    }
}