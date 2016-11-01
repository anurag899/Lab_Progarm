import java.util.*;
class Process{
	String id;
	int bt,wt,tat,temp,ct;
	Process(String id,int bt){
		this.id=id;
		temp=this.bt=bt;
		wt=tat=ct=0;
	}
}
class Gantt{
	ArrayList<String> c=new ArrayList<String>();
	ArrayList<Integer> ft=new ArrayList<Integer>();
}
class Round_Robin{
	public static void main(String... a){
		ArrayList<Process> p=new ArrayList<Process>();
		Gantt g=new Gantt();
		int tq=	5,i=1;
		int[] bt={9,5,3,4};
		for(int b:bt){p.add(new Process("P"+i++,b));}
		int complete=0,j=0,k=0;
		g.ft.add(0);
		while(complete!=bt.length){
			if(tq<p.get(j).temp){
				p.get(j).temp-=tq;
				g.c.add(p.get(j).id);
				g.ft.add(g.ft.get(g.ft.size()-1)+tq);
				if(p.get(j).temp==0){
					p.get(j).ct=g.ft.get(g.ft.size()-1);
					complete++;}
			}
			else{
				if(p.get(j).temp!=0)
				{	
					g.ft.add(g.ft.get(g.ft.size()-1)+p.get(j).temp);
					p.get(j).temp=0;
					complete++;
					p.get(j).ct=g.ft.get(g.ft.size()-1);
					//System.out.println(complete);
					g.c.add(p.get(j).id);}
			}

			j=(j==bt.length-1)?0:j+1;
		}
		for(int m=0;m<bt.length;m++){
			p.get(m).tat=p.get(m).ct;
			p.get(m).wt=p.get(m).ct-p.get(m).bt;
		}
		System.out.printf("%s%15s%15s%20s\n","Process","Burst Time","waiting Time","Turnaround Time");
		for(Process m:p){
			System.out.printf("%s%15d%15d%20d\n",m.id,m.bt,m.wt,m.tat);
		}
		System.out.printf("\n");
		for(String m:g.c){
			System.out.printf("%5s\t",m);
		}
		System.out.printf("\n");
		for(int m:g.ft){
			System.out.printf("%d\t",m);
		}
		System.out.printf("\n");
		
	}
}
