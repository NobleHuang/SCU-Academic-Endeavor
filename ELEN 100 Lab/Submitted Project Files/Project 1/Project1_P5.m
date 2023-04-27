%{
Name: Mulia Widjaja (Noble), Dennis Cao
ELEN 100 Lab Project 1
%}

R1 = 125;
R2 = 400/3;
C1 = 1e-6;
C2 = 1e-6;


b = [1; 0; 0];

r = [1 2 3 4 5 6 7 8 9];

w = [r (10*r) (1e2*r) (1e3*r) (1e4*r) (1e5*r)];

QX = [R1 R2 C1 C2];
num = 20;
freqresp5(QX, b, w, num);

grid