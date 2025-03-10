package pilhas;

public class GenericNode<E> {
	
	private E element;
	private GenericNode<E> next;
	
	public GenericNode(E element, GenericNode<E> next){
		this.element = element;
		this.next = next;
	}
	
	public GenericNode() {
		this(null,null);
	}
	
	public E getElement() {
		return this.element;
	}
	
	public void setElement(E newElement) {
		this.element = newElement;
	}
	
	public GenericNode<E> getNext(){
		return this.next;
	}
	
	public void setNext(GenericNode<E> newNext) {
		this.next = newNext;
	}
	
	
	
}
