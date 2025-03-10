package exe0301;
import java.util.Date;
import java.time.LocalDate;

public class Funcionario {
		
	private static int contador = 0;
	private int id = 0;
	private String nome;
	private LocalDate dataAdmissao;
	private double salario;
	
	public Funcionario() {
		id = contador++;
	}
	
	public double getSalario() {
		return this.salario;
	}
	
	public void setSalario(double salario) {
		if(salario <= 1100.0) {
			System.out.println("Insira um salário válido acima de 1100.0");
		} else {
			this.salario = salario;
		}
		
	}
	
	public LocalDate getDataAdmissao() {
		return this.dataAdmissao;
	}
	
	public void setDataAdmissao(LocalDate data) {
		if(data.isAfter(LocalDate.now())) {
			System.out.println("Você não é um viajante do tempo, insira data válida");
		} else {
			this.dataAdmissao = data;
		}
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}

	public void getId() {
		System.out.println("Identificador: " + this.id);
	}

	public void tirarFerias(int dias) {
		System.out.println(this.nome + "Está tirando " + dias + " dias de férias.");
	}
	
	public void tirarFerias() {
		System.out.println(this.nome + "Está tirando 30 dias de férias");
	}
}

	
