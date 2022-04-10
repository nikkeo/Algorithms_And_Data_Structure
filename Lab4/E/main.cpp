#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int binaryserchLow(int arr[1000000], int left,int right, int whattosearch){

    int midle;
    while ((left + 1) < right){
        midle = (right + left) / 2;

        if (arr[midle] < whattosearch){
            left = midle;
        }
        else{
            right = midle;
        }
    }

    if (whattosearch == arr[left]){
        return ++left;
    }
    else if (whattosearch == arr[right]){
        return ++right;
    }
    else{
        return -1;
    }
}

int binaryserchhIGH(int arr[1000000], int left,int right, int whattosearch){

    int midle;
    while ((left + 1) < right){
        midle = (right + left) / 2;

        if (arr[midle] <= whattosearch){
            left = midle;
        }
        else{
            right = midle;
        }
    }

    if (whattosearch == arr[right]){
        return ++right;
    }
    else if (whattosearch == arr[left]){
        return ++left;
    }
    else{
        return -1;
    }
}

int binaryserchlow(int arr[1000000], int left,int right, int whattosearch){

    int midle = (left+right) / 2;

    if (right >= left){
        if (arr[midle] == whattosearch){
            return ++midle;
        }
        else if(arr[midle] < whattosearch){
            return binaryserchlow(arr, midle + 1, right, whattosearch);
        }
        else{
            return binaryserchlow(arr, left, midle - 1, whattosearch);
        }
    }
    else{
        return -1;
    }
}
int main() {

    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");

    int a[1000000];
    int n, num, k, first, second;

    fin >> n;

    for (int i = 0; i < n; ++i){
        fin >> num;
        a[i] = num;
    }

    fin >> k;

    for (int i = 0; i < k; ++i){
        fin >> num;

        first = binaryserchLow(a, 0, n - 1, num);
        second = binaryserchhIGH(a, 0, n - 1, num);

        fout << first << " " << second << endl;
    }


    return 0;
}
