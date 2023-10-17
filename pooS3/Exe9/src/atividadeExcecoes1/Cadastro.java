package atividadeExcecoes1;

import javax.swing.JOptionPane;

public class Cadastro {
	public static void main(String[] args) {
		
		String nomeCompleto;
		String ddd;
		String numero;
		
		nomeCompleto = JOptionPane.showInputDialog("Insira seu nome completo ");
		ddd = (JOptionPane.showInputDialog("Insira o DDD do seu telefone "));
		numero = (JOptionPane.showInputDialog("Insira o seu telefone ")); 
		
		try {
			Cliente c1 = new Cliente(nomeCompleto,ddd,numero);
			System.out.println("Cliente criado");
			
		} catch (ClienteException e) {
			System.out.println(e);
		}
		
		
	}
}
