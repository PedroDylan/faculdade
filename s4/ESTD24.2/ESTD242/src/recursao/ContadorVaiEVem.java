package recursao;

public class ContadorVaiEVem {
	public static void contadorVaiEVem(int number, int aux) {
		if(aux == number) {
			System.out.println(aux);
		} else {
			System.out.println(aux);
			contadorVaiEVem(number,aux+1);
			System.out.println(aux);	
		}
	}
}
