package exe0301;

public class PrincipalRelogio {
	public static void main(String[] args) {
		Relogio omega = new Relogio("Omega");
		Relogio patecFelipe = new Relogio("Patec Felipe");
		Relogio rolex = new Relogio("Rolex");
		
		omega.inicializar(5, 12, 36);
		patecFelipe.inicializar(5, 12);
		rolex.inicializar(5);
		
		
		omega.print();
		patecFelipe.print();
		rolex.print();
		
	}
}
