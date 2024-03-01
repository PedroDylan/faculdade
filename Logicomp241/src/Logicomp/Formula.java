package Logicomp;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Dictionary;
import java.util.Hashtable;
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
		Formula[] subformulas = this.Subformulas();            //Criando array de subformulas
		List<Formula> listatoms = new ArrayList<Formula>();    //Alocando memória para lista de átomos
		
		for(int i=0; i< subformulas.length; i++) {             //Iterando pelo array e achando os 
			if((subformulas[i] instanceof Atom) && (!listatoms.contains(subformulas[i]))) { 
				listatoms.add(subformulas[i]);                 //átomos que Não estão presentes na lista 
			}                                                  //para evitar duplicatas   
		}
		
		Formula[] resultfinal = new Formula[listatoms.size()]; //Alocando memória para o array de 
		resultfinal = listatoms.toArray(resultfinal);          //átomos e convertendo a lista para
		return resultfinal;									   //o array de resultado
	}
	
	public int NumberOfAtoms() {
		return this.Atoms().length;
	}
		
	public Boolean IsNegationNormalForm() {
		Boolean result = true;
		List<Formula> listanots = new ArrayList<Formula>();
		
		for(int i = 0; i<this.Subformulas().length; i++) {
			
			if(this.Subformulas()[i] instanceof Implies) {     //NNF permite apenas disjunções
				result = false;								   //e conjunções como operadores binários
				break;
			}
			
			
			if(this.Subformulas()[i] instanceof Not) {		   //Adicionar cada not na lista
				listanots.add(this.Subformulas()[i]);
			}
		}
		
		for(Formula f : listanots) {						   //Iterar pela lista e buscar
			Not notf = (Not) f;								   //Apenas os casos nos quais a negação se 
			if (!(notf.inner instanceof Atom)) {			   //aplica somente em átomos
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
		if(this instanceof Not) {								//Literais são definidos como atomos 
			Not nthis = (Not) this;								//Ou negações de átomos
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
	
	public abstract Boolean PartialTruthValue(Hashtable<Formula,Boolean> Interpretation) throws NullValueException;
	public abstract Boolean TruthValue(Dictionary<Formula,Boolean> Interpretation);
	public abstract Boolean Equals(Formula other);
	public abstract Formula Substituicao(Formula B, Formula C);
	public abstract Formula[] Subformulas();
	public abstract String toString();
	public abstract int NumeroConectivos();
	public abstract int Length();
	
	
}
