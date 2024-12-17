from Linkedlist import LinkedList
from Node import Node

def inverteduplas(lista):
    current = lista.getHead()
    dummy = 0

    while(current.next != None):
        dummy = current.data
        current.data = current.next.data
        current.next.data = dummy

        current = current.next
        current = current.next

lista = LinkedList()
for i in range(7):
    lista.insertAtEnd(2*i)
lista.print()

inverteduplas(lista)
lista.print()