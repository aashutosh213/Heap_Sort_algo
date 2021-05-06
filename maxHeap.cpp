#include <iostream>
#include <vector>

using namespace std;

int Parent(int i){
    return i>>1;   // left bit shift : i<<1 ~~ i/2
}

int Right(int i){
    return (i<<1)+2; // right bit shift : i>>1 ~~ i*2
    // return (2*(i) + 2);
}

int Left(int i){
    return (i<<1)+1;
    // return (2*(i)+1);
}

void swap(int *a, int *b){
    int c{0};
    c = *a;
    *a = *b;
    *b = c;
}

void print(vector<int> vec){
    for (auto i : vec)
    {
        cout<< i<< " ,";
    }
    cout<<endl;
    cout << "------------------------------"<<endl;
}

void maxHeapify(vector<int> &vec, int i){
    int left = Left(i);//(2*i+1)
    int right = Right(i);//(2*i + 2)
    int largest = i;
    
    if(left<vec.size() && vec.at(left)> vec.at(largest))
        largest = left;
    
    if(right < vec.size() && vec.at(right)> vec.at(largest))
        largest= right;
    

    if(largest != i){
        swap(vec.at(largest), vec.at(i));
        // cout<< vec.at(largest) << ": vec at largest" <<endl;
        maxHeapify(vec,largest);
    }
    // cout<< largest<< " : largest" << endl;
}

int main(){
    vector<int> vec{1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    print(vec);
    int n =vec.size();

    for(int i{(n/2)-1};i>=0;i--){
        maxHeapify(vec,i);
    }

    print(vec);

    return 0;
}