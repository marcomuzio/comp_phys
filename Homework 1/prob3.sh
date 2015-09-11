#!/bin/sh

# Generate data from random walks
./prob3

# Plot data

# Plot sigma^2
gnuplot << EOF
set terminal x11 persist
set title 'sigma^2_n'
set xlabel 'n'
set ylabel 'sigma^2_n'
set autoscale
plot 'prob3_sigma.txt' with lines
EOF

# Plot s_3
gnuplot << EOF
set terminal x11 persist
set title 's_3'
set xlabel 'n'
set ylabel 's_3'
set autoscale
plot 'prob3_s3.txt' with lines
EOF

# Plot s_4
gnuplot << EOF
set terminal x11 persist
set title 's_4'
set xlabel 'n'
set ylabel 's_4'
set autoscale
plot 'prob3_s4.txt' with lines
EOF

