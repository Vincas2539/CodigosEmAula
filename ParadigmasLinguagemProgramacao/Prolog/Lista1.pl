%% To run main, run the Repl and type 'main.' into the prompt

%% tam([a,b,c,d,e],R).

tam([],0).
tam([_|X], R) :- tam(X,R1), R is R1+1.

sum([],0).
sum([A|X], R) :- sum(X,R1), R is R1+A.

media(L,R):- tam(L,S1), sum(L,S2), R is S2/S1.




%% 1
membro(A,[A|_]).
membro(A,[_|X]):- membro(A,X).

%% 2
rev([],[]).
rev([A],R):- R is [A].
rev([A|X],R):- rev(X,R1), append(R1, [A], R).

%% 3
ult([],[]).
ult([A],A).
ult([_|X],R):- ult(X,R1), R is R1.

%% 4
soma2l([],[],[]).
soma2l([],L,L).
soma2l(L,[],L).
soma2l([A|L1],[B|L2],R):- soma2l(L1,L2,R1), T is A+B, append([T], R1, R).

%% 5
del_dup([],[]).
del_dup([A],[A]).
del_dup([A,B|X],R):- A == B, del_dup([B|X],R).
del_dup([A,B|X],[A|R]):- A \= B, del_dup([B|X],R).


%% 6
del_rep([],[]).
del_rep([A],[A]).
del_rep([A|X],R):-  membro(A,X), del_rep(X,R).
del_rep([A|X],[A|R]):- \+ membro(A,X), del_rep(X,R).

%% 7
inter([],[],[]).
inter(_,[],[]).
inter([],_,[]).
inter([A|L1],L2,[A|Z]):- membro(A,L2), inter(L1,L2,Z).
inter([_|L1],L2,Z):- inter(L1,L2,Z).

%% 8
delpri(_,[],[]).
delpri(N,[A|X],X):- N==A.
delpri(N,[A|X],[A|R]):- delpri(N,X,R).

%% 9
delall(_,[],[]).
delall(N,[A|X],R):- N==A, delall(N,X,R).
delall(N,[A|X],[A|R]):- delall(N,X,R).

%% 10
agrup(_,[],[]).
agrup(N,L,[R1|R2]):- aux(N,L,R1,X), agrup(N,X,R2).
aux(_,[],[],[]).
aux(0,L,[],L).
aux(Naux,[A|X],[A|S],Y):- N1 is Naux-1, aux(N1,X,S,Y).



