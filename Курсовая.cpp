#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

struct fig
{
	int gor;
	int ver;
	char f;
};

struct Desk
{
	bool death;
	char fig;
};

fig vvod(char a)
{
	fig r;
	char c;
	int b;
	cin >> c >> b;
	if (c >= 'A'&&c <= 'Z'&&b >= 0&&b <= 9)
	{
		r.gor = 8 - b;
		r.ver = c - 65;
		r.f = a;
	}
	else cout << "Нерпаавильные координаты";
		return r;
}



void death_h( Desk **desk, fig f)
{
	if (desk[f.gor][f.ver].fig == f.f)
	{
		int i = f.gor;
		int j = f.ver - 2;
		bool d = false;
		while (!d)
		{
			while (j >= 0 && j < f.ver + 3)
			{
				if (i <= 7 && i > 1 && j != f.ver)
					desk[i - (3 - abs(f.ver - j))][j].death = true;
				if (i == 1 && j != f.ver&&j != f.ver - 1 && j != f.ver + 1)
					desk[i - 1][j].death = true;
				if (i >= 0 && i < 6 && j != f.ver)
					desk[i + (3 - abs(f.ver - j))][j].death = true;
				if (i == 6 && j != f.ver&&j != f.ver - 1 && j != f.ver + 1)
					desk[i + 1][j].death = true;
				++j;
				d = true;
			}
			if (!d)
				++j;
		}
	}
}
void death_p( Desk **desk, fig f)//
{
	if (desk[f.gor][f.ver].fig == f.f)
	{
		int i = f.gor, j = f.ver;
		if (i != 0)
		{
			if (j >= 0 && j < 7)
				desk[f.gor - 1][f.ver + 1].death = true;
			if (j > 0 && j <= 7)
				desk[f.gor - 1][f.ver - 1].death = true;
		}
		else
			if (i == 7)
				cout << "Неравильная позиция пешки.";
	}
}



void death_k( Desk **desk, fig f)
{
	if (desk[f.gor][f.ver].fig == f.f)
	{
		int i = f.gor - 1, j = f.ver - 1;
		bool b = false, d = false;
		while (!b || !d)
		{
			while ((i >= 0 && i < 8) && i < f.gor + 2 && i>f.gor - 2)
			{
				while ((j >= 0 && j < 8) && j < f.ver + 2 && j>f.ver - 2)
				{
					desk[i][j].death = true;
					++j;
					d = true;
				}
				if (!d)
					++j;
				else
				{
					j = f.ver - 1;
					++i;
					d = false;
				}
				b = true;
			}
			if (!b)
				++i;
			if (i == f.gor + 2 || i == f.gor + 1)
				d = true;
		}
		desk[f.gor][f.ver].death = false;
	}
}
void death_l( Desk **desk, fig f)
{
	if (desk[f.gor][f.ver].fig == f.f)
	{
		int i, j = f.ver;
		for (i = f.gor + 1; i < 8; i++)
		{
			desk[i][j].death = true;
			if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
				break;
		}
		for (i = f.gor - 1; i >= 0; i--)
		{
			desk[i][j].death = true;
			if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
				break;
		}
		i = f.gor;
		for (j = f.ver + 1; j < 8; j++)
		{
			desk[i][j].death = true;
			if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
				break;
		}
		for (j = f.ver - 1; j >= 0; j--)
		{
			desk[i][j].death = true;
			if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
				break;
		}
	}
}
	void death_f( Desk **desk, fig f)
	{
		if (desk[f.gor][f.ver].fig == f.f)
		{
			int i, j;
			death_l( desk, f);
			j = f.ver + 1;
			i = f.gor + 1;
			while (i < 8 && j < 8) {
				desk[i][j].death = true;
				if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
					break;
				i++;
				j++;
			}
			i = f.gor - 1;
			j = f.ver + 1;
			while (i >= 0 && j < 8) {
				desk[i][j].death = true;
				if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
					break;
				i--;
				j++;
			}
			i = f.gor - 1;
			j = f.ver - 1;
			while (i >= 0 && j >= 0) {
				desk[i][j].death = true;
				if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
					break;
				i--;
				j--;
			}
			i = f.gor + 1;
			j = f.ver - 1;
			while (i < 8 && j >= 0) {
				desk[i][j].death = true;
				if (desk[i][j].fig != 'o' && desk[i][j].fig != 'B')
					break;
				i++;
				j--;
			}
		}
	}

bool check_d( Desk **desk, fig b,fig k ,fig f, fig l, fig p, fig h, bool forp)
{
	death_l(desk, l);
	death_f(desk, f);
	death_k(desk, k);
	death_p(desk, p);
	death_h(desk, h);
	if (forp)
	return desk[b.gor][b.ver].death;
	if (desk[b.gor][b.ver].death==false)
		return false;
	else
	{
		int i = b.gor - 1, j = b.ver - 1;
		bool c = false, d = false;
		while (!c|| !d)
		{
			while ((i >= 0 && i < 8) && i < b.gor + 2 && i>b.gor - 2)
			{
				while ((j >= 0 && j < 8) && j < b.ver + 2 && j>b.ver - 2)
				{
					if (desk[i][j].death == false && desk[i][j].fig =='o')
						return false;
					++j;
					d = true;
				}
				if (!d)
					++j;
				else
				{
					j = b.ver - 1;
					++i;
					d = false;
				}
				c = true;
			}
			if (!c)
				++i;
			if (i == b.gor + 2 || i == b.gor + 1)
				d = true;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Desk **desk = new Desk*[8];
	for (int q = 0; q < 8; ++q)
		desk[q] = new Desk[8];
	fig k, f, l, p, h, b, u;
	int i = 0, j = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			desk[i][j].death = false;
			desk[i][j].fig = 'o';
		}
	}
	cout << "Веведите координаты белого Короля" << endl;
	k = vvod('K');
	desk[k.gor][k.ver].fig = k.f;
	cout << "Веведите координаты белого ферзя" << endl;
	f = vvod('F');
	desk[f.gor][f.ver].fig = f.f;
	cout << "Веведите координаты белой пешки" << endl;
	p=vvod('P');
	desk[p.gor][p.ver].fig = p.f;
	cout << "Веведите координаты белой ладьи" << endl;
	l = vvod('L');
	desk[l.gor][l.ver].fig = l.f;
	cout << "Веведите координаты белого Коня" << endl;
	h=vvod('H');
	desk[h.gor][h.ver].fig = h.f;
	cout << "Введите черные фигуры" << endl << "Для короля, пешки" << endl;
	cout << "Веведите Короля" << endl;
	b = vvod('B');//blackking
	desk[b.gor][b.ver].fig = b.f;
	cout << "Веведите пешку" << endl;
	u = vvod('U');
	desk[u.gor][u.ver].death = true;
	desk[u.gor][u.ver].fig = u.f;
	bool mat= check_d(desk,b,k,f,l,p,h,false);
	if (mat) {
		if (u.ver != 0 && u.gor != 7 && desk[u.gor + 1][u.ver - 1].fig !='B')
		{

			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					desk[i][j].death = false;
			desk[u.gor][u.ver].fig = 'o';
			desk[u.gor + 1][u.ver - 1].fig = u.f;
			mat = check_d(desk, b, k, f, l, p, h,true);
		}
		if (u.gor != 7 && desk[u.gor + 1][u.ver].fig == 'o'&&(mat))
		{
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					desk[i][j].death = false;
			desk[u.gor][u.ver].fig = 'o';
			desk[u.gor + 1][u.ver].fig = u.f;
			mat = check_d(desk, b, k, f, l, p, h,true);
		}
		if (u.ver != 7 && u.gor != 7 && desk[u.gor + 1][u.ver + 1].fig != 'B'&&(mat))
		{
			for (i = 0; i < 8; i++)
				for (j = 0; j < 8; j++)
					desk[i][j].death = false;
			desk[u.gor][u.ver].fig = 'o';
			desk[u.gor + 1][u.ver + 1].fig = u.f;
			mat = check_d(desk, b, k, f, l, p, h,true);
		}
	}
	if (mat)
		cout << " В данной позиции черному королю мат" << endl;
	else
		cout << " В данной позиции черному королю мата нет" << endl;
	cout << "Доска:"<<endl;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cout << desk[i][j].fig << ' ';
		}
		cout << endl;
	}
	cout << endl << "Смертельные позиции для короля:"<<endl;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cout << desk[i][j].death << ' ';
		}
		cout << endl;
	}
	

	for (int q = 0; q < 8; ++q)
	delete[] desk[q];
	delete[] desk;
}

