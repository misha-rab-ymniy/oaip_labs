//������������ 5, ������ 1. ��������� ������� �. �.
/*C�������� ��������� ��� ���������� ����������� �������� ����������
������������� �������-������� Z. ������ ������� �������-������� Z ��������� ��
�������.
������������ �������.*/

#include <iostream>
#include "../StaticLib/Header.h"

using namespace std;

int main()
{
	int n = check1();
	int m = check1();

	double* X = Create_massive(n);
	double* Y = Create_massive(m);

	cout << "Max element = " << max_element(n, m, X, Y) << "loh";
}