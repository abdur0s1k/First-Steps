#include <iostream>
#include <math.h>
using namespace std;

void Z18() {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
	for (int i = 0; i < 10; i++) {
		if (a[i] < a[9]) {
			cout << a[i] << endl;
		}
		else if (a[i] >= a[9]) {
			cout << "0" << endl;
		}
	}
}

void Z19() {
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
	for (int i = 0; i < 10; i++) {
		if (a[i] < a[9] && a[i] > a[0]) {
			cout << a[i] << endl;
		}
		else if (a[i] >= a[9] && a[i] == a[2]) {
			cout << "0" << endl;
		}
	}
}

void Z20() {
	int k,l;
	const int n = 10;
	int a[n] = {1,2,3,4,5,6,7,8,9,0};
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter K and L : ";
	cin >> k >> l;
	int sum = 0;
	if (1 <= k && k <= l && l <= n) {
		for (int i = k - 1; i < l; i++) {
			sum += a[i];
		}
	}

	cout << "The sum of elements from index " << k<< " to " << l << " is: " << sum << endl;
}

void Z21() {
	int k, l;
	const int n = 10;
	int a[n] = { 1,2,3,4,5,6,7,8,9,0 };
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter K and L : ";
	cin >> k >> l;
	int sum = 0;
	if (1 <= k && k <= l && l <= n) {
		for (int i = k - 1; i < l; i++) {
			sum += a[i];
		}
	}
	double average = sum / (l - k + 1);
	cout << "The sum of elements from index " << k << " to " << l << " is: " << average << endl;
}

void Z22() {
	int k, l;
	const int n = 10;
	int a[n] = { 1,2,3,4,5,6,7,8,9,0 };
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter K and L : ";
	cin >> k >> l;
	int sum = 0;
	if (1 <= k && k <= l && l <= n) {
		for (int i = 0; i < n; i++) {
			if (i < k - 1 || i > l - 1) {
				sum += a[i];
			}
		}
	}
	cout << "The sum of all elements except those from index " << k << " to " << l << " is: " << sum << endl;
}

void Z23() {
	int k, l;
	const int n = 10;
	int a[n] = { 1,2,3,4,5,6,7,8,9,0 };
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter K and L : ";
	cin >> k >> l;
	int sum = 0;
	int count = 0;
	if (1 <= k && k <= l && l <= n) {
		for (int i = 0; i < n; i++) {
			if (i < k - 1 || i > l - 1) {
				sum += a[i];
				count++;
			}
		}
	}
	if (count == 0) {
		cout << "There are no elements to calculate the average." << endl;
	}
	else {
		double average = static_cast<double>(sum) / count;
		cout << "The average of all elements except those from index " << k << " to " << l << " is: " << average << endl;
	}
}

void Z51() {
	const int N = 5; 

	int A[N] = { 1, 2, 3, 4, 5 }; 
	int B[N] = { 6, 7, 8, 9, 10 }; 

	for (int i = 0; i < N; i++) {
		int temp = A[i];
		A[i] = B[i];
		B[i] = temp;
	}
    cout << "Преобразованный массив A: ";
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	
	cout << "Преобразованный массив B: ";
	for (int i = 0; i < N; i++) {
		std::cout << B[i] << " ";
	}
	cout << endl;
}

void Z52() {
	int N ; 
	cin >> N;
	int* A = new int[N];
	double* B = new double[N];

	for (int i = 0; i < N; i++) {
		A[i] = 0 + rand() % (N - 0 + 1);
	}
	
	for (int i = 0; i < N; i++) {
		if (A[i] < 5) {
			B[i] = 2 * A[i];
		}
		else {
			B[i] = A[i] / 2;
		}
	}

	
	cout << "Новый массив B: ";
	for (int i = 0; i < N; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
}

void Z53() {
	int n;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	int* C= new int [n];

	for (int i = 0; i < n; i++) {
		A[i]= 0 + rand() % (n - 0 + 1);
		B[i]= 0 + rand() % (n - 0 + 1);
	}

	for (int i = 0; i < n; i++) {
		if (A[i] > B[i]) {
			C[i] = A[i];
		}
		else {
			C[i] = B[i];
		}
	}


	cout << "Новый массив C: ";
	for (int i = 0; i < n; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
}

void mat1() {
	int M, N;
	cout << "Enter the number of rows (M): ";
	cin >> M;
	cout << "Enter the number of columns (N): ";
	cin >> N;

	int** matrix = new int* [M];
	for (int i = 0; i < M; i++) {
		matrix[i] = new int[N];
		for (int j = 0; j < N; j++) {
			matrix[i][j] = 10 * (i + 1);
		}
	}
	cout << "The resulting matrix is:\n";
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int z;
	cin >> z;
	switch (z)
	{
	case 1:
		Z18();
	break;
	case 2:
		Z19();
		break;
	case 3:
		Z20();
		break;
	case 4:
		Z21();
		break;
	case 5:
		Z22();
		break;
	case 6:
		Z23();
		break;
	case 7:
		Z51();
		break;
	case 8:
		Z52();
		break;
	case 9:
		mat1();
		break;
	}
}



