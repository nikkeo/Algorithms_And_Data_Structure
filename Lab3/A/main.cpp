#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;


string isheap(vector <int> vec, int lenght){

    for (int i = 1; i <= (lenght / 2); ++i){

        if ((2 * i < lenght) && (vec[i] > vec[2 * i])){
            return "NO";
        }
        if (((2 * i + 1) < lenght) && (vec[i] > vec[2 * i + 1])){
            return "NO";
        }
    }

    return "YES";
}


int main() {

    int n, num;
    vector <int> ve;

    ifstream fin("isheap.in");
    ofstream fout("isheap.out");

    fin >> n;
    ve.push_back(0);

    for(int i = 0; i < n; ++i){
        fin >> num;
        ve.push_back(num);
    }

    n++;

    fout << isheap(ve, n);

    return 0;
}
