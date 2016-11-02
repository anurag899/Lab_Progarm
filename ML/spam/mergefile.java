import java.io.*;
import java.util.*;
class mergefile{
	public static void main(String[] a){
		byte[] b=new byte[100];
		int num_File=Integer.parseInt(a[1]);
		ArrayList<String> spam=new ArrayList<String>();
		try{
			for(int i=1;i<=num_File;i++){
				FileInputStream in=new FileInputStream(a[0]+i+".txt");
				in.read(b);
				spam.add(new String(b));
				in.close();
			}
			String add="";
			for(String m:spam){
				String t=m.trim();
				add+=t+"\n";
			}
			FileOutputStream fspam=new FileOutputStream(a[0]+".txt");
			b=add.getBytes();
			fspam.write(b);
			fspam.close();
		}
		catch(Exception	 e){System.out.println(e);}
	}
}
