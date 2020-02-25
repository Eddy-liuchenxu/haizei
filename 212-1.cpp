/*************************************************************************
	> File Name: 212-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月24日 星期二 20时39分09秒
 ************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;
struct stu{
    char name[10];
}arr[10];
bool cmp(stu a, stu b) {
    int t  = strcmp(a.name, b.name);
    return t < 0;
}
int main() {
    for(int i = 0; i < 10; i++) {
        cin >> arr[i].name;
    }
    sort(arr, arr + 10, cmp);
    return 0;
}
