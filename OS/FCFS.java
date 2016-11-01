class Process{
	String id;
	int bt,wt,tat;
	Process(String id,int bt){
		this.id=id;
		this.bt=bt;
		wt=tat=0;
	}
}
class FCFS{
	public static void main(String a[]){
		int[] bt={24,3,3};
		Process[] p=new Process[3];
		for(int i=0;i<3;i++){
			p[i]=new Process("P"+(i+1),bt[i]);
		}
		//waiting time
		for(int i=1;i<3;i++){
			p[i].wt=p[i-1].wt+p[i-1].bt;
		}
		//tat time
		for(int i=0;i<3;i++){
			p[i].tat=p[i].wt+p[i].bt;
		}
		System.out.printf("%s%15s%15s%20s\n","Process","Burst Time","waiting Time","Turnaround Time");
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