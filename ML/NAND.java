class NAND{
	void wUpdate(float[][] x,float[] w,float[] z){
		boolean flag=true;
		do{
			for(int i=0;i<4;i++){
				float  sum=0,t=.5f,r=.1f;
				flag=false;
				for(int j=0;j<3;j++){
					sum+=x[i][j]*w[j];
				}
				int n=(sum>t)?1:0;
				float e=z[i]-n;
				if(e!=0){flag=true;}
				float d=r*e;
				for(int j=0;j<3;j++){
					w[j]+=x[i][j]*d;
				}
				for(int j=0;j<3;j++){
					System.out.printf("%.1f\t",w[j]);
				}
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
		float[] z={1f,1f,1f,0f};
		NAND nand = new NAND();
		nand.wUpdate(x,w,z);	
	}
}