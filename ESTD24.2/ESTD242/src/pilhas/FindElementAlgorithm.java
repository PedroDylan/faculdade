package pilhas;
import filas.NodeQueue;

public class FindElementAlgorithm {
	public static void main(String[] args) {
		
		NodeStack<Integer> stack = new NodeStack<Integer>();
		NodeQueue<Integer> queue = new NodeQueue<Integer>();
		int busca = 8;
		boolean found = false;
		
		for(int i = 0; i<10 ;i++) {
			stack.push(i);
		}
		System.out.println(stack.toString());
		
		
		for(int i = 0;i<10;i++) {
			int temp = stack.pop();
			if(temp == busca) {
				found = true;
			}
			queue.enqueue(temp);
			stack.push(queue.dequeue());
			queue.enqueue(stack.pop());
			stack.push(queue.dequeue());
		}
		
		System.out.println(stack.toString());
		//problema : só retorna verdadeiro
		//caso a busca seja igual ao último elemento
		System.out.println(found);
		
		
	}
}
