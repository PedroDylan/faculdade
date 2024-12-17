package pilhas;

public interface Stack<E> {
	
	public int size(); 
	public boolean isEmpty();
	
	//retornar o elemento no topo da pilha sem remove-lo
	public E top() throws EmptyStackException; 
	
	//Inserir um elemento no topo da pilha
	public void push(E element);
	
	//Remove o elemento no topo da pilha e o retorn
	public E pop();
	
}
