import java.util.*;

public class Bill {

    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
		
		System.out.println("Enter the subtotal of your bill: ");
		
		double subtotal = input.nextDouble();
		
		System.out.println("Enter the gratuity rate as a decimal: ");
		
		double gratuity = input.nextDouble();
		double total = subtotal * (1 + gratuity);
		
		System.out.println("Your total is: " +total);
    }
}
