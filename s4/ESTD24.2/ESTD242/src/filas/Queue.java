package filas;

public interface Queue<E> {
	
	public int size();
	public boolean isEmpty();
	
	//Retorna o elemento na frente da fila sem remove-lo 
	public E front() throws EmptyQueueException;
	
	//insere elemento no fim da fila
	public void enqueue(E element);
	
	//Remove o elemento na frente da fila e o retorna
	public E dequeue() throws EmptyQueueException;
	
	
}
