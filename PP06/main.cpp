#include <vector>
#include <iostream>

using namespace std;

//���ø�(���׸�)���� ����
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
	//���Ͱ��� ������� ���� ����
	cout << a.size() << endl;

	//���� ���� ��Ҹ� ����Ѵ� 1,2,4�� ����Ѵ�
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	//a�� ���Ͱ�3���� �־���
	cout << a.size() << endl;
	//a[0]�� �� ó������ ����Ѵ� 1�� ��µȴ�
	cout << "�� :" << a[0] << endl;

	return 0;
}