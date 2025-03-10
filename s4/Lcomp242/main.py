from Atom import Atom
from Implies import Implies
from Not import Not
from And import And
from Functions import *
from array import *

p = Atom("p")
np = Not(p)
q = Atom("q")
nq = Not(q)
r = Atom("r")
nr = Not(r) 

interpretation = {'p':True, 'q':False}

print(And(q,r))
print(partial_truth_value(And(q,r),interpretation))

print(Or(q,r))
print(partial_truth_value(Or(q,r),interpretation))

print(Implies(q,r))
print(partial_truth_value(Implies(q,r),interpretation))