%{
Name: Mulia Widjaja (Noble), Dennis Cao
ELEN 100 Lab Project 2
Winter 2023
%}

R1 = 5000;
R2 = 5000;
R3 = 400;

C1 = 0.1e-6;
C2 = 0.1e-6;

A = [1, 0, 0, 0, 0;
    -1/R1, (1/R1 + 1/R2 + j*w*C1 + 1/R3), -1/R3, -j*w*C1, 0;
    0, (1/R2 - 1/R3), 1/R3, 0, 0;
    0, 0, 1, 0, -1;
    0, 0, 0, -1/R4, (1/R4 + 1/R5)];

B = [Vg, 0, 0, 0, 0];

fprintf('%s', A\B);