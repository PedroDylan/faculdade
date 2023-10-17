package exe7;

public class Paciente extends Pessoa{
	
	public String doenca;
	public String medicacao;
	
	public Paciente(String nome, String endereco, boolean sexo, int idade, int cpf, String doenca, String medicacao) {
		super(nome,endereco,sexo,idade,cpf);
		this.doenca = doenca;
		this.medicacao = medicacao;
	}
	
	public Paciente(Pessoa pessoa,String doenca, String medicacao) {
		super(pessoa.nome,pessoa.endereco,pessoa.sexo,pessoa.idade,pessoa.cpf);
		this.doenca = doenca;
		this.medicacao = medicacao;
	}
	
	protected void dor() {
		System.out.println(this.nome + " está gritando de dor, por favor acabe com seu sofrimento.");
	}
		
	protected void alta() {
		System.out.println(this.nome + " foi liberto do suplício hospitalar");
	}
	
	protected void imprimirValores() {
		super.imprimirValores();
		System.out.println("doença: " + this.doenca);
		System.out.println("medicação: " + this.medicacao);
	}
	
}
