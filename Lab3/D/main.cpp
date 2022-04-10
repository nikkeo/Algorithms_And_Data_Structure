#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;


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

    int n, m, num = 0;
    string str;
    int arr[1000001];
    int arrdop[1000001];

    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");

    while (fin >> str){
        if (str == "push"){
            fin >> n;
            arr[num] = n;
            arrdop[num++] = n;
        }
        else if (str == "extract-min"){
            if (num == 0){
                fout << '*' << endl;
            }
            else{
                heapsort(arr, num);
                fout << arr[0] << endl;
                num--;
                arr[0] = arr[num];
            }
        }
        else{
            fin >> n >> m;
            int dop = arrdop[n - 1];
            for (int i = 0; i < num; ++i){
                if (arr[i] == dop){
                    arr[i] = m;
                    arrdop[n-1] = m;
                    break;
                }
            }
        }
    }
    return 0;
}