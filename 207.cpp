/*************************************************************************
	> File Name: 207.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月28日 星期三 17时55分25秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cinttypes>
using namespace std;
#define max_n 30
struct stdu{
	char name[max_n + 5];
	int math;
	int chin;
	int engl;
	int gol;
	int sum;
};

bool cmp(stdu a, stdu b) {
	return a.sum > b.sum;
}

int main() {
	int n, max = 0, min = INT32_MAX;
	cin >> n;
	struct stdu studs[max_n + 5];
	for(int i = 0; i < n; i++) {
		cin >> studs[i].name >> studs[i].math >> studs[i].chin >> studs[i].engl >> studs[i].gol;
		studs[i].sum = studs[i].math + studs[i].chin + studs[i].engl + studs[i].gol;
		if(studs[i].math > max) {
			max = studs[i].math;
		}
		if(studs[i].chin > max) {
			max = studs[i].chin;
		}
		if(studs[i].engl > max) {
			max = studs[i].engl;
		}
		if(studs[i].gol > max) {
			max = studs[i].gol;
		}
		if(studs[i].math < min) {
			min = studs[i].math;
		}
		if(studs[i].chin < min) {
			min = studs[i].chin;
		}
		if(studs[i].engl < min) {
			min = studs[i].engl;
		}
		if(studs[i].gol < min) {
			min = studs[i].gol;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << studs[i].sum << endl;
	}
	sort(studs, studs + n, cmp);
	cout << studs[0].name << endl;
	cout << max << " " << min;
}

