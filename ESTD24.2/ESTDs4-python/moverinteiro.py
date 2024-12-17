from Linkedlist import LinkedList
from Node import Node

def moveinteiro(Lista,inteiro):
    prev = Lista.getHead()
    current = Lista.getHead()

    while(current!=None):
        if(current.data == inteiro):
            prev.setNext(current.getNext())
            current.setNext(Lista.head)
            Lista.head = current
            current = prev.getNext()
        else:
            prev = current
        current = current.next            

lista = LinkedList()
for i in range(6):
    lista.insertAtEnd(2*i)
lista.print()

moveinteiro(lista,8)
lista.print()