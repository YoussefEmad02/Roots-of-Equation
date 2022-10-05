#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;



///global variable if equal 1 there is no error else if = 0 there is error;

int global_variable = 0;

// function to find 1st degree error
void first_degree_error(string eq)
{
	int coeff1 = eq.at(eq.find("x") - 1);
	int coeff0 = eq.at(eq.find("x") + 2);
	int coeff0_sign = eq.at(eq.find("x") + 1);
	int X_error = eq.find("X");

	// Error if coeff0 doesn't exist

	if (coeff1 != 48 && coeff1 != 49 && coeff1 != 50 && coeff1 != 51 && coeff1 != 52 && coeff1 != 53 && coeff1 != 54 && coeff1 != 55 && coeff1 != 56 && coeff1 != 57)
		cout << "Error !! " << endl << "Please make sure that x^2 Coefficient from 0 to 9 " << endl;

	// Error if coeff1 coefficient doesn't exist

	else if (coeff0 != 48 && coeff0 != 50 && coeff0 != 51 && coeff0 != 52 && coeff0 != 53 && coeff0 != 54 && coeff0 != 55 && coeff0 != 56 && coeff0 != 57)
		cout << "Error !! " << endl << "Please make sure that x Coefficient from 0 to 9 " << endl;

	//Error if coeff0 doesn't exist

	else if (coeff0_sign != '-' && coeff0_sign != '+')
		cout << "Error !! " << endl << "Please input last coefficient sign" << endl;

	else
		global_variable = 1;
}

//function to find first degree roots
void first_degree_root(string eq)
{
	first_degree_error(eq);
	if (global_variable == 1)
	{
		string first_coeff = eq.substr(0, eq.find("x"));
		float coeff1 = stof(first_coeff);

		string second_coeff;
		if (eq.at(eq.find("x") + 1) == '+')
			second_coeff = eq.substr((eq.find("x") + 2), eq.length());

		else if (eq.at(eq.find("x") + 1) == '-')
			second_coeff = eq.substr((eq.find("x") + 1), eq.length());

		float coeff0 = stof(second_coeff);

		// finding root 1

		float root1 = (-1 * coeff0) / coeff1;


		cout << "Root = " << root1 << endl;
	}
	else
	{

	}
}



//functioon to find if there is error at quadratic equation
void quadratic_equation_error(string eq)
{
	int first_coeff = eq.at(eq.find("x") - 1);
	int second_coeff = eq.at(eq.rfind("x") - 1);
	int third_coeff = eq.at(eq.length() - 1);
	int first_sign = eq.at(eq.find("x") + 3);
	int second_sign = eq.at(eq.rfind("x") + 1);
	int power = eq.at(eq.find("x") + 2);
	int power_sign = eq.at(eq.find("x") + 1);

	// Error if coeff2 doesn't exist

	if (first_coeff != 48 && first_coeff != 49 && first_coeff != 50 && first_coeff != 51 && first_coeff != 52 && first_coeff != 53 && first_coeff != 54 && first_coeff != 55 && first_coeff != 56 && first_coeff != 57)
		cout << "Error !! " << endl << "Please make sure that x^2 Coefficient from 0 to 9 " << endl;

	// Error if coeff1 coefficient doesn't exist

	else if (second_coeff != 48 && second_coeff != 49 && second_coeff != 50 && second_coeff != 51 && second_coeff != 52 && second_coeff != 53 && second_coeff != 54 && second_coeff != 55 && second_coeff != 56 && second_coeff != 57)
		cout << "Error !! " << endl << "Please make sure that x Coefficient from 0 to 9 " << endl;

	// coeff0 length -1 because we start from 0 not 1 so no value at length

	else if (third_coeff == '-' || third_coeff == '+') //f_num != 2 || f_num != 3 || f_num != 4 || f_num != 5 || f_num != 6 || f_num != 7 || f_num != 8 || f_num != 9)
		cout << "Error !! " << endl << "Please make sure that last Coefficient from 0 to 9 " << endl;

	// Error if x^2 power sign ( ^ ) doesn't exist

	else if (power_sign != '^')
		cout << "Error !! " << endl << "Please add ( ^ ) sign for x^2 " << endl << power_sign;

	// Error if power doesn't exist

	else if (power != 49 && power != 50 && power != 51 && power != 52 && power != 53 && power != 54 && power != 55 && power != 56 && power != 57)
		cout << "Error !! " << endl << "Please make sure that x^2 power from 0 to 9 " << endl;

	// if last x has ^ after it

	else if (second_sign == '^')
		cout << "Error !! " << endl << "Please remove ( ^ ) sign after last x" << endl;


	// if sign before x isn't + or - output error

	else if (first_sign != '-' && first_sign != '+')
		cout << "Error !! " << endl << "Please input x coefficient sign" << endl;

	// if coeff 0 sign not + or - output error

	else if (second_sign != '-' && second_sign != '+')
		cout << "Error !! " << endl << "Please input last coefficient sign" << endl;
	else
		global_variable = 1;
}


// function to return coeff to it as float after reduce it and to find quadratic roots

void quadratic_equation_roots_to_use(float a, float b, float c)
{

	float root1, root2, discriminant, realPart, imaginaryPart;

	discriminant = b * b - 4 * a * c;

	if (discriminant > 0)
	{
		root1 = (-b + sqrt(discriminant)) / (2 * a);
		root2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "First  Root = " << root1 << endl;
		cout << "Second Root = " << root2 << endl;
	}

	else if (discriminant == 0)
	{
		root1 = -b / (2 * a);
		cout << "First  Root = " << root1 << endl;
		cout << "Second Root = " << root1 << endl;
	}

	else
	{
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-discriminant) / (2 * a);
		cout << "First  Root = " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "second Root = " << realPart << "-" << imaginaryPart << "i" << endl;
	}
}


void quadratic_equation_roots(string eq)
{
	quadratic_equation_error(eq);

	if (global_variable == 1)
	{
		char power = eq.at(eq.find("x") + 2);

		int z = eq.find("x");
		string r = eq.substr(0, z);
		float a = stof(r);

		int q = eq.rfind("x");
		string w = eq.substr(z + 3, q);
		float b = stof(w);

		int e = eq.rfind("x");
		float c;
		if (e + 1 == '+')
		{
			string p = eq.substr(q + 2, eq.length());
			c = stof(p);
		}
		else
		{
			string p = eq.substr(q + 1, eq.length());
			c = stof(p);
		}

		int size = power - 48;

		int* arr = new int[power];

		for (int i = size; i >= 0; i--)
		{
			switch (i)
			{
			case 0: arr[i] = c;
				break;
			case 1: arr[i] = b;
				break;
			case 2: arr[i] = a;
				break;
			}
			cout << "coeff" << i << " = " << arr[i] << "\t";
		}

		cout << endl << endl;

		delete[]arr;


		quadratic_equation_roots_to_use(a, b, c);

	}
	else
	{

	}

}



void cubic_equation_error(string eq)
{
	int pow_sign = eq.find("^");
	int coeff3 = eq.at(eq.find("^") - 2);
	int power = eq.at(eq.rfind("^") + 1);
	string quadratic_eq;


	if (coeff3 != 48 && coeff3 != 49 && coeff3 != 50 && coeff3 != 51 && coeff3 != 52 && coeff3 != 53 && coeff3 != 54 && coeff3 != 55 && coeff3 != 56 && coeff3 != 57)
		cout << "Error !! " << endl << "Please make sure that x^3 Coefficient from 0 to 9 " << endl;

	else if (pow_sign == 0)
		cout << " Error !! " << endl << "Please make sure that x^3 has power sign ^ " << endl;

	else if (power != 49 && power != 50 && power != 51 && power != 52 && power != 53 && power != 54 && power != 55 && power != 56 && power != 57)
		cout << "Error !! " << endl << "Please make sure that x^3 Coefficient from 1 to 9 " << endl;

	else
	{
		if (eq.at(eq.find("^") + 2) == '+')
		{
			quadratic_eq = (eq.substr(eq.find("^") + 3, eq.length()));

		}

		else if (eq.at(eq.find("^") + 2) == '-')
		{
			quadratic_eq = (eq.substr(eq.find("^") + 2, eq.length()));
		}

		quadratic_equation_error(quadratic_eq);
	}

}



void cubic_equation_roots_to_use(float coeff3, float coeff2, float coeff1, float coeff0)
{
	// split the equation into (1st eq) * (2nd) equation

	// new coeff to put it in quadratic roots fun

	float quadratic_coeff2, quadratic_coeff1, quadratic_coeff0;

	float Third_Root;

	float x1, x2, x3;

	int o = 0, q = 0, l = 0;

	int check_size = pow(coeff0, 2);

	int size = sqrt(check_size);

	float* pos_arr = new float[size];


	for (int i = 1; i <= size; i++)
	{
		if (size % i == 0)
		{
			pos_arr[o] = i;
			o++;
		}

	}


	int check_size_2 = pow(coeff3, 2);

	int size_2 = sqrt(check_size_2);

	float* pos_arr_2 = new float[size_2];


	for (int i = 1; i <= size_2; i++)
	{
		if (size_2 % i == 0)
		{
			pos_arr_2[q] = i;
			q++;
		}

	}


	int size_3 = q * o;
	int last = 0;
	float* pos_arr_3 = new float[size_3];

	for (int d = 0; d < o; d++)
	{
		for (int e = 0; e < q; e++)
		{
			pos_arr_3[l] = (pos_arr[d] / pos_arr_2[e]);
			l++;


		}
	}


	float* final_arr = new float[2 * size_3];

	for (int i = 0; i < size_3; i++)
	{
		final_arr[i] = pos_arr_3[i];
	}

	for (int i = size_3; i < (2 * size_3); i++)
	{
		final_arr[i] = -1 * pos_arr_3[i - 4];
	}


	for (int i = 0; i < 2 * size_3; i++)
	{
		x1 = (coeff3 * pow(final_arr[i], 3));
		x2 = (coeff2 * pow(final_arr[i], 2));
		x3 = (coeff1 * final_arr[i]);

		if (x1 + x2 + x3 + coeff0 == 0)
		{
			Third_Root = final_arr[i];
			quadratic_coeff2 = coeff3;
			quadratic_coeff1 = (quadratic_coeff2 * final_arr[i]) + coeff2;
			quadratic_coeff0 = (quadratic_coeff1 * final_arr[i]) + coeff1;
			quadratic_equation_roots_to_use(quadratic_coeff2, quadratic_coeff1, quadratic_coeff0);
			cout << "Third  Root = " << Third_Root << endl;
			break;
		}
		else continue;

	}

	if (x1 + x2 + x3 + coeff0 != 0)
	{
		cout << "The following Roots not found" << endl;
	}
}

//function to find roots of cubic equation by find x^3 index and take from the index after it to length in string to sub by it in quadratic function 

void cubic_equation_roots(string eq)
{
	cubic_equation_error(eq);

	if (global_variable == 1)
	{

		float coeff3, coeff2, coeff1, coeff0;

		// finding the cofficients

		char power = eq.at(eq.find("x") + 2);

		int z = eq.find("x");
		string r = eq.substr(0, z);
		coeff3 = stof(r);

		int q = eq.rfind("^");
		string w = eq.substr(z + 3, q - 1);
		coeff2 = stof(w);

		int u = eq.rfind("x");
		if (u + 1 == '+')
		{
			string p = eq.substr(q + 3, u);
			coeff1 = stof(p);
		}
		else
		{
			string d = eq.substr(q + 2, u);
			coeff1 = stof(d);
		}

		int e = eq.rfind("x");
		if (e + 1 == '+')
		{
			string d = eq.substr(u + 2, eq.length());
			coeff0 = stof(d);
		}
		else
		{
			string p = eq.substr(u + 1, eq.length());
			coeff0 = stof(p);
		}


		int size = power - 48;

		int* arr = new int[power];

		for (int i = size; i >= 0; i--)
		{
			switch (i)
			{
			case 0: arr[i] = coeff0;
				break;
			case 1: arr[i] = coeff1;
				break;
			case 2: arr[i] = coeff2;
				break;
			case 3: arr[i] = coeff3;
				break;
			}
			cout << "coeff" << i << " = " << arr[i] << "\t";
		}

		cout << endl << endl;

		delete[]arr;


		// split the equation into (1st eq) * (3rd) equation by send coefficients to this function

		cubic_equation_roots_to_use(coeff3, coeff2, coeff1, coeff0);

	}
	else
	{

	}
}


void fourth_degree_equation_error(string eq)
{
	int pow_sign = eq.find("^");
	int coeff4 = eq.at(eq.find("^") - 2);
	int power = eq.at(eq.rfind("^") + 1);
	string cubic_eq;


	if (coeff4 != 48 && coeff4 != 49 && coeff4 != 50 && coeff4 != 51 && coeff4 != 52 && coeff4 != 53 && coeff4 != 54 && coeff4 != 55 && coeff4 != 56 && coeff4 != 57)
		cout << "Error !! " << endl << "Please make sure that x^4 Coefficient from 0 to 9 " << endl;

	else if (pow_sign == 0)
		cout << " Error !! " << endl << "Please make sure that x^4 has power sign ^ " << endl;

	else if (power != 49 && power != 50 && power != 51 && power != 52 && power != 53 && power != 54 && power != 55 && power != 56 && power != 57)
		cout << "Error !! " << endl << "Please make sure that x^4 Coefficient from 0 to 9 " << endl;

	else
	{
		if (eq.at(eq.find("^") + 2) == '+')
		{
			cubic_eq = (eq.substr(eq.find("^") + 3, eq.length()));

		}

		else if (eq.at(eq.find("^") + 2) == '-')
		{
			cubic_eq = (eq.substr(eq.find("^") + 2, eq.length()));
		}

		cubic_equation_error(cubic_eq);
	}
}

void fourth_degree_equation_roots_to_use(float coeff4, float coeff3, float coeff2, float coeff1, float coeff0)
{


	// split the equation into (1st eq) * (2nd) equation

	float cubic_coeff3, cubic_coeff2, cubic_coeff1, cubic_coeff0;

	float fourth_root;

	float x1, x2, x3, x4;

	int o = 0, q = 0, l = 0;

	int check_size = pow(coeff0, 2);

	int size = sqrt(check_size);

	float* pos_arr = new float[size];


	for (int i = 1; i <= size; i++)
	{
		if (size % i == 0)
		{
			pos_arr[o] = i;
			o++;
		}

	}


	int check_size_2 = pow(coeff4, 2);

	int size_2 = sqrt(check_size_2);

	float* pos_arr_2 = new float[size_2];


	for (int i = 1; i <= size_2; i++)
	{
		if (size_2 % i == 0)
		{
			pos_arr_2[q] = i;
			q++;
		}

	}


	int size_3 = q * o;
	int last = 0;
	float* pos_arr_3 = new float[size_3];

	for (int d = 0; d < o; d++)
	{
		for (int e = 0; e < q; e++)
		{
			pos_arr_3[l] = (pos_arr[d] / pos_arr_2[e]);
			l++;


		}
	}


	float* final_arr = new float[2 * size_3];

	for (int i = 0; i < size_3; i++)
	{
		final_arr[i] = pos_arr_3[i];
	}

	for (int i = size_3; i < (2 * size_3); i++)
	{
		final_arr[i] = -1 * pos_arr_3[i - 4];
	}



	for (int i = 0; i < 2 * size_3; i++)
	{

		x1 = (coeff4 * pow(final_arr[i], 4));
		x2 = (coeff3 * pow(final_arr[i], 3));
		x3 = (coeff2 * pow(final_arr[i], 2));
		x4 = (coeff1 * final_arr[i]);

		if (x1 + x2 + x3 + x4 + coeff0 == 0)
		{
			fourth_root = final_arr[i];
			cubic_coeff3 = coeff4;
			cubic_coeff2 = (cubic_coeff3 * final_arr[i]) + coeff3;
			cubic_coeff1 = (cubic_coeff2 * final_arr[i]) + coeff2;
			cubic_coeff0 = (cubic_coeff1 * final_arr[i]) + coeff1;
			cubic_equation_roots_to_use(cubic_coeff3, cubic_coeff2, cubic_coeff1, cubic_coeff0);
			cout << "Fourth Root = " << fourth_root << endl;
			break;
		}
		else continue;

	}

	if (x1 + x2 + x3 + x4 + coeff0 != 0)
	{
		cout << "The following Roots not found" << endl;
	}
}


void fourth_degree_equation_roots(string eq)
{
	fourth_degree_equation_error(eq);

	if (global_variable == 1)
	{
		float coeff4, coeff3, coeff2, coeff1, coeff0;
		float cubic_coeff3, cubic_coeff2, cubic_coeff1, cubic_coeff0;

		// finding the cofficients

		char power = eq.at(eq.find("x") + 2);


		string b = eq.substr(0, eq.find("x"));
		coeff4 = stof(b);

		string cubic_eq;

		if (eq.at(eq.find("^") + 2) == '+')
		{
			cubic_eq = (eq.substr(eq.find("^") + 3, eq.length()));
			//string cubic_eq =  8x^3 -3x^2 +5x +2 = 0

		}

		else if (eq.at(eq.find("^") + 2) == '-')
		{
			cubic_eq = (eq.substr(eq.find("^") + 2, eq.length()));
			//string cubic_eq = - 8x^3 -3x^2 +5x +2 = 0
		}

		int z = cubic_eq.find("x");
		string r = cubic_eq.substr(0, z);
		coeff3 = stof(r);

		int q = cubic_eq.rfind("^");
		string w = cubic_eq.substr(z + 3, q - 1);
		coeff2 = stof(w);

		int u = cubic_eq.rfind("x");
		if (u + 1 == '+')
		{
			string p = cubic_eq.substr(q + 3, u);
			coeff1 = stof(p);
		}
		else
		{
			string d = cubic_eq.substr(q + 2, u);
			coeff1 = stof(d);
		}

		int e = cubic_eq.rfind("x");
		if (e + 1 == '+')
		{
			string d = cubic_eq.substr(u + 2, w.length());
			coeff0 = stof(d);
		}
		else
		{
			string p = cubic_eq.substr(u + 1, w.length());
			coeff0 = stof(p);
		}


		int size = power - 48;

		int* arr = new int[power];

		for (int i = size; i >= 0; i--)
		{
			switch (i)
			{
			case 0: arr[i] = coeff0;
				break;
			case 1: arr[i] = coeff1;
				break;
			case 2: arr[i] = coeff2;
				break;
			case 3: arr[i] = coeff3;
				break;
			case 4: arr[i] = coeff4;
				break;
			}
			cout << "coeff" << i << " = " << arr[i] << "\t";
		}

		cout << endl << endl;

		delete[]arr;

		// split the equation into (1st eq) * (3rd) equation

		fourth_degree_equation_roots_to_use(coeff4, coeff3, coeff2, coeff1, coeff0);

	}
	else
	{

	}
}



void fifth_degree_equation_error(string eq)
{
	int pow_sign = eq.find("^");
	int coeff5 = eq.at(eq.find("x") - 1);
	int power = eq.at(eq.rfind("^") + 1);
	string fourth_degree_eq;


	if (coeff5 != 48 && coeff5 != 49 && coeff5 != 50 && coeff5 != 51 && coeff5 != 52 && coeff5 != 53 && coeff5 != 54 && coeff5 != 55 && coeff5 != 56 && coeff5 != 57)
		cout << "Error !! " << endl << "Please make sure that x^5 Coefficient from 0 to 9 " << endl;

	else if (pow_sign == 0)
		cout << " Error !! " << endl << "Please make sure that x^5 has power sign ^ " << endl;

	else if (power != 48 && power != 49 && power != 50 && power != 51 && power != 52 && power != 53 && power != 54 && power != 55 && power != 56 && power != 57)
		cout << "Error !! " << endl << "Please make sure that x^5 power from 2 to 9 " << endl;

	else
	{
		if (eq.at(eq.find("^") + 2) == '+')
		{
			fourth_degree_eq = (eq.substr(eq.find("^") + 3, eq.length()));

		}

		else if (eq.at(eq.find("^") + 2) == '-')
		{
			fourth_degree_eq = (eq.substr(eq.find("^") + 2, eq.length()));
		}

		fourth_degree_equation_error(fourth_degree_eq);
	}
}

void fifth_degree_equation_roots_to_use(float coeff5, float coeff4, float coeff3, float coeff2, float coeff1, float coeff0)
{
	float quartic_coeff4, quartic_coeff3, quartic_coeff2, quartic_coeff1, quartic_coeff0;


	// split the equation into (1st eq) * (2nd) equation

	// new coeff to put it in quadratic roots fun

	float fifth_root;

	float x1, x2, x3, x4, x5;

	int o = 0, q = 0, l = 0;

	int check_size = pow(coeff0, 2);

	int size = sqrt(check_size);

	float* pos_arr = new float[size];


	for (int i = 1; i <= size; i++)
	{
		if (size % i == 0)
		{
			pos_arr[o] = i;
			o++;
		}

	}


	int check_size_2 = pow(coeff4, 2);

	int size_2 = sqrt(check_size_2);

	float* pos_arr_2 = new float[size_2];


	for (int i = 1; i <= size_2; i++)
	{
		if (size_2 % i == 0)
		{
			pos_arr_2[q] = i;
			q++;
		}

	}


	int size_3 = q * o;
	int last = 0;
	float* pos_arr_3 = new float[size_3];

	for (int d = 0; d < o; d++)
	{
		for (int e = 0; e < q; e++)
		{
			pos_arr_3[l] = (pos_arr[d] / pos_arr_2[e]);
			l++;


		}
	}


	float* final_arr = new float[2 * size_3];

	for (int i = 0; i < size_3; i++)
	{
		final_arr[i] = pos_arr_3[i];
	}

	for (int i = size_3; i < (2 * size_3); i++)
	{
		final_arr[i] = -1 * pos_arr_3[i - 4];
	}



	for (int i = 0; i < 2 * size_3; i++)
	{

		x1 = (coeff5 * pow(final_arr[i], 5));
		x2 = (coeff4 * pow(final_arr[i], 4));
		x3 = (coeff3 * pow(final_arr[i], 3));
		x4 = (coeff2 * pow(final_arr[i], 2));
		x5 = (coeff1 * final_arr[i]);


		if (x1 + x2 + x3 + x4 + x5 + coeff0 == 0)
		{
			fifth_root = final_arr[i];
			quartic_coeff4 = coeff5;
			quartic_coeff3 = (quartic_coeff4 * final_arr[i]) + coeff4;
			quartic_coeff2 = (quartic_coeff3 * final_arr[i]) + coeff3;
			quartic_coeff1 = (quartic_coeff2 * final_arr[i]) + coeff2;
			quartic_coeff0 = (quartic_coeff1 * final_arr[i]) + coeff1;
			fourth_degree_equation_roots_to_use(quartic_coeff4, quartic_coeff3, quartic_coeff2, quartic_coeff1, quartic_coeff0);
			cout << "Fifth  Root = " << fifth_root << endl;
			break;
		}
		else continue;

	}

	if (x1 + x2 + x3 + x4 + x5 + coeff0 != 0)
	{
		cout << "The following Roots not found" << endl;
	}
}

void fifth_degree_equation_roots(string eq)
{
	fifth_degree_equation_error(eq);

	if (global_variable == 1)
	{
		char power = eq.at(eq.find("x") + 2);
		float coeff5, coeff4, coeff3, coeff2, coeff1, coeff0;
		float res;
		string fourth;

		// finding the cofficients

		string m = eq.substr(0, eq.find("x"));
		coeff5 = stof(m);


		if (eq.at(eq.find("^") + 2) == '+')
		{
			fourth = (eq.substr(eq.find("^") + 3, eq.length()));
		}
		else if (eq.at(eq.find("^") + 2) == '-')
		{
			fourth = (eq.substr(eq.find("^") + 2, eq.length()));
		}


		string b = fourth.substr(0, fourth.find("x"));
		coeff4 = stof(b);

		string cubic_eq;

		if (fourth.at(fourth.find("^") + 2) == '+')
		{
			cubic_eq = (fourth.substr(fourth.find("^") + 3, fourth.length()));
			//string cubic_eq =  8x^3 -3x^2 +5x +2 = 0

		}

		else if (fourth.at(fourth.find("^") + 2) == '-')
		{
			cubic_eq = (fourth.substr(fourth.find("^") + 2, fourth.length()));
			//string cubic_eq = - 8x^3 -3x^2 +5x +2 = 0
		}

		int z = cubic_eq.find("x");
		string r = cubic_eq.substr(0, z);
		coeff3 = stof(r);

		int q = cubic_eq.rfind("^");
		string w = cubic_eq.substr(z + 3, q - 1);
		coeff2 = stof(w);

		int u = cubic_eq.rfind("x");
		if (u + 1 == '+')
		{
			string p = cubic_eq.substr(q + 3, u);
			coeff1 = stof(p);
		}
		else
		{
			string d = cubic_eq.substr(q + 2, u);
			coeff1 = stof(d);
		}

		int e = cubic_eq.rfind("x");
		if (e + 1 == '+')
		{
			string d = cubic_eq.substr(u + 2, w.length());
			coeff0 = stof(d);
		}
		else
		{
			string p = cubic_eq.substr(u + 1, w.length());
			coeff0 = stof(p);
		}

		int size = power - 48;

		int* arr = new int[power];

		for (int i = size; i >= 0; i--)
		{
			switch (i)
			{
			case 0: arr[i] = coeff0;
				break;
			case 1: arr[i] = coeff1;
				break;
			case 2: arr[i] = coeff2;
				break;
			case 3: arr[i] = coeff3;
				break;
			case 4: arr[i] = coeff4;
				break;
			case 5: arr[i] = coeff5;
				break;
			}
			cout << "coeff" << i << " = " << arr[i] << "\t";
		}

		cout << endl << endl;

		delete[]arr;

		fifth_degree_equation_roots_to_use(coeff5, coeff4, coeff3, coeff2, coeff1, coeff0);

	}
	else
	{

	}
}




//  Finding the order
void find_order(string eq)
{
	int n = eq.at(eq.find("^") + 1) - 48;
	int pow = eq.at(eq.find("^") + 1);

	if (eq.at(eq.find("x") + 1) == '+' || eq.at(eq.find("x") + 1) == '-')
	{
		cout << "The order is: " << 2 << endl;
		first_degree_root(eq);
	}

	else
	{
		if (eq.at(eq.find("x") + 1) != '^')
			cout << "Error !! " << endl << "Please make sure that power sign ( ^ ) exist after first x" << endl;

		else if (pow != 49 && pow != 50 && pow != 51 && pow != 52 && pow != 53 && pow != 54 && pow != 55 && pow != 56 && pow != 57)
			cout << "Error !! " << endl << "Please make sure that power exist after first x" << endl;

		else if (n == 2)
		{
			cout << "The order is: " << n << endl << endl;
			quadratic_equation_roots(eq);
		}

		else if (n == 3)
		{
			cout << "The order is: " << n << endl << endl;
			cubic_equation_roots(eq);
		}

		else if (n == 4)
		{
			cout << "The order is: " << n << endl << endl;
			fourth_degree_equation_roots(eq);
		}

		else if (n == 5)
		{
			cout << "The order is: " << n << endl << endl;
			fifth_degree_equation_roots(eq);
		}
		else
		{
			for (int i = 6; i <= 1000; i++)
			{
				if (n == i)
				{
					cout << "Error!!" << endl << "Make sure that power from 2 to 5" << endl;
					break;
				}
				else
				{

				}
			}
		}
	}
}


int main()

{

	// Take input from user and finding the order

	string eq;
	cout << "Enter the Equation: " << endl;
	getline(cin, eq);

	find_order(eq);

}