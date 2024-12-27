package arvores;

import java.util.Iterator;

public interface Tree<E> {
	public int size();
	public boolean isEmpty();
	//Retorna um iterador sobre os elementos armazenados
	public Iterator<E> iterator();
	//Retorna uma coleção iterável dos nodos
	public Iterable<Position<E>> positions();
	//Substitui o elemento em um dado nó
	public E replace(Position<E> node, E element) throws InvalidPositionException;
	//Retorna a raiz da árvore
	public Position<E> root() throws EmptyTreeException;
	//Retorna o pai de um dado nó
	public Position<E> parent(Position<E> node) throws InvalidPositionException, BoundaryViolationException;
	//Retorna um iterável com os filhos do dado nó
	public Iterable<Position<E>> children(Position<E> node) throws InvalidPositionException;
	//retorna se um dado nó é interno
	public boolean isInternal(Position<E> node) throws InvalidPositionException;
	//retorna se um dado nó é externo
	public boolean isExternal(Position<E> node) throws InvalidPositionException;
	//Retorna se o dado nó é a raiz
	public boolean isRoot(Position<E> node) throws InvalidPositionException;
	
	
	
	
	
	
}
