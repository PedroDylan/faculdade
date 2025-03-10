package recursao;

public class ContadorCrescente {
	public static void contadorCrescente(int number) {
		if(number == 0) {
			System.out.println(0);
		} else {
			contadorCrescente(number-1);
			System.out.println(number);
		}
	}
}
