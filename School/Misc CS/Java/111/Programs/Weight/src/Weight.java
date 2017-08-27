import java.util.*;

public class Weight {
	public static void main(String args[]){
		Scanner input = new Scanner (System.in);
		
		System.out.println("Please enter a weight in pounds to convert it to kilograms: ");
		
	double pounds = input.nextDouble();
	double kilograms = pounds/.454;

	System.out.println(+pounds+ " pounds in kilograms is " +kilograms);
	}
}