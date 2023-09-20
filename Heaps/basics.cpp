#include<iostream>

using namespace std;

class Heaps{
    public:
        int arr[101]; 
        int size;

        Heaps() {
            size = 0;
        }

        void insert(int value) {
            //data ko array ke last mein place karna hai and insertion 1 se start karna hai
            size = size + 1;
            int index = size;
            arr[index] = value;
           

            while(index > 1) {
                int parentIndex = index/2; 

                if(arr[index] > arr[parentIndex]) {
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else{
                    break;
                }
            }
        }
        int deletion() {
            int ans = arr[1];
            arr[1] = arr[size];
            size--;
           
           //place root node on its right position
           int index = 1;
           while( index < size) {
                int left = 2*index;
                int right = 2*index + 1;

                int largest = index;

                if(left < size && arr[largest] < arr[left] )
                    largest = left;

                if(right < size && arr[largest] < arr[right])
                    largest = right;

                if(largest == index)
                    return ans;
                else 
                    swap(arr[index], arr[largest]);
           }

        }
};
int main()
{
    Heaps h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;
    // h.size = 5;

    h.insert(100);
    h.insert(70);
    h.insert(80);
    h.insert(30);
    h.insert(40);
    h.insert(50);

           

    cout<<"Printing Heap: "<<endl;
    for(int i=0; i<= h.size; i++) {
        cout<< h.arr[i] <<" ";
    }
    cout<<endl;
   

}