#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
 
using namespace std;
long long int a, b, c, d;
string myText;
 
int main() {
    ifstream fin("aplusbb.in");
    ofstream fout("aplusbb.out");
    fin >> a >> b;
    fout << a + (b*b) << endl;
 
    fout.close();
    fin.close();
    return 0;
}
