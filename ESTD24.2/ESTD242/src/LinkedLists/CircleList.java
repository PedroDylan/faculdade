package LinkedLists;

public class CircleList {
	
	//Nó de marcação importante para a existñcia de coesão 
	//na lista circular
	protected Node cursor; 
	protected int size;
	
	public CircleList() {
		this.cursor = null;
		this.size=0;
	}
	
	public int size() {return this.size;}
	
	public Node getCursor() {return this.cursor;}
	
	// avançar na contagem da lista
	public void advance() { 
		this.cursor = this.cursor.getNext();
	}
	
	
	//Adiciona nó após o cursor
	public void add(Node newNode) {
		//No caso do cursor nulo o nó adicionado
		//se torna o cursor e é marcado como o 
		//próprio cursor
		if(this.cursor==null) { 
			newNode.setNext(newNode);
			this.cursor = newNode; 
		} 
		else  
		//Método de inserção similar ao usado na lista
		//duplamente encadeada no qual o next do cursor se 
		//torna o inserido e o next do inserido se torna o 
		//que era o next do cursor
		{	
			newNode.setNext(cursor.getNext());
			this.cursor.setNext(newNode);
		}
		this.size++;
	}
	
	//Remove o nó após o cursor
	public Node remove() {
		Node oldNode = cursor.getNext();
		if(oldNode == cursor) {
			cursor = null;
		} else {
			//Definimos o next do cursor como o next 
			//de oldnode, com isso pulando por cima dele 
			//na lista e tiramos o next de old node para
			//extirpa-lo completamente.
			cursor.setNext(oldNode.getNext());
			oldNode.setNext(null);
		}
		this.size--;
		return oldNode;
	}
	
	//retorna uma representação em String da lista 
	//começando pelo cursor
	public String toString() {
		if(cursor ==null) {
			return "[ ]";
		} else {
			String s = "[..."+cursor.getElement();
			Node oldCursor = cursor; //marcação do ponto inicial da contagem
			
			//for loop baseado na função advance que vai ciclar
			//pela lista enquanto o cursor não voltar ao ponto
			//incial e vai adicionar o elemento dos nós à string
			for(advance();oldCursor!=cursor;advance()) {
				s+=", "+cursor.getElement();
			}
			
			return s+"...]";
			
			
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
