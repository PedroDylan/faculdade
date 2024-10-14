from Atom import Atom
from Implies import Implies
from Not import Not
from And import And
from Or import Or

def size(formula):
    if isinstance(formula,Atom):
        return 1
    elif(isinstance(formula,Not)):
        return 1 + size(formula.inner)
    elif(isinstance(formula,And) or isinstance(formula,Or) or isinstance(formula,Implies)):
        return 1 + size(formula.left) + size(formula.right)
  
def subformulas(formula):
    if isinstance(formula, Atom):
        return {formula}
    if isinstance(formula, Not):
        return {formula}.union(subformulas(formula.inner))
    if isinstance(formula, Implies) or isinstance(formula, And) or isinstance(formula, Or):
        sub1 = subformulas(formula.left)
        sub2 = subformulas(formula.right)
        return {formula}.union(sub1).union(sub2)


def numberOfConectives(formula):
    if isinstance(formula,Atom):
        return 0
    elif isinstance(formula,Not):
        return 1 + numberOfConectives(formula.inner)
    elif (isinstance(formula,And) or isinstance(formula,Or) or isinstance(formula,Implies)):
        return 1 + numberOfConectives(formula.left) + numberOfConectives(formula.right)
    
def conjuntoAtomicas(formula):
    if isinstance(formula,Atom):
        return {formula}
    elif isinstance(formula,Not):
        return conjuntoAtomicas(formula.inner)
    elif (isinstance(formula,And) or isinstance(formula,Or) or isinstance(formula,Implies)):
        return conjuntoAtomicas(formula.left).union(conjuntoAtomicas(formula.right))  
     
def isNNF(formula):
    if(isinstance(formula,Atom)):
        return True
    elif(isinstance(formula,Implies)):
        return False
    elif(isinstance(formula,Not)):
        return isinstance(formula.inner,Atom)
    elif(isinstance(formula,And) or isinstance(formula,Or)):
        return isNNF(formula.left) and isNNF(formula.right)
    






