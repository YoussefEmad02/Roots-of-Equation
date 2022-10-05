#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;


int main()
{
	
	srand(0);

	// n is the size of matrix
	int n;
	float t, sum, sub;

	// Take size from user 
	cout << "Enter size (n) : " << endl;
	cin >> n;

	// MATRIX A
	// 1- make a 2d dynamic array (A) with size n*n

	float** A = new float* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new float[n];
	}

	// 2- fill it with random number

	cout << endl << "A Matrix " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() ;
			cout << A[i][j] << " \t";
		}
		cout << endl;

	}

	cout << endl;

	// MATRIX B
	// 1- make a 2d dynamic array (B) with size n*1

	float** B = new float* [n];
	for (int i = 0; i < n; i++)
	{
		B[i] = new float[1];
	}

	// 2- fill it with random number

	cout << "B Matrix " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			B[i][j] = rand();
			cout << B[i][j] << " \t";
		}
		cout << endl;

	}
	
	// FInd A Inverse
	// 1- make a 2d dynamic array (A_inverse) with size n*n

	float** A_inverse = new float* [n];
	for (int i = 0; i < n; i++)
	{
		A_inverse[i] = new float[n];
	}

	// 2- Find inverse of matrix A


	float** check_A = new float* [n];
	for (int i = 0; i < n; i++)
	{
		check_A[i] = new float[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			check_A[i][j] = A[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < 2 * n; j++)
		{
			if (i == j - n)
				check_A[i][j] = 1;
			else
				check_A[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		t = check_A[i][i];
		for (int j = i; j < 2 * n; j++)
			check_A[i][j] = check_A[i][j] / t;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				t = check_A[j][i];
				for (int k = 0; k < 2 * n; k++)
					check_A[j][k] = check_A[j][k] - t * check_A[i][k];
			}
		}
	}

	// Printing Matrix A_inverse

	cout << endl << endl << "A Inverse" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		for (int j = n; j < 2 * n; j++)
		{
			cout << check_A[i][j] << "\t";
			A_inverse[i][temp] = check_A[i][j];
			temp++;
		}
		cout << endl;
	}

	cout << endl << endl;
	
	// Vector X
	// Make 2d Dynamic with size n*1
	float** x = new float* [n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new float[1];
	}

	// Multiplying Matrix A_inverse by Matrix B

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += (A_inverse[i][k] * B[k][j]);

			}
			x[i][j] = sum;

		}

	}

	// Printing Vector X 

	cout << "X" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			cout << x[i][j];
		}
		cout << endl;
	}
	cout << endl;

	// A * X
    // Make 2d Dynamic with size n*1
	float** A_Times_x = new float* [n];
	for (int i = 0; i < n; i++)
	{
		A_Times_x[i] = new float[1];
	}

	// Multiplying Matrix A by Matrix X

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += (A[i][k] * x[k][j]);
			}
			A_Times_x[i][j] = sum;

		}

	}


	float** fx = new float* [n];
	for (int i = 0; i < n; i++)
	{
		fx[i] = new float[1];
	}

	for (int i = 0; i < n; i++)
	{
		sub = 0;
		sub = (A_Times_x[i][1] - B[i][1]);
		fx[i][1] = sub;
	}

	// printing f(x)
	float fx_mag = 0;
	for (int i = 0; i < n; i++)
	{
		fx_mag += pow((fx[i][1]), 2);
	}

	cout << "f(x) = " << fx_mag;


	

	return 0;
}