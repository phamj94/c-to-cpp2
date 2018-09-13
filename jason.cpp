/*

Written by: Jason Pham, Sadra Vahedi, Angelica Garcia

CS 36 - Afternoon


*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	

void load(char *name, float *HW, float *HR, float *FT, float *ST) 
{
	printf("Enter a name:  ");
	gets_s(name, 20);
	printf("Enter Hours Worked:  ");
	scanf("%f", &(*HW));
	printf("Enter Hourly Rate:  ");
	scanf("%f", &(*HR));
	printf("Enter Federal Tax Rate:  ");
	scanf("%f", &(*FT));
	printf("Enter State Tax Rate:  ");
	scanf("%f", &(*ST));
	getchar();
}

void calc(float HW, float HR, float FT, float ST, float *gp, float *fto, float *sto, float *netp,float *tothw, float *totgp, float *totftax, float *totstax, float *totnp, float *overHW, float *overHR, float *overname)
{
	(*gp) = (HW) * (HR);
	(*fto) = (*gp) * (FT) / (float)100;
	(*sto) = (*gp) * (ST) / (float)100;
	(*netp) = (*gp) - (*fto) - (*sto);
	*tothw += HW;
	*totgp += *gp;
	*totftax += *fto;
	*totstax += *sto;
	*totnp += *netp;

	if (HW > 40.0)

	{
		*overHW = HW - 40.0;
		*overHR = *overHW *(1.5 * HR);
		*overname += 1;
	}
	else 
	{
		 *overHW = 0;
		 *overHR = 0;
	}
}

void print(char *name, float gp, float fto, float sto, float netp, float overHW, float overHR)
{
	printf("\n%s has a gross pay of $%0.2f\n", name, gp);
	printf("%s owes a Federal Tax of %0.2f\n", name, fto);
	printf("%s owes a State Tax of %0.2f\n", name, sto);
	printf("%s has a net pay of $%0.2f\n\n", name, netp);

	printf("Overtime worked hours %0.2f\n", overHW);
	printf("Overtime paid $%0.2f\n\n", overHR);
}

void printtotal(float tothw, float totgp, float totftax, float totstax, float totnp)
{

	printf( "The total hours worked are %0.2f\n", tothw);
	printf( "The total gross pay $%0.2f\n", totgp);
	printf( "The total federal taxes paid are $%0.2f\n", totftax);
	printf( "The total state taxes paid are $%0.2f\n", totstax);
	printf( "The total net pay is $%0.2f\n", totnp);

	
}
void main()
{
	float HW, HR, FT, ST, gp, fto, sto, netp, tothw, totgp, totftax, totstax, totnp, overHW, overHR, overname;
	char name[20];

	totgp = 0, totftax = 0, totstax = 0, totnp = 0,  tothw = 0;
	// Used a 4 loop because we can assume there are 4 employees
	for(int i = 1; i<=4; i++)
	{
	load(name, &HW, &HR, &FT, &ST);
	calc(HW, HR, FT, ST, &gp, &fto, &sto, &netp, &tothw, &totgp, &totftax, &totstax, &totnp, &overHW, &overHR, &overname);
	print(name, gp, fto, sto, netp, overHW, overHR);
	}
	printtotal(tothw, totgp, totftax, totstax, totnp);
	
	system("PAUSE");
	
}
/*
Enter a name:  Charles
Enter Hours Worked:  46.3
Enter Hourly Rate:  49.14
Enter Federal Tax Rate:  21.2
Enter State Tax Rate:  7.5

Charles has a gross pay of $2275.18
Charles owes a Federal Tax of 482.34
Charles owes a State Tax of 170.64
Charles has a net pay of $1622.20

Overtime worked hours 6.30
Overtime paid $464.37

Enter a name:  Kobe
Enter Hours Worked:  38.75
Enter Hourly Rate:  45.65
Enter Federal Tax Rate:  20.1
Enter State Tax Rate:  8.75

Kobe has a gross pay of $1768.94
Kobe owes a Federal Tax of 355.56
Kobe owes a State Tax of 154.78
Kobe has a net pay of $1258.60

Overtime worked hours 0.00
Overtime paid $0.00

Enter a name:  Ervin
Enter Hours Worked:  31.6
Enter Hourly Rate:  39.95
Enter Federal Tax Rate:  17.5
Enter State Tax Rate:  6.8

Ervin has a gross pay of $1262.42
Ervin owes a Federal Tax of 220.92
Ervin owes a State Tax of 85.84
Ervin has a net pay of $955.65

Overtime worked hours 0.00
Overtime paid $0.00

Enter a name:  Michael
Enter Hours Worked:  53.25
Enter Hourly Rate:  59.33
Enter Federal Tax Rate:  22.5
Enter State Tax Rate:  9.25

Michael has a gross pay of $3159.32
Michael owes a Federal Tax of 710.85
Michael owes a State Tax of 292.24
Michael has a net pay of $2156.24

Overtime worked hours 13.25
Overtime paid $1179.18

The total hours worked are 169.90
The total gross pay $8465.86
The total federal taxes paid are $1769.67
The total state taxes paid are $703.50
The total net pay is $5992.69
Press any key to continue . . .
*/