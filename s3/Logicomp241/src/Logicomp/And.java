package Logicomp;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Dictionary;
import java.util.List;

public class And extends Formula{

	public Formula left;
	public Formula right;
	
	public And(Formula left, Formula right) {
		super(left.getName()+"and"+right.getName());
		this.left= left;
		this.right=right;
	}
	
	public String toString() {
		return "("+this.left.toString() + "\u2227" + this.right.toString()+")";
	}
	
	public Boolean Equals(Formula other) {
		if(other instanceof And) {
			And Aother = (And)other;
			return (Aother.left==this.left)&&(Aother.right==this.right);
		} else {
			return false;
		}
	} 
	
	public int Length() {
		return 1 + this.left.Length() + this.right.Length();
	}
	
	public Formula[] Subformulas() {
		Formula[] leftFormulas = this.left.Subformulas();
		Formula[] rightFormulas = this.right.Subformulas();
		
		List<Formula> leftlist = new ArrayList<Formula>(Arrays.asList(leftFormulas));
		List<Formula> rightlist = new ArrayList<Formula>(Arrays.asList(rightFormulas));
		
		for(int i = 0; i<rightlist.size(); i++) {
			if(!leftlist.contains(rightFormulas[i])) {
				leftlist.add(rightlist.get(i));
			}
		}
		leftlist.add(this);
		
		leftFormulas = leftlist.toArray(leftFormulas);
		return leftFormulas;
	}
	
	public int NumeroConectivos() {
		return 1 + this.left.NumeroConectivos() + this.right.NumeroConectivos();
	}
	
	public Formula[] Atoms(){
		Formula[] subformulas = this.Subformulas();
		List<Formula> listatoms = new ArrayList<Formula>();
		
		for(int i=0; i< subformulas.length; i++) {
			if(subformulas[i] instanceof Atom) {
				listatoms.add(subformulas[i]);
			}
		}
		
		Formula[] resultfinal = new Formula[listatoms.size()]; 
		resultfinal = listatoms.toArray(resultfinal);
		return resultfinal;
	}
	
	public Formula Substituicao(Formula B, Formula C) {
		if(this.equals(B)) {
			return C;
		} else {
			Formula SubLeft = this.left.Substituicao(B, C);
			Formula SubRight = this.right.Substituicao(B, C);
			And result = new And(SubLeft,SubRight);
			return result;
		}
	}
	
	public Boolean TruthValue(Dictionary<Formula,Boolean> Interpretation) {
		return ( Interpretation.get(this.left)&&Interpretation.get(this.right));
	}
	
	
	
	
}
