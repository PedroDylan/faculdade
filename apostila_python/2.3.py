class Matrix:
    def __init__(self,list1,list2,list3) -> None:
        self.body = [list1,list2,list3]
        self.row_len = len(list1)
        self.c1 = [list1[0],list2[0],list3[0]]
        self.c2 = [list1[1],list2[1],list3[1]]
        self.c3 = [list1[2],list2[2],list3[2]]

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
        
    def _transpose(self):
        c0 = [self.body[0][0],self.body[0][1],self.body[0][2]]
        c1 = [self.body[1][0],self.body[1][1],self.body[1][2]]
        c2 = [self.body[2][0],self.body[2][1],self.body[2][2]]
        
        return Matrix(c0,c1,c2)
    
    def add_mat(self,other):
        dummy_list = list(map(self._add_list,self.body,other.body))
        return Matrix(dummy_list[0],dummy_list[1],dummy_list[2])

    def mult_mat(self,other):
        dummy_list = [[],[],[]]
        other_t = other._transpose()

        for i in range(len(self.body)):
            for j in range(len(other.body)):
                dummy_list[i].append(self._weird_sum(self.body[i],other.body[j]))




        return Matrix(dummy_list[0],dummy_list[1],dummy_list[2])

    
    def represent(self):
        print(self.body)
    
        
l1 = [1,1,1]
l2 = [1,1,1]
l3 = [1,1,1]

mt1 = Matrix(l1,l2,l3)
mt2 = Matrix(l1,l2,l3)

mt3 = mt1.mult_mat(mt2)
mt3.represent()
