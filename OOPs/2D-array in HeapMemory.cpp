#include <iostream>
using namespace std;

int main() {

        //creating a 2D array in Heap memory.
        int row = 5;
        int col = 3;

        int **arr = new int*[row];

        for(int i = 0; i < row; i++) {
                arr[i] = new int[col];
        }

        // for(int i = 0; i < row; i++) {
        //         for(int j = 0; j < col; j++) {
        //                 cout << arr[i][j] <<" ";
        //         }
        //         cout<<endl;
        // }

        //de-allocating memory in 2D array

        for(int i = 0; i < row; i++) {
                delete []arr[i];
        }

        delete []arr;
        
        cout<<sizeof(arr);
  return 0;
}