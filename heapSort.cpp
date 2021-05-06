//running time O(nlogn)
#include <iostream>
#include <vector>

using namespace std;

void print(vector <int> vec){
    for (auto i : vec)
    {
        cout<< i <<", ";
    }
    cout<<endl;
    cout<< "---------------------------"<<endl;
    
}

int Parent(int i){
    return (i-1)>>1;//right bit shift
}

int Left(int i){
    return (i<<1) +1;
}

int Right(int i){
    return (i<<1) +2;
}

void swap(int *a, int*b){
    int c{0};
    c=*a;
    *a=*b;
    *b=c;
}

void maxHeapify(vector<int> &vec,int hSize, int i){
    int largest = i;
    int left = Left(i);
    int right = Right(i);

    if(left<hSize && vec.at(left)>vec.at(largest))
        largest = left;

    if(right < hSize && vec.at(right)>vec.at(largest))
        largest = right;
    
    if(largest!= i){
        swap(vec.at(largest), vec.at(i));
        maxHeapify(vec,hSize,largest);
    }
}

void buildMaxHeap(vector<int> &vec, int hSize){
    int n = vec.size();
    for(int i{(n/2) -1};i>=0;i--){
        maxHeapify(vec,hSize,i);
    }
}

int main(){
    vector<int> vec{1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = vec.size();
    int heapSize{n};
    print(vec);

    buildMaxHeap(vec,heapSize);

    print(vec);


    for(int i{n-1}; i>0;i--){
        swap(vec.at(0), vec.at(i));
        // cout<< "vec at 0:" << vec.at(0)<< endl;
        heapSize--;
        maxHeapify(vec,heapSize,0);

    }

    print(vec);
    
    return 0;
}
