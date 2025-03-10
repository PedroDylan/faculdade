package exe7;

public class Medico extends Pessoa {
	
	private int crm;
	private int salario;
	public String especializacao;
	
	public Medico(String nome, String endereco, boolean sexo, int idade, int cpf,int crm,int salario,String espec) {
		super(nome,endereco,sexo,idade,cpf);
		this.crm = crm;
		this.salario=salario;
		this.especializacao = espec;
	}
	
	public Medico(Pessoa pessoa,int crm,int salario,String espec) {
		super(pessoa.nome,pessoa.endereco,pessoa.sexo,pessoa.idade,pessoa.cpf);
		this.crm = crm;
		this.salario=salario;
		this.especializacao = espec;
	}
	
	protected void plantao() {
		System.out.println(this.nome + " está dormindo na sala dos médicos");
	}
	
	protected void imprimirValores() {
		super.imprimirValores();
		System.out.println("crm: " + this.crm);
		System.out.println("salário: " + this.salario);
		System.out.println("especialização: "+this.especializacao);
	}
	
}
