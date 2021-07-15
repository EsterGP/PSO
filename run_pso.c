#include <stdio.h>

void ofun(float x[]) {
    of=10*(x[1]-1)^2+20*(x[2]-2)^2+30*(x[3]-3)^2;

    return of;
}

void main() {
    LB=[0 0 0]; //limite inferior
    UB=[10 10 10]; //limite superior

    m=3;
    n=100; //tamanho da população
    wmax=0.9; //coeficiente de inércia
    wmin=0.4; //coeficiente de inércia
    c1=2; //constantes positivas
    c2=2; //constantes positivas
    
    maxite=1000; //número máximo de iterações
    maxrun=1;
    for run=1:maxrun
    run
    for i=1:n
        for j=1:m
        x0[i,j]=round(LB[j]+rand()*(UB[j]-LB[j]));
        end
    end
    
    x=x0; 
    v=0.1*x0;
    
    for i=1:n
        f0(i,1)=ofun(x0(i,:));
    end
    
    [fmin0,index0]=min(f0);
    pbest=x0;
    gbest=x0(index0,:);

    ite=1; //iteração
    tolerance=1;
    while ite<=maxite && tolerance>10^-12
        
        w=wmax-(wmax-wmin)*ite/maxite; //coeficiente de inércia

        //atualizando a velocidade
        for i=1:n
        for j=1:m
            v(i,j)=w*v(i,j)+c1*rand()*(pbest(i,j)-x(i,j))+c2*rand()*(gbest(1,j)-x(i,j));
        end
        end

        //atualizando as posições das partículas
        for i=1:n
        for j=1:m
            x(i,j)=x(i,j)+v(i,j);
        end
        end

        //verificando os limites
        for i=1:n
        for j=1:m
            if x(i,j)<LB(j)
            x(i,j)=LB(j);
            elseif x(i,j)>UB(j)
            x(i,j)=UB(j);
            end
        end
        end

        //calculando a aptidão
        for i=1:n
        f(i,1)=ofun(x(i,:));
        end

        //atualizando pbest
        for i=1:n
        if f(i,1)<f0(i,1)
            pbest(i,:) = x(i,:);
            f0(i,1)=f(i,1);
        end
        end

        [fmin,index]=min(f0); 
        ffmin(ite,run)=fmin;
        ffite(run)=ite;

        //atualizando gbest
        if fmin<fmin0
        gbest=pbest(index,:);
        fmin0=fmin;
        end

        if ite>100;
        tolerance=abs(ffmin(ite-100,run)-fmin0);
        end

        //mostrando resultados
        if ite==1
        disp(sprintf('Iteration Best particle Objective fun'));
        end
        disp(sprintf('%8g %8g %8.4f',ite,index,fmin0));
        ite=ite+1;
    end
    
    gbest;
    fvalue=10*(gbest(1)-1)^2+20*(gbest(2)-2)^2+30*(gbest(3)-3)^2;
    fff(run)=fvalue;
    rgbest(run,:)=gbest;
    disp(sprintf('--------------------------------------'));
    end

    disp(sprintf('\n'));
    disp(sprintf('*********************************************************'));
    disp(sprintf('Final Results-----------------------------'));
    [bestfun,bestrun]=min(fff)
    best_variables=rgbest(bestrun,:)
    disp(sprintf('*********************************************************'));
    toc

    plot(ffmin(1:ffite(bestrun),bestrun),'-k');
    xlabel('Iteration');
    ylabel('Fitness function value');
    title('PSO convergence characteristic')

}
