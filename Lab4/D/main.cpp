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

    ifstream fin("postfix.in");
    ofstream fout("postfix.out");

    stack *stack1 = new stack;
    int num, x, y;
    char ch;

    while (fin >> ch){
        if (ch == '+'){
            x = pop(stack1);
            y = pop(stack1);
            add(stack1, x + y);
        }
        else if (ch == '-'){
            x = pop(stack1);
            y = pop(stack1);
            add(stack1, y - x);
        }
        else if (ch == '*'){
            x = pop(stack1);
            y = pop(stack1);
            add(stack1, x * y);
        }
        else{
            num = ch - '0';
            add(stack1, num);
        }
    }

    fout << stack1->el;
    return 0;
}
