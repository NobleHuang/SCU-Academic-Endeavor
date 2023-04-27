%{
Name: Mulia Widjaja (Noble)
ELEN 100 Lab Project 1
%}

function Q=variation(R)
m=length(R);
g=ones(1,m)+0.5*rand(1,m);

Q=0.8*(R.*g);