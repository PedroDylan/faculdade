package pilhas;

public class NodeStack<E> implements Stack<E> {
	
	protected GenericNode<E> top; 
	protected int size;
	
	public NodeStack() {
		this.top = null;
		this.size=0;
	}
	
	public int size() {return this.size;}
	
	public boolean isEmpty() {
		if(top==null) {return true;}
		else {return false;}
	}
	
	//Cria um novo nó acima do nó cabeça/topo e depois o define
	//como topo, substituindo o antigo topo
	public void push(E element) {
		GenericNode<E> v = new GenericNode<E>(element, this.top);
		this.top = v;
		size++;
	}
	
	//Retorna o elemento do nó topo e no caso de lista 
	//vazia lança exceção de pilha vazia
	public E top() throws EmptyStackException{
		if(this.isEmpty()) {
			throw new EmptyStackException("Stack is empty");
		} 
		return this.top.getElement();
	}
	
	//Armazena o topo em uma variável temporária e remove as
	//referências a ele na pilha para passar por cima dele
	public E pop() throws EmptyStackException{
		if(this.isEmpty()) {
			throw new EmptyStackException("Stack is empty");
		}
		E temp = this.top.getElement();
		this.top = this.top.getNext();
		size --;
		return temp;
	}
	
	
	//Método recursivo para remover todos os elementos da pilha
	public void recursiveRemoveAll() {
		if(this.isEmpty()) {
			return;
		}
		this.pop();
		recursiveRemoveAll();
	}
	
	public String toString() {
		String s = "[";
		GenericNode i = this.top;
		
		while(i!=null) {
			s += i.getElement().toString();
			i = i.getNext();
			if(i!=null) {
				s+=".";
			}
		}
		s+="]";
		return s;
	}
	


}


