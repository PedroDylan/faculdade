package exe0301;
import java.util.Date;
import java.time.LocalDate;
import java.util.Calendar;

public class Principal {
	public static void main(String[] args) {
		
		Funcionario pedro = new Funcionario();
		Funcionario marcos = new Funcionario();
		Funcionario andre = new Funcionario();
		
		pedro.setNome("Pedro Dylan");
		marcos.setNome("Marcos Yuri");
		andre.setNome("Andre Luiz");
		
		pedro.setSalario(1100.0);
		marcos.setSalario(50000.0);
		andre.setSalario(3960.0);
		
		LocalDate dataAdminPe = LocalDate.parse("2025-10-12");
		LocalDate dataAdmin = LocalDate.parse("2020-10-12");
		
		pedro.setDataAdmissao(dataAdminPe);
		marcos.setDataAdmissao(dataAdmin);
		andre.setDataAdmissao(dataAdmin);

		System.out.println("Data de admissão do Marcos : " + marcos.getDataAdmissao());
		System.out.println("Salário do André : " + andre.getSalario());
		
		
	}
}
