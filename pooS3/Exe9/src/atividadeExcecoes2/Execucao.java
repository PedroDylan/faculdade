package atividadeExcecoes2;

public class Execucao {
	public static void main(String[] args) {
		try{
			Data dia1 = new Data(3,5,3);
		} catch (DataException e) {
			System.out.println(e);
		}
		try{
			Data dia2 = new Data(1,2,3);
		} catch (DataException e) {
			System.out.println(e);
		}
		try{
			Data dia3 = new Data(1,15,15);
		} catch (DataException e) {
			System.out.println(e);
		}
		try{
			Data dia4 = new Data(-1,11,15);
		} catch (DataException e) {
			System.out.println(e);
		}
		
	}
}
