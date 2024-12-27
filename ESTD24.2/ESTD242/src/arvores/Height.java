package arvores;

public class Height {
	//A altura de uma árvore é a altura de sua raiz
	//A altura é definida como 0 para um nó externo e
	//1 + altura máxima dos nós filhos no caso contrário
	public static<E> int height(Tree<E> tree) {
		int h = 0;
		
		try {
			//Iterando pelos nós da árvore e, caso o nó seja externo 
			//aumentamos o contador para o máximo entre ele mesmo e a 
			//profundidade do nó, dessa forma analisamos a distância 
			//máxima até a raiz
			for(Position<E> v : tree.positions()) {
				if(tree.isExternal(v)) {
					h = Math.max(h,Depth.depth(tree,v));
				}
			}
		} catch (InvalidPositionException exception) {
			System.out.println("Unexistent node");
			return -1;
		}
		
		return h;
	}
}
