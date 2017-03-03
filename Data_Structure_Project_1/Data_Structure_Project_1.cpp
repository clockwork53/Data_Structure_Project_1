// Data_Structure_Project_1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <utility>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::swap;
using std::endl;
using std::ofstream;
using std::string;
using std::ios;

int mainMenu();				   //menu selection to choose the required algorithms
int fetchArraySize();			//fetch array size from user
int fetchRange();				//fetch the range of random numbers from the user
short verboseSwitch();			//asks user whether to show the sorting_list/hanoi_instructions/searching_list
void saveResults(string, double, long int, long int);
void fillArray(long int* , long int , long int);			//fills the given array with random numbers
void printArray(long int* , long int ,short);		 //print the given array (the short argument acts as an on/off switch)
void BubbleSort(long int* , long int );
void QuickSort(long int* , long int , long int );
int LinarySearch(long int* , long int , long int );
int BinarySearch(long int* , long int, long int );
void HanoiTower(int ,char ,char ,char ,short);	//the short argument acts as a silent switch
int partition(long int*, long int, long int);					//part of the quick sort algorithm

int main()
{
	do
	{
		clock_t start, end;
		int choice = mainMenu();
		if (choice == 6)
			return 0;									//exit the program
		short V = verboseSwitch();						//the key to silent the program!
		if (choice >= 1 && choice <= 4)					//dont create testList[] if Hanoi Tower is selected by user
		{
			long int ARRAY_SIZE = fetchArraySize();			//fetch the array size from user
			long int RANGE = fetchRange();					//fetch the range from user
			long int* testList = new long int[ARRAY_SIZE];		//create a dynamic array
			long int key, answer;         //"the key to search for" in binary & linary algorithms, answer = position of the key
			if (choice == 1)
			{
				//BubbleSort();
				system("cls");						//windows command to clear the screen
				fillArray(testList, ARRAY_SIZE , RANGE);
				printArray(testList, ARRAY_SIZE ,V);
				start = clock();
				BubbleSort(testList, ARRAY_SIZE);
				end = clock();
				printArray(testList, ARRAY_SIZE ,V);
				double time = (end - start) / (double)CLOCKS_PER_SEC;
				cout << "Time: " << time;							//shows the CPU time spend for the algorithm in seconds
				saveResults("Bubble Sort" , time, ARRAY_SIZE, RANGE );
				cin.get();
				delete[] testList;							//delete array to avoid memory leaks
			}
			else if (choice == 2)
			{
				//QuickSort();
				system("cls");
				fillArray(testList, ARRAY_SIZE,RANGE);
				printArray(testList, ARRAY_SIZE ,V);
				start = clock();
				QuickSort(testList, 0, ARRAY_SIZE - 1);
				end = clock();
				cout << "\nThe list has been sorted, now it is : \n";
				printArray(testList, ARRAY_SIZE ,V);
				double time = (end - start) / (double)CLOCKS_PER_SEC;
				cout << "Time: " << time;							//shows the CPU time spend for the algorithm in seconds
				saveResults("Quick Sort", time, ARRAY_SIZE, RANGE);
				cin.get();
				delete[] testList;
			}
			else if (choice == 3)
			{
				//LinarySearch();
				system("cls");
				fillArray(testList, ARRAY_SIZE , RANGE);
				srand((unsigned int)time(0));
				key = testList[(rand() % ARRAY_SIZE)];		//random generated key
				QuickSort(testList, 0, ARRAY_SIZE - 1);						//sorts the array before searching
				printArray(testList, ARRAY_SIZE ,V);
				start = clock();
				answer = LinarySearch(testList, ARRAY_SIZE, key);
				end = clock();
				if (answer == -1)
					cout << " Element is not found in an array\n";
				else
					cout << " Element " << key << " is found at position " << (answer + 1) << endl;
				double time = (end - start) / (double)CLOCKS_PER_SEC;
				cout << "Time: " << time;							//shows the CPU time spend for the algorithm in seconds
				saveResults("Linary Search", time, ARRAY_SIZE, RANGE);
				cin.get();
				delete[] testList;
			}
			else if (choice == 4)
			{
				//BinarySearch();
				system("cls");
				fillArray(testList, ARRAY_SIZE , RANGE);
				srand((unsigned int)time(0));
				key = testList[(rand() % ARRAY_SIZE)];		//random generated key
				QuickSort(testList, 0, ARRAY_SIZE - 1);						//sorts the array before searching
				printArray(testList, ARRAY_SIZE ,V);
				start = clock();
				answer = BinarySearch(testList, ARRAY_SIZE, key);
				end = clock();
				if (answer == -1)
					cout << " Element " << key << " is not found in an array\n";
				else
					cout << " Element " << key << " is found at position " << (answer + 1) << endl;
				double time = (end - start) / (double)CLOCKS_PER_SEC;
				cout << "Time: " << time;							//shows the CPU time spend for the algorithm in seconds
				saveResults("Binary Search", time, ARRAY_SIZE, RANGE);
				cin.get();
				delete[] testList;
			}
		}
		else if (choice == 5)
		{
			//HanoiTower();
			system("cls");
			int num;
			cout << "Enter the number of disks : ";
			cin >> num;
			if(V)
				cout << "The sequence of moves involved in the Tower of Hanoi are :\n";
			start = clock();
			HanoiTower(num, 'A', 'B', 'C' ,V);
			end = clock();
			double time = (end - start) / (double)CLOCKS_PER_SEC;
			cout << "Time: " << time;							//shows the CPU time spend for the algorithm in seconds
			saveResults("Hanoi Tower", time, num,NULL);
			cin.get();
		}
	} while (true);
}
int mainMenu()
{
	system("cls");
	int x;
	cout << "/**************************************************************************************/";
	cout << "\n\n\n\n\t\t\t1) BubbleSort";
	cout << "\n\t\t\t2) QuickSort";
	cout << "\n\t\t\t3) LinarySearch";
	cout << "\n\t\t\t4) BinarySearch";
	cout << "\n\t\t\t5) HanoiTower";
	cout << "\n\t\t\t6) Exit";
	do
	{
		cout << "\n\nEnter your choice: ";
		cin >> x;
		cin.ignore(1, '\n');
		if (x < 1 || x>6)
			cout << "Your choice is invalid !!!!!!!!!";
	} while (x < 1 || x>6);
	return x;
}
int fetchArraySize()
{
	int ARRAY_SIZE;
	cout << "Enter the size of the array ...\n";
	cin >> ARRAY_SIZE;
	cin.get();
	return ARRAY_SIZE;
}
int fetchRange()
{
	int Range;
	cout << "Enter the Range of the numbers ...\n";
	cin >> Range;
	cin.get();
	return Range;
}
short verboseSwitch()
{
	char holder;
	do
	{
		cout << "Do you want to see the details(y/n)\n";
		cin >> holder;
		cin.get();
	} while (holder != 'y' && holder != 'n' && holder != 'N' && holder != 'Y');
	if (holder == 'y' || holder == 'Y')
		return 1;
	else
		return 0;
}
void saveResults(string algorithm, double time, long int size, long int range)
{
	static bool oneTimeFormatting = true;										//checks if this is the first run
		char holder;
	do
	{
		cout << "\nDo you want to save the results?";
		cin >> holder;
		cin.get();
	} while (holder != 'y' && holder != 'n' && holder != 'N' && holder != 'Y');
	if (holder == 'y' || holder == 'Y')
	{
		ofstream* results = new ofstream;
		if (oneTimeFormatting)
			results->open("Results.txt", ios::out | ios::trunc);					//deletes the last result file(if exists)
		else
			results->open("Results.txt", ios::out | ios::app );					//append the new data without deleting the rest
		if (results->is_open())
		{
			if (oneTimeFormatting)
			{
				*results << "Algorithm" << "\tTime (Seconds)" << "\tSize" << "\t\tRange";
				oneTimeFormatting = false;
			}
			*results << "\n" << algorithm << "\t" << time << "\t\t" << size << "\t\t";
			if (range != NULL)
				*results << range;
			else
				*results << "N/A";
			if (results->bad())
				cout << "\nSorry for the inconvience but we couldnt save the results! If this happends again contact support";
			delete results;
		}
		else
			cout << "\nCouldnt create a file! check permissions";
	}
	else
		return;
}
void fillArray(long int* array, long int size , long int range)
{
	srand((unsigned int)time(0));
	for (long int i = 0;i < size;i++)
	{
		array[i] = rand() % range;
	}
}
void printArray(long int* array, long int size ,short enable)
{
	if (!enable)
		return;
	for (long int i = 0;i < size;i++)
		cout << array[i] << endl;
}
int partition(long int* array, long int low, long int high)
{
	int mid = low + (high - low) / 2;
	int pivot = array[mid];

	swap( array[mid] , array[low] );
	long int i = (low + 1);
	long int j = high;
	while (i <= j)
	{
		while (i <= j && array[i] <= pivot)
		{
			i++;
		}
		while (i <= j && array[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			swap(array[i], array[j]);
		}
	}
	swap(array[i - 1], array[low]);
	return i - 1;
}
void BubbleSort(long int* array, long int size)
{
	for (long int i = 0; i < size ;i++)
	{
		for (long int j = 0; j < size - 1;j++)
		{
			if (array[j + 1]<array[j])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
void QuickSort(long int* array, long int low, long int high)
{
	if (low < high)
	{
		int splitPoint = partition(array, low, high);
		QuickSort(array, low, splitPoint - 1);
		QuickSort(array, splitPoint + 1, high);
	}
	}
int LinarySearch(long int* array, long int size, long int key)
{
	bool flag;
	long int i;
	for (i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			flag = true;
			break;
		}
	}
	if (flag == false)
		return -1;
	else
	{
		return i;
	}
}
int BinarySearch(long int* array, long int size, long int key)
{
	long int low = 0, mid, high = size-1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == array[mid])
			return mid;
		else if (key < array[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return -1;
}
void HanoiTower(int num, char from_peg, char to_peg, char aux_peg ,short Verbose)
{
	if (num == 1)
	{
		if(Verbose)
			cout << " Move disk 1 from peg " << from_peg << " to peg " << to_peg << endl;
		return;
	}
	HanoiTower(num - 1, from_peg, aux_peg, to_peg ,Verbose);
	if(Verbose)
		cout << " Move disk " << num << " from peg " << from_peg << " to peg " << to_peg << endl;
	HanoiTower(num - 1, aux_peg, to_peg, from_peg ,Verbose);
}
