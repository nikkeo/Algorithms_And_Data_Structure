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

void insert(tree* &Tree, int num, tree* &Parent){
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
    else if(num > Tree->el){
        insert(Tree->right, num, Parent);
    }
    else{
        insert(Tree->left, num, Parent);
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

    if (num > Tree->el){
        del(Tree->right, num);
    }
    else if (num < Tree->el){
        del(Tree->left,num);
    }
    else if(Tree->right != NULL && Tree->left != NULL){
        Tree->el = Next(Tree->el, Tree->right).el;
        del(Tree->right, Tree->el);
    }
    else if(Tree->right != NULL){
        Tree = Tree->right;
    }
    else if(Tree->left != NULL){
        Tree = Tree->left;
    }
    else{
        Tree = NULL;
    }
}

int main() {

    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    int num;
    string str;
    tree *Tree =  NULL;

    while (fin >> str >> num){
        if (str == "insert"){
            insert(Tree, num, Tree);
        }
        else if (str == "delete"){
            del(Tree, num);
            //TreePrint(Tree);
            //cout << endl;
        }
        else if (str == "exists"){
            if (existance(num, Tree)){
                fout << "true" << endl;
            }
            else{
                fout << "false" << endl;
            }
        }
        else if (str == "next"){
            if (Next(num, Tree).el == 100000000){
                fout << "none" << endl;
            }
            else{
                fout << Next(num, Tree).el << endl;
            }
        }
        else{
            if (Prev(num, Tree).el == 100000000){
                fout << "none" << endl;
            }
            else{
                fout << Prev(num, Tree).el << endl;
            }
        }
    }

    return 0;
}