package exe0301;

public class Relogio {
	
	String nome;
	int horas;
	int minutos;
	int segundos;
	
	public Relogio(String nome) {
		this.nome = nome;
	}

	public void inicializar(int horas, int minutos, int segundos) {
		this.horas = horas;
		this.minutos = minutos;
		this.segundos = segundos;
	}
	
	public void inicializar(int horas, int minutos) {
		this.horas = horas;
		this.minutos = minutos;
		this.segundos = 1;
	}
	
	public void inicializar(int horas) {
		this.horas = horas;
		this.minutos = 1;
		this.segundos = 1;
	}
	
	public void print() {
		System.out.println(this.nome+ " " + this.horas + " Horas");
		System.out.println(this.nome+ " " +this.minutos + " Minutos");
		System.out.println(this.nome+ " " +this.segundos + " Segundos");
	}
}
