package exe8;

public class Questao4 {
	public static void main(String[] args) {
		imprimir_quadrados(1,2,3,4,5,6,7,8,9);
		imprimir_quadrados(1,2,4);
		imprimir_quadrados(3);
	}
	
	
	public static void imprimir_quadrados(int...itens) {
		System.out.println("Função chamada");
		for(int item : itens) {
			System.out.println(quadrado(item));
		}
	}
	
	
	public static int quadrado(int numero) {
		return numero*numero;
	}
}
