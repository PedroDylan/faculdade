package exe7;

public class Pessoa {
	
	protected String nome;
	protected String endereco;
	protected boolean sexo;
	protected int idade;
	protected int cpf;
	
	public Pessoa(String nome, String endereco, boolean sexo, int idade, int cpf) {
		this.nome = nome;
		this.endereco = endereco;
		this.sexo = sexo;
		this.idade = idade;
		this.cpf = cpf;
	}
	
	
	protected void andar() {
		System.out.println(this.nome +" está andando.");
	}
	
	protected void imprimirValores() {
		System.out.println("nome: "+this.nome);
		System.out.println("endereço: "+this.endereco);
		if(sexo==true) {
			System.out.println("sexo: masculino");
		} else {
			System.out.println("sexo: feminino");
		}
		System.out.println("idade: "+this.idade);
		System.out.println("cpf: "+this.cpf);
	
	}
	
	
}
