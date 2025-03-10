from Linkedlist import LinkedList


def invertelista(lista):
    current = lista.getHead()
    prev = None

    while(current != None):
        next = current.next
        current.next = prev
        prev = current
        current = next
    
    lista.setHead(prev)

lista = LinkedList()
for i in range(6):
    lista.insertAtEnd(2*i)
lista.print()

invertelista(lista)
lista.print()
        