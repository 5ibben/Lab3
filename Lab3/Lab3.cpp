#include <iostream>

using namespace std;


int strlen(char *s)
{
	int len = 0;
	for (int i = 0; *(s+i) != 0; i++)
		len++;
	return len;
}

int average_salary(const int **p, int n)//pointer array input and int number of employees
{
	int sum = 0;
	int i = 0;
	while (i<n)
	{
		sum += *p[i];
		cout << "\nSalary no " << i << ": " << *p[i];
		i++;
	}
	return sum/i;
}



int main()
{
	//(Task 1: String length) input
	char arr[] = "computer";
	cout <<"The Lenghts of the word "<<arr<<" is: "<< strlen(arr);;

	
	//(Task 2: Average salaries) input
	int arraySize; 
	cout << "\nhow many employees? "; 
	cin >> arraySize; 

	const int** salArr = new const int*[arraySize];
	int* intArr = new int [arraySize];
	for (int i = 0; i < arraySize; ++i) 
	{
		cout << "Enter salary for employee no " << i+1 << ": "; cin >> intArr[i];
		salArr[i] = &intArr[i];
	}
	int x= average_salary(salArr, arraySize);
	cout << "\nAverage salary: " << x;
	
	delete[] salArr;
	delete[] intArr;





}