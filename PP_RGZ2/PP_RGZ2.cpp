#include "pch.h"
#include <vector>
#include <iostream>
#include <omp.h>
#include <chrono>
#include <iomanip> 

using namespace std;

vector<int> Vector(int N)
{
	vector<int> a;
	a.reserve(N);

	for (int i = 0; i < N; i++)
	{
		a.push_back(rand() % N);
	}
	return a;
}

vector<int> Summ(int N, vector<int> a, vector<int> b)
{
	vector<int> sum;
	sum.resize(N);

#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		sum[i] = a[i] + b[i];
	}
	return sum;
}

int main()
{
	int N = 0;
	int S = 0;

	while (true)
	{
		cout << endl;
		cout << "Enter the size of the vector a" << endl;
		cin >> N;
		cout << "Enter the size of the vector b" << endl;		
		cin >> S;

		if (N == S)
		{
			vector<int> a = Vector(N);
			vector<int> b = Vector(N);
			vector<int> sum = Summ(N, a, b);

			auto begin = chrono::high_resolution_clock::now();

			Summ(N, a, b);

			auto end = chrono::high_resolution_clock::now();

			cout << endl << "Time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;

			cout << "Do you want to see vectors?" << " Y or N" << endl;
			char t;
			cin >> t;
			if (t == 'Y' || t == 'y')
			{
				cout << "Vector a" << endl;
				for (int i = 0; i < N; i++)
					cout << setw(4) << a[i] << " ";
					cout << endl;

				cout << "Vector b" << endl;
				for (int i = 0; i < N; i++)
					cout << setw(4) << b[i] << " ";
					cout << endl;

				cout << "Vector sum" << endl;
				for (int i = 0; i < N; i++)
					cout << setw(4) << sum[i] << " ";
					cout << endl;
			}
			else
			{
				break;
			}			
		}
		else
		{
			cout << "Vectors have different sizes" << endl << "Try again =)" << endl;
		}
	}
	return 0;
}