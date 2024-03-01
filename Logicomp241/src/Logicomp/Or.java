package Logicomp;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Dictionary;
import java.util.List;

public class Or extends Formula {
	
	private Formula left;
	private Formula right;
	
	public Or(Formula left, Formula right) {
		super(left.getName()+"or"+right.getName());
		this.left = left;
		this.right = right;
	}
	
	public String toString() {
		return "("+this.left.toString() + "\u2228" + this.right.toString()+")";
	}
	
	public Boolean Equals (Formula other) {
		if(other instanceof Or) {
			Or Oother = (Or) other;
			return (Oother.left==this.left)&&(Oother.right==this.right);
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
		
		leftlist.addAll(rightlist);
		leftlist.add(this);
		
		leftFormulas = leftlist.toArray(leftFormulas);
		return leftFormulas;
	}
	
	public int NumeroConectivos() {
		return 1 + this.left.NumeroConectivos() + this.right.NumeroConectivos();
	}
	
	public Formula Substituicao(Formula B, Formula C) {
		if(this.equals(B)) {
			return C;
		} else {
			Formula SubLeft = this.left.Substituicao(B, C);
			Formula SubRight = this.right.Substituicao(B, C);
			Or result = new Or(SubLeft,SubRight);
			return result;
		}
	}
	
	public Boolean TruthValue(Dictionary<Formula,Boolean> Interpretation) {
		return ( Interpretation.get(this.left) || Interpretation.get(this.right));
	}
	
}
