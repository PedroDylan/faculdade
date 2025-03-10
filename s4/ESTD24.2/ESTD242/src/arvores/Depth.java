package arvores;

public class Depth {
	//Retorna a quantidade de ancestrais
	public static<E> int depth(Tree<E> tree, Position<E> node) {
		try {
			//Chamada recursiva do método 
			if(tree.isRoot(node)) {
				return 0;
			} else {
				return (1 + depth(tree,tree.parent(node))); 
			} 
		} catch (InvalidPositionException exception) {
			System.out.println("Unexistent node");
			return -1;
		} catch (BoundaryViolationException exception) {
			System.out.println("Root node inserted");
			return -1;
		}
	}
}