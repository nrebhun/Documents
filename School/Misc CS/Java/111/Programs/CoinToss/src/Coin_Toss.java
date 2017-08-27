import java.util.*;
import java.util.Scanner;

public class Coin_Toss{ 
	public static void main(String args[]){ 
		Scanner input = new Scanner(System.in);
		int flip = (int)(Math.random() * 2);
		
		System.out.print("I just flipped a coin... heads or tails? \n (heads = 1, tails = 0): ");
		int guess = input.nextInt();
		if(guess == flip){ 
			System.out.println("Correct!");
		}
		else{
			System.out.println("Incorrect.");
		}
	}
}