package recursao;

public class somadorArray {
	public static void main(String[] args) {
		int[] array = new int[] {1,2,3,4,5}; 
		int soma = somarArray(array,5);
		System.out.println(soma);
		
	}
	
	public static int somarArray(int[] array, int num) {
		if(num < 1) {
			return 0;
		} else if (num == 1) {
			return array[0];
		} else {
			return array[num-1] + somarArray(array,num-1);
		}
	}
}
