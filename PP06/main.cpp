#include <vector>
#include <iostream>

using namespace std;

//템플릿(제네릭)으로 생성
template<typename T>
T sum(T a, T b)
{
	return a + b;
}


int main()
{
	vector<int> a;
	//8/8
	cout << sum<double>(3.9, 4.9) << endl;
	//백터값에 집어넣은 값이 없다
	cout << a.size() << endl;

	//백터 끝에 요소를 출력한다 1,2,4를 출력한다
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	//a에 백터값3개를 넣었다
	cout << a.size() << endl;
	//a[0]번 즉 처음값을 출력한다 1이 출력된다
	cout << "값 :" << a[0] << endl;

	return 0;
}