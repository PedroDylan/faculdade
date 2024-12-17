package deques;

public class EmptyDequeException extends RuntimeException {
	public EmptyDequeException(String error) {
		super(error);
	}
}
