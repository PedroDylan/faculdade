package atividadeExcecoes1;

public class ClienteException extends Exception{

	private String nome;
	private String ddd;
	private String numero;
	
	public ClienteException() {}
	
	public ClienteException(String msg) {
		super(msg);
	}
	
	public ClienteException(String nome, String ddd, String numero) {
		this.ddd=ddd;
		this.nome = nome;
		this.numero = numero;
	}
	
	public String toString() {
		return ("O cliente de nome: "+ nome +", ddd: "+ddd+" e numero: " + numero+ " é inválido");
	}
	
}
