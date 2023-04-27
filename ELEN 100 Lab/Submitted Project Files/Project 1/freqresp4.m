%{
Name: Mulia Widjaja (Noble)
ELEN 100 Lab Project 1
%}

function F=freqresp4(G,C,b,w) 
mag=zeros(3,1); 
% We need to initialize vector mag, in order not 
% to confuse Matlab. 

for k=1:length(w)
	omega=w(k);
	% Omega is the next frequency in vector w. 
	
	A=G+i*omega*C;
	x=A\b;
	% Vector x contains the solution of the node voltage 
	% equations in complex form.
	
	mag=[mag abs(x)]; 
	% The function abs(x) computes the magnitudes of all voltages.
	% These magnitudes are stored as a new column in matrix mag.
end

% Each column of matrix mag now contains voltage magnitudes computed 
% at a particular frequency. Note, however, that the first column of 
% this matrix is essentially redundant. It is a vector of zeros that 
% serves only as a place holder.

V3=mag(3,2:length(w)+1);
% Since we are interested only in V3, we will extract row 3 of matrix 
% mag (and ignore the first column).
F=20*log10(V3);

