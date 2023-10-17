package atividadeExcecoes1;

public class Cliente {
	private String nome;
	private int ddd;
	private int numero;
	
	public Cliente(String nome, String ddd, String numero) throws ClienteException {
		if(validaNome(nome) && validaNUM(ddd,true) && validaNUM(numero,false)) {
			this.nome = nome;
			this.ddd = Integer.parseInt(ddd);
			this.numero = Integer.parseInt(numero);
		} else {
			throw new ClienteException(nome,ddd,numero);
		}
		
	}
	
	private boolean validaNome(String nome) {
		return (!nome.isBlank());
	}
	
	private boolean validaNUM(String num, boolean isDDD) {
		int inum;

		try {
			inum = Integer.parseInt(num);
			if(isDDD) {
				return (inum > 10 && inum < 100);
			} else {
			return (inum > 10000000 && inum < 1000000000);
			}
		} catch (NumberFormatException e) {
			return false;
		}
	}
	
	
}
