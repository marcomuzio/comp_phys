// Marco Muzio - Homework 1 Problem 1 Source Code

#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float forward_diff(float x, float h, float (*f)(float));
float central_diff(float x, float h, float (*f)(float));
float extrap_diff(float x, float h, float (*f)(float));
float rel_error(float x, float derivative, float (*df)(float));
float neg_sin(float x);

int main()
{
	const float e_m = 1.0e-7; // Approximate machine precision for SP
	float derivative, x;

	ofstream cos0d1, cos10, exp0d1, exp10;

	// Forward difference calculations

	cos0d1.open("cos0d1_forward_diff.txt");
	cos10.open("cos10_forward_diff.txt");
	exp0d1.open("exp0d1_forward_diff.txt");
	exp10.open("exp10_forward_diff.txt");

	for(float h=1.0; h>=e_m/10.0; h /= 10.0)
	{
		x = 0.1;
		derivative = forward_diff(x, h, cos);
		cos0d1 << h << "\t" << derivative << "\t" << rel_error(x, derivative, neg_sin) << endl;
		
		derivative = forward_diff(x, h , exp);
		exp0d1 << h << "\t" << derivative << "\t" << rel_error(x, derivative, exp)<< endl;

		x = 10.0;
		derivative = forward_diff(x, h, cos);
		cos10 << h << "\t" << derivative << "\t" << rel_error(x, derivative, neg_sin) << endl;

		derivative = forward_diff(x, h, exp);
		exp10 << h << "\t" << derivative << "\t" << rel_error(x, derivative, exp) << endl;
	}

	cos0d1.close();
	cos10.close();
	exp0d1.close();
	exp10.close();

	// Central difference calculations

	cos0d1.open("cos0d1_central_diff.txt");
	cos10.open("cos10_central_diff.txt");
	exp0d1.open("exp0d1_central_diff.txt");
	exp10.open("exp10_central_diff.txt");

	for(float h=1.0; h>=e_m/10.0; h /= 10.0)
	{
		x = 0.1;
		derivative = central_diff(x, h, cos);
		cos0d1 << h << "\t" << derivative << "\t" << rel_error(x, derivative, neg_sin) << endl;
		
		derivative = central_diff(x, h , exp);
		exp0d1 << h << "\t" << derivative << "\t" << rel_error(x, derivative, exp)<< endl;

		x = 10.0;
		derivative = central_diff(x, h, cos);
		cos10 << h << "\t" << derivative << "\t" << rel_error(x, derivative, neg_sin) << endl;

		derivative = central_diff(x, h, exp);
		exp10 << h << "\t" << derivative << "\t" << rel_error(x, derivative, exp) << endl;
	}

	cos0d1.close();
	cos10.close();
	exp0d1.close();
	exp10.close();
	
	// Extrapolated difference calculations

	cos0d1.open("cos0d1_extrap_diff.txt");
	cos10.open("cos10_extrap_diff.txt");
	exp0d1.open("exp0d1_extrap_diff.txt");
	exp10.open("exp10_extrap_diff.txt");

	for(float h=10.0; h>=e_m/10.0; h /= 10.0)
	{
		x = 0.1;
		derivative = extrap_diff(x, h, cos);
		cos0d1 << h << "\t" << derivative << "\t" << rel_error(x, derivative, neg_sin) << endl;
		
		derivative = extrap_diff(x, h , exp);
		exp0d1 << h << "\t" << derivative << "\t" << rel_error(x, derivative, exp)<< endl;

		x = 10.0;
		derivative = extrap_diff(x, h, cos);
		cos10 << h << "\t" << derivative << "\t" << rel_error(x, derivative, neg_sin) << endl;

		derivative = extrap_diff(x, h, exp);
		exp10 << h << "\t" << derivative << "\t" << rel_error(x, derivative, exp) << endl;
	}

	cos0d1.close();
	cos10.close();
	exp0d1.close();
	exp10.close();

	return 0;
}

// Forward difference algorithm for calculating f'
float forward_diff(float x, float h, float (*f)(float))
{
	float derivative;

	derivative = (*f)(x+h) - (*f)(x);
	derivative /= h;

	return derivative;
}

// Central difference algorithm for calculating f'
float central_diff(float x, float h, float (*f)(float))
{
	float derivative;

	derivative = (*f)(x+h) - (*f)(x-h);
	derivative /= 2.0*h;

	return derivative;
}

// Extrapolated difference algorithm for calculating f'
float extrap_diff(float x, float h, float (*f)(float))
{
	float derivative;

	derivative = 4.0*central_diff(x, h/4.0, (*f)) - central_diff(x, h/2.0, (*f));
	derivative /= 3.0;

	return derivative;
}

// Relative error
float rel_error(float x, float derivative, float (*df)(float))
{
	float error;

	error = derivative - (*df)(x);
	error /= (*df)(x);
	error = abs(error);

	return error;
}

// Negative of sin(x) so that the derivative of cos(x) can be passed to the above functions
float neg_sin(float x)
{
	return -1.0*sin(x);

}
