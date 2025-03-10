from Linkedlist import LinkedList

def contaciclo(lista):
    fast = lista.getHead()
    slow = lista.getHead()
    counter = 0

    while(slow.next != None):
        slow = slow.next
        fast = fast.next.next

        if(slow == fast):
            slow = slow.next
            counter += 1
            while(slow!=fast):
                slow = slow.next
                counter += 1
            return counter

    
lista = LinkedList()



