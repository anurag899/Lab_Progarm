import java.util.*;
class Perceptron{
	float[][] x;
	float[] w,z;
	Perceptron(float[][] x,float[] w,float[] z){
		this.x=Arrays.copyOf(x, x.length);
		this.w=Arrays.copyOf(w, w.length);
		this.z=Arrays.copyOf(z, z.length);
	}
}
class NAND{
	void wUpdate(Perceptron p){
		boolean flag=true;
		do{
			for(int i=0;i<4;i++){
				float  sum=0,t=.5f,r=.1f	;
				flag=false;
				for(int j=0;j<3;j++){
					sum+=p.x[i][j]*p.w[j];
				}
				int n=(sum>t)?1:0;
				float e=p.z[i]-n;
				if(e!=0){flag=true;}
				float d=r*e;
				for(int j=0;j<3;j++){
					p.w[j]+=p.x[i][j]*d;
				}
				for(int j=0;j<3;j++){
					System.out.printf("%.1f\t",p.w[j]);
				}
				System.out.printf("\t%f",e);
				System.out.print("\n");
			}
		}while(flag);
	}
	public static void main(String[] a){
		float[][] x={
			{1f,0f,0f},
			{1f,0f,1f},
			{1f,1f,0f},
			{1f,1f,1f}
		};
		float[] w={.3f,.1f,.1f};
		float[] z={0f,0f,0f,1f};
		NAND nand = new NAND();
		Perceptron p=new Perceptron(x,w,z);
		nand.wUpdate(p);	
		Scanner sc =new Scanner(System.in);
		System.out.println("After weight updation:");
		System.out.println("Enter 1'st input :-");
		int c=sc.nextInt();
		System.out.println("Enter 2'nd input :-");
		int b=sc.nextInt();
		float sum=1*p.w[0]+c*p.w[1]+b*p.w[2];
		System.out.println("Resulted Output:");
		System.out.println((sum>.5)?1:0);

	}

}