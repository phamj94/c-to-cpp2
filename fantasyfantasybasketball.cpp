//Exam Program 1
//Written by: Jason Pham
//CS37 Afternoon
//Sept. 9, 2018

#include<iostream>
#include<iomanip>
using namespace std;


void load(char name[20], float hw, float hr, float ftr, float str)
{

	
	cout << "  Enter your name  ";
	cin >> name;
	cout << "  Enter your Hours Worked" << endl;
	cin >> hw;
	cout << "  Enter your Hourly rate" << endl;
	cin >> hr; 
	cout << "  Enter your Federal Tax Rate " << endl;
	cin >> ftr;
	cout << "  Enter your Sales Tax Rate " << endl;
	cin >> str;
}

void calc(float hw, float hr, float ftr, float str, float gp, float fto, float sto, float np,
	float totgp, float totfto, float totsto, float totnp, float overhw, float overpay, 
	float totoverpay, float overname)
{
	

	gp = (hw * hr + overpay);
	fto = (gp * ftr) / (float)100;
	sto = (gp * str) / (float)100;
	np = (gp - fto - sto);

	totgp = 0, totfto = 0, totsto = 0, totnp = 0, totoverpay = 0, overname = 0;

	totgp += gp;
	totfto += fto;
	totsto += sto;
	totnp += np;
	totoverpay += overpay;

	if (hw > 40.0)
	{
		overhw = hw - (float)40.0;
		overpay = overhw *((float)1.5 * hr);
		overname += 1;
	}
	else
	{
		overhw = 0;
		overpay = 0;
	}
}

void print(char name[20],float gp, float fto,float sto,float np)
{
	 

	cout << endl << "Employee  " << name << endl;
	cout<< setprecision(2) << showpoint << fixed;
	cout << "Gross Pay: $  " << gp << endl;
	cout << "Federal Tax Owed: $  " << fto << endl;
	cout << "State Tax Owed: $  " << sto << endl;
	cout << "Net Pay: $  " << np << endl;
}

void printtotal(float totgp, float totfto, float totsto, float totnp,
	float overhw, float overpay, float totoverpay, float overname)
{
	cout << endl << "Total Gross Pay:  " << totgp << endl;
	cout << "Total Federal Tax Owed:  " << totfto << endl;
	cout << "Total State Tax Owed:  " << totsto << endl;
	cout << "Total Net Pay:  " << totnp << endl;
}

void printovertime(float totoverpay,float overname)
{
	cout << endl << "Total Overtime Pay:  " << totoverpay << endl;
	cout << "Number of Employees who were paid Overtime:  " << overname << endl;
}

int main(char name[20], float hw, float hr, float ftr, float str, float gp, float fto, float sto, float np,
	float totgp, float totfto, float totsto, float totnp, float overhw, float overpay,
	float totoverpay, float overname)
{
	for (int i = 1; i <= 4; i++)
	{
		load(name, hw, hr, ftr, str);
		calc(hw, hr, ftr,  str,  gp,  fto,  sto,  np,totgp,totfto, 
			totsto, totnp, overhw, overpay,totoverpay,overname);
		print(name, gp, fto, sto, np);
		printtotal(totgp, totfto, totsto,  totnp, overhw, overpay,  totoverpay, overname);
		printovertime(totoverpay, overname);

	}
	system("pause");
	return 0;
}
