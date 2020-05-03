import java.io.*;

import java.util.*;
 public class distance  {
     public static class Person{
         double a,b;boolean infected;
         Person(double a0,double b0,boolean inf){
             a=a0;
             b=b0;
             infected = inf;
         }
 }
	//static BufferedReader br = new BufferedReader(new FileReader("Data.in"));

	static StringTokenizer st;

    public static void main(String[] args) throws InterruptedException,IOException {

       Person loc[] = new Person[12000000];//12 million in Ontario

       for(int ii=0;ii<args.length;ii++){
           System.out.println(ii);
           int id = 0;
           double x = Double.parseDouble(args[ii++]),y = Double.parseDouble(args[ii++]),dis = Integer.parseInt(args[ii++]);

               loc[0] = new Person(x,y,false);

               int count = 0;
               for(int i=0;i<loc.length;i++){
                   if(i==id || !loc[i].infected )continue;
                    double radius = 6371e3;
                    double phi1 = x * Math.PI/180;
                    double phi2 = loc[i].a * Math.PI/180;
                    double deltaphi = (loc[i].a-x) * Math.PI/180;
                    double deltalambda = (loc[i].b-y) * Math.PI/180;
                    double a = Math.sin(deltaphi/2) * Math.sin(deltaphi/2) + Math.cos(phi1) * Math.cos(phi2) * Math.sin(deltalambda/2) * Math.sin(deltalambda/2);
                    double c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
                    double d = radius * c / 1000;
                    if(d <= dis){
                        count++;
                    }
               }System.out.println("There are " + count + " infected people near you");


       }
    }

	/*static String next () throws IOException,InterruptedException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException,InterruptedException {
		return Long.parseLong(next());
	}static char readCharacter () throws IOException,InterruptedException {
                return next().charAt(0);
        }
	static int readInt () throws IOException,InterruptedException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException,InterruptedException {
		return Double.parseDouble(next());
	}
	static String readLine () throws IOException,InterruptedException {
		return br.readLine().trim();
	}    */
}
