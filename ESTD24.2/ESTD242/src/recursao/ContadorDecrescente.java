package recursao;

public class ContadorDecrescente {
	public static void contadorDecrescente(int number) {
		if(number == 0) {
			System.out.println(0);
		} else {
			System.out.println(number);
			contadorDecrescente(number-1);
			
		}
	}
}
