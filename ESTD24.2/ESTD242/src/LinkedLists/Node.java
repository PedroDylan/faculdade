package LinkedLists;

public class Node {
	
	private String element;
	private Node next;
	
	public Node(String element, Node next) {
		this.element = element;
		this.next = next;
	}
	
	public Node(String element) {
		this.element=element;
		this.next=null;
	}
	
	public String getElement() {
		return this.element;
	}
	
	public void setElement(String newElement) {
		this.element = newElement;
	}
	
	public Node getNext() {
		return this.next;
	}
	
	public void setNext(Node newNext) {
		this.next = newNext;
	}
	
	public void recursiveInsertAtEnd(String newValue) {
		if(this.next==null) {
			this.next = new Node(newValue);
		} else {
			this.next.recursiveInsertAtEnd(newValue);
		}
	}
	
	
}
