#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

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



//Task.6.1.initialize database
void database_initialize(vector<string> *v)
{
	cout << "This will erase all names from database. Proceed?(y/n) : ";
	char c;
	cin >> c;
	if (c == *"y")
		(*v).clear();
}

//Task.6.2.insert
void database_insert(vector<string>* v, string name)
{	
		(*v).push_back(name);	
}

//Task.6.3.search
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

//Task.6.4.delete
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

//Task.6.5.print
void database_print(const vector<string>* v)
{	//prints all elements of the database(vector v)
	for (auto e : *v)
	{
		cout << e << endl;
	}
}

void database_save(const vector<string>* v, string filename)
{
	//save to file
}

void database_load(const vector<string>* v, string filename)
{
	//load from file
}

void database()
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




int main()
{/*
	//(Task 1: String length) input
	char arr[] = "computer";
	cout <<"The Lenghts of the word "<<arr<<" is: "<< strlen(arr)<<endl;

	
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
	cout << "\nAverage salary per person: " << x<<endl;
	
	delete[] salArr;
	delete[] intArr;
	


	//(Task 3: Swap sort with pointers) input
	cout << "\nSort some numbers, ABC.\n";
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

	
	//(Task 4: Swap sort with double pointers) input
	int a = 7, b = 6, c = 1;
	int* p1 = &a, * p2 = &b, * p3 = &c;
	cout <<"\nbefore swap: "<< *p1 << " " << *p2 << " " << *p3;    // Points "1 6 7"
	swap_sort_ptr_addr(&p1, &p2, &p3, true);
	cout << "\nafter swap: " << *p1 << " " << *p2 << " " << *p3<<"\n\n";    // Points "1 6 7"
	


	//(Task 5: Character replacement with pointers) input
	char str[] = "Herrens hus!";
	char SearchForMe = 104;//ASCII 104 = h
	char ReplaceWithMe = 109;//ASCII 109 = m

	cout <<"before replacement: "<< str<<endl;
	replace_chars(str, SearchForMe, ReplaceWithMe);
	cout << "after replacement: " << str<<endl;

	*/


	//(Task 6: Modular vector database with pointers)



	//database()
	string filename = "testiclefile1.txt";
	ofstream myfile;
	myfile.open(filename);
	myfile << "Writing this to a file.\n";
	myfile.close();


	
	char u = 254;
	char e = 255;
	cout << "  A B C D E\n";
	cout << "1 " << u << " " << u << " " << u << " " << u << " " << u << " \n";
	cout << "2 " << u << " " << 3 << " " << 2 << " " << u << " " << u << " \n";
	cout << "3 " << 1 << " " << e << " " << 1 << " " << 1 << " " << u << " \n";
	cout << "4 " << u << " " << 2 << " " << e << " " << 2 << " " << u << " \n";
	cout << "5 " << u << " " << u << " " << 2 << " " << 3 << " " << u << " \n";
	cout << "6 " << u << " " << u << " " << u << " " << u << " " << u << " \n";
}