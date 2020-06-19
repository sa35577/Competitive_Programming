import static java.lang.Math.*;
import static java.lang.System.*;
import java.util.*;
public class r1p3
{
	public static final double SQRT3=sqrt(3);
	public static final void main(String...args)
	{
		Scanner scanner=new Scanner(in);
		int exp=0,prec=0,pin=0;
		double x=0,y=0;
		double xd=0,yd=0;
		double dist=0,coef=0;
		double[]pinx=null,piny=null;
		for(int test=0;test<10;test++)
		{
			coef=scanner.nextDouble();
			exp=scanner.nextInt();
			x=coef*pow(10,exp);
			coef=scanner.nextDouble();
			exp=scanner.nextInt();
			y=coef*pow(10,exp);
			coef=scanner.nextDouble();
			exp=scanner.nextInt();
			dist=coef*pow(10,exp)/3;
			prec=scanner.nextInt();
			pinx=new double[10];
			piny=new double[10];
			pinx[0]=x;
			piny[0]=y;
			pinx[1]=x-dist/2;
			piny[1]=y+dist*SQRT3/2;
			pinx[2]=x+dist/2;
			piny[2]=y+dist*SQRT3/2;
			pinx[3]=x-dist;
			piny[3]=y+dist*SQRT3;
			pinx[4]=x;
			piny[4]=y+dist*SQRT3;
			pinx[5]=x+dist;
			piny[5]=y+dist*SQRT3;
			pinx[6]=x-dist*3/2;
			piny[6]=y+dist*3*SQRT3/2;
			pinx[7]=x-dist/2;
			piny[7]=y+dist*3*SQRT3/2;
			pinx[8]=x+dist/2;
			piny[8]=y+dist*3*SQRT3/2;
			pinx[9]=x+dist*3/2;
			piny[9]=y+dist*3*SQRT3/2;
			for(int i=0;i<5;i++)
			{
				coef=scanner.nextDouble();
				exp=scanner.nextInt();
				x=coef*pow(10,exp);
				coef=scanner.nextDouble();
				exp=scanner.nextInt();
				y=coef*pow(10,exp);
				dist=Double.POSITIVE_INFINITY;
				for(int j=0;j<10;j++)
				{
					xd=x-pinx[j];
					yd=y-piny[j];
					if(sqrt(xd*xd+yd*yd)<dist)
					{
						dist=sqrt(xd*xd+yd*yd);
						pin=j+1;
					}
				}
				if(i==4)
				{
					out.println(pin);
				}
				else
				{
					out.print(Integer.toString(pin)+" ");
				}
			}
		}
	}
}