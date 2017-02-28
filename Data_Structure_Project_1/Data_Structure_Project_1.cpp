// Data_Structure_Project_1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>
#define ARRAY_SIZE 1000

using namespace std;
void swap(int& a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int mainMenu();
void fillArray(int a[], int x);
void printArray(int a[], int x);
void BubbleSort(int* array,int x);
void QuickSort(int* array, int startIndex, int endIndex);
void LinarySearch();
void BinarySearch();
void HanoiTower(int ,char ,char ,char );

int main()
{
	clock_t start, end;
	int a[ARRAY_SIZE];
	int c = mainMenu();
	switch (c)
	{
	case 1:
		system("cls");
		fillArray(a, ARRAY_SIZE);
		//printArray(a, ARRAY_SIZE);
		start = clock();
		BubbleSort(a,ARRAY_SIZE);
		end = clock();
		//printArray(a, ARRAY_SIZE);
		cout << "Time: " << (end - start) / (double)CLOCKS_PER_SEC;
		cin.get();
		cin.get();
		break;
	case 2:
		system("cls");
		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			cout << "Enter an integer : ";
			cin >> a[i];
		}
		cout << endl << "The list you input is : " << endl;
		printArray(a, ARRAY_SIZE);
		start = clock();
		QuickSort(a, 0, ARRAY_SIZE - 1);
		end = clock();
		cout << endl << "The list has been sorted, now it is : " << endl;
		printArray(a, ARRAY_SIZE);
		cout << "Time : " << (end - start) / (double)CLOCKS_PER_SEC;
		cin.get();
		cin.get();
		system("cls");
		break;
	case 3:
		//LinarySearch();
		break;
	case 4:
		//BinarySearch();
		break;
	case 5:
		system("cls");
		int num;
		cout << "Enter the number of disks : ";
		cin >> num;
		cout << "The sequence of moves involved in the Tower of Hanoi are :\n";
		start = clock();
		HanoiTower(num,'A', 'B', 'C');
		end = clock();
		cout << "Time: " << (end - start) / (double)CLOCKS_PER_SEC;
		cin.get();
		cin.get();
		system("cls");
		break;
	case 6:
		return 0;
	default:
		break;
	}

    return 0;
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
void fillArray(int a[], int x)
{
	srand(time(0));
	for (int i = 0;i < x;i++)
	{
		a[i] = rand() % 5000;
	}
}
void printArray(int a[], int x)
{
	for (int i = 0;i < x;i++)
		cout << a[i] << endl;
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
void BinarySearch(int arr[], int size)
{
	int low = 0;
	int high = size-1;
	while (low <= high)
	{
		
	}
	

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
