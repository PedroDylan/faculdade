package Logicomp;

public class Teste {
	public static void main(String[] args) {
		
		Atom a = new Atom("a");
		Atom b = new Atom("b");
		Atom c = new Atom("c");
		Atom d = new Atom("d");
		
		Not na = new Not(a);
		Not nb = new Not(b);
		Not nc = new Not(c);
		Not nd = new Not(d);
		
		Or aob = new Or(a,b);
		Or aonb = new Or(a,nb);
		Or cod = new Or(c,d);
		Or ncond = new Or(nc,nd);
		
		And formula1 = new And(aonb,cod);
		And formula2 = new And(aob,ncond);
		Or formula3 = new Or(formula1,formula2);
		
		System.out.println(formula3);
		System.out.println(formula3.IsNegationNormalForm());
		System.out.println(formula3.IsDNNF());
		
	
		
	}
}
