//Author: Tyler Patrick
//Date: 3/16/19
//Assignment: Lab 7: Fun with Functions
//General Description:Write the functions detailed below. Use the main() provided below to test the functions. See the notes
//on the website on Implementing Functions for tips on interpreting these descriptions and writing the
//functions.Also review the notes on Functions covered in class.

#include <iostream>

using namespace std;

const int MIN_FRAC = 1, MAX_FRAC = 10;

struct Fraction
{
	int numerator;
	int denominator;
	float decimal;

};

//----------------------------
//           askFraction
//----------------------------
Fraction askFraction()
{
	Fraction f;
	f.denominator = 0;
	cout << "Enter value for Numerator: ";
	cin >> f.numerator;
	while (f.denominator == 0)
	{
		cout << "Enter value for Denominator: ";
			cin >> f.denominator;
	}
	f.decimal = 0.0;
	return f;

}
//----------------------------
//           Calculate Decimal
//----------------------------
void calcDecimal(Fraction & f)
{
	if (f.denominator == 0)
	{
		f.decimal = 0.0;
	}
	else
		f.decimal = float(f.numerator) / float(f.denominator);

}
//----------------------------
//           Print Fraction
//----------------------------
void printFraction(Fraction & f)
{
	cout << f.numerator << " / " << f.denominator << " (" << f.decimal << ")";
}
//----------------------------
//       Asks for fraction list
//----------------------------
void askFractionList(Fraction fractions[], int & numFractions)
{
	numFractions = -50;
	while (numFractions < MIN_FRAC || numFractions > MAX_FRAC)
	{
		cout << "Enter number of fractions: ";
		cin >> numFractions;
		if (numFractions < MIN_FRAC || numFractions > MAX_FRAC)
		{
			cout << "Enter a number between 1 and 10 " << endl;
		}
	}
	for (int i = 0; i < numFractions; i++)
	{
		cout << "For Fraction " << i + 1 << endl;
		fractions[i] = askFraction();
		calcDecimal(fractions[i]);
	}
}
//----------------------------
//       Prints Fraction List
//----------------------------

void printFractionList(Fraction fractions[], int numFractions)
{
	for (int i = 0; i < numFractions; i++)
	{
		printFraction(fractions[i]);
		cout << endl;
    }

}
//----------------------------
//       Finds Max Fraction
//----------------------------
int findMaxFraction(Fraction fractions[], int numFractions)
{
	int maxindex = 0;
	for (int i = 0; i < numFractions; i++)
	{
		if (fractions[i].decimal > fractions[maxindex].decimal)
		{
			maxindex = i;
		}
	}
	return maxindex;
}
int main()
{
	int numFractions = 0;
	Fraction fractions[MAX_FRAC];
	askFractionList(fractions, numFractions);
	printFractionList(fractions, numFractions);
	cout << "The hightest value fraction is:";
	printFraction(fractions[findMaxFraction(fractions, numFractions)]);
	cout << endl;
	system("PAUSE");
}

