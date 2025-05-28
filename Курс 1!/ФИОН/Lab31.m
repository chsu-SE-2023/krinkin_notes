L=1;
Vvoln=1;
Vist=1;
N=1000;
dx=L/N;

for k=1:(N+1);
    x(k)=dx.*(k-1);
    u(k)=0;
    v(k) = 0.01-(L/2-x(k)).^2;
    a(k)=0;
end; 
dt=0.001; 
T=1;

for t=dt:dt:T; 
    for k=2:1:N; 
        if abs(L/2-x(k))<0.1;
            f(k)=0.01-(L/2-x(k)).^2;
        else f(k)=0; end; 

        a(k)=Vvoln.^2.*(u(k+1)-2.*u(k)+u(k-1))./dx.^2+f(k);
    end; 
    v=v+a.*dt;
    u=u+v.*dt;
    
    u(1)=u(2);
    u(N+1)=u(N);
    plot(x,u)
    axis([0 1 -0.1 0.01]); 
    pause(0);
end;