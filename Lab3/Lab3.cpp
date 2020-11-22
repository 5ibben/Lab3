#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


#pragma region Task functions 1-5.
//Task.1
int strlen(char *s)
{
	int len = 0;
	for (int i = 0; *(s+i) != 0; i++)
		len++;
	return len;
}

//Task.2
int average_salary(const int **p, int n)//pointer array input and int number of employees
{
	int sum = 0;
	int i = 0;
	while (i<n)
	{
		sum += *p[i];
		i++;
	}
	return sum/i;
}

//Task.3
void swap_sort(int*a, int*b, int*c, bool ascending)
{	//Swaps between the given integers a,b,c to order them in either ascending or descending order.
	int aTemp = *a;
	int bTemp = *b;
	if (ascending)
	{
		for (int i = 0; i < 2; i++)		//ascending
		{
			if (*a > *b)
			{
				*a = *b; *b = aTemp;
				aTemp = *a; bTemp = *b;
			}
			if (*b > *c)
			{
				*b = *c; *c = bTemp;
				bTemp = *b;
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)		//descending
		{
			if (*a < *b)
			{
				*a = *b; *b = aTemp;
				aTemp = *a; bTemp = *b;
			}
			if (*b < *c)
			{
				*b = *c; *c = bTemp;
				bTemp = *b;
			}
		}
	}
}

//Task.4
void swap_sort_ptr_addr(int** a, int** b, int** c, bool ascending)
{	//Swaps between the given integers a,b,c to order them in either ascending or descending order.
	int aTemp = **a;
	int bTemp = **b;
	if (ascending)
	{
		for (int i = 0; i < 2; i++)		//ascending
		{
			if (**a > ** b)
			{
				**a = **b; **b = aTemp;
				aTemp = **a; bTemp = **b;
			}
			if (**b > ** c)
			{
				**b = **c; **c = bTemp;
				bTemp = **b;
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)		//descending
		{
			if (**a < **b)
			{
				**a = **b; **b = aTemp;
				aTemp = **a; bTemp = **b;
			}
			if (**b < **c)
			{
				**b = **c; **c = bTemp;
				bTemp = **b;
			}
		}
	}
}

//Task.5
void replace_chars(char* str, char search, char replacement)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (*(str + i) == search)
			*(str + i) = replacement;
	}
}
#pragma endregion Task functions 1-5.


#pragma region Task functions 6.
//Task.6.1.database initialize
void database_initialize(vector<string> *v)
{
	cout << "This will erase all names from the current database. Proceed?(y/n) : ";
	char c;
	cin >> c;
	if (c == *"y")
		(*v).clear();
}

//Task.6.2.database insert
void database_insert(vector<string>* v, string name)
{	
		(*v).push_back(name);	
}

//Task.6.3.database search
void database_search(const vector<string>* v, string name)
{
	for (auto e : *v)
	{
		if (!e.find(name))
		{
			cout << "\n" << e;
		}
	}
	cout << "\n";
}

//Task.6.4.database delete
void database_delete(vector<string>* v, string name)
{	//Makes a copy of the database(v) into vTemp, excluding all eventual positions where the given name is found.
	vector<string> vTemp;
	for (int i = 0; i < (*v).size(); i++)
	{
		if ((*v)[i] != name)
		{
			vTemp.push_back((*v)[i]);
		}
	}
	*v = vTemp;//assigns v to the new vector vTemp, which excludes the given name.
}

//Task.6.5.database print
void database_print(const vector<string>* v)
{	//prints all elements of the database(vector v)
	for (auto e : *v)
	{
		cout << e << endl;
	}
}

//Task.6.6.database save
void database_save(const vector<string>* v, string filename)
{
	//save to file
	ofstream myfile(filename);
	if (myfile.is_open())
	{
		for (auto e : *v)
		{
			myfile << e << endl;
		}
	}else
		cout<<"\nUnable to open file\n";
	myfile.close();
}

//Task.6.7.database load
void database_load(vector<string>* v, string filename)
{
	cout << "Load " << filename << " as a new database or add it to current one? (new/add): ";
	string input;
	while (true)
	{
		cin >> input;
		if (input == "new")
		{
			database_initialize(v);
			break;
		}
		else if (input == "add")
		{
			break;
		}
		else
			cout << "\nInvalid input!\nTry again: ";
	}

	//load from file
	string line;
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			(*v).push_back(line);
		}
		myfile.close();
	}
	else cout << "\nUnable to open file\n";
}
#pragma endregion Task functions 6.


#pragma region Input functions.
//(Task 1: String length) input
void task1_input()
{
	char arr[] = "computer";
	cout <<"The Lenghts of the word "<<arr<<" is: "<< strlen(arr)<<endl;
}

//(Task 2: Average salaries) input
void task2_input()
{
	int arraySize; 
	cout << "how many employees? "; 
	cin >> arraySize; 

	const int** salArr = new const int*[arraySize];
	int* intArr = new int [arraySize];
	for (int i = 0; i < arraySize; ++i) 
	{
		cout << "Enter salary for employee no " << i+1 << ": "; cin >> intArr[i];
		salArr[i] = &intArr[i];
	}
	int x= average_salary(salArr, arraySize);
	cout << "\nAverage salary per person: " << x<<endl;
	
	delete[] salArr;
	delete[] intArr;
}

//(Task 3: Swap sort with pointers) input
void task3_input()
{
	cout << "Sort some numbers, ABC.\n";
	while (true)
	{
		cout << "\nGive a number A(0 to quit): "; int a; cin >> a;
		if (a == 0)
			break;
		cout << "Give a number B: "; int b; cin >> b;
		cout << "Give a number C: "; int c; cin >> c;
		cout << "Sort ascending / descending(1 / 0) :"; bool d; cin >> d;
		swap_sort(&a, &b, &c, d);
		cout << "\nResult: " << a << b << c << "\n";
	}
}

//(Task 4: Swap sort with double pointers) input
void task4_input()
{
	int a = 7, b = 6, c = 1;
	int* p1 = &a, * p2 = &b, * p3 = &c;
	cout <<"before swap: "<< *p1 << " " << *p2 << " " << *p3;
	swap_sort_ptr_addr(&p1, &p2, &p3, true);
	cout << "\nafter swap: " << *p1 << " " << *p2 << " " << *p3<<"\n\n";
}

//(Task 5: Character replacement with pointers) input
void task5_input()
{
	char str[] = "Herrens hus!";
	char SearchForMe = 104;//ASCII 104 = h
	char ReplaceWithMe = 109;//ASCII 109 = m

	cout <<"before replacement: "<< str<<endl;
	replace_chars(str, SearchForMe, ReplaceWithMe);
	cout << "after replacement: " << str<<endl;
}

//(Task 6: Modular vector database with pointers) input
void  task6_input()
{
	vector<string> v;// this is the actual database
	string name;
	int x;

	//Database menu loop.
	while (true)
	{
		cout << "\n1.initialize database\n"
			<< "2.insert\n"
			<< "3.search\n"
			<< "4.delete\n"
			<< "5.print\n"
			<< "6.save\n"
			<< "7.load\n"
			<< "0.quit\n\n"
			<< "Make your choice: ";
		cin >> x;
		cout << "\n";

		//name input for option 2, 3, 4.
		if (x == 2 || x == 3 || x == 4)
		{
			cout << "Please enter name: ";
			cin >> name;
		}

		//filename input for option 6,7.
		if (x == 6 || x == 7)
		{
			cout << "Please enter filename: ";
			cin >> name;
		}

		//1.initialize database
		if (x == 1)
			database_initialize(&v);

		//2.insert
		if (x == 2)
			database_insert(&v, name);

		//3.search
		if (x == 3)
			database_search(&v,name);

		//4.delete
		if (x == 4)
			database_delete(&v, name);

		//5.print
		if (x == 5)
			database_print(&v);

		//6.save
		if (x == 6)
			database_save(&v,name);

		//7.load
		if (x == 7)
			database_load(&v,name);

		//0.quit
		if (x == 0)
		{
			break;
		}
	}
}
#pragma endregion Input functions.


int main()
{
	bool loop = true;
	int input;
	while (loop)
	{
		cout << "\n1: Task 1. String length\n"
			<< "2: Task 2. Average salaries\n"
			<< "3: Task 3. Swap sort with pointers\n"
			<< "4: Task 4. Swap sort with double pointers\n"
			<< "5: Task 5. Character replacement with pointers\n"
			<< "6: Task 6. Modular vector database with pointers\n"
			<< "0: Exit\n"
			<< "\nInput: ";
		if (cin >> input)
		{
			cout << endl;
			switch (input)
			{
				case 1:
					task1_input();
					break;
				case 2:
					task2_input();
					break;
				case 3:
					task3_input();
					break;
				case 4:
					task4_input();
					break;
				case 5:
					task5_input();
					break;
				case 6:
					task6_input();
					break;
				case 0:
					loop = false;
					cout << "\nGood bye!\n";
					break;
				default:
					cout << "invalid number!\n";
					break;
			}
		}
		else
		{
			cout << "invalid input!\n";
			break;
		}
	}
}