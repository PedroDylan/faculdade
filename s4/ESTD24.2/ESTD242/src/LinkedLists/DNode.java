package LinkedLists;

public class DNode {
	
	protected String element;
	protected DNode next;
	protected DNode prev;
	
	public DNode(String e, DNode prev, DNode next) {
		this.element = e;
		this.prev = prev;
		this.next = next;
	}
	
	public String getElement() {return this.element;}
	
	public DNode getPrev() {return this.prev;}
	public void setPrev(DNode newPrev) {
		this.prev = newPrev;
	}
	
	public DNode getNext() {return this.next;}
	public void setNext(DNode newNext) {
		this.next = newNext;
	}
	
	public void setElement(String newElement) {
		this.element = newElement;
	}
	
	public String toString() {
		return ("[" + this.getElement() + "]");
	}
	
}
