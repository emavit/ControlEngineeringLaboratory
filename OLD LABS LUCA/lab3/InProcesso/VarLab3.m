M=0.455; %[kg] Cart mass
m=0.21; %[kg] Pendulum mass
l=0.305; %[m] Pendulum half-length 
I=1/3*m*l^2; %[kg*m^2]Pendulum moment of inertia 
b=1.0; %[N*s/m] Cart viscous friction coefficient
Ie=I+m*l^2;
g=9.81;
%initCond=[0 0 0 0 0];
%{
          theta
%}
function y=f(u1, u2)
    y = (m*l*cos(u1)*u2+m*g*l*sin(u1))/Ie;
end

%{
double function f(double u1, double u2)
{
    y = (m*l*cos(u1)*u2+m*g*l*sin(u1))/Ie;
    return y;
}
%}