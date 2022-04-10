#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

#define left 2*root+1
#define right 2*root+2

using namespace std;

void forheap (int *arr, int downel, int root){
    int Descendant = root;

    //cout << root << " " << downel << endl;
    if ((left) < downel){
        Descendant = root;

        if (downel > left){
            if (arr[left] > arr[Descendant]){
                Descendant = left;
            }
        }
        if (downel > right){
            if (arr[right] > arr[Descendant]){
                Descendant = right;
            }
        }

        if (Descendant != root){
            swap(arr[root], arr[Descendant]);
            forheap(arr, downel, Descendant);
        }
    }
}

void heapsort(int arr[], int n){

    for (int i = (n / 2 - 1); i >= 0; --i){
        forheap(arr, n, i);
    }
    for (int i = (n - 1); i >= 0; i--) {
        swap(arr[0], arr[i]);
        forheap(arr, i, 0);
    }
    return;
}

int main() {

    int n, num;

    ifstream fin("sort.in");
    ofstream fout("sort.out");

    fin >> n;
    int arr[n];

    for(int i = 0; i < n; ++i){
        fin >> num;
        arr[i] = num;
    }

    n = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr, n);

    for (int i = 0; i < n; ++i){
        if (i != 0){
            fout << " ";
        }
        fout << arr[i];
    }
    return 0;
}
