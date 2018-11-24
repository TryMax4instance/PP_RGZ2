#include "pch.h"
#include <vector>
#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> sum;

	
int vectorA(int N)
{
	a.reserve(N);

	for (int i = 0; i < N; i++)
	{
		a.push_back(rand() % N);
	}

	for (int i = 0; i < N; i++)
		cout << a[i] << " ";

	return 0;
}

int vectorB(int N)
{
	b.reserve(N);

	for (int i = 0; i < N; i++)
	{
		b.push_back(rand() % N);
	}

	for (int i = 0; i < N; i++)
		cout << b[i] << " ";

	return 0;
}

int summ(int N)
{
	sum.reserve(N);

	#pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		sum.push_back(a[i] + b[i]);
	}

	for (int i = 0; i < N; i++)
		cout << sum[i] << " ";

	return 0;
}

int main()
{
	int N = 0;

	cout << "Enter the size of the vectors" << endl;
	cin >> N;

	vectorA(N);
	cout << endl;
	vectorB(N);
	cout << endl;

	auto begin = chrono::high_resolution_clock::now();

	summ(N);
	
	auto end = chrono::high_resolution_clock::now();

	cout <<endl << "Work time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count();
	return 0;
}