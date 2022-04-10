#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    ifstream fin("brackets.in");
    ofstream fout("brackets.out");

    char stack[1000001];
    int n = 1, vari, cnt = 0;
    char ch;

    while (fin.get(ch)){
        if (ch == '\n'){
            if (n and cnt != 1){
                fout << "YES" << endl;
            }
            else {
                fout << "NO" << endl;
            }
            n = 1;
            cnt = 0;
        }

        //cout << ch << endl;

        if (n){
            if (ch == '('){
                stack[cnt++] = '(';
            }
            else if (ch == ')' and stack[cnt - 1] != '('){
                n = 0;
            }
            else if ((ch == ')' and stack[cnt - 1] == '(')){
                cnt--;
            }

            if (ch == '['){
                stack[cnt++] = '[';
            }
            else if (ch == ']' and stack[cnt - 1] != '['){
                n = 0;
            }
            else if ((ch == ']' and stack[cnt - 1] == '[')){
                cnt--;
            }
        }
    }
    return 0;
}