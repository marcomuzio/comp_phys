#!/bin/sh

### Marco Muzio - Homework 1 Problem 2 Script

# Runs prob2 program to generate data
./prob2

# Plots results on log-log plots

## Plot data for trapezoid rule
gnuplot << EOF
set terminal pngcairo enhanced
set encoding utf8
set output 'trapezoid_rule.png'
set title 'Relative Error {/Symbol e}_r vs. N Abscissas for Trapezoid Rule Algorithm'
set xlabel 'N'
set ylabel '{/Symbol e}_r'
set logscale xy
set format xy '1e%T'
set grid
set nokey
plot 'trapezoid_rule.txt' using 1:3 with lines
EOF

## Plot data for Simpson's rule
gnuplot << EOF
set terminal pngcairo enhanced
set encoding utf8
set output 'simpsons_rule.png'
set title "Relative Error {/Symbol e}_r vs. N Abscissas for Simpson's Rule Algorithm"
set xlabel 'N'
set ylabel '{/Symbol e}_r'
set logscale xy
set format xy '1e%T'
set grid
set nokey
plot 'simpsons_rule.txt' using 1:3 with lines
EOF

## Plot data for Gauss-Legendre quadrature
gnuplot << EOF
set terminal pngcairo enhanced
set encoding utf8
set output 'GL_quad.png'
set title 'Relative Error {/Symbol e}_r vs. N Abscissas for Gauss-Legendre Quadrature Algorithm'
set xlabel 'N'
set ylabel '{/Symbol e}_r'
set logscale xy
set format xy '1e%T'
set grid
set nokey
plot 'GL_quadrature.txt' using 1:3 with lines
EOF
