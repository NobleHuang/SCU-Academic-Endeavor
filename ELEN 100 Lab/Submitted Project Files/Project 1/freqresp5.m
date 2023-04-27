%{
Name: Mulia Widjaja (Noble)
ELEN 100 Lab Project 1
%}

function F=freqresp5(QX, b, w, num)
for s=1:num
    % random variations of element values (within 20%)
    Q=variation(QX)
    
    % Resistors and Capacitors Matrices
    G=zeros(3,3); C=zeros(3,3);
    
    % Recomputation of Matrices G and C
    G(1,1)=1;
    G(2,1)=-1/Q(1);
    G(2,2)=1/Q(1)+1/Q(2);
    G(2,3)=-1/Q(2);
    G(3,2)=-1/Q(2);
    G(3,3)=1/Q(2);

    C(2,2)=Q(3);
    C(3,3)=Q(4);
    
    mag=zeros(3,1);
    
    for k=1:length(w)
	    omega=w(k);
	    
        % 
        A=G+i*omega*C;
        x=A\b;
        
        %
        %
        mag = [mag abs(x)];
    
    end
    
    V3=mag(3,2:length(w)+1);
    
    FX=20*log10(V3);
    F=[];
    F=[F;FX];

    freq = (w/(2*pi));

    semilogx(freq, F);
    hold on
	    
end
end

function Q=variation(R)
m=length(R);
g=ones(1,m)+0.5*rand(1,m);

Q=0.8*(R.*g);
end