%{
Name: Mulia Widjaja (Noble)
ELEN 100 Lab Project 1
%}

R1 = 10000;
R2 = 5/3;
C1 = 1e-6;
C2 = 1e-6;

G = [1, 0, 0;
	-1/R1, 1/R1+1/R2, -1/R2;
	0, -1/R2, 1/R2];

C = [0, 0, 0;
	0, C1, 0;
	0, 0, C2];
    
b = [1; 0; 0];

r = [1 2 3 4 5 6 7 8 9];

w = [r (10*r) (1e2*r) (1e3*r) (1e4*r) (1e5*r)];

freq = (w/(2*pi));

freqresp4(G,C,b,w);

semilogx(freq, freqresp4(G,C,b,w))
grid