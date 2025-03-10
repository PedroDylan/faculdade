from Formula import Formula

class Implies(Formula):
    def __init__(self,left,right):
        super().__init__()
        self.left = left
        self.right = right

    def __str__(self):
        return "(" + self.left.__str__()+ " " + u"\u2192" + " " + self.right.__str__()+")" 

    def __eq__(self, other):
        return isinstance(other,Implies) and other.left == self.left and other.right == self.right     
    