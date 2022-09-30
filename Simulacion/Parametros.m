clear
s = tf('s')
xa = 39.5/1000; % [m]
vo = 0.1; % [m/s]  50%*0.0624*0.0303
Km =  2;
p1 = 1.2;
Pw = -Km/(1+s/p1)*exp(-0.06*s);
P1 = Pw*1/s;

Kp= -2.36;
Td = 0.4;
N = 2.2;
G =P1*Kp*(1+Td*s/(1+Td*s/N));
G =pade(P1,1)*Kp*(1+Td*s/(1+Td*s/N));
Fry = G/(G*(0.1*s+1)+1);
Fry = minreal(Fry)
% ltiview(Fry)
P2 = vo*(1+xa/vo*s)/s;

Ptotal = Fry*P2;
Ptotal = minreal(Ptotal)
clf
nichols(Ptotal)
hold on
K = 35
nichols(Ptotal*K)

Ptotal = pade(Ptotal,1)
ltiview(zpk(minreal(Ptotal)*K/(1+minreal(Ptotal)*K)))
Dist = zpk(xa/(1+minreal(Ptotal)*K))
ltiview(Dist)
