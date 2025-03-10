package exe7;

public class Main {
	public static void main(String[] args) {
		
		Pessoa pedro = new Pessoa("Pedro","Fortaleza",true,20,0001);
		pedro.imprimirValores();
		pedro.andar();
		
		Paciente jose = new Paciente("Jose","Goiás",true,45,2,"Câncer","Quimioterapia");
		jose.andar();
		jose.imprimirValores();
		jose.dor();
		jose.alta();
		
		Pessoa julia = new Pessoa("Julia","São Paulo", false, 22, 3);
		Medico drJulia = new Medico(julia,101,2000,"Cardiologia");
		
		julia.andar();
		drJulia.andar();
		
		julia.imprimirValores();
		drJulia.imprimirValores();
		
		drJulia.plantao();
	}
}
