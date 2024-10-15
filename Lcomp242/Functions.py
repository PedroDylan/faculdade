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

def substitution(formula,exe,ins):
    if(isinstance(formula,Atom) and formula != exe):
        return formula
    elif (formula == exe):
        return ins
    elif(isinstance(formula,Not)):
        sub = substitution(formula.inner,exe,ins)
        return Not(sub)
    elif(isinstance(formula,And)):
        sub_l = substitution(formula.left,exe,ins)
        sub_r = substitution(formula.right,exe,ins)
        return And(sub_l,sub_r)
    elif(isinstance(formula,Or)):
        sub_l = substitution(formula.left,exe,ins)
        sub_r = substitution(formula.right,exe,ins)
        return Or(sub_l,sub_r)
    elif(isinstance(formula,Implies)):
        sub_l = substitution(formula.left,exe,ins)
        sub_r = substitution(formula.right,exe,ins)
        return Implies(sub_l,sub_r)
    
def numberOfAtoms(formula):
        if (isinstance(formula,Atom)):
            return 1 
        elif(isinstance(formula,Not)):
            return numberOfAtoms(formula.inner)
        elif(isinstance(formula,And) or isinstance(formula,Or) or isinstance(formula,Implies)):
            return numberOfAtoms(formula.left) + numberOfAtoms(formula.right)

def isLiteral(formula):
    if isinstance(formula,Atom):
        return True
    elif isinstance(formula,Not):
        return isinstance(formula.inner,Atom)
    elif isinstance(formula,And) or isinstance(formula,Or) or isinstance(formula,Implies):
        return False

def isClause(formula):
    #if isinstance(formula,Atom):
    #    return True
    #elif isinstance(formula,Not):
    #    return isinstance(formula.inner,Atom)
    if (isinstance(formula,Atom) or isinstance(formula,Not)):
        return isLiteral(formula)    
    elif(isinstance(formula,And) or isinstance(formula,Implies)):
        return False
    elif isinstance(formula,Or):
        return (isClause(formula.left) or isLiteral(formula.left)) and (isClause(formula.right) or isLiteral(formula.right))
    
def isCNF(formula):
    if isinstance(formula,Atom):
        return True
    elif isinstance(formula,Not):
        return isClause(formula.inner)
    elif isinstance(formula,Or) or isinstance(formula,Implies):
        return False
    elif isinstance(formula,And):
        return (isCNF(formula.left) or isClause(formula.left)) and (isCNF(formula.right) or isClause(formula.right)) 