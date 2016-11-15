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
				byte[] c=new byte[100];
				in.read(c);
				spam.add(new String(c));
				in.close();
			}
			String add="";
			for(String m:spam){
				String t=m.trim();
				System.out.println(t);
				add += t+"\n";
				//System.out.println(add);
			}
			FileOutputStream fspam=new FileOutputStream(a[0]+".txt");
			b=add.getBytes();
			fspam.write(b);
			fspam.close();
		}
		catch(Exception	 e){System.out.println(e);}
	}
}
