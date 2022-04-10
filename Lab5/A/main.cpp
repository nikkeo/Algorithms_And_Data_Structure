#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct tree{
    int el = 100000000;
    tree *right = NULL;
    tree *left = NULL;
    tree *parent = NULL;
};

void TreePrint(tree* &Tree){
    if (Tree != NULL){
        cout << Tree->el << " ";
        TreePrint(Tree->left);
        TreePrint(Tree->right);
    }
}

void insert(tree* &Tree, tree* &Parent, int num){

    if (Tree == NULL){
        Tree = new tree;

        if (Parent == Tree){
            Tree->parent = NULL;
        }
        else{
            Tree->parent = Parent;
        }

        Tree->el = num;
    }
    else if(Tree->el == num){
        return;
    }
    else if(num > Tree->el){
        insert(Tree->right, Parent, num);
    }
    else{
        insert(Tree->left, Parent, num);
    }
}

bool existance(int num, tree* &Tree){
    if (Tree == NULL){
        return 0;
    }
    if (Tree->el == num){
        return 1;
    }
    if (num > Tree->el){
        return existance(num, Tree->right);
    }
    else{
        return existance(num, Tree->left);
    }
}

tree Next(int num, tree* &Tree){

    tree *mini = new tree;
    tree *current = Tree;

    while (current != 0){
        if (num >= current->el){
            current = current->right;
        }
        else{
            mini = current;
            current = current->left;
        }
    }

    return *mini;
}

tree Prev(int num, tree* &Tree){

    tree *maxi = new tree;
    tree *current = Tree;

    while (current != 0){
        if (num >= current->el){
            maxi = current;
            current = current->right;
        }
        else{
            current = current->left;
        }
    }

    return *maxi;
}

void del(tree* &Tree, int num){

    if (Tree == NULL){
        return;
    }

    bool b = 1;
    if (Tree->parent == NULL){
        b = 0;
    }
    if (Tree->left == NULL && Tree->right == NULL){
        if (b) {
            if (Tree->parent->left == Tree) {
                Tree->parent->left = NULL;
            }
            if (Tree->parent->right == Tree) {
                Tree->parent->right = NULL;
            }
        }
        Tree = NULL;
        delete &Tree;
    }
    else if(Tree->left == NULL){
        if (b) {
            if (Tree->parent->left == Tree) {
                Tree->parent->left = Tree->right;
            }
            else {
                Tree->parent->right = Tree->right;
            }
        }
        Tree->right->parent = Tree->parent;
        Tree = NULL;
        delete &Tree;
    }
    else if(Tree->right == NULL){
        if (b) {
            if (Tree->parent->left == Tree) {
                Tree->parent->left = Tree->left;
            }
            if (Tree->parent->right == Tree) {
                Tree->parent->right = Tree->left;
            }
        }
        Tree->left->parent = Tree->parent;
        Tree = NULL;
        delete &Tree;
    }
    else{
        tree ToDelet = Next(num, Tree);
        Tree->el = ToDelet.el;

        if (b) {
            if (ToDelet.parent->left->el == ToDelet.el) {
                ToDelet.parent->left = ToDelet.right;
            } else {
                ToDelet.parent->right = ToDelet.right;
            }
        }

        if (ToDelet.right){
            ToDelet.right->parent = ToDelet.parent;
        }
        delete &ToDelet;
    }
}


int main() {

    ifstream fin("set.in");
    ofstream fout("set.out");

    tree *arr[100000];
    string str;
    long long int num;


    while (fin >> str >> num){
        if (str == "insert"){
            insert(arr[abs(num % 100000)], arr[abs(num % 100000)], num);
        }
        else if (str == "exists"){
            if (existance(num, arr[abs(num % 100000)])){
                fout << "true" << endl;
            }
            else{
                fout << "false" << endl;
            }
        }
        else if (str == "delete"){
            del(arr[abs(num % 100000)], num);
        }
    }

    return 0;
}