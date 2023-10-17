package atividadeExcecoes2;

public class DataException extends Exception {
	private int dia;
	private int mes;
	private int ano;
	
	public DataException() {}
	
	public DataException(String msg) {
		super(msg);
	}
	
	public DataException(int dia, int mes ,int ano) {
		this.mes = mes;
		this.dia = dia;
		this.ano = ano;
	}
	
	public String toString() {
		return ("A data " + dia+ "/" + mes+ "/"+ ano + " é inválida!");
	}
}
