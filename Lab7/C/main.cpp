#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;


ifstream fin("addition.in");
ofstream fout("addition.out");

struct tree{
    int el = NULL;
    tree *right = NULL;
    tree *left = NULL;
    int hight = 1;
};


int isHeight(tree *Tree){
    if (Tree == NULL){
        return 0;
    }
    return Tree->hight;
}


int showBalance(tree *Tree){
    if (Tree == NULL){
        return 0;
    }
    else{
        return isHeight(Tree->left) - isHeight(Tree->right);
    }
}


tree *leftRotation(tree *Tree){
    tree *newTree = Tree->right;
    tree *rotationHelp = newTree->left;

    newTree->left = Tree;
    Tree->right = rotationHelp;

    Tree->hight = 1 + max(isHeight(Tree->left), isHeight(Tree->right));
    newTree->hight = 1 + max(isHeight(newTree->left), isHeight(newTree->right));

    return newTree;
}


tree *rightRotation(tree *Tree){
    tree *newTree = Tree->left;
    tree *rotationHelp = newTree->right;

    newTree->right = Tree;
    Tree->left = rotationHelp;

    Tree->hight = 1 + max(isHeight(Tree->left), isHeight(Tree->right));
    newTree->hight = 1 + max(isHeight(newTree->left), isHeight(newTree->right));

    return newTree;
}


tree *insert(tree *Tree, int num){
    if (Tree == NULL){
        tree *Newone = new tree;
        Newone->el = num;
        return Newone;
    }
    if (num > Tree->el){
        Tree->right = insert(Tree->right, num);
    }
    else if (num < Tree->el){
        Tree->left = insert(Tree->left, num);
    }
    else{
        return Tree;
    }

    Tree->hight = 1 + max(isHeight(Tree->left), isHeight(Tree->right));

    if (showBalance(Tree) > 1){
        if (num > Tree->left->el){
            Tree->left = leftRotation(Tree->left);
            return rightRotation(Tree);
        }
        else if (num < Tree->left->el){
            return rightRotation(Tree);
        }
    }
    if (showBalance(Tree) < -1){
        if (num > Tree->right->el){
            return leftRotation(Tree);
        }
        else if (num < Tree->right->el){
            Tree->right = rightRotation(Tree->right);
            return leftRotation(Tree);
        }
    }
    return Tree;
}


int isTree(tree *Tree){
    if (Tree == NULL){
        return 0;
    }
    return Tree->el;
}


void printedTree(tree *Tree, int first, int cnt){
    if (Tree != NULL){
        if (!first){
            fout << endl;
        }
        fout << Tree->el;
        if (Tree->left != NULL){
            fout << " " << cnt++;
        }
        else{
            fout << " " << 0;
        }
        if (Tree->right != NULL){
            fout << " " << cnt++;
        }
        else{
            fout << " " << 0;
        }
        printedTree(Tree->left, 0, cnt);
        printedTree(Tree->right, 0, cnt);
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



int main() {

    int n, k, l, r, x;

    fin >> n;
    tree *Tree = NULL;

    for (int i = 0; i < n; ++i){
        fin >> k >> l >> r;
        if (!existance(k, Tree)){
            Tree = insert(Tree, k);
        }
    }
    if (n!=0) {
        fin >> x;
        Tree = insert(Tree, x);
        fout << (n + 1) << endl;

        printedTree(Tree, 1, 2);
    }
    else{
        fout << 0;
    }
    return 0;
}