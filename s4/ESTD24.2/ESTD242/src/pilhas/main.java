package pilhas;

public class main {
	public static void main(String[] args) {
		
		NodeStack pilha = new NodeStack();
		
		pilha.push(1);
		pilha.push(2);
		pilha.push(3);
		pilha.push(4);
		pilha.push(5);
		
		System.out.println(pilha.toString());
		pilha.recursiveRemoveAll();
		System.out.println(pilha.toString());
		
		
		
	}
}
