from Formula import Formula

class Not(Formula):
    def __init__(self,inner):
        super().__init__()
        self.inner = inner

    def __str__(self):
        return "(" + u"\u00ac" +str(self.inner) + ")"
    
    def __eq__(self, other):
        return isinstance(other,Not) and other.inner == self.inner
    
