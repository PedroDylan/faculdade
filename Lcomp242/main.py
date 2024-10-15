from Atom import Atom
from Implies import Implies
from Not import Not
from And import And
from Functions import *

p = Atom("p")
np = Not(p)
q = Atom("q")
nq = Not(q)
r = Atom("r")
nr = Not(r) 

f1 = Or(Or(np,q),r)
print(f1)

f2 = Or(Or(np,nq),p)
print(f2)

f3 = And(f1,f2)
f4 = And(p,f3)

print (f4)
print(isCNF(f4))

e1 = Or(nq,And(np,r))
e2 = And(p,e1)
print(e2)
print(isCNF(e2))