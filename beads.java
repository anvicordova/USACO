/*
ID: georgex1
LANG: JAVA
TASK: beads
*/
import java.io.*;
import java.util.*;

public class beads{
    private static int N, leftOver;
    private static String[] colors;
    
    public static void main (String [] args) throws IOException
    {
        BufferedReader f = new BufferedReader (new FileReader("beads.in"));
        N = Integer.parseInt(f.readLine());
        String beadsString = f.readLine();
        int max = 0;
        colors = breakToArray(beadsString);
        for (int i = 0; i < N; i++)
        {
            if (countFwd(i) + countBwd(prev(i)) > max)
                max = countFwd(i) + countBwd(prev(i));
        }
        PrintWriter out = new PrintWriter(new FileWriter("beads.out"));
        out.println(max);
        out.close();
        System.exit(0);
    }
    
    public static int countFwd (int i)
    {
        String color = "w";
        int count = 0;
        boolean first = true;
        for (int c = i; c!=i || first; c = next(c))
        {
            if (!color.equals("w") && (color.equals(colors[c])||colors[c].equals("w")))
            {
                count ++;
                
                System.out.println ("count " + count);
                System.out.println ("color " + color);
            }
            else if (color.equals("w"))
            {
                color = colors[c];
                count++;
                System.out.println ("2count " + count);
                System.out.println ("2color " + color);
            }
            else
            {
                
                System.out.println ("bcount " + count);
                System.out.println ("bcolor " + color);
                break;
                
            }
            first = false;
        }
            leftOver = N - count;
            return count;
    }
    
    public static int countBwd(int i)
    {
        String color = "w";
        int count = 0;
        if (leftOver == 0)
            return 0;
        for (int c = i; c != prev(i,leftOver); c = prev(c))
        {
            if (!color.equals("w") && (color.equals(colors[c])||colors[c].equals("w")))
            {
                count ++;
            }
            else if (color.equals("w"))
            {
                color = colors[c];
                count ++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
        
    
    private static int next(int i)
    {
        return (i+1)%N;
    }
    private static int prev(int i)
    {
        return (i-1+N)%N;
    }
    private static int prev(int i, int n)
    {
        int answer = i;
        for (int c = 0; c<n; c++)
            answer = prev(answer);
        return answer;
    }
        
        
        
        
        
 
    public static String[] breakToArray(String string)
    {
       String[] array = new String[string.length()];
        for (int c = 0; c < string.length(); c++)
        {
            array[c] = string.substring(c,c+1);
        }

        return array;
    }
    
    
    
}
    
    
    
    
    
