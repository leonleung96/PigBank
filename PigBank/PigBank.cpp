// PigBank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
using namespace std;

int findMinValue(int fit_weight, int num_item, int value[], int weight[])
{
	int* result = new int[fit_weight+1];
	//base case
	result[0] = 0;

	for (int w = 1; w < fit_weight+1; w++)
	{
		result[w] = 9999;

		for (int i = 0; i < num_item; i++)
		{
			if (w >= weight[i])
			{
				if ((result[w - weight[i]] + value[i]) < result[w])
				{
					result[w] = result[w - weight[i]] + value[i];
				}
			}
		}
	}

	return result[fit_weight];
}

int main()
{
	int* weights;
	int* values;
	int empty_pig_wt, filled_pig_wt, num_coins;

	cout << "Enter weight of empty pig: \n";
	cin >> empty_pig_wt;
	cout << "Enter weight of filled pig: \n";
	cin >> filled_pig_wt;
	cout << "Enter the number of various coins used: \n";
	cin >> num_coins;

	if (num_coins < 0)
	{
		cout << "Number of various coins must be positive\n";
		return 0; 
	}

	weights = new int[num_coins];
	values = new int[num_coins];

	for (int i = 0; i < num_coins; i++)
	{
		cout << "Enter the 'value' and 'weight' of coin #" << i + 1 << " in the format: Value Weight\n";
		cin >> values[i] >> weights[i];
	}
	
	int result = findMinValue(filled_pig_wt - empty_pig_wt, num_coins, values, weights);
	
	if (result == INFINITY) { cout << "This is impossible.\n"; }
	else { cout << "The minimum amount of money in the piggy-bank is " << result << ".\n"; }
	return 0;
}