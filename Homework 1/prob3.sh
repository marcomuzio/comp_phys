#!/bin/sh

### Marco Muzio - Homework 1 Problem 3 Script

# Generate data from random walks
./prob3

## Plot data

# Plot sigma^2
gnuplot << EOF
set terminal pngcairo enhanced
set encoding utf8
set output 'sigma2.png'
set xlabel 'n'
set ylabel '{/Symbol s}^2_n'
set autoscale
set nokey
set grid
plot 'prob3_sigma.txt' with lines
EOF

# Plot s_3
gnuplot << EOF
set terminal pngcairo enhanced
set encoding utf8
set output 's_3.png'
set xlabel 'n'
set ylabel 's_3'
set autoscale
set nokey
set grid
plot 'prob3_s3.txt' with lines
EOF

# Plot s_4
gnuplot << EOF
set terminal pngcairo enhanced
set encoding utf8
set output 's_4.png'
set xlabel 'n'
set ylabel 's_4'
set autoscale
set nokey
set grid
plot 'prob3_s4.txt' with lines
EOF

