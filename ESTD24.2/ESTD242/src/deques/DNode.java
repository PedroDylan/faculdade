package deques;

public class DNode<E> {
	
	protected E element;
	protected DNode<E> next;
	protected DNode<E> prev;
	
	public DNode(E e, DNode<E> prev, DNode<E> next) {
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
	
	public DNode<E> getPrev() {return this.prev;}
	public void setPrev(DNode<E> newPrev) {
		this.prev = newPrev;
	}
	
	public DNode<E> getNext() {return this.next;}
	public void setNext(DNode<E> newNext) {
		this.next = newNext;
	}
	
	public void setElement(E newElement) {
		this.element = newElement;
	}
	
	public String toString() {
		return ("[" + this.getElement().toString() + "]");
	}
	
}
