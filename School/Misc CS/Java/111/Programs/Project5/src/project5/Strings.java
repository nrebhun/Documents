package project5;

import java.util.*;
import java.io.*;

public class Strings{

    int arraynumber;
    int addnumb;

    public static void main(String[] args) throws Exception {

        Strings tpo = new Strings();

        File file = new File("/Users/nrfactor/Desktop/strings.txt");
        Scanner input = new Scanner(file);

        int arraySize = input.nextInt();
        String[] strdata  = new String[arraySize];

      String names;
      names =  input.nextLine();


       tpo.arraynumber = 0;


       while (input.hasNext() == true)
       {

            strdata[tpo.arraynumber] = names;
            tpo.arraynumber = tpo.arraynumber + 1;
            names =  input.nextLine();
       }

       tpo.sortstrings(strdata);

 }

    public void sortstrings(String[] out) throws Exception {

        String[] outarray = out;
        Arrays.sort(outarray);

   File outfile = new File("/Users/nrfactor/Desktop/outstrdata.txt");
   PrintWriter output = new PrintWriter(outfile);


   for (int num = 0; num < outarray.length; num++)
    {
    output.println(outarray[num]);
    }
    output.println("The meadian is " + outarray[out.length/2]);
    output.close();

    }
 }


