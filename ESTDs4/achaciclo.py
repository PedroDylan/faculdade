from Linkedlist import LinkedList
from Node import Node

def achaciclo(Lista):
    fast = Lista.getHead()
    slow = Lista.getHead()

    while(slow.next != None):
        slow = slow.next
        fast = fast.next.next
        if (slow == fast):
            return True
        return False