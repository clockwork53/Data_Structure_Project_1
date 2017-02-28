// Data_Structure_Project_1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>
#include <utility>

using std::cout;
using std::cin;
using std::swap;
using std::endl;

int mainMenu();				   //menu selection to choose the required algorithms
int fetchArraySize();			//fetch array size from user
short verboseSwitch();			//asks user whether to show the sorting_list/hanoi_instructions/searching_list
void fillArray(int* , int );   //fills the given array with random numbers
void printArray(int* , int ,short);  //print the given array (the short argument acts as an on/off switch)
void BubbleSort(int* ,int );
void QuickSort(int* , int , int );
int LinarySearch(int* ,int ,int );
int BinarySearch(int* ,int, int );
void HanoiTower(int ,char ,char ,char ,short);	//the short argument acts as a silent switch
int partition(int*, int, int);  //part of the quick sort algorithm

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
			int ARRAY_SIZE = fetchArraySize();			//fetch the array size from user
			int* testList = new int[ARRAY_SIZE];		//create a dynamic array
			int key, answer;         //"the key to search for" in binary & linary algorithms, answer = position of the key
			if (choice == 1)
			{
				//BubbleSort();
				system("cls");						//windows command to clear the screen
				fillArray(testList, ARRAY_SIZE);
				printArray(testList, ARRAY_SIZE ,V);
				start = clock();
				BubbleSort(testList, ARRAY_SIZE);
				end = clock();
				printArray(testList, ARRAY_SIZE ,V);
				cout << "Time: " << (end - start) / (double)CLOCKS_PER_SEC;   //shows the CPU time spend for the algorithm in seconds
				cin.get();
				cin.get();
				delete[] testList;							//delete array to avoid memory leaks
			}
			else if (choice == 2)
			{
				//QuickSort();
				system("cls");
				fillArray(testList, ARRAY_SIZE);
				printArray(testList, ARRAY_SIZE ,V);
				start = clock();
				QuickSort(testList, 0, ARRAY_SIZE - 1);
				end = clock();
				cout << "\nThe list has been sorted, now it is : \n";
				printArray(testList, ARRAY_SIZE ,V);
				cout << "Time : " << (end - start) / (double)CLOCKS_PER_SEC;
				cin.get();
				cin.get();
				delete[] testList;
			}
			else if (choice == 3)
			{
				//LinarySearch();
				system("cls");
				fillArray(testList, ARRAY_SIZE);
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
				cout << "Time : " << (end - start) / (double)CLOCKS_PER_SEC;
				cin.get();
				cin.get();
				delete[] testList;
			}
			else if (choice == 4)
			{
				//BinarySearch();
				system("cls");
				fillArray(testList, ARRAY_SIZE);
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
				cout << "Time : " << (end - start) / (double)CLOCKS_PER_SEC;
				cin.get();
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
			cout << "Time: " << (end - start) / (double)CLOCKS_PER_SEC;
			cin.get();
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
short verboseSwitch()
{
	char holder;
	do
	{
		cout << "Do you want to see the details(answer with y/n)\n";
		cin >> holder;
		cin.get();
	} while (holder != 'y' && holder != 'n' && holder != 'N' && holder != 'Y');
	if (holder == 'y' || holder == 'Y')
		return 1;
	else
		return 0;
}
void fillArray(int* array, int size)
{
	srand((unsigned int)time(0));
	for (int i = 0;i < size;i++)
	{
		array[i] = rand() % 5000;
	}
}
void printArray(int* array, int size ,short enable)
{
	if (!enable)
		return;
	for (int i = 0;i < size;i++)
		cout << array[i] << endl;
}
int partition(int* array, int low, int high)
{
	int mid = low + (high - low) / 2;
	int pivot = array[mid];

	swap( array[mid] , array[low] );
	int i = (low + 1);
	int j = high;
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
void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size ;i++)       
	{
		for (int j = 0; j < size - 1;j++)
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
void QuickSort(int* array, int low, int high)
{
	if (low < high)
	{
		int splitPoint = partition(array, low, high);
		QuickSort(array, low, splitPoint - 1);
		QuickSort(array, splitPoint + 1, high);
	}
	}
int LinarySearch(int* array,int size,int key) 
{
	short flag;
	int i;
	for (i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return -1;
	else
	{
		return i;
	}
}
int BinarySearch(int* array, int size, int key)
{
	int low = 0, mid, high = size-1;
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
	HanoiTower(num - 1, from_peg, aux_peg, to_peg ,NULL);
	if(Verbose)
		cout << " Move disk " << num << " from peg " << from_peg << " to peg " << to_peg << endl;
	HanoiTower(num - 1, aux_peg, to_peg, from_peg ,NULL);
}
