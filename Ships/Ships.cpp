#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 12;//размер поля	
char pole[MAX][MAX];//само поле
const char SHIP = 'X';//часть корабля/корабль
const char BORDER = '@';//граница

void createPole()//создаем поле без кораблей
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i == 0 || j == 0 || i == (MAX - 1) || j == (MAX - 1))
				pole[i][j] = BORDER;
			else
				pole[i][j] = ' ';
		}
	}
}

void showPole()//тут понятно
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			cout << pole[i][j];
		cout << endl;
	}
}

class cub
{
	int x;
	int y;
	int size;
public:
	cub(int SIZE) :size(SIZE){}//конструктор, типо инициализатор объекта класса

	int stepDown(int x1, int y1)//функция проверки наличии соседних кораблей рядом
	{
		int choose = 1;
		for (int i = x1; i < (x1 + size); i++)//проверяем не входит ли часть нашего корабля в границу поля
		{
			if (pole[i][y1] == BORDER)//тут можно было и проверить наличие частей другого корабля, чтобы срезать время роботы программы
			{
				choose = 0;
				return choose;
			}
		}
		for (int i = x1 - 1; i <= x1 + size; i++)// проверка наличии соседних кораблей
		{
			for (int j = y1 - 1; j <= y1 + 1; j++)
			{
				if (pole[i][j] == SHIP)
				{
					choose = 0;
					return choose;
				}
			}
		}
		return choose;
	}

	int stepUp(int x1, int y1)//аналогично
	{
		int choose = 1;
		for (int i = x1; i > (x1 - size); i--)
		{
			if (pole[i][y1] == BORDER)
			{
				choose = 0;
				return choose;
			}
		}
		for (int i = x1 + 1; i >= x1 - size; i--)
		{
			for (int j = y1 - 1; j <= y1 + 1; j++)
			{
				if (pole[i][j] == SHIP)
				{
					choose = 0;
					return choose;
				}
			}
		}
		return choose;
	}

	int stepLeft(int x1, int y1)//аналогично
	{
		int choose = 1;
		for (int i = y1; i > (y1 - size); i--)
		{
			if (pole[x1][i] == BORDER)
			{
				choose = 0;
				return choose;
			}
		}
		for (int i = x1 - 1; i <= x1 + 1; i++)
		{
			for (int j = y1 + 1; j >= y1 - size; j--)
			{
				if (pole[i][j] == SHIP)
				{
					choose = 0;
					return choose;
				}
			}
		}
		return choose;
	}

	int stepRight(int x1, int y1)//аналогично
	{
		int choose = 1;
		for (int i = y1; i < (y1 + size); i++)
		{
			if (pole[x1][i] == BORDER)
			{
				choose = 0;
				return choose;
			}
		}
		for (int i = x1 - 1; i <= x1 + 1; i++)
		{
			for (int j = y1 - 1; j <= y1 + size; j++)
			{
				if (pole[i][j] == SHIP)
				{
					choose = 0;
					return choose;
				}
			}
		}
		return choose;
	}

	void drawUp(int x1, int y1)//собственно рисуем кораблики)
	{
		for (int i = x1 - size + 1; i <= x1; i++)
			pole[i][y1] = SHIP;
	}

	void drawDown(int x1, int y1)
	{
		for (int i = x1 + size - 1; i >= x1; i--)
			pole[i][y1] = SHIP;
	}

	void drawRight(int x1, int y1)
	{
		for (int i = y1 + size - 1; i >= y1; i--)
			pole[x1][i] = SHIP;
	}

	void drawLeft(int x1, int y1)
	{
		for (int i = y1 - size + 1; i <= y1; i++)
			pole[x1][i] = SHIP;
	}
	void letsGo()
	{
		int step;
		while (true)
		{
			step = rand() % 4;//фигня, чтобы задать направление
			x = rand() % (MAX - 2) + 1;//генерируем координаты
			y = rand() % (MAX - 2) + 1;
			if (step == 2)
			{
				if (stepDown(x, y) == 1)//если рядом кораблей нету, то рисeем корабль
				{
					drawDown(x, y);
					break;
				}
			}
			else if (step == 0)
			{
				if (stepUp(x, y) == 1)
				{
					drawUp(x, y);
					break;
				}
			}
			else if (step == 1)
			{
				if (stepRight(x, y) == 1)
				{
					drawRight(x, y);
					break;
				}
			}
			else if (step == 3)
			{
				if (stepLeft(x, y) == 1)
				{
					drawLeft(x, y);
					break;
				}
			}
		}
	}
};

int main(int arcg, char* arcv[])
{
	//тут все сильно некрасиво
	srand(time(NULL));//генератор посева случайных чисел
	createPole();
	cub one1(1);// создание объектов класса
	cub one2(1);
	cub one3(1);
	cub one4(1);
	cub two1(2);
	cub two2(2);
	cub two3(2);
	cub three1(3);
	cub three2(3);
	cub four(4);
	four.letsGo();// вызов функции объекта класса
	three1.letsGo();
	three2.letsGo();
	two1.letsGo();
	two2.letsGo();
	two3.letsGo();
	one1.letsGo();
	one2.letsGo();
	one3.letsGo();
	one4.letsGo();
	showPole();// отображение в консоли
	return 0;
}