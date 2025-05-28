V=0.2;% скорость распространени€ точек волны
E=0.5;% радиус
W=10;% частота распространени€ волны
a=1;% скорость волны
dy=0.1;% шаг по оси ”
dx=0.1;% шаг по оси ’
n=15/dx;
RV=[];
for t=0:0.05:10;% начало цикла по времени
    RV=[V.*t 0];
    for i=1:n+1;
        for j=1:n+1;
            x=-5+dx.*(i-1);
            y=-5+dx.*(j-1);
            rv=[x y];
            r=norm(rv);
            if r<E;  
                r=E; U(j,i)=sin(W.*(t-r/a))/r;
            else 
                %Votnv=(a.*(rv-RV)/r)-[V 0];
                %Votn=norm(Votnv);
                if r>a.*t;
                    U(j,i)=0;
                else U(j,i)=sin(W.*(t-r/a))/r; 
                end;
            end;
        end;
    end;
    [X,Y]=meshgrid(-5:dx:10);
    mesh(X,Y,U);
    axis([-5 10 -5 10 -2 2]);
    pause(0); 
end;