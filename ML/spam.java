import java.io.*;
import java.util.regex.*;
import java.util.*;
class spam{
	public static void main(String a[]){
		byte b[]=new byte[100];
		ArrayList<String> spamword=new ArrayList<String>();
		ArrayList<String> nonspamword=new ArrayList<String>();
		try{
			FileInputStream spamFile = new FileInputStream("spam.txt");
			FileInputStream nonspamFile = new FileInputStream("nonspam.txt");
			spamFile.read(b);
			String s=new String(b);
			nonspamFile.read(b);
			String ns=new String(b);
			float nspam=s.split("\n").length;
			float nnspam=ns.split("\n").length;
			float post[]=new float[2];
			post[0]=nspam/(nspam+nnspam);
			post[1]=nnspam/(nspam+nnspam);
			//System.out.println("Posterior(spam): "+post[0]+" Posterior(nonspam): "+post[1]);
			String spam[]=s.split("\n");
			String nonspam[]=ns.split("\n");
			for(String line:spam){
				String t[]=line.split(" ");
				for(String w:t){spamword.add(w);}
			}
			for(String line:nonspam){
				String t[]=line.split(" ");
				for(String w:t){nonspamword.add(w);}
			}
			//for(String tt:spamword){System.out.println(tt);}
			ArrayList<String> voc=new ArrayList<String>();
			for(String t:spamword){voc.add(t);}
			for(String t:nonspamword){voc.add(t);}
			//for(String t:voc){System.out.println(t);}
			float no_spam=spamword.size();
			float no_nonspam=nonspamword.size();
			float no_voc=voc.size();
			System.out.printf("At Least This word should be contained (");
			for(int i=0;i<no_voc;i++){System.out.printf("%s,",voc.get(i));}
			System.out.printf("\b)\n");
			System.out.printf("Enter Your Mail:\n");
			Scanner sc=new Scanner(System.in);
			String t=sc.nextLine();
			String text[]=t.split(" ");
			//for(String tt:text){System.out.println(tt);}
			float occ_spam,occ_nonspam;
			float p[][]=new float[20][2];
			int i=0;
			for(String word:text){
				occ_spam=occ_nonspam=0;
				if(voc.contains(word)){
					Pattern pattern=Pattern.compile(word);
					//for occurence in spam
					Matcher m_spam=pattern.matcher(s);
					while(m_spam.find()){occ_spam++;}
					p[i][0]=(occ_spam+1)/(no_spam+no_voc);
					//for occurence in non spam
					Matcher m_nonspam=pattern.matcher(ns);
					while(m_nonspam.find()){occ_nonspam++;}
					//System.out.println(occ_nonspam+" "+occ_spam+" "+ word);
					p[i][1]=(occ_nonspam+1)/(no_nonspam+no_voc);
					i++;
				}
				else{
					p[i][0]=1;
					p[i][1]=1;
					//System.out.println("No : "+word);
					i++;
				}
			}	
			/*for(int m=0;m<4;m++){
				for(int n=0;n<2;n++){
					System.out.printf("%f\t",p[m][n]);
				}
				System.out.printf("\n");
			}*/
			float p_spam=1,p_nonspam=1;
			for(int j=0;j<2;j++){
				for(int k=0;k<text.length;k++){
					if(j==0){p_spam*=p[k][j];}
					else{p_nonspam*=p[k][j];}
				}
			}
			//System.out.println(p_spam+" "+p_nonspam);
			System.out.println("------------------------------------------------------");
			if(p_spam>p_nonspam){System.out.println("Beware ! This mail is spam");}
			else{System.out.println("Feel Safe ! This mail is not spam");}
			System.out.println("------------------------------------------------------");
		}
		catch(Exception e){}

	}
}