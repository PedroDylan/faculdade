package Logicomp;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Dictionary;
import java.util.List;

public class Not extends Formula{

	public Formula inner;
	
	public Not(Formula inner) {
		super("not"+inner.getName());
		this.inner=inner;
	}
	
	public String toString() {
		return "("+"\u00AC"+ this.inner.toString()+")";
	}
	
	public Boolean Equals(Formula other) {
		if(other instanceof Not) {
			Not Nother = (Not) other;
			return Nother.inner == this.inner;
		} else {
			return false;
		}
	}
	
	public int Length() {
		return 1 + this.inner.Length();
	}
	
	public Formula[] Subformulas() {
		
		Formula[] innerSubFormulas = this.inner.Subformulas();
		
		List<Formula> arrlist = new ArrayList<Formula>(Arrays.asList(innerSubFormulas));
		arrlist.add(this);
		
		innerSubFormulas = arrlist.toArray(innerSubFormulas);
		return innerSubFormulas;
	}
	
	public int NumeroConectivos() {
		return 1 + this.inner.NumeroConectivos();
	}
	
	public Formula Substituicao(Formula B, Formula C) {
		if(this.equals(B)) {
			return C;
		} else {
			Not result = new Not(inner.Substituicao(B,C));
			return result;
		}
	}
	
	public Boolean TruthValue(Dictionary<Formula,Boolean> Interpretation) {
		return !Interpretation.get(this.inner);
	}
	
	
}
