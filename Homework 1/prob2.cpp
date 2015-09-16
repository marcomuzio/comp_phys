// Marco Muzio - Homework 1 Problem 2 Source Code

#include<iostream>
#include<cmath>
#include<fstream>

#define pi 3.14159265

using namespace std;

float trap_rule(float lower, float upper, int N_points);
float simps_rule(float lower, float upper, int N_points);
float GL_quad(float lower, float upper, int N_points);
float Laguerre(int n, float x);
float Lag_roots(int n, int root);
int factorial(int n);
int binomial(int n, int k);
float rel_error(float integral);

int main()
{
	float integral;
	
	ofstream trap, simps, GL;

	trap.open("trapezoid_rule.txt");
	simps.open("simpsons_rule.txt");
	GL.open("GL_quadrature.txt");

	// Trapezoid rule calculations
	for(int i=2; i<=1024; i *= 2)
	{
		integral = trap_rule(0.0, 1.0, i);

		trap << i << "\t" << integral << "\t" << rel_error(integral) << endl;
	}
	
	trap.close();

	// Simpson's rule calculations
	for(int i=2; i<=1024; i *= 2)
	{
		integral = simps_rule(0.0, 1.0, i);

		simps << i << "\t" << integral << "\t" << rel_error(integral) << endl;
	}

	simps.close();

	// GL quadrature calculations
	for(int i=2; i<6; i++)
	{
		integral = GL_quad(0.0, 1.0, i);

		GL << i << "\t" << integral << "\t" << rel_error(integral) << endl;
	}

	GL.close();

	return 0;
}

// Trapezoid rule algorithm to calculate integral of exp(-t)
float trap_rule(float lower, float upper, int N_points)
{
	float h, integral, x; 
	
	h = (upper - lower)/(N_points - 1.0);
	
	integral = 0.5*exp(-lower) + 0.5*exp(-upper);

	for(int i=2; i<N_points-1; i++)
	{
		x = lower + (i-1)*h;
		integral += exp(-x);
	}

	integral *= h;

	return integral;
}

// Simpson's rule algorithm to calculate integral of exp(-t)
float simps_rule(float lower, float upper, int N_points)
{
	float h, integral, x_even, x_odd;

	h = (upper - lower)/(N_points - 1.0);

	integral = exp(-lower)/3.0 + exp(-upper)/3.0;

	for(int i=2; i<N_points-1; i += 2)
	{
		x_even = lower + (i-1)*h;
		x_odd = lower + i*h;
		
		integral += 4.0*exp(-x_even)/3.0 + 2.0*exp(-x_odd)/3.0;
	}

	integral *= h;

	return integral;
}

// Gauss-Legendre quadrature algorithm to calculate integral of exp(-t) -- only valid for N_points<6
float GL_quad(float lower, float upper, int N_points)
{
	float integral, x, laguerre, weight, transformation_factor;

	integral = 0.0;

	for(int i=1; i<=N_points; i++)
	{
		laguerre = Laguerre(N_points+1, Lag_roots(N_points, i));
		weight = Lag_roots(N_points, i)/pow(N_points+1, 2)/pow(laguerre, 2);
		transformation_factor = 2.0/pi/(pow(Lag_roots(N_points, i), 2) + 1.0);

		integral += exp(-2.0/pi*atan(Lag_roots(N_points, i)))*weight*transformation_factor;
	}

	return integral;
}

// nth Laguerre polynomial at x
float Laguerre(int n, float x)
{
	float value = 0.0;

	for(int i=0; i<=n; i++)
	{
		value += binomial(n, i)*pow(-1.0, i)*pow(x, i)/factorial(i);
	}

	return value;
}

// Look-up table of Laguerre polynomial roots
float Lag_roots(int n, int root)
{
	switch(n)
	{
		case 2:

			switch(root)
			{
				case 1: return 0.585786;
				case 2: return 3.41421;
			}

		case 3:

			switch(root)
			{
				case 1: return 0.415775;
				case 2: return 2.29428;
				case 3: return 6.28995;
			}

		case 4:

			switch(root)
			{
				case 1: return 0.322548;
				case 2: return 1.74576;
				case 3: return 4.53662;
				case 4: return 9.39507;
			}

		case 5:
			
			switch(root)
			{	
				case 1: return 0.26356;
				case 2: return 1.4134;
				case 3: return 3.59643;
				case 4: return 7.08581;
				case 5: return 12.6408;
			}
	}

	return 0;
}

// Factorial function for definition of Laguerre polynomials
int factorial(int n)
{
	  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

// Binomial coefficients function for definition of Laguerre polynomials
int binomial(int n, int k)
{
	return factorial(n)/factorial(k)/factorial(n-k);
}

// Relative error in calculated integral
float rel_error(float integral)
{
	float error;

	error = integral - (1.0-exp(-1.0));
	error /= 1.0-exp(-1.0);
	error = abs(error);

	return error;
}
