class Matrix:
    def __init__(self,list1,list2,list3) -> None:
        self.body = [list1,list2,list3]
        self.row_len = len(list1)
        self.c1 = [list1[0],list2[0],list3[0]]
        self.c2 = [list1[1],list2[1],list3[1]]
        self.c3 = [list1[2],list2[2],list3[2]]

    def __eq__(self,other) -> bool:
        if(isinstance(self,Matrix)) and (isinstance(other,Matrix)):
            if self.body[0] == other.body[0] and self.body[1] == other.body[1] and self.body[2] == other.body[2]:
                return True
            else:
                return False
        

    def _add(self,x,y):
        return x+y

    def _prod(self,x,y):
        return x*y

    def _add_list(self,l1,l2):
        return list(map(self._add,l1,l2))
    
    def _mult_list(self,l1,l2):
        return list(map(self._prod,l1,l2))

    def _weird_sum(self,l1,l2):
        return sum(self._mult_list(l1,l2))
    
    def add_mat(self,other):
        dummy_list = list(map(self._add_list,self.body,other.body))
        return Matrix(dummy_list[0],dummy_list[1],dummy_list[2])

    def mult_mat(self,other):
        dummy_list = [[],[],[]]

        for i in range(len(self.body)):
            for j in range(len(other.body)):
                dummy_list[i].append(self._weird_sum(self.body[i],other.body[j]))

        return Matrix(dummy_list[0],dummy_list[1],dummy_list[2])

    
    def represent(self):
        print(self.body)
    
        
l1 = [1,2,3]
l2 = [1,2,3]
l3 = [1,2,3]

l4 = [2,3,4]
l5 = [2,3,4]
l6 = [2,3,4]

mt1 = Matrix(l1,l2,l3)
mt2 = Matrix(l4,l5,l6)

mt3 = mt1.mult_mat(mt2)
mt3.represent()
