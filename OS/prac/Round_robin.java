import java.util.*;
class Process{
	String name;
	int bt,ct,tat;
	int temp;
	Process(String name,int bt){
		this.name=name;
		this.bt=temp=bt;
		ct=tat=0;
	}
}
class Gatt{
	ArrayList<String> pid=new ArrayList<String>();
	ArrayList<Integer> ptime=new ArrayList<Integer>();
}
class Round_robin{
	public static void main(String[] a){
		int[] bt={10,29,3,7,12};
		int tq=10;
		Gatt gc=new Gatt();
		ArrayList<Process> p=new ArrayList<Process>();
		for(int i=0;i<bt.length;i++){
			p.add(new Process("P"+(i+1),bt[i]));
		}
		int complete=0,j=0;
		gc.ptime.add(0);
		while(complete!=bt.length){
			if(tq<p.get(j).temp){
				p.get(j).temp-=tq;
				gc.pid.add(p.get(j).name);
				gc.ptime.add(gc.ptime.get(gc.ptime.size()-1)+tq);
				if(p.get(j).temp==0){
					p.get(j).ct=gc.ptime.get(gc.ptime.size()-1);
					complete++;
				}
			}
			else{
				if(p.get(j).temp!=0){
					p.get(j).temp=0;
					gc.pid.add(p.get(j).name);
					gc.ptime.add(gc.ptime.get(gc.ptime.size()-1)+p.get(j).bt);
					p.get(j).ct=gc.ptime.get(gc.ptime.size()-1);
					complete++;
				}
			}
			j=(j==bt.length-1)?0:j+1;
		}
		for(int i=0;i<p.size();i++){
			// System.out.println(gc.pid.get(i));
			// System.out.println(gc.ptime.get(i));
			System.out.println(p.get(i).ct);
		}
	}
}