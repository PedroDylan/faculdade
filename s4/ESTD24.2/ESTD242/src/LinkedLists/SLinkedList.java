package LinkedLists;

public class SLinkedList {

	protected Node head;
	protected Node tail;
	protected long size;
	
	//construtor sem argumentos para criação de
	//lista vazia
	public SLinkedList() {
		this.head=null;
		this.size = 0;
	}
	
	//construtor que cria a lista definindo a head
	//como a entrada
	public SLinkedList(Node head) {
		this.head = head;
		this.head.setNext(null);
		this.size = 1; 
	}
	
	//Função responsável por adicionar um novo nó atrás
	//da head e redefinindo a head para ser o novo nó
	public void addFirst(Node node) {
		node.setNext(head);
		head = node;
		this.size++;
	}
	
	//Função responsável por adicionar um novo nó na frente
	//da tail e redefinindo a tail para ser o novo nó	
	public void addLast(Node node){
		node.setNext(null);
		tail.setNext(node);
		tail = node;
		this.size++;			
	}
	
	public void removeFirst() {
		if (head == null) {
			System.out.println("Lista vazia. Implementar esquema de exceção.");
		} else {
			Node removido = head;
			head = head.getNext();
			removido.setNext(null);
			this.size--;
		}
	}
	
	public void invert() {
		Node current = this.head;
		Node prev = null;
		
		
		while (current!=null) {
			Node next = current.getNext();
			current.setNext(prev);
			prev = current;
			current = next;
		}
		
		this.head = prev;
	}
	
	public String toString() {
		String s = "[";
		Node i = this.head;
		
		while(i!=null) {
			s += i.getElement();
			i=i.getNext();
			if(i!=null) {
				s+=".";
			}	
		}
		s+="]";
		return s;
	}
	
	
}
