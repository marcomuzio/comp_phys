// Marco Muzio - Homework 1 Problem 3 Source Code

#include<cmath>
#include<iostream>
#include<fstream>

using namespace std;

int random_number(int x_in);
int step_sign(int num);

int main()
{

	int iseed, sign, n_max=500, N_R=1000;
	double x_0=0.0;
	double x[N_R], sigma[n_max], s3[n_max], s4[n_max];

	// Initialization of arrays to zero
	for(int i=0; i<n_max; i++)
	{
		sigma[i]=0.0; s3[i]=0.0; s4[i]=0.0;
	}

	for(int j=0; j<N_R; j++)
	{
		x[j]=0.0;
	}

	// Steps Loop
	for(int n_steps=1; n_steps<=n_max; n_steps++)
	{
		// Realizations Loop
		for(int realization=0; realization<N_R; realization++)
		{
			iseed=realization+1;

			// First step
			iseed=random_number(iseed);
			sign=step_sign(iseed);
			x[realization]=x_0+pow(-1.0,sign);

			// Remaining Walk Loop
			for(int step=1; step<n_steps; step++)
			{
				iseed=random_number(iseed);
				sign=step_sign(iseed);
				x[realization]+=pow(-1.0,sign);
			}
		}

		// Calculation of data for n=n_step
		for(int realization=0; realization<N_R; realization++)
		{
			sigma[n_steps-1] += pow(x[realization],2);
			s3[n_steps-1] += pow(x[realization],3); 
			s4[n_steps-1] += pow(x[realization],4);
		}
		
		sigma[n_steps-1] /= N_R;
		s3[n_steps-1] /= N_R;
		s4[n_steps-1] /= N_R;
	
		s3[n_steps-1] /= pow(sigma[n_steps-1], 3.0/2.0);
		s4[n_steps-1] /= pow(sigma[n_steps-1], 2);

		s4[n_steps-1] -= 3.0;
	}

	// Writes results to output files
	ofstream sigma_data, s3_data, s4_data;
	sigma_data.open("prob3_sigma.txt");
	s3_data.open("prob3_s3.txt");
	s4_data.open("prob3_s4.txt");

	for(int n_steps=1; n_steps<=n_max; n_steps++)
	{
		sigma_data << n_steps << "\t" << sigma[n_steps-1] << endl;
		s3_data << n_steps << "\t" << s3[n_steps-1] << endl;
		s4_data << n_steps << "\t" << s4[n_steps-1] << endl;
	}

	sigma_data.close(); s3_data.close(); s4_data.close();

	return 0;
}

// Random number generator
int random_number(int x_in)
{
	int x_out, a=9301, c=49297, m=233280;

	x_out= a*x_in + c;
	x_out = x_out % m;
	
	return x_out;
}

// Gives sign (direction) of step
int step_sign(int num)
{
	double q, m=233280;

	q = abs(((double)num)/m);
	if(q<0.5) return 0;
	else return 1;
}
