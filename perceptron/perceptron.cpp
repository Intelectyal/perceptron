#include "pch.h"
#include <iostream>
#include <ctime>
#define activation_function(x) (1/(1+exp(-(x))))
using namespace std;

float learn(float a[], float b[], int const size)
{
	float c = 0;
	for (int i = 0; i < size; i++)
	{
		c += a[i] * b[i];
	}
	c = activation_function(c);
	return(c);
}
float ErrorN(float find, float Out)
{
	float c;
	c = find - Out;
	return(c);
}
void weight_calibration(float w[], float in[], float weight, int const size)
{
	for (int i = 0; i < size; i++)
	{
		if (in[i] > 0)
		{
			w[i] += weight;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int const size = 2;
	int j = 0, k = -1;
	float weight_arr[size], input_arr[size], find_result = 1, Output = 0, Error = -1, weight = 0.10;
	cout << "Введите значение изменения веса(по умолчанию значение установлено на 0.10)\n" << endl;
	cin >> weight;
	if (weight == 0)
	{
		cout << "Ошибка, вес не может быть равен 0" << endl;
		weight = 0.10;
	}
	for (int i = 0; i < size; i++)
	{
		weight_arr[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		input_arr[i] = 0;
	}
	srand(time(NULL));
	k = rand() % size;
	input_arr[k] = find_result;
	do
	{
		cout << "--------------" << endl;
		Output = learn(weight_arr, input_arr, size);
		Error = ErrorN(find_result, Output);
		cout << Output << " - Ответ сети\n" << Error << " - Ошибка\n" << endl;
		cout << "Веса:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << weight_arr[i] << endl;
		}
		weight_calibration(weight_arr, input_arr, weight, size);
		cout << "Количество повторений - " << ++j << endl;
		cout << "--------------" << "\n" << endl;
	} while (Error != 0);
	cin.get();
}

