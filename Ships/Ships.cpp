#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 12;//������ ����	
char pole[MAX][MAX];//���� ����
const char SHIP = 'X';//����� �������/�������
const char BORDER = '@';//�������

void createPole()//������� ���� ��� ��������
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

void showPole()//��� �������
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
	cub(int SIZE) :size(SIZE){}//�����������, ���� ������������� ������� ������

	int stepDown(int x1, int y1)//������� �������� ������� �������� �������� �����
	{
		int choose = 1;
		for (int i = x1; i < (x1 + size); i++)//��������� �� ������ �� ����� ������ ������� � ������� ����
		{
			if (pole[i][y1] == BORDER)//��� ����� ���� � ��������� ������� ������ ������� �������, ����� ������� ����� ������ ���������
			{
				choose = 0;
				return choose;
			}
		}
		for (int i = x1 - 1; i <= x1 + size; i++)// �������� ������� �������� ��������
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

	int stepUp(int x1, int y1)//����������
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

	int stepLeft(int x1, int y1)//����������
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

	int stepRight(int x1, int y1)//����������
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

	void drawUp(int x1, int y1)//���������� ������ ���������)
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
			step = rand() % 4;//�����, ����� ������ �����������
			x = rand() % (MAX - 2) + 1;//���������� ����������
			y = rand() % (MAX - 2) + 1;
			if (step == 2)
			{
				if (stepDown(x, y) == 1)//���� ����� �������� ����, �� ���e�� �������
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
	//��� ��� ������ ���������
	srand(time(NULL));//��������� ������ ��������� �����
	createPole();
	cub one1(1);// �������� �������� ������
	cub one2(1);
	cub one3(1);
	cub one4(1);
	cub two1(2);
	cub two2(2);
	cub two3(2);
	cub three1(3);
	cub three2(3);
	cub four(4);
	four.letsGo();// ����� ������� ������� ������
	three1.letsGo();
	three2.letsGo();
	two1.letsGo();
	two2.letsGo();
	two3.letsGo();
	one1.letsGo();
	one2.letsGo();
	one3.letsGo();
	one4.letsGo();
	showPole();// ����������� � �������
	return 0;
}