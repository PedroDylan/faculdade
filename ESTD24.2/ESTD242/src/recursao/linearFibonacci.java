package recursao;

public class linearFibonacci {
	public static void main(String[] args) {
		for(int i = 0;i<13;i++) {
		System.out.println(linearFibonacci(i)[0]);
		}
	}
	
	public static int[] linearFibonacci(int number) {
		if(number <= 1) {
			int[] result = {number,0};
			return result;
		} else {
			int[] auxiliar = linearFibonacci(number-1);
			int[] result = {auxiliar[0]+auxiliar[1],auxiliar[0]};
			return result;
		}
	}
}
