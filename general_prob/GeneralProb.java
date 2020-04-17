

class GeneralProb{

	public static boolean isPalindrome(String testString){
		testString = testString.toLowerCase();

		int index = 0;

		int lastIndex = testString.length()- 1;

		while(index < lastIndex){
			char forwardChar = testString.charAt(index);
			char reverseChar = testString. charAt(lastIndex);

			while(forwardChar == ' '){
				index ++;
				forwardChar = testString.charAt(index);
			}
			while(reverseChar == ' '){
				lastIndex--;
				reverseChar = testString.charAt(lastIndex);
			}
			if(forwardChar != reverseChar){
				return false;
			}
			index ++;
			lastIndex --;
		}

		return true;
	}

	public static void main(String args[]){
		System.out.println( isPalindrome("Malayalam"));
	}
}