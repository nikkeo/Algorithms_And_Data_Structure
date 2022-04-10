#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("queue.in");
    ofstream fout("queue.out");

    int queue[1000001];
    int n, vari, cnt = 0, cnttop = 0;
    char ch;

    fin >> n;

    for (int i = 0; i < n; ++i){
        fin >> ch;
        if (ch == '-'){
            fout << queue[cnt++] << endl;
        }
        else if (ch == '+'){
            fin >> vari;
            queue[cnttop++] = vari;
        }
        else{
            vari = ch - '0';
        }

    }
    return 0;
}
