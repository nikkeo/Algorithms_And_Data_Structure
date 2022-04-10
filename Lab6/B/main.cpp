#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;



int main() {

    ifstream fin("check.in");
    ofstream fout("check.out");

    int n, k, l, r;
    string str;

    fin >> n;

    int arr[n][5];

    for (int i = 0; i < n; ++i){
        fin >> k >> l >> r;
        --l;
        --r;
        arr[i][0] = k;
        arr[i][1] = l;
        arr[i][2] = r;
        arr[i][3] = -1;
        arr[i][4] = -1;
    }

    for (int i = 0; i < n; ++i){
        if (arr[i][1] != 0){
            arr[arr[i][1]][3] = i;
        }
        if (arr[i][2] != 0){
            arr[arr[i][2]][4] = i;
        }
        //cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << " " << arr[i][4] << " " << endl;
    }

    int max, min, midle = arr[0][0];
    for (int i = 0; i < n; ++i){
        if (arr[i][3] == -1 && arr[i][4] == -1){
            //cout << arr[arr[i][1]][0] << " " << arr[arr[i][2]][0] << " " << arr[i][0] << endl;
            if (arr[i][1] != -1){
                if (arr[arr[i][1]][0] >= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
            }
            if (arr[i][2] != -1){
                if (arr[arr[i][2]][0] <= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
            }
        }
        else if(arr[i][3] == -1){
            max = arr[arr[i][4]][0];
            int current = arr[i][4];
            while (current < n && current > -1){
                if (arr[current][0] >= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
                current = arr[current][4];
            }

            if (max >= arr[i][0] && midle>= arr[i][0]){
                fout << "NO";
                return 0;
            }
            if (arr[i][1] != -1){
                if (arr[arr[i][1]][0] >= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
                if (arr[arr[i][1]][0] <= max && arr[arr[i][1]][0] <= midle ){
                    fout << "NO";
                    return 0;
                }
            }
            if (arr[i][2] != -1){
                if (arr[arr[i][2]][0] <= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
                if (arr[arr[i][2]][0] <= max && arr[arr[i][2]][0] <= midle){
                    fout << "NO";
                    return 0;
                }
            }
        }
        else{
            min = arr[arr[i][3]][0];

            int current = arr[i][3];
            while (current < n && current > -1){
                if (arr[current][0] <= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
                current = arr[current][3];
            }
            if (min <= arr[i][0] && midle <= arr[i][0]){
                fout << "NO";
                return 0;
            }
            if (arr[i][1] != -1){
                if (arr[arr[i][1]][0] >= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
                if (arr[arr[i][1]][0] >= min && arr[arr[i][1]][0] >= midle){
                    fout << "NO";
                    return 0;
                }
            }
            if (arr[i][2] != -1){
                if (arr[arr[i][2]][0] <= arr[i][0]){
                    fout << "NO";
                    return 0;
                }
                if (arr[arr[i][2]][0] >= min && arr[arr[i][2]][0] >= midle){
                    fout << "NO";
                    return 0;
                }
            }
        }
    }

    fout << "YES";
    return 0;
}