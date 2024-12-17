package filas;
import pilhas.GenericNode;

public class NodeQueue<E> implements Queue<E> {
	
	protected GenericNode<E> head;
	protected GenericNode<E> tail;
	protected int size;

	public int size() {return this.size;}
	public boolean isEmpty() {
		return (this.size==0);
	}
	
	public E front() throws EmptyQueueException{
		if(this.size==0) {throw new EmptyQueueException("Queue is empty");}
		return this.head.getElement();
	}
	
	public void enqueue(E element) {
		GenericNode<E> node = new GenericNode<E>();
		node.setElement(element);
		//O novo nó inserido será o último da fila
		node.setNext(null); 
		
		if(this.size == 0) {
			this.head = node;
		} else {
			//definindo o novo nó após o atual fim da fila
			this.tail.setNext(node);
		}
		//definindo novo nó como nova cauda 
		this.tail = node;
		size++;
	}
	
	public E dequeue() throws EmptyQueueException{
		if(this.size==0) {throw new EmptyQueueException("Queue is empty");}
		E temp = this.head.getElement();
		//Passando por cima do cabeça definindo ele
		//como seu getNext();
		this.head = this.head.getNext();
		this.size--;
		//Caso da fila vazia remove-se a referência da cauda 
		if(this.size==0) {
			this.tail = null;
		}
		return temp;
	}
	
	
	
}
