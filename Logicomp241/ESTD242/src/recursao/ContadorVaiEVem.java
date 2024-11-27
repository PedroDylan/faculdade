package recursao;

public class ContadorVaiEVem {
	
	public static void main(String[] args) {
		contadorVaiEVem(10,8);
	}
		
	public static void contadorVaiEVem(int number, int aux) {
		if(aux == number) {
			System.out.println(aux);
		} else {
			System.out.println(aux);
			contadorVaiEVem(number,aux+1);
			System.out.println(aux);	
		}
	}
	
	public static void contadorVaiEVemClean(int number, int aux) {
		System.out.println(aux);
		if(aux<number) {
			contadorVaiEVemClean(number, aux+1);
			System.out.println(aux);
		}
	}
}
