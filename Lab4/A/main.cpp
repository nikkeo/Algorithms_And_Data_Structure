#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct stack{
    int el;
    stack *next;
};

void add(stack* &newer, int num){
    stack *newone = new stack;

    newone->el=num;
    newone->next=newer;

    newer = newone;
}

int pop(stack* &newer){
    int var = newer->el;
    newer = newer -> next;

    return var;
}
int main() {

    ifstream fin("stack.in");
    ofstream fout("stack.out");

    stack *sta = new stack;

    int n, el, nfirst = 0;
    char ch;

    fin >> n;

    for (int i = 0; i < n; ++i){
        fin >> ch;
        if (ch == '-'){
            if (nfirst){
                fout << endl;
            }
            nfirst = 1;
            fout << pop(sta);
        }
        else{
            fin >> el;
            add(sta, el);
        }
    }
    return 0;
}
