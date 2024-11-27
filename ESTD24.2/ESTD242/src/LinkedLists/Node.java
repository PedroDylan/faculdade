package LinkedLists;

public class Node {
	
	private String element;
	private Node next;
	
	public Node(String element, Node next) {
		this.element = element;
		this.next = next;
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
	
	
}
