from Atom import Atom
from Implies import Implies
from Not import Not
from And import And
from Functions import *

a = Atom("a")
c = Atom("c")
aIc = Implies(a,c)
na = Not(a)
nc = Not(c)
ainc = Implies(a,nc)
naanc = And(na,nc)
fg = Implies (ainc,naanc)

print(a)
print(na)
print(aIc)
print(ainc)
print(naanc)
print(fg)

print(isNNF(fg))
print(isNNF(naanc))
print(isNNF(na))