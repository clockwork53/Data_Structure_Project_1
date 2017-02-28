// Data_Structure_Project_1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>

using namespace std;

const int ARRAY_SIZE = 1000;

void swap(int& a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int mainMenu();
void fillArray(int* , int );
void printArray(int* , int );
void BubbleSort(int* ,int );
void QuickSort(int* , int ,int );
int LinarySearch(int* ,int ,int );
int BinarySearch(int* ,int, int);
void HanoiTower(int ,char ,char ,char );

int main()
{
	do
	{
		clock_t start, end;
		int testList[ARRAY_SIZE];
		int choice = mainMenu();
		switch (choice)
		{
		case 1:
			//BubbleSort();
			system("cls");
			fillArray(testList, ARRAY_SIZE);
			//printArray(testList, ARRAY_SIZE);
			start = clock();
			BubbleSort(testList, ARRAY_SIZE);
			end = clock();
			//printArray(testList, ARRAY_SIZE);
			cout << "Time: " << (end - start) / (double)CLOCKS_PER_SEC;
			cin.get();
			cin.get();
			break;
		case 2:
			//QuickSort();
			system("cls");
			fillArray(testList, ARRAY_SIZE);
			//printArray(testList, ARRAY_SIZE);
			start = clock();
			QuickSort(testList, 0, ARRAY_SIZE - 1);
			end = clock();
			cout << endl << "The list has been sorted, now it is : " << endl;
			//printArray(testList, ARRAY_SIZE);
			cout << "Time : " << (end - start) / (double)CLOCKS_PER_SEC;
			cin.get();
			cin.get();
			break;
		case 3:
			//LinarySearch();
			int key, answer;
			fillArray(testList, ARRAY_SIZE);
			//printArray(testList, ARRAY_SIZE);
			srand(time(0));
			key = testList[ rand() % (ARRAY_SIZE + (ARRAY_SIZE / 10)) ];
			BubbleSort(testList, ARRAY_SIZE);
			start = clock();
			answer = LinarySearch(testList, ARRAY_SIZE, key);
			end = clock();
			/*if (answer == 0)
				cout << " Element is not found in an array\n";
			else
				cout << " Element is found at position " << (answer + 1) << endl;*/
			cout << "Time : " << (end - start) / (double)CLOCKS_PER_SEC;
			cin.get();
			cin.get();
			break;
		case 4:
			//BinarySearch();
			int key, answer;
			fillArray(testList, ARRAY_SIZE);
			//printArray(testList, ARRAY_SIZE);
			srand(time(0));
			key = testList[ rand() % (ARRAY_SIZE + (ARRAY_SIZE / 10)) ];
			BubbleSort(testList, ARRAY_SIZE);
			start = clock();
			answer = BinarySearch(testList, key, ARRAY_SIZE);
			end = clock();
			/*if (answer == 0)
			cout << " Element is not found in an array\n";
			else
			cout << " Element is found at position " << (answer + 1) << endl;*/
			cout << "Time : " << (end - start) / (double)CLOCKS_PER_SEC;
			cin.get();
			cin.get();
			break;
		case 5:
			system("cls");
			int num;
			cout << "Enter the number of disks : ";
			cin >> num;
			cout << "The sequence of moves involved in the Tower of Hanoi are :\n";
			start = clock();
			HanoiTower(num, 'A', 'B', 'C');
			end = clock();
			cout << "Time: " << (end - start) / (double)CLOCKS_PER_SEC;
			cin.get();
			cin.get();
			break;
		case 6:
			return 0;
		default:
			break;
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
void fillArray(int* array, int size)
{
	srand(time(0));
	for (int i = 0;i < size;i++)
	{
		array[i] = rand() % 5000;
	}
}
void printArray(int* array, int size)
{
	for (int i = 0;i < size;i++)
		cout << array[i] << endl;
}
void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size ;i++)       
	{
		for (int j = 0; j < size - 1;j++)
		{
			if (array[j + 1]>array[j])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
/*void QuickSort(int* array, int startIndex, int endIndex)
{
	int pivot = array[startIndex];
	int splitPoint;
	if (endIndex > startIndex)
	{
		splitPoint = SplitArray(array, pivot, startIndex, endIndex);
		array[splitPoint] = pivot;
		QuickSort(array, startIndex, splitPoint - 1);
		QuickSort(array, splitPoint + 1, endIndex);
	}
}*/
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
int BinarySearch(int* array, int key, int size)
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
void HanoiTower(int num, char frompeg, char topeg, char auxpeg)
{
	if (num == 1)
	{
		cout << " Move disk 1 from peg " << frompeg << " to peg " << topeg << endl;
		return;
	}
	HanoiTower(num - 1, frompeg, auxpeg, topeg);
	cout << " Move disk " << num << " from peg " << frompeg << " to peg " << topeg << endl;
	HanoiTower(num - 1, auxpeg, topeg, frompeg);
}
