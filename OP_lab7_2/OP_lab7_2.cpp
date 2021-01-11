﻿// OP_lab7_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int n = 40;
    double x = 0.1;
	while (x <= 0.8)
	{
		double y = log(1 / (2 + 2 * x + pow(x, 2)));
		double s = 0;
		for (int i = 1; i <= n; i++)
		{
			double slag = pow(1 + x, i * 2) / i;
			if (i % 2 != 0) {
				s = s - slag;
			}
			else {
				s = s + slag;
			}
			
		}
		printf("| %lf\t| %lf\t| %lf\t|\n", x, y, s);
		x += 0.01;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
