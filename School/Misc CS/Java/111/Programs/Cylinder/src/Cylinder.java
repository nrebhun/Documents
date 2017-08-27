import java.util.*;

public class Cylinder {

    public static void main (String args[]) {
        Scanner input = new Scanner(System.in);
		System.out.println("There is a cylinder in front of you. Enter its radius: ");
		double radius = input.nextDouble();
		double area = radius * radius * 3.14;
		System.out.println("Now enter its length: ");
		double length = input.nextDouble();
		double volume = area * length;
		System.out.println("The volume of the cylinder is " +volume);
    }
}
