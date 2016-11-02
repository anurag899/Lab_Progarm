import java.util.*;
class Process implements Comparable<Process>{
	String id;
	int bt,wt,tat,priorty;
	Process(String id,int bt,int priorty){
		this.id=id;
		this.bt=bt;
		wt=tat=0;
		this.priorty=priorty;
	}
	public int compareTo(Process p){
		if(priorty==p.priorty){return 0;}
		else if(priorty>p.priorty){return 1;}
		else{return -1;}
	}
}
class Priorty{
	public static void main(String a[]){
		int[] bt={10,7,6,13,5};
		int[] pt={3,1,3,4,2};
		ArrayList<Process> p=new ArrayList<Process>();
		for(int i=0;i<bt.length;i++){
			p.add(new Process("P"+(i+1),bt[i],pt[i]));
		}
		Collections.sort(p);
		//waiting time
		for(int i=1;i<bt.length;i++){
			p.get(i).wt=p.get(i-1).wt+p.get(i-1).bt;
		}
		//tat time
		System.out.printf("%s%15s%15s%20s\n","Process","Burst Time","waiting Time","Turnaround Time");
		for(int i=0;i<bt.length;i++){
			p.get(i).tat=p.get(i).wt+p.get(i).bt;
		}
		for(Process m:p){
			System.out.printf("%s%15d%15d%20d\n",m.id,m.bt,m.wt,m.tat);
		}
		System.out.printf("\n");
		for(Process m:p){
			System.out.printf("%5s\t",m.id);
		}
		
		System.out.printf("\n");
		System.out.printf("0\t");
		for(Process m:p){
			System.out.printf("%d\t",m.tat);
		}
		System.out.printf("\n");
	}
}