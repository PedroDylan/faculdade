package atividadeExcecoes2;

public class Data {
	private int dia;
	private int mes;
	private int ano;
	
	public Data(int dia, int mes, int ano) throws DataException {
		if(validaMes(mes) && validaDia(dia,mes) && validaAno(ano)) {
			this.mes = mes;
			this.dia = dia;
			this.ano = ano;
		} else {
			throw new DataException(dia,mes,ano);
		}
	}
	
	private boolean validaMes(int mes){
		return (mes>0 && mes<13); 
	}
	
	private boolean validaDia(int dia, int mes) {
		if(mes<7) {
			if(mes%2==0) {
				return (dia<=31 && dia>0);
			} else {
				return (dia<=30 && dia>0);
			}
		} else {
			if(mes%2==0) {
				return (dia<=30 && dia>0);
			} else {
				return (dia<=31 && dia>0);
			}
		}
	}
	
	private boolean validaAno(int ano) {
		return (ano>0);
	}

}

