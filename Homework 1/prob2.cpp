// Marco Muzio - Homework 1 Problem 2 Source Code

#include<iostream>
#include<cmath>
#include<fstream>

#define pi 3.14159265

using namespace std;

float trap_rule(float lower, float upper, int N_points);
float simps_rule(float lower, float upper, int N_points);
float GL_quad(float lower, float upper, int N_points);
float Leg_roots(int n, int root);
float Leg_weights(int n, int root);
float rel_error(float integral);

int main()
{
	float integral;
	
	ofstream trap, simps, GL;

	trap.open("trapezoid_rule.txt");
	simps.open("simpsons_rule.txt");
	GL.open("GL_quadrature.txt");

	// Trapezoid rule calculations
	for(int i=2; i<=pow(2, 25); i *= 2)
	{
		integral = trap_rule(0.0, 1.0, i);

		trap << i << "\t" << integral << "\t" << rel_error(integral) << endl;
	}
	
	trap.close();

	// Simpson's rule calculations
	for(int i=2; i<=pow(2, 20); i *= 2)
	{
		integral = simps_rule(0.0, 1.0, i+1);

		simps << i << "\t" << integral << "\t" << rel_error(integral) << endl;
	}

	simps.close();

	// GL quadrature calculations
	for(int i=2; i<9; i++)
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

	for(int i=2; i<N_points; i++)
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
		x_odd = x_even + h;
		
		integral += 4.0*exp(-x_even)/3.0 + 2.0*exp(-x_odd)/3.0;
	}

	x_even = lower + (N_points-2.0)*h;

	integral += 4.0*exp(-x_even)/3.0;

	integral *= h;

	return integral;
}

// Gauss-Legendre quadrature algorithm to calculate integral of exp(-t) -- only valid for N_points<9
float GL_quad(float lower, float upper, int N_points)
{
	float integral, weight, transformation_factor, f;
	float x;

	integral = 0.0;

	for(int i=1; i<=N_points; i++)
	{
		x = Leg_roots(N_points, i);
		weight = Leg_weights(N_points, i);
		transformation_factor = (upper - lower)/2.0;
		f = exp(-((upper - lower)/2.0*x + (upper + lower)/2.0));

		integral += f*weight*transformation_factor;
	}

	return integral;
}

// Look-up table of 2nd-7th Legendre polynomial roots
float Leg_roots(int n, int root)
{
	switch(n)
	{
		case 2:

			switch(root)
			{
				case 1: return -0.577350269189626;
				case 2: return 0.577350269189626;
			}

		case 3:

			switch(root)
			{
				case 1: return -0.774596669241483;
				case 2: return 0.0;
				case 3: return 0.774596669241483;
			}

		case 4:

			switch(root)
			{
				case 1: return -0.86113631159405;
				case 2: return -0.339981043584856;
				case 3: return 0.339981043584856;
				case 4: return 0.86113631159405;
			}

		case 5:
			
			switch(root)
			{	
				case 1: return -0.906179845938664;
				case 2: return -0.538469310105683;
				case 3: return 0.0;
				case 4: return 0.538469310105683;
				case 5: return 0.906179845938664;
			}

		case 6:

			switch(root)
			{
				case 1: return -0.932469514203152;
				case 2: return -0.661209386466265;
				case 3: return -0.238619186083197;
				case 4: return 0.238619186083197;
				case 5: return 0.661209386466265;
				case 6: return 0.932469514203152;
			}

		case 7:

			switch(root)
			{
				case 1: return -0.949107912342759;
				case 2: return -0.741531185599394;
				case 3: return -0.405845151377397; 
				case 4: return 0.000000000000000;
				case 5: return 0.405845151377397;
				case 6: return 0.741531185599394;
				case 7: return 0.949107912342759;
			}

		case 8:

			switch(root)
			{
				case 1: return -0.960289856497536;
				case 2: return -0.796666477413627;
				case 3: return -0.525532409916329;
				case 4: return -0.183434642495650;
				case 5: return 0.183434642495650;
				case 6: return 0.525532409916329;
				case 7: return 0.796666477413627;
				case 8: return 0.960289856497536;
			}
	}

	return 0;
}

// Look-up table for weights corresponding to roots of 2nd-7th Legendre polynomial
float Leg_weights(int n, int root)
{
	switch(n)
	{
		case(2):

			switch(root)
			{
				case 1: return 1.000000000000000;
				case 2: return 1.000000000000000;
			}

		case(3):

			switch(root)
			{
				case 1: return 0.555555555555556;
				case 2: return 0.888888888888889;
				case 3: return 0.555555555555556;
			}

		case(4):

			switch(root)
			{
				case 1: return 0.347854845137454;
				case 2: return 0.652145154862546;
				case 3: return 0.652145154862546;
				case 4: return 0.347854845137454;
			}

		case(5):

			switch(root)
			{
				case 1: return 0.236926885056189;
				case 2: return 0.478628670499366;
				case 3: return 0.568888888888889;
				case 4: return 0.478628670499366;
				case 5: return 0.236926885056189;
			}

		case(6):

			switch(root)
			{
				case 1: return 0.171324492379170;
				case 2: return 0.360761573048139;
				case 3: return 0.467913934572691;
				case 4: return 0.467913934572691;
				case 5: return 0.360761573048139;
				case 6: return 0.171324492379170;
			}

		case(7):

			switch(root)
			{
				case 1: return 0.129484966168870;
				case 2: return 0.279705391489277;
				case 3: return 0.381830050505119;
				case 4: return 0.417959183673469;
				case 5: return 0.381830050505119;
				case 6: return 0.279705391489277;
				case 7: return 0.129484966168870;
			}

		case(8):

			switch(root)
			{
				case 1: return 0.101228536290376;
				case 2: return 0.222381034453374;
				case 3: return 0.313706645877887;
				case 4: return 0.362683783378362;
				case 5: return 0.362683783378362;
				case 6: return 0.313706645877887;
				case 7: return 0.222381034453374;
				case 8: return 0.101228536290376;
			}
	}

	return 0;
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
