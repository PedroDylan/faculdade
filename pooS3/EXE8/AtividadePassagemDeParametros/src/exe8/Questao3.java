package exe8;

public class Questao3 {
	public static void main(String[] args) {
		int valor = 5;
		int valor_quad = quadrado(valor);
		
		System.out.println("Valor : "+ valor);		
		System.out.println("Quadrado : "+ valor_quad);
	}
	
	public static int quadrado(int numero) {
		numero = 3;
		return numero*numero;
	}
}
//No caso desse código o parâmetro de entrada é alterado dentro da função e retornado para fora dela
//com o valor alterado por conta do retorno da função
