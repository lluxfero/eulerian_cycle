#include <iostream>
#include <Windows.h>
#include <clocale>
#include <vector>
using namespace std;

vector<int> help_v;
vector<int> result;

void eulerian_cycle(int m[6][6], int n) {
	int m_copy[6][6];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m_copy[i][j] = m[i][j];

	int t;
	for (int i = 0; i < n; i++) {
		t = 0;
		for (int j = 0; j < n; j++) {
			if (m_copy[i][j] == 1) {
				help_v.push_back(j);
				m_copy[i][j] = 0;
				m_copy[j][i] = 0;
				i = j - 1;
				t = 1;
				break;
			}
		}
		if (t == 0) {
			result.push_back(help_v.back());
			help_v.pop_back();
			if (help_v.size() == 0) return;
			else i = help_v.back() - 1;
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 6;
	int adj_matrix[6][6] = {
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 0, 0, 0},
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 0, 1, 1},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 0, 1, 1, 0}
	};

	cout << "Эйлеров цикл для матрицы: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << adj_matrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;

	help_v.push_back(0);
	eulerian_cycle(adj_matrix, n);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] + 1 << " ";
	}
	cout << endl;
}