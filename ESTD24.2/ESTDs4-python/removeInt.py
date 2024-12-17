from Linkedlist import LinkedList
from Node import Node

def removeInt(Lista, inteiro):
    prev = Lista.getHead()
    current = Lista.getHead()

    while(current != None):
        if(current.data == inteiro):
            prev.setNext(current.next)
        else:
            prev = current
        current = current.next
   

lista = LinkedList()
for i in range(10):
    lista.insertAtEnd(2*i)
lista.print()

removeInt(lista, 10)
lista.print()