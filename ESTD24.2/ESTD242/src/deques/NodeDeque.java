package deques;


public class NodeDeque<E> implements Deque<E> {

	protected DNode<E> header;
	protected DNode<E> trailer;
	protected int size;
	
	public NodeDeque() {
		this.header = new DNode<E>();
		this.trailer = new DNode<E>();
		this.header.setNext(trailer);
		this.trailer.setPrev(header);
		this.size=0;
	}
	
	public int size() {return this.size;}
	public boolean isEmpty() {return (this.size==0);}
	
	public E getFirst() throws EmptyDequeException{
		if(this.isEmpty()){throw new EmptyDequeException("Deque is empty");}
		return (E)this.header.getNext().getElement();
	}
	
	//Inserindo nó novo entre o header e o segundo
	public void addFirst(E object) {
		DNode<E> second = this.header.getNext();
		DNode<E> first = new DNode<E>(object,this.header,second);
		
		second.setPrev(first);
		header.setNext(first);
		size++;
	}
	
	public E removeFirst() throws EmptyDequeException{
		if(this.isEmpty()) {throw new EmptyDequeException("Deque is empty");}
		
		
		DNode<E> first = this.header.getNext();
		E firstElement = first.getElement();
		DNode<E> second = first.getNext();
		
		this.header.setNext(second);
		second.setPrev(this.header);
		this.size--;
		return firstElement;
	}
	
	
	public E getLast() throws EmptyDequeException{
		if(this.isEmpty()) {throw new EmptyDequeException("Deque is empty");}
		return (E)this.trailer.getPrev().getElement();
	}
	
	public E removeLast() throws EmptyDequeException{
		if(this.isEmpty()) {throw new EmptyDequeException("Deque is empty");}
	
		DNode<E> last = this.trailer.getPrev();
		E lastElement = last.getElement();
		DNode<E> secondToLast = last.getPrev();
		//Removendo o último do deque ao passar por cima 
		//dele com as outras referências
		this.trailer.setPrev(secondToLast);
		secondToLast.setNext(this.trailer);
		this.size--;
		return lastElement;
	
	}
	
	public void addLast(E element) {
		DNode prev = this.trailer.getPrev();
		DNode last = new DNode(element,prev,this.trailer);
		
		prev.setNext(last);
		this.trailer.setPrev(last);
		this.size++;
	}
	
	
	
	
}
