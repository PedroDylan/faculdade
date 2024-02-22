package Logicomp;

public class Atom extends Formula{

	public Atom(String name) {
		super(name);
	}

	public String toString() {
		return this.getName();
	}
	
	public Boolean Equals(Formula other) {
		return (other instanceof Atom) || (other.getName()==this.getName());
	}
	
	public int Length() {
		return 1;
	}
	
	public Formula[] Subformulas() {
		Formula[] conjunto = {this};
		return conjunto;
	}
	
	public int NumeroConectivos() {
		return 0;
	}
	
	public Formula[] Atoms() {
		Formula[] result = {this};
		return result;
	}
	
	public Formula Substituicao(Formula B, Formula C) {
		if(this.equals(B)) {
			return C;
		} else {
			return this;
		}
	}
	
}
