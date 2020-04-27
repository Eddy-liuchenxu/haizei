/*************************************************************************
	> File Name: 14.template.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月23日 星期一 23时48分45秒
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
    return a + b;
}

template<typename T>
class Array{
public:
    Array(int n) : n(n) {
        this->arr = new T[n];

    }
    T &operator[](int ind){
        if(ind < 0 || ind > n) {
            return this->__end;
        }
        return this->arr[ind];
    }
private :
    T *arr;
    T __ end;
    int n;
};

ostream &operator<<(ostream &out,)

int main() {
    Array<int> a(10);
    a[0] = 123;
    cout << add(2,3) << endl;
    cout << add(1.2,2.3) << endl;
    cout << add<int>(2.0,3) << endl;
}
