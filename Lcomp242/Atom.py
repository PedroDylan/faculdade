from Formula import Formula

class Atom(Formula):
    def __init__(self, name:str):
        super().__init__()
        self.name = name

    def __str__(self):
        return str(self.name)
    
    def __eq__(self, other):
        return isinstance(other,Atom) and other.name == self.name
    
    def __hash__(self):
        return hash((self.name,'atom'))
    
    