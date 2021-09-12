import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        PrintWriter pr  = new PrintWriter(new OutputStreamWriter(System.out));
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(bf);
        st.nextToken();
        int a = (int)st.nval;
        st.nextToken();
        int b = (int)st.nval;
        int c = a + b;
        if(c<0){
            pr.print("-");
            c = -c;
        }
        String s = new StringBuilder(Integer.toString(c)).reverse().toString();
        StringBuilder res = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(i%3==0 && i!=0){
                res.append(",");
            }
            res.append(s.charAt(i));
        }
        pr.println(res.reverse());
        pr.flush();
    }
}