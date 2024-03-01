package Logicomp;

import java.util.Dictionary;
import java.util.Hashtable;

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
		
		And aeb = new And(a,b);
		
		
		Dictionary<Formula,Boolean> interpretation1 = new Hashtable<Formula, Boolean>();
		interpretation1.put(a,true);
		interpretation1.put(b,false);
		interpretation1.put(c,false);
		interpretation1.put(d,false);
		
		System.out.println(na.TruthValue(interpretation1));
		System.out.println(nb.TruthValue(interpretation1));
		System.out.println(aeb.TruthValue(interpretation1));
		System.out.println(aonb.TruthValue(interpretation1));
		
	}
}
