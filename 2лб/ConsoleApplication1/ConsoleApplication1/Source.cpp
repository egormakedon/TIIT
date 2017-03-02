#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;


int n, m, i, x, j, nc, mc, sum, **c, **sev, k, u[1000], v[1000], **cc, min, ll,kl;   //c-стоимость, sev- матрица сев-зап угла u,v- потенциалы cc-дельта с
double b[1005];
int YT[1000];															//Потребность в продукции
bool bsb;
int zz = 10000000;


struct s {																//s - структура хранения исходных данных 
	double a[1005];														//a - хранение списка коров
}st[105];


struct cyc {												//структура хранения данных цикла
	int si;													//итый номер
	int sj;													//jтый номер
	int sch;												//значение элемента	
}q[1000];




void potencial()
{
	for (i = 1; i <= nc; i++)
		u[i] = zz;

	for (j = 1; j <= mc; j++)
		v[j] = zz;

	v[mc] = 0;

	do
	{
		bsb = false;

		for (i = 1; i <= nc; i++)
		{
			for (j = 1; j <= mc; j++)
			{
				if ((u[i] != zz) && (v[j] == zz) && (sev[i][j] >= 0)) { v[j] = c[i][j] - u[i]; bsb = true; }
				if ((u[i] == zz) && (v[j] != zz) && (sev[i][j] >= 0)) { u[i] = c[i][j] - v[j]; bsb = true; }
			}
		}
	} while (bsb);
}



void Deltc()
{
	for (i = 1; i <= nc; i++)
		for (j = 1; j <= mc; j++)
			cc[i][j] = c[i][j];

	for (i = 1; i <= nc; i++)
		for (j = 1; j <= mc; j++)
			if (sev[i][j] == -1) cc[i][j] = c[i][j] - u[i] - v[j];
}





void cycle(int p,int kol)
{
	if (kol == 0)
	{
		if ((k >= 3) && ((q[k].si == q[0].si) || (q[k].sj == q[0].sj))) return;

		kl = 0;
		for (j = p; j <= mc; j++)
		{
			if ((sev[q[k].si][j] >= 0) && (j != q[k].sj))
			{
				k++;
				q[k].si = q[k - 1].si;
				q[k].sj = j;
				q[k].sch = sev[q[k].si][j];
				kl++;
				break;
			}
		}

		if (kl == 1) cycle(1, 1);
		if (kl == 0)
		{
			k--;
			cycle(q[k + 1].si + 1, 1);
		}
	}

	if (kol == 1)
	{
		if ((k >= 3) && ((q[k].si == q[0].si) || (q[k].sj == q[0].sj))) return;

		kl = 0;
		for (i = p; i <= nc; i++)
		{
			if ((sev[i][q[k].sj] >= 0) && (i != q[k].si))
			{
				k++;
				q[k].si = i;
				q[k].sj = q[k - 1].sj;
				q[k].sch = sev[i][q[k].sj];
				kl++;
				break;
			}
		}

		if (kl == 1) cycle(1, 0);
		if (kl == 0)
		{
			k--;
			cycle(q[k + 1].sj + 1, 0);
		}
	}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*int kol, ii, jj, p, pp;

	ii = q[0].si;
	jj = q[0].sj;

	p = 1;
	pp = 1;

	for (j = p; j <= mc; j++)
	{
		kol = 0;

		if ((sev[q[k].si][j] >= 0) && (j != q[k].sj))
		{
			k++;
			q[k].si = q[k-1].si;
			q[k].sj = j;
			q[k].sch = sev[q[k].si][j];
			kol = 1;
			pp = 1;
		}

		if ((kol == 0) && (j == mc))
		{
			pp = q[k].si + 1;
			k--;
			p = 1;
			kol = 1;
		}

		if (kol == 1)
		{
			if ((k >= 3) && (j == jj)) return;

			for (i = pp; i <= nc; i++)
			{
				if ((sev[i][q[k].sj] >= 0) && (i != q[k].si))
				{
					k++;
					q[k].si = i;
					q[k].sj = q[k - 1].sj;
					q[k].sch = sev[i][q[k].sj];
					kol = 2;
				}

				if ((kol == 1) && (i == nc))
				{
					p = q[k].sj + 1;
					k--;
					pp = 1;
					break;
				}
				

				if (kol == 2)
				{
					if ((k >= 3) && (i == ii)) return;
					p = 1;
					pp = 1;
					break;
				}
			}
		}
	}
	*/

















	/*
	if (k >= 4)
	{
		if ((ii == iii) || (jj == jjj))
		{
			q[0].si = iii;
			q[0].sj = jjj;
			ll = k - 1;
			return;
		}
	}

	int kol;

	kol = 0;

	if (k % 2 != 0)
	{
		for (j = 1; j <= mc; j++)
			if ((j != jj) && (sev[ii][j] >= 0))
			{
				q[k].si = ii;
				q[k].sj = j;
				q[k].sch = sev[ii][j];
				k++;



				if (j == jjj)
				{
					q[0].si = iii;
					q[0].sj = jjj;
					ll = k - 1;
					return;
				}



				for (i = 1; i <= nc; i++)
					if ((i != ii) && (sev[i][j] >= 0))
					{
						kol++;
						q[k].si = i;
						q[k].sj = j;
						k++;
						break;
					}

				if (kol == 1) break;
				else k--;
			}
	}

	else
	{
		for (i = 1; i <= nc; i++)
			if ((i != ii) && (sev[i][jj] >= 0))
			{
				q[k].si = i;
				q[k].sj = jj;
				q[k].sch = sev[i][jj];
				k++;



				if (i == iii)
				{
					q[0].si = iii;
					q[0].sj = jjj;
					ll = k - 1;
					return;
				}



				for (j = 1; j <= mc; j++)
					if ((j != jj) && (sev[i][j] >= 0))
					{
						kol++;
						q[k].si = i;
						q[k].sj = j;
						k++;
						break;
					}

				if (kol == 1) break;
				else k--;
			}
	}

	//cycle(q[k - 1].si, q[k - 1].sj, iii, jjj, k);
	*/
}


void fun()
{

	int ii, jj;
	min = cc[1][1];
	ii = 1;
	jj = 1;
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			if (min > cc[i][j])
			{
				min = cc[i][j];
				ii = i;
				jj = j;
			}
	}

	if (min >= 0) return;

	q[0].si = ii;
	q[0].sj = jj;
	k = 0;

	cycle(1,0);

	ll = k;

	min = q[1].sch;
	ii = q[1].si;
	jj = q[1].sj;
	for (i = 0; i <= ll; i++)
	{
		if (i % 2 != 0)
		{
			if (min > q[i].sch)
			{
				min = q[i].sch;
				ii = q[i].si;
				jj = q[i].sj;
			}
		}
	}

	sev[q[0].si][q[0].sj] = min;
	sev[ii][jj] = -1;

	for (i = 1; i <= ll; i++)
	{
		if ((q[i].si != ii) && (q[i].sj != jj))
		{
			if (i % 2 == 0) sev[q[i].si][q[i].sj] = q[i].sch + min;
			else sev[q[i].si][q[i].sj] = q[i].sch - min;
		}
	}


	potencial();

	Deltc();


	/*cout << endl << "Матрица сeверо-западного угла:\n";
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			cout << setw(4) << sev[i][j] << " ";
		cout << endl;
	}



	cout << endl << "Матрица дельта c:\n";
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			cout << cc[i][j] << " ";
		cout << endl;
	}
	cout << endl;



	cout << endl << "Потенциалы u:\n";
	for (i = 1; i <= nc; i++)
		cout << u[i] << " ";
	cout << endl;

	cout << endl << "Потенциалы v:\n";
	for (i = 1; i <= mc; i++)
		cout << v[i] << " ";
	cout << endl;
	*/

	fun();
}


int main()
{
	ifstream f1("cookie.in");
	ofstream f2("cookie.out");

	setlocale(LC_ALL, "Rus");

	f1 >> n >> m;

	for (i = 1; i <= m; i++)
	{
		f1 >> x;
		st[i].a[1] = x;
		for (j = 2; j <= st[i].a[1] + 1; j++)
		{
			f1 >> x;
			st[i].a[j] = x;
		}
	}

	for (i = 1; i <= n; i++)
		b[i] = 0;

	for (i = 1; i <= m; i++)
	{
		for (j = 2; j <= st[i].a[1] + 1; j++)
		{
			x = st[i].a[j];
			b[x] = b[x] + 1 / st[i].a[1];
		}
	}

	sum = 0;
	for (i = 1; i <= n; i++)
	{
		b[i] = ceil(b[i]);
		sum = sum + b[i];
	}

	for (i = 1; i <= m; i++)
		YT[i] = 1;

	nc = n;
	mc = m;

	if (sum > m)
	{
		mc = m + 1;
		YT[mc] = sum - m;
	}

	if (sum < m)
	{
		nc = n + 1;
		b[nc] = m - sum;
	}



	c = new int*[nc+1];
	for (i = 1; i <= nc; i++)
		c[i] = new int[mc+1];


	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			c[i][j] = 1;

	for (i = 1; i <= m; i++)
	{
		for (j = 2; j <= st[i].a[1] + 1; j++)
		{
			x = st[i].a[j];
			c[x][i] = 0;
		}
	}

	if (mc > m)
	{
		for (i = 1; i <= nc; i++)
			c[i][mc] = 0;
	}

	if (nc > n)
	{
		for (i = 1; i <= mc; i++)
			c[nc][i] = 0;
	}


	sev = new int*[nc+1];
	for (i = 1; i <= nc; i++)
		sev[i] = new int[mc+1];

	for (i = 1; i <= nc; i++)
		for (j = 1; j <= mc; j++)
			sev[i][j] = -1;

	i = 1;
	j = 1;
	int ii = 1, jj = 1;
	int kol12 = 0;
	while ((b[nc] > 0) && (YT[mc] > 0))
	{
		sev[i][j] = 1;
		kol12++;
		YT[jj] = YT[jj] - 1;
		if (YT[jj] == 0) jj++;
		b[ii] = b[ii] - 1;
		if (b[ii] == 0)
		{
			if (i < nc) i++;
			if (j < mc) j++;
			ii++;
		}
		else
		{
			if (j < mc) j++;
		}
	}

	
	i = 1;
	j = 1;
	ii = 0;
	while (kol12 != nc+mc-1)
	{
	if ((sev[i][j] == 1) && (ii == 0)) { sev[nc][j] = 0; ii++; kol12++; }
	if (sev[i][j] == 1) j++;
	else { i++; ii = 0; }
	}
	
	
	potencial();


	cc = new int*[nc+1];
	for (i = 1; i <= nc; i++)
		cc[i] = new int[mc+1];


	Deltc();




	/*cout << endl << "Матрица сeверо-западного угла:\n";
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			cout << setw(4) << sev[i][j] << " ";
		cout << endl;
	}
	

	cout << endl << "Матрица стоимости перевозок:\n";
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	cout << endl;




	cout << endl << "Матрица дельта c:\n";
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			cout << cc[i][j] << " ";
		cout << endl;
	}
	cout << endl;



	cout << endl << "Потенциалы u:\n";
	for (i = 1; i <= nc; i++)
		cout << u[i] << " ";
	cout << endl;

	cout << endl << "Потенциалы v:\n";
	for (i = 1; i <= mc; i++)
		cout << v[i] << " ";
	cout << endl;*/


	//cout << "-------------------------------------------------------------------------" << endl;


	fun();

	//cout << endl << endl << endl << "-----------------------------------------------------------------" << endl;
	
	/*int kol;
	int p;
	for (j = 1; j <= m; j++)
	{
		kol = 0;
		for (i = 1; i <= n; i++)
			if (sev[i][j] == 1) { kol++; p = i; break; }
		if (kol == 1)
		{
			for (i = 1; i <= n; i++)
				if (p!=i) sev[i][j] = -1;
		}
	}

	for (j = 1; j <= m; j++)
	{
		for (i = 1; i <= n; i++)
			if (sev[i][j] != -1)
			{
				cout << i << endl;
				break;
			}
	}*/
	
	



	kl = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			if (sev[i][j] != -1) kl = kl + (sev[i][j]*c[i][j]);
	}

	if (kl != 0) f2 << "-1";
	else
	{
		for (j = 1; j <= m; j++)
		{
			kl = 0;
			for (i = 1; i <= n;i++)
				if (sev[i][j] == 1)
				{ 
					kl++;
					f2 << i << endl;
					break; 
				}

			if (kl == 0)
			{
				i = 1;
				while (sev[i][j] != 0) i++;
				f2 << i << endl;
			}
		}
	}

























	/*cout << endl << "Матрица сeверо-западного угла:\n";
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			cout << setw(4) << sev[i][j] << " ";
		cout << endl;
	}*/

	/*
	cout << endl << "Матрица дельта c:\n";
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			cout << cc[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	for (i = 0; i <= ll; i++)
	{
		cout << q[i].si << " " << q[i].sj;
		cout << endl;
	}


	cout << endl << "Кол-во вечеринок, на которые может прийти корова:\n";
	for (i = 1; i <= n; i++)
		cout << b[i] << " ";
	cout << endl;

	cout << endl << "Матрица стоимости перевозок:\n";
	for (i = 1; i <= nc; i++)
	{
		for (j = 1; j <= mc; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	cout << endl;


	cout << endl;

	cout << endl << "Потенциалы u:\n";
	for (i = 1; i <= nc; i++)
		cout << u[i] << " ";
	cout << endl;

	cout << endl << "Потенциалы v:\n";
	for (i = 1; i <= mc; i++)
		cout << v[i] << " ";
	cout << endl;
	*/


	f1.close();
	f2.close();
	return 0;
}