#include <iostream>
using namespace std;

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
	delete[] matrix;
}

void mat3() {
	int m, n;
	cout << "Enter the number of rows (M): ";
	cin >> m;
	cout << "Enter the number of columns (N): ";
	cin >> n;

	int* numbers = new int[m];
	cout << "Enter " << m << " numbers: ";
	for (int i = 0; i < m; i++) {
		cin >> numbers[i];
	}

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			matrix[i][j] = numbers[i];
		}
	}

	cout << "The resulting matrix is:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	delete[] matrix;
}

void mat7() {
	int m, n, k;
	cout << "Enter the number of rows (M): ";
	cin >> m;
	cout << "Enter the number of columns (N): ";
	cin >> n;
	cout << "Enter the value of K (1 <= K <= M): ";
	cin >> k;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "The elements of the " << k << "-th row are: ";
	for (int j = 0; j < n; j++) {
		cout << matrix[k - 1][j] << " ";
	}
	cout << endl;

	delete[] matrix;
}

void mat13() {
	int m;
	std::cout << "Enter the order of the square matrix: ";
	std::cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	std::cout << "Enter the elements of the matrix:" << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
		}
	}

	int startRow = 0, startCol = 0;
	int endRow = m - 1, endCol = m - 1;

	while (startRow <= endRow && startCol <= endCol) {
		for (int i = startCol; i <= endCol; i++) {
			std::cout << matrix[startRow][i] << " ";
		}
		startRow++;

		for (int i = startRow; i <= endRow; i++) {
			std::cout << matrix[i][endCol] << " ";
		}
		endCol--;

		if (startRow <= endRow) {
			for (int i = endCol; i >= startCol; i--) {
				std::cout << matrix[endRow][i] << " ";
			}
			endRow--;
		}

		if (startCol <= endCol) {
			for (int i = endRow; i >= startRow; i--) {
				std::cout << matrix[i][startCol] << " ";
			}
			startCol++;
		}
	}
	delete[] matrix;

}

void mat80() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += matrix[i][i];
	}

	cout << "Сумма элементов главной диагонали: " << sum << endl;
	delete[] matrix;
}

void mat81() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	double sum = 0;
	for (int i = 0; i < m; i++) {
		sum += matrix[i][m - 1 - i];
	}

	double average = sum / m;
	cout << "The average of the elements of the secondary diagonal is: " << average << endl;

	delete[] matrix;
}

void mat82() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int k = 1 - m; k < m; k++) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (i - j == k) {
					sum += matrix[i][j];
				}
			}
		}
		cout << "The sum of elements of diagonal A1," << m + k << " is: " << sum << endl;
	}

	delete[] matrix;
}

void mat88() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i > j) {
				matrix[i][j] = 0;
			}
		}
	}

	
	cout << "The modified matrix with elements below the main diagonal set to 0 is:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat92() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i < j && i + j < m - 1) {
				matrix[i][j] = 0;
			}
		}
	}
	
	cout << "The modified matrix with elements above the main and secondary diagonals set to 0 is:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat93() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (i < j && i + j > M - 1) {
				matrix[i][j] = 0;
			}
		}
	}

	cout << "The modified matrix is:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat94() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (i < j        i + j > M - 1) {
				matrix[i][j] = 0;
			}
		}
	}

	cout << "The modified matrix is:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat95() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (!(i >= j || i + j <= M - 1)) {
				matrix[i][j] = 0;
			}
		}
	}

	cout << "Измененная матрица:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat96() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < i; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	cout << "Зеркально отраженная матрица:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat97() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < i; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[M - 1 - j][M - 1 - i]; 
			matrix[M - 1 - j][M - 1 - i] = temp;
		}
	}

	cout << "Mirrored matrix with respect to the secondary diagonal:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat98() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < M / 2; i++) {
		for (int j = 0; j < M; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[M - 1 - i][M - 1 - j];
			matrix[M - 1 - i][M - 1 - j] = temp;
		}
	}

	cout << "Повернутая матрица на 180 градусов:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat99() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < M; i++) {
		for (int j = i; j < M; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M / 2; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][M - 1 - j];
			matrix[i][M - 1 - j] = temp;
		}
	}

	cout << "Повернутая матрица на 90 градусов:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	delete[] matrix;

}

void mat100() {
	int m;
	cout << "Enter the order of the square matrix: ";
	cin >> m;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[m];
	}

	cout << "Enter the elements of the matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "matrix:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	for (int layer = 0; layer < M / 2; layer++) {
		int first = layer;
		int last = M - 1 - layer;
		for (int i = first; i < last; i++) {
			int offset = i - first;
			int top = matrix[first][i];
			matrix[first][i] = matrix[last - offset][first];
			matrix[last - offset][first] = matrix[last][last - offset];
			matrix[last][last - offset] = matrix[i][last];
			matrix[i][last] = top;
		}
	}

	cout << "Повернутая матрица на 90 градусов в отрицательном направлении:" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	delete[] matrix;

}

int main() {
	int z;
	cin >> z;
	switch (z)
	{
	case 1:
		mat1();
		break;
	case 2:
		mat3();
		break;
	case 3:
		mat7();
		break;
	case 4:
		mat13();
		break;
	case 5:
		mat80();
		break;
	case 6:
		mat81();
		break;
	case 7:
		mat82();
		break;
	case 8:
		mat88();
		break;
	case 9:
		mat92();
		break;
	case 10:
		mat93();
		break;
	case 11:
		mat94();
		break;
	case 12:
		mat95();
		break;
	case 13:
		mat96();
		break;
	case 14:
		mat97();
		break;
	case 15:
		mat98();
		break;
	case 16:
		mat99();
		break;
	case 17:
		mat100();
		break;
}
}