% Nick Rebhun 

% FACTS
husband(adam, eve).
husband(proton, electron).
husband(john, jane).

wife(eve, adam).
wife(electron, proton).
wife(jane, john).

male(adam).
male(proton).
male(john).
male(bob).

female(eve).
female(electron).
female(sue).
female(jane).

parent(adam, jane).
parent(eve, jane).
parent(proton, john).
parent(electron, john).
parent(jane, bob).
parent(jane, sue).
parent(john, bob).
parent(john, sue).

% ---------- RULES ----------
% Descendents
descendant(C,GP):-grandmother(GP,C);grandfather(GP,C).
son(S,P):-male(S),parent(P,S).
daughter(D,P):-female(D),parent(P,D).

% Siblings
sibling(A,B):-brother(A,B);sister(A,B).
brother(A,B):-male(A),parent(P,A),parent(P,B),A\=B.
sister(A,B):-female(A),parent(P,A),parent(P,B),A\=B.

% Parents
mother(M,C):-female(M),parent(M,C).
father(F,C):-male(F),parent(F,C).

grandmother(GM,C):-female(GM),parent(GM,P),parent(P,C).
grandfather(GF,C):-male(GF),parent(GF,P),parent(P,C).

greatgrandmother(GM,C):-female(GM),parent(GM,P),parent(P,C).
greatgrandfather(GF,C):-male(GF),parent(GF,P),parent(P,C).

% Ancestor
ancestor(A,C):-parent(A,C).
ancestor(A,C):-parent(P,C),ancestor(A,P).

% Boolean Versions
% Descendants
is_descendant(C):-descendant(C,_).
is_son(C):- -son(C,_).
is_daughter:-daughter(C,_).

% Siblings
is_sibling(C):-sibling(C,_).
is_brother(C):- -brother(C,_).
is_sister:-sister(C,_).

% Parents
is_father(F):-father(F,_).
is_mother(M):-mother(M,_).
is_parent(P):-is_father(P);is_mother(P).

is_grandmother(GM):-grandmother(GM,_).
is_grandfather(GF):-grandfather(GF,_).
is_grandparent(GP):-is_grandmother(GP);is_grandfather(GP).

% Marital status
married(H,W):-wife(W,H),husband(H,W).

% Removal Function
remove(Pattern,[Pattern|T],TD):- remove(Pattern,T,TD).
remove(Pattern,[H|T],[H|TD]):- remove(Pattern,T,TD).