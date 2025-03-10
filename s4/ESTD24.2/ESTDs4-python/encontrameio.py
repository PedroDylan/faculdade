from Node import Node
from Linkedlist import LinkedList

def encontrameio(lista):
    fast = lista.getHead()
    slow = lista.getHead()
    

    while(fast != None):
        fast = fast.next
        if(fast == None):
            return slow

        
        fast = fast.next
        slow = slow.next
        


    return slow



lista = LinkedList()
for i in range(7):
    lista.insertAtEnd(2*i)
lista.print()

meio = encontrameio(lista)
print(meio.data)
        




