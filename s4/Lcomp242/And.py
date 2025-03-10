from Formula import Formula

class And(Formula):
    def __init__(self,left,right):
        super().__init__()
        self.left = left
        self.right = right

    def __str__(self):
        return "(" + self.left.__str__() +  " " + u"\u2227" + " " + self.right.__str__() + ")"
    
    def __eq__(self, other):
        return isinstance(other,And) and other.left == self.left and other.right == self.right