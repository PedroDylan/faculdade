package deques;

public class DNode<E> {
	
	protected E element;
	protected DNode next;
	protected DNode prev;
	
	public DNode(E e, DNode prev, DNode next) {
		this.element = e;
		this.prev = prev;
		this.next = next;
	}
	
	public DNode() {
		this.element = null;
		this.prev = null;
		this.next = null;
	}
	
	public E getElement() {return this.element;}
	
	public DNode getPrev() {return this.prev;}
	public void setPrev(DNode newPrev) {
		this.prev = newPrev;
	}
	
	public DNode getNext() {return this.next;}
	public void setNext(DNode newNext) {
		this.next = newNext;
	}
	
	public void setElement(E newElement) {
		this.element = newElement;
	}
	
	public String toString() {
		return ("[" + this.getElement().toString() + "]");
	}
	
}
