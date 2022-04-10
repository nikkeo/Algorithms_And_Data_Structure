#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;


int height_of_tree(int arr[200000][3], int key){
    //cout << arr[key][0] << " " << arr[key][1] << " " << arr[key][2] << " " << *arr[ arr[key][2] - 1] << " " << *arr[ arr[key][1] - 1] << endl;
    if (arr[key][1] != 0 && arr[key][2] != 0){
        return 1 + max(height_of_tree(arr, (arr[key][1] - 1)), height_of_tree(arr, (arr[key][2]) - 1));
    }
    else if(arr[key][1] != 0){
        return 1 + height_of_tree(arr, arr[key][1] - 1);
    }
    else if(arr[key][2] != 0){
        return 1 + height_of_tree(arr, arr[key][2] - 1);
    }
    return 1;
}


int main() {

    ifstream fin("height.in");
    ofstream fout("height.out");

    int arr[200000][3];
    int n;

    fin >> n;

    for (int i = 0; i < n; ++i){
        fin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    if (n == 0){
        fout << 0;
    }
    else{
        fout << height_of_tree(arr, 0);
    }

    return 0;
}