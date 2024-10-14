package recursao;

public class inversorArray {
	public static void main(String[] args) {
		int[] array = new int[] {1,2,3,4,5}; 
		
		inversorArray(array,0,4);
		
		for(int i =0; i<5;i++) {
			System.out.println(array[i]);
		}
	}
	
	public static void inversorArray(int[] array, int sobe, int desce) {
		int dummy;
		if(sobe<desce) {
			dummy = array[sobe];
			array[sobe] = array[desce];
			array[desce]=dummy;
			inversorArray(array,sobe+1,desce-1);;
		}
	}
}
