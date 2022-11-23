#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

class MaxHeap{
    vector<int> heap;
    int size;
    int parent(int i){
        return i/2;
    }
    int left_child(int i){
        return 2*i;
    }
    int right_child(int i){
        return 2*i+1;
    }
    void max_heapify(int i){
        int l = left_child(i);
        int r = right_child(i);
        int largest_num;
        if(l <= size && heap[l] > heap[i])
            largest_num = l;
        else
            largest_num = i;
        if(r <= size && heap[r] > heap[largest_num])
            largest_num = r;
        if(largest_num != i){
            int temp = heap[i];
            heap[i] = heap[largest_num];
            heap[largest_num] = temp;
            max_heapify(largest_num);
        }
    }

public:
// add method to add an element to the max_heap
    void Add(int n){
        heap.push_back(n);
        size += 1;
        int index = size-1;
        int par = parent(index);
        while(index != 0 && heap[index] > heap[par]){
            int temp = heap[index];
            heap[index] = heap[par];
            heap[par] = temp;
            index = par;
            par = parent(index);
        }
    }

    void printer(){
        for(auto item:heap){
            cout<<item<<",";
        }
        cout<<endl;
    }

};

int main(){
    MaxHeap heap;
    heap.Add(10);
    heap.Add(9);
    heap.Add(6);
    heap.printer();
    heap.Add(8);
    heap.printer();
    heap.Add(2);
    heap.printer();
    heap.Add(7);
    heap.printer();
    return 0;
};
