package Logicomp;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public abstract class Formula {

	private String name;
	
	public Formula() {}
	
	public Formula(String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}
	
	public Formula[] Atoms(){
		Formula[] subformulas = this.Subformulas();
		List<Formula> listatoms = new ArrayList<Formula>();
		
		for(int i=0; i< subformulas.length; i++) {
			if((subformulas[i] instanceof Atom) && (!listatoms.contains(subformulas[i]))) {
				listatoms.add(subformulas[i]);
			}
		}
		
		Formula[] resultfinal = new Formula[listatoms.size()]; 
		resultfinal = listatoms.toArray(resultfinal);
		return resultfinal;
	}
	
	public int NumberOfAtoms() {
		return this.Atoms().length;
	}
		
	public Boolean IsNegationNormalForm() {
		Boolean result = true;
		List<Formula> listanots = new ArrayList<Formula>();
		
		for(int i = 0; i<this.Subformulas().length; i++) {
			
			if(this.Subformulas()[i] instanceof Implies) {
				result = false;
				break;
			}
			
			
			if(this.Subformulas()[i] instanceof Not) {
				listanots.add(this.Subformulas()[i]);
			}
		}
		
		for(Formula f : listanots) {
			Not notf = (Not) f;
			if (!(notf.inner instanceof Atom)) {
				result = false;
			}
		}
		
		return result;
	}
	
	public int NumberOfBinaryConectives() {
		int contador = 0;
		
		for(int i = 0; i<this.Subformulas().length; i++) {
			if (this.Subformulas()[i] instanceof And ||
				this.Subformulas()[i] instanceof Or  ||
				this.Subformulas()[i] instanceof Implies) {
				contador++;
			}
		}
		return contador;
		
	}
	
	public Boolean IsLiteral() {
		if(this instanceof Not) {
			Not nthis = (Not) this;
			return nthis.inner instanceof Atom;
		} else {
			return this instanceof Atom;
		}
		
		
	}

	public Boolean IsClausule() {
		Boolean result = true;
		
		for (int i = 0; i<this.Subformulas().length; i++) {
			if (!(this.Subformulas()[i] instanceof Or || this.Subformulas()[i].IsLiteral())){
				result = false;
			}
		}
		
		return result;
	}
	
	public Boolean isCNF() {
		Boolean result = true;
		
		for (int i = 0; i<this.Subformulas().length; i++) {
			if (!(this.Subformulas()[i] instanceof Or || this.Subformulas()[i].IsClausule())){
				result = false;
			}
		}
		
		return result;
	}
	
	public Boolean IsTermo() {
		Boolean result = true;
		
		for (int i = 0; i<this.Subformulas().length; i++) {
			if (!(this.Subformulas()[i] instanceof And || this.Subformulas()[i].IsLiteral())){
				result = false;
			}
		}
		
		return result;
	}
	
	public Boolean IsDNF() {
		Boolean result = true;
		
		for(int i = 0; i<this.Subformulas().length; i++) {
			if(!(this.Subformulas()[i] instanceof Or || this.Subformulas()[i].IsTermo())) {
				result = false;
			}
		}
		
		return result;
	}
	
	public Boolean IsDNNF() {
		Boolean result = false;
		if(this.IsNegationNormalForm()) {                     //Checagem condição inicial NNF  
			
			for(int i = 0; i<this.Subformulas().length; i++) {//Iterar por todas as subformulas
			
				if(this.Subformulas()[i] instanceof And) {    //Analisar apenas as conjunções
				
					And andSub = (And) this.Subformulas()[i]; //Castando item para And
					List<Formula> leftList = Arrays.asList(andSub.left.Atoms());
					List<Formula> rightList = Arrays.asList(andSub.right.Atoms());
					//Seprarando listas com os átomos da esquerda e direita
					
					if(leftList.size()>rightList.size()) {    //Se a esquerda tem mais itens
	 					for(Formula item : leftList) {        //Iteraremos por cada um    
							if(rightList.contains(item)) {    //E se ele estiver presente na direita
								result = false;               //Conjuntos se intersectam 
								break;                        //E saimos do laço
							} else {
								result = true;
							}
						}
					} else {
						for(Formula item : rightList) {       //Simetria do problema para caso a 
							if(leftList.contains(item)){      //Direita tenha mais itens
								result = false;
								break;
							} else {
								result = true;
							}
						}
					}
					
				}
			}
		}
		return result;
	}
	
	public abstract Formula Substituicao(Formula B, Formula C);
	public abstract Formula[] Subformulas();
	public abstract String toString();
	public abstract Boolean Equals(Formula other);
	public abstract int NumeroConectivos();
	public abstract int Length();
	
	
}
