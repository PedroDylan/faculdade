package Logicomp;

public class NullValueException extends Exception {
	
	public String msg;
	
	public NullValueException(String msg) {
		super(msg);
		this.msg = msg;
		
	}
	
	public String toString() {
		return this.msg;
	}
	
}
