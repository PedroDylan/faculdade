package LinkedLists;

public class main {

	public static void main(String[] args) {
		Node no1 = new Node("1");
		Node no2 = new Node("2");
		Node no3 = new Node("3");
		SLinkedList lista = new SLinkedList();
		lista.addFirst(no1);
		lista.addFirst(no2);
		lista.addFirst(no3);
		System.out.println(lista.toString());
		lista.invert();
		System.out.println(lista.toString());
		
		
	}
	
}
