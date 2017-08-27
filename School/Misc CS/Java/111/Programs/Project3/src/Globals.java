/* ______________
 / Nick Rebhun   \
 | 9/22/2009     |
 | CS-111 (Java) |
 \_______________/
 */
import java.util.*;

public class Globals {
	static int num;
	static int min_number = 1;
	static int max_number = 8;
	static int current_image;
	
	public static void main ( String [] args) {
		//  call showMenu, must create object to call non-static method
		Globals tpo = new Globals();
		tpo.showMenu();
	}
	
	public  int  forward ( int num ) {
		
		if(num != max_number && num >= min_number) {
			num++;
		}
		else if(num == max_number) {
			num = min_number;
		}
		return num;
	}
	
	public  int  backward ( int num ) {
		if(num <= max_number && num != min_number) {
			num--;
		}
		return num;
	}
	
	public  void  FOVERLOAD () {
		// overloaded method, use global variable as input and output
		if(num != max_number && num >= min_number) {
			num++;
		}
		else if(num == max_number) {
			num = min_number;
		}
	}
	
	public  void  BOVERLOAD () {
		// overloaded method, use global variable as input and output
		if(num <= max_number && num != min_number) {
			num--;
		}
	}
	
	public  String  createFileName (int pictureX.gif) {
		// return a filename like pictureX.gif
		int random = gen.nextInt(max_number) + min_number;
		System.out.println("picture" + random + ".gif");
		return pictureX.gif;
	}
	
	public  String  createRandomName (  ) {
		// return a filename like pictureX.gif
		// using a RANDOM number between min_number and max_number
		int randomGenerator = Math.Random() * (max_number + min_number);
		return null;
	}
	
	public  void  showMenu (int choice) {
		// write a loop
		// Display a menu, with options 1 .. N for each method above, and an exit option
		// get user input and call the correct method using a switch
		
		Scanner input = new Scanner(System.in);
		
		do {
			
		System.out.println("vvvvvvvvvvvvvMENUvvvvvvvvvvvvv");
		System.out.println("|1........Forward            |");
		System.out.println("|2........Backward           |");
		System.out.println("|3........Forward (Overload) |");
		System.out.println("|4........Backward (Overload)|");
		System.out.println("|5........Create File Name   |");
		System.out.println("|6........Create Random File |");
		System.out.println("|0........Quit Program       |");
		System.out.println("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		
			System.out.print("Enter a number to choose a function: ");
		
		choice = input.nextInt();
		
		switch (choice) {
			case '1':
				forward();
				break;
			
			case '2':
				backward();
				break;
			
			case '3':
				FOVERLOAD();
				break;
			
			case '4':
				BOVERLOAD();
				break;
			
			case '5':
				createFileName();
				break;
				
			case '6':
				createRandomName();
				break;

			default:
				System.out.println("Error: That is not an option. Try again.");
				break;
		}
		}while(choice == 0)
		}
	}

}