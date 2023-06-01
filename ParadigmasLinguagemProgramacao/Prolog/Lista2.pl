%% To run main, run the Repl and type 'main.' into the prompt
%% main :- write('Hello, world!').

%% 1
onde(_,[],-1).
onde(N,[N],1).
onde(N,[N|_],1).
onde(N,[_|X],R):- onde(N,X,R1), R is R1+1.

%% 2
ateh(_,[],[]).
ateh(N,[N|_],[N]).
ateh(N,[A|X],[A|R]):- ateh(N,X,R).

%% 3
apos(_,[],[]).
apos(N,[N|X],[N|X]).
apos(N,[_|X],R):- apos(N,X,R).

%% 4
npri(0,[]).
npri(N,R):- N1 is N-1, npri(N1,R1), append(R1,[N],R).

%% 5
gera_m_mult(A,A,[A]).
gera_m_mult(A,B,[]):- A>B.
gera_m_mult(A,B,[A|R1]):- A<B, A1 is A+A, gera_m_mult(A,A1,B,R1).
gera_m_mult(_,A1,B,[]):- A1>B.
gera_m_mult(A,A1,B,[A1|R1]):- A1=<B, A2 is A1+A, gera_m_mult(A,A2,B,R1).

%% 6
tam([],0).
tam([_|X], R) :- tam(X,R1), R is R1+1.

split([],[]).
split(L,[R1,R2]):- tam(L,T), N is T/2, aux1(N,L,R1), aux2(N,L,R2).

aux1(N,_,[]):- N=<0.
aux1(N,[A|X],[A|R]):- N1 is N-1, aux1(N1,X,R).

aux2(N,L,L):- N=<0.
aux2(N,[_|X],R):- N1 is N-1, aux2(N1,X,R).

%% 7
mtam([],[]).
mtam([_|X],[_|Y]):- mtam(X,Y).

%% 8
tri([],[]).
tri([A|X],R):- tri(X,R1), append([A,A,A],R1,R).

%% 9
subs(_,_,[],[]).
subs(A,B,[A|X],[B|R]):- subs(A,B,X,R).
subs(A,B,[C|X],[C|R]):- subs(A,B,X,R).

%% 10
mackenzie(N,A,B,R):- A<B,A<N,B<N, npri(N,Seq), ateh(A,Seq,R1), apos(B,Seq,R2), 
                     append(R1,["M","A","C","K","E","N","Z","I","E"],R3), 
                     append(R3,R2,R).



