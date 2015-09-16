#!/bin/sh

# Runs prob1 program to generate data
./prob1

# Plots results on log-log plots

## Plot data for forward difference algorithm
gnuplot << EOF
set terminal x11 persist
set title 'Relative Error {/Symbol e}_r vs. Step h for Forward Difference Algorithm' 
set xlabel 'h'
set ylabel '{/Symbol e}'
set logscale xy
set format xy '1e%T'
set grid
plot 'cos0d1_forward_diff.txt' using 1:3 with lines title 'Cos(0.1)',\
	 'cos10_forward_diff.txt' using 1:3 with lines title 'Cos(10)', \
	 'exp0d1_forward_diff.txt' using 1:3 with lines title 'Exp(0.1)', \
	 'exp10_forward_diff.txt' using 1:3 with lines title 'Exp(10)'
EOF

## Plot data for central difference algorithm
gnuplot << EOF
set terminal x11 persist
set title 'Relative Error {/Symbol e}_r vs. Step h for Central Difference Algorithm' 
set xlabel 'h'
set ylabel '{/Symbol e}'
set logscale xy
set format xy '1e%T'
set grid
plot 'cos0d1_central_diff.txt' using 1:3 with lines title 'Cos(0.1)', \
	 'cos10_central_diff.txt' using 1:3 with lines title 'Cos(10)', \
	 'exp0d1_central_diff.txt' using 1:3 with lines title 'Exp(0.1)', \
	 'exp10_central_diff.txt' using 1:3 with lines title 'Exp(10)'
EOF

## Plot data for extrapolated difference algorithm
gnuplot << EOF
set terminal x11 persist
set title 'Relative Error {/Symbol e}_r vs. Step h for Extrapolated Difference Algorithm' 
set xlabel 'h'
set ylabel '{/Symbol e}'
set logscale xy
set format xy '1e%T'
set grid
plot 'cos0d1_extrap_diff.txt' using 1:3 with lines title 'Cos(0.1)', \
	 'cos10_extrap_diff.txt' using 1:3 with lines title 'Cos(10)', \
	 'exp0d1_extrap_diff.txt' using 1:3 with lines title 'Exp(0.1)', \
	 'exp10_extrap_diff.txt' using 1:3 with lines title 'Exp(10)'
EOF
