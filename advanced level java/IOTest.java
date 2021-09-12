import java.io.*;
public class IOTest{
    public static void main(String[] args) throws IOException{
        WriteTest();
    }

    static void ReadTest(){
        // StreamTokenizer re = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        // only read strings
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        try{
            String x = re.readLine();
            System.out.println(x);
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    static void WriteTest() throws IOException{
        BufferedReader re = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer r = new StreamTokenizer(re);
        PrintWriter pr = new PrintWriter(new OutputStreamWriter(System.out));
        r.nextToken();
        int n = (int)r.nval;
        //re.readLine();
        String x = re.readLine();
        pr.println(n+ "" + x);
        pr.flush();
    }
}