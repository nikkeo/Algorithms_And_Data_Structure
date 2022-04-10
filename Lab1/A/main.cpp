#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
long long int a, b, c, d;
string myText;
 
int main() {
    ifstream fin("aplusb.in");
    ofstream fout("aplusb.out");
    fin >> a >> b;
    fout << a + b << endl;
 
    fout.close();
    fin.close();
    return 0;
}
