//Лабораторная 4, задача 10. Выполнена Дубинка М. А.
/*Построить магический квадрат любого порядка, используя любой
алгоритм. Выделение памяти через функции языка С.*/
#include <iostream>

using namespace std;


long long check()
{
	while (true) {
		cout << "Enter the number ";
		long long n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n' || n <= 2) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid value entered. Please try again. \n";
		}
		else {
			return n;
		}
	}
}

int main()
{
	int n = check();

	ios_base::sync_with_stdio(0); cin.tie(0);
	iostream::sync_with_stdio(0); cout.tie(0);

	unsigned int start_time = clock();
	int** a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}

	if (n % 2 != 0) {
		int i = 0;
		int j = n / 2;
		for (int k = 1; k <= n * n; k++) {
			a[i][j] = k;
			if (k % n == 0) {
				i++;
			}
			else { 
				i--;
				j++;
				if (i < 0) i = n - 1;
				if (j > n - 1) j = 0;
			}
		}
	}
	else if (n % 4 != 0) {
		int m = n - 1;
		int n = m / 2;
		a[0][n / 2] = 1;
		int i = 0;
		int j = n / 2;
		int r;
		for (r = 2; r <= (n + 1) * (n + 1); r++) 
		{
			i--;
			j++;
			if (i < 0 && j <= n) {
				a[n][j] = r;
				i = n;
			}
			else if (j > n && i >= 0) {
				a[i][0] = r;
				j = 0;
			}
			else if (i < 0 && j > n) {
				a[i + 2][n] = r;
				i += 2;
				j = n;
			}
			else if ((r - 1) % (n + 1) == 0) {
				a[i + 2][j - 1] = r;
				i += 2;
				j--;
			}
			else {
				a[i][j] = r;
			}
		}

		a[n + 1][n + (m + 1 - n) / 2] = r;
		i = n + 1;
		j = n + (m + 1 - n) / 2;
		r++;
		int q = r;

		for (; r <= q + (n + 1) * (n + 1) - 2; r++) {
			i--;
			j++;
			if (i < n + 1 && j <= m) {
				a[m][j] = r;
				i = m;
			}
			else if (j > m && i >= n + 1) {
				a[i][n + 1] = r;
				j = n + 1;
			}
			else if (i < n + 1 && j > m) {
				a[i + 2][m] = r;
				i += 2;
				j = m;
			}
			else if ((r - 1) % (n + 1) == 0) {

				a[i + 2][j - 1] = r;
				i += 2;
				j--;

			}
			else {
				a[i][j] = r;
			}

		}


		a[0][n + (m + 1 - n) / 2] = r;
		i = 0;
		j = n + (m + 1 - n) / 2;
		r++;
		q = r;
		for (; r <= q + (n + 1) * (n + 1) - 2; r++) {
			i--;
			j++;
			if (i < 0 && j <= m) {
				a[n][j] = r;
				i = n;
			}
			else if (j > m && i >= 0) {
				a[i][n + 1] = r;
				j = n + 1;
			}
			else if (i < 0 && j > m) {
				a[i + 2][m] = r;
				i += 2;
				j = m;
			}
			else if ((r - 1) % (n + 1) == 0) {
				a[i + 2][j - 1] = r;
				i += 2;
				j--;
			}
			else {
				a[i][j] = r;
			}
		}


		a[n + 1][n / 2] = r;
		i = n + 1;
		j = n / 2;
		r++;
		q = r;
		for (; r <= q + (n + 1) * (n + 1) - 2; r++) {
			i--;
			j++;
			if (i <= n && j <= n) {
				a[m][j] = r;
				i = m;
			}
			else if (i > n && j > n) {
				a[i][0] = r;
				j = 0;
			}
			else if (i >= n && j > n) {
				a[i + 2][n] = r;
				i += 2;
				j = n;
			}
			else if ((r - 1) % (n + 1) == 0) {
				a[i + 2][j - 1] = r;
				i += 2;
				j--;
			}
			else {
				a[i][j] = r;
			}
		}

		int p; 
		for (int k = 0; k < (n + 1) / 2; k++) {
			for (j = 0; j < (n + 1) / 2; j++) {
				p = a[k][j];
				a[k][j] = a[k + m / 2 + 1][j];
				a[k + m / 2 + 1][j] = p;
			}
		}

		int k = (n + 1) / 2;
		for (j = (n + 1) / 2; j > 0; j--) {
			p = a[k][j];
			a[k][j] = a[k + m / 2 + 1][j];
			a[k + m / 2 + 1][j] = p;
		}

		for (k = (n + 1) / 2 + 1; k < n + 1; k++) {
			for (j = 0; j < (n + 1) / 2; j++)
			{
				p = a[k][j];
				a[k][j] = a[k + m / 2 + 1][j];
				a[k + m / 2 + 1][j] = p;
			}
		}

		if (n != 6)
		{
			for (k = 0; k <= n; k++)
			{
				for (j = n - (n - 1) / 2; j < n; j++)
				{
					p = a[k][j];
					a[k][j] = a[k + m / 2 + 1][j];
					a[k + m / 2 + 1][j] = p;
				}
			}
		}
	}
	else {
		int c1 = 1, c2 = n * n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i % 4 == j % 4 || (i + j) % 4 == 3) { 
					a[i][j] = c2;
				}
				else {
					a[i][j] = c1;
				}
				c2--;
				c1++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
	
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time;
	return 0;
}