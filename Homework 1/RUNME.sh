#!/bin/sh

### Marco Muzio - Homework 1 Script

# Compile *.cpp files

g++ prob1.cpp -o prob1
g++ prob2.cpp -o prob2
g++ prob3.cpp -o prob3

# Makes sure scripts are executable

chmod +x prob1.sh
chmod +x prob2.sh
chmod +x prob2.sh

# Runs scripts for each problem

./prob1.sh
./prob2.sh
./prob3.sh

# Opens plots

echo "Do you wish to open all plots?"
select yn in "Yes" "No"; do
    case $yn in
	        Yes ) open *.png; break;;
			No ) exit;;
	esac
done
