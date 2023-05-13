%% Create the matrix M & C & g & Fv1

%create the M matrix
M11=2*wheel.Iyy+2*(gbox.N^2)*mot.rot.Iyy+(body.m+2*wheel.m+2*mot.rot.m)*(wheel.r^2);
M12=2*gbox.N*(1-gbox.N)*mot.rot.Iyy+(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r;

M22=body.Iyy+2*((1-gbox.N)^(2))*mot.rot.Iyy+body.m*(body.zb^2)+2*mot.rot.m*(mot.rot.zb)^2;
M21=M12;

%create C matrix
C11=0;
C21=C11;
C22=C21;
C22=(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*wheel.r;
% Create vector g
g1=0;
g2=-(body.m*body.zb+2*mot.rot.m*mot.rot.zb)*g;



% Create Fv1
Fv1_11=2*(mot.B+wheel.B);
Fv1_12=-2*mot.B;
Fv1_21=Fv1_12;
Fv1_22=2*mot.B;
Fv1=[Fv1_11,Fv1_12;Fv1_21,Fv1_22];

ua2tau=2*gbox.N*mot.R*[1;-1];