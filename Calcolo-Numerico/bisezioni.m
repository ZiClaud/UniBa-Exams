function alpha=bisezioni(f, a, b, tol)  % bisezioni -> Nome funzione
% Metodo delle successive bisezioni
%
% Parametri di input:
% f: funzione di cui ricercare uno zero
% [a,b]: intervallo di lavoro
% tol: Precisione richiesta/Tolleranza
%
% Parametri di output:
% alpha: zero di f
%
% Help bisezioni -> dice roba
fa=f(a);
fb=f(b);
if fa*fb>0      % si poteva scrivere anche f(a)*f(b)>0, però se le riuso devo ricalcolarle quindi non conviene
    error('La funzione non cambia segno agli estremi dell''intervallo')
end

while b-a>tol
    c=(a+b)/2; % Se metto il ';' non mi printa il risultato dell'assegnazione
    fc=f(c);
    if fc==0
        alpha=c;
        return
    elseif fa*fc<0
        b = c;
        fb=fc;
    else    %elseif fb*fc<0
        a=c;
        fa=fc;
    end
end
alpha = c