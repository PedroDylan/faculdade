from Node import Node
from linkedlist import LinkedList

def insereOrd(Head, inteiro):
    newNode = Node(inteiro)
    current = Head #Nó Atual
    prev = Head
    while(current != None and current.data<inteiro):
        prev = current
        current = current.next
    prev.next = newNode
    newNode.next = current

lista = LinkedList()
for i in range(10):
    lista.insertAtEnd(2*i)
lista.print()

insereOrd(lista.getHead(),7)
lista.print()
