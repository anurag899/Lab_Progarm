import java.util.regex.*;
import java.io.*;
import java.util.*;
class pattern{
	public static void main(String a[]){
		byte b[]=new byte[50];
		try{FileInputStream spamFile = new FileInputStream("spam.txt");
		FileInputStream nonspamFile = new FileInputStream("nonspam.txt");
		spamFile.read(b);
		String s=new String(b);
		nonspamFile.read(b);
		String ns=new String(b);
		String spam[]=s.split("\n");
		String nonspam[]=ns.split("\n");
		ArrayList<String> spamword=new ArrayList<String>();
		for(String line:spam){
			String l[]=line.split(" ");
			for(String t:l){spamword.add(t);}
		}
		System.out.println(spamword.get(1));
		String voc[]=new String[50];
		/*int n=0;
		for(String t:spamword){voc[n]=t;n++;}
		for(String t:nonspamword){voc[n]=t;n++;}
		String word="You Get A Lottery";
		String text[]=word.split(" ");
		for(String m:spamword){System.out.println(m);}
		for(int i=0;i<voc.length;i++){
			if(!("Lottery".equals(voc[i]))){System.out.println("yes");}
			else{System.out.println("NO");}
			
		}*/
		}
		catch(Exception e){}
	}
}