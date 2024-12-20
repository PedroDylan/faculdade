package LinkedLists;

public class DList {

	protected int size;
	protected DNode header;//nó responsável por ser o "início" da lista 
	protected DNode trailer;//nó responsável por ser o "fim" da lista
	
	public DList() {
		this.size = 0;
		this.header = new DNode(null,null,null);
		this.trailer = new DNode (null,header,null);
		this.header.setNext(trailer);
	}
	
	public int size() {return this.size;}
	public boolean isEmpty() {return (this.size == 0);}
	
	//Função responsável por retornar o primeiro nó da lista
	public DNode getFirst() throws IllegalStateException{
		if(this.isEmpty()) {
			throw new IllegalStateException("List is empty");
		} else {
			//o primeiro elemento é o definido após o header
			return this.header.getNext();
		}
	}
	
	//Função responsável por retornar o último nó da lista
	public DNode getLast() throws IllegalStateException{
		if(this.isEmpty()) {
			throw new IllegalStateException("List is empty");
		} else {
			//o último nó antes do trailer
			return this.trailer.getPrev();
		}
	}
	
	//Função responsável por retornar o nó anterior ao recebido
	public DNode getPrev(DNode node) throws IllegalArgumentException{
		if(node ==this.header) {
			throw new IllegalArgumentException("Cannot move back past the header of the list");
		} else {
			return node.getPrev();
		}
	}
	
	//Função responsável por retornar o nó posterior ao recebido
	public DNode getNext(DNode node) throws IllegalArgumentException{
		if(node ==this.trailer) {
			throw new IllegalArgumentException("Cannot move forward past the trailer of the list");
		} else {
			return node.getNext();
		}
	}
	
	//Função responsável por adicionar um nó anterior ao nó recebido
	public void addBefore(DNode v, DNode insert) throws IllegalArgumentException {
		
		//referenciando o nó anterior ao recebido
		DNode previo = getPrev(v); 
		
		//Processo de inserção do nó definindo o seu anterior como o anterior
		//ao recebido v e next como o recebido v
		insert.setPrev(previo);     
		insert.setNext(v);
		
		//processo de inserção baseado em redefinir os previos e nexts 
		v.setPrev(insert);
		previo.setNext(insert);
		this.size++;
	}
	
	public void addAfter(DNode v, DNode insert) throws IllegalArgumentException {
		DNode next= getNext(v);
		//definindo insert entre o recebido v e o seu next
		//via definições internas
		insert.setPrev(v);
		insert.setNext(next);	
		//definindo insert entre o recebido v e seu next 
		//via definições externas
		next.setPrev(insert);
		v.setNext(insert);
		this.size++;
	}
	
	//as próximas duas funções são responsáveis por 
	//retornar os elementos antes e depois do header e trailer para
	//analisarmos o início e o fim da fila
	public void addFirst(DNode node) {
		addAfter(this.header,node);
	}
	
	public void addLast(DNode v) {
		addBefore(this.trailer,v);
	}
	
	//Função responsável por remover o nó recebido 
	public void remove(DNode v) throws IllegalArgumentException{
		DNode prev = getPrev(v);
		DNode next = getNext(v);
		
		//Removendo o nó recebido v pulando-o 
		//com as referências externas de seu next e prev
		next.setPrev(prev);
		prev.setNext(next);
		
		v.setPrev(null);
		v.setNext(null);
		
		this.size--;
	}
	
	//Checagens booleanas se o recebido é diferente do nó de marcação para
	//identificar se estamos ou não em uma extremidade da lista
	public boolean hasPrev(DNode v) {return (v!=this.header);}
	public boolean hasNext(DNode v) {return (v!=this.trailer);}
	
	
	public String toString() {
		String s = "[";
		DNode v = header.getNext();
		while ( v != trailer) {
			s+= v.getElement();
			v= v.getNext();
			if(v!=trailer) {
				s+=".";
			}
		}
		s+="]";
		return s;
	}
	
	//método responsável por encontrar o elemento do meio
	//fast é o marcador que andará dois nós a cada iteração e 
	//slo andará um nó a cada iteração, dessa forma quando fast 
	//chegar ao fim da lista slow estará no meio
	public DNode encontraMeio() {
		DNode fast = this.header;
		DNode slow = this.header;
		
		while(fast!=null) {
			fast = fast.getNext();
			if(fast==null) {
				return slow;
			}
			fast = fast.getNext();
			slow = slow.getNext();
			
		
		}
		
		
		return slow;
	}
	
	
	
	
	
	
	
	
	
	
}
