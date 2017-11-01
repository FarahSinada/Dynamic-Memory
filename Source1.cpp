#include <iostream>
#include <fstream>

using namespace std;

int N;
int k;
double *A(nullptr);

void ReadNumbers();
void SortNumbers();
void Print();

int main()
{

	do
	{
		ReadNumbers();
		SortNumbers();
		Print();

		//de-allocate A
		delete[]A;

	} while (true);

}

void ReadNumbers()
{
	do
	{
		cout << "How many numbers would you like to sort: ";
		cin >> N;
		if (N <= 0) exit(-1);
		A = new double[N];

		for (k = 0; k < N; k++) //starting from k = 0, while k is less than N, k++ every loop
		{
			cout << "Please enter number " << k + 1 << ": "; //this k doesnt affect other k
			cin >> A[k];
		}

	} while (k < N);
	return;
}

void SortNumbers()
{
	bool Sorted = true;
	double temp;

	do
	{
		Sorted = true;
		for (int sortcount = 0; sortcount < N; sortcount++)
		{

			if (A[sortcount] > A[sortcount++])
			{
				temp = A[sortcount];
				A[sortcount] = A[sortcount++];
				A[sortcount++] = temp;
				Sorted = false;
			}

		}

		Sorted = true;

	} while (!(Sorted));

	return;//go back
}

void Print()
{
	cout << "Sorted numbers: ";

	for (k = 0; k < N; k++) //starting from k = 0, while k is less than N, k++ every loop
	{
		cout << A[k] << " , "; //this k doesnt affect other k
	}
	cout << endl;
	return;
}