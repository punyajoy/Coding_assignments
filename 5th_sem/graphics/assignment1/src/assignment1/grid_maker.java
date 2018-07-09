/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package assignment1;
import java.util.Scanner;
import java.applet.*;
import java.awt.*;
import java.math.*;
import java.awt.event.ActionListener;
import java.awt.event.*;

/**
 *
 * @author student
 */



public class grid_maker extends button implements MouseListener,MouseMotionListener {

    /**
     * Initialization method that will be called after the applet is loaded into
     * the browser.
     */
    int X=0,Y=0,flag=0;
     
    int height =getHeight();
    int width =getWidth();
    int OriginX=(getX()+width)/2;
    int OriginY=(getY()+height)/2;
    
    String msg="MouseEvents";
    public void init() {
         Color color1 = new Color(0,0,0);
         setBackground(color1);
        //setBackground(Color.red);
         int height =this.getHeight();
         int width =this.getWidth();
         int OriginX=(this.getX()+width)/2;
         int OriginY=(this.getY()+height)/2;
         Button Button1 = new Button("Zoom in");
         Button Button2 = new Button("Zoom out");
         Button Button3 = new Button("move_left");
         Button Button4 = new Button("move_right");
        
         
         
         Button EButton1 = new Button("copy");
         Button EButton2 = new Button("upset");
         Button EButton3 = new Button("angry");
         Button EButton4 = new Button("cunning");
         Button EButton5 = new Button("fear");
         Button EButton6 = new Button("surprise");
         Button EButton7 = new Button("sad");

         addMouseListener(this);
	 addMouseMotionListener(this);
                //add Buttons
         add(Button1);
         add(Button2);
         //add(Button3);
         //add(Button4);
         add(EButton1);
         add(EButton2);
         add(EButton3);
         add(EButton4);
         add(EButton5);
         add(EButton6);
         add(EButton7);

                //set action listeners for buttons
         Button1.addActionListener(this);
         Button2.addActionListener(this);
         //Button3.addActionListener(this);
         //Button4.addActionListener(this);
         EButton1.addActionListener(this);
         EButton2.addActionListener(this);
         EButton3.addActionListener(this);
         EButton4.addActionListener(this);
         EButton5.addActionListener(this);
         EButton6.addActionListener(this);
         EButton7.addActionListener(this);

        // TODO start asynchronous download of heavy resources
    }
public void mouseEntered(MouseEvent m)
	{

	//repaint();
	}
	public void mouseExited(MouseEvent m)
	{

	}
	public void mousePressed(MouseEvent m)
	{

		 //X = (int) m.getX();
	         //Y = (int) m.getY();


		//repaint();
	}
	public void mouseReleased(MouseEvent m)
	{

		//repaint();
	}
	public void mouseMoved(MouseEvent m)
	{


		//repaint();
	}
	public void mouseDragged(MouseEvent m)
	{

		//repaint();
	}
	public void mouseClicked(MouseEvent m)
	{
		 X = (int) m.getX();
		 Y = (int) m.getY();
                 int height_1 =getHeight();
                  int width_1 =getWidth();
        
                 int OriginX_mouse=(getX()+width_1)/2;
                 int OriginY_mouse=(getY()+height_1)/2;
                  
                 int x_click=((X-OriginX_mouse)/r);
                 int y_click=((OriginY_mouse-Y)/r)-1;
                System.out.println(X);
                System.out.println(Y);
                System.out.println(OriginX_mouse);
                System.out.println(OriginY_mouse);
                 
                System.out.println(x_click);
                System.out.println(y_click);
                
                flag=1;
//repaint();

	}
        int c=1;
        int w_counter=0;
      int [ ] [ ] [ ]window = new int [ 10 ][ 2 ] [ 2 ] ;

        
public void paint(Graphics g)
    {



     
      Scanner scan = new Scanner(System.in);
      //String s = scan.next();
        //int i = scan.nextInt();




      make_grid(g);


      double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
      //double [ ] [ ] trans_mat = new double [ 3 ] [ 3 ] ;



      //g.setColor(Color.red);
      //setPixel(g,8,8,trans_mat);
      //trans_mat=scaling_mat(2,2);
      //g.setColor(Color.blue);
      //setPixel(g,8,8,trans_mat);
      trans_mat=make_trans_mat(0,0,0,0,0,1,1);
      //ellipse_mid(g,0,0,10,4,trans_mat);
      //circle(g,0,0,5,trans_mat);
      int [ ] [ ] window_1 = new int [ 2 ] [ 2 ] ;
      int [ ] [ ] window_2 = new int [ 2 ] [ 2 ] ;
      
      
      
      
      
      window[w_counter][0][0]=120;
      window[w_counter][1][0]=140;
      window[w_counter][0][1]=140;
      window[w_counter][1][1]=100;
      window[1][0][0]=0;
      window[1][1][0]=70;
      window[1][0][1]=70;
      window[1][1][1]=0;
      
      //w_counter++;        



      //drawQuad1(g,x_1,y_1,trans_mat);
      //g.setColor(Color.blue);
      //line_b_2(g,0,0,200,200,trans_mat);
      g.setColor(Color.yellow);
      window_1=ithwindow(g,window,0);
      
      make_window(g,window_1);
      window_2=ithwindow(g,window,1);
      
      make_window(g,window_2);
            
      cohen_suderland(g,window_1,0,0,200,200);
      cohen_suderland(g,window_2,0,0,200,200);
      
      /*
      int [ ] ar_x = new int [ 4 ];
      int [ ] ar_y = new int [ 4 ];
      
      
      ar_x[0]=20;
      ar_x[1]=10;
      ar_x[2]=20;
      ar_x[3]=30;
      ar_y[0]=40;
      ar_y[1]=10;
      ar_y[2]=60;
      ar_y[3]=30;
      
      g.setColor(Color.red);
      
      drawQuad1(g,ar_x,ar_y,trans_mat);
      
      
      if(emotion==1)
      {
       copy_object(g,window_2,window_1,ar_x,ar_y);
      }
      
      */
      
      
      
      
      
      
      
      
      
      
      
      //g.drawLine(100,100,200,500);


       //trans_mat=rotation_mat(0);
      //
      //make_face(g,emotion,0,0,trans_mat);
      //make_grid(g);
      //ellipse_mid(g,0,0,10,4,trans_mat);
      //trans_mat=make_trans_mat(0,0,0,0,0,1,1);

      //ellipse_mid(g,0,0,4,6,trans_mat);

      //trans_mat=make_trans_mat(4,4,30,-4,-4);

      //ellipse_mid(g,4,4,4,6,trans_mat);



       //trans_mat=rotation_mat(0);
       //solar_system(g);
      //circle(g,0,0,5,trans_mat);
      
      
      //move_robot(g);
      //jump_robot(g);
      //make_delay(1000);

}
//window_1 is the original
private void copy_object(Graphics g,int window_1[][],int window_2[][],int ar_x[],int ar_y[])
{
    int xw_max,xw_min,xv_max,xv_min,yw_max,yw_min,yv_max,yv_min;
    if(window_1[0][0]>window_1[1][0])
    {
        xw_max=window_1[0][0];
        xw_min=window_1[1][0];
    }
    else
    {
        xw_max=window_1[1][0];
        xw_min=window_1[0][0];
    }
    if(window_2[0][0]>window_2[1][0])
    {
        xv_max=window_2[0][0];
        xv_min=window_2[1][0];
    }
    else
    {
        xv_max=window_2[1][0];
        xv_min=window_2[0][0];
    }
    if(window_1[0][1]>window_1[1][1])
    {
        yw_max=window_1[0][1];
        yw_min=window_1[1][1];
    }
    else
    {
        yw_max=window_1[1][1];
        yw_min=window_1[0][1];
    }
    if(window_2[0][1]>window_2[1][1])
    {
        yv_max=window_2[0][1];
        yv_min=window_2[1][1];
    }
    else
    {
        yv_max=window_2[1][1];
        yv_min=window_2[0][1];
    }
    
    
    double sx=(xv_max-xv_min)/(double)(xw_max-xw_min);
    double sy=(yv_max-yv_min)/(double)(yw_max-yw_min);
    int i;
    int [ ] ar_x1 = new int [ 4 ];
      int [ ] ar_y1= new int [ 4 ];
    for(i=0;i<4;i++)
    {
        System.out.println("quad"+ar_x[i]);
        System.out.println("quad"+ar_y[i]);
      
        ar_x1[i]=xv_min+(int)((double)(ar_x[i]-xw_min)*sx);
        ar_y1[i]=yv_min+(int)((double)(ar_y[i]-yw_min)*sy);
        
        System.out.println("quad"+sx);
        System.out.println("quad"+sy);
    
    }
    
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
        
    
    drawQuad1(g,ar_x1,ar_y1,trans_mat);
    
    
    
    
    
    
    
    
    
    
    
}













private int[][] ithwindow(Graphics g,int window[][][],int i)
{
      int [ ] [ ] ithwindow = new int [ 2 ] [ 2 ] ;
    
      ithwindow[0][0]=window[i][0][0];
      ithwindow[1][0]=window[i][1][0];
      ithwindow[0][1]=window[i][0][1];
      ithwindow[1][1]=window[i][1][1];
      
    
    return ithwindow;
}






private void make_window(Graphics g,int window[][])
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ];
    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    line_b_2(g,window[0][0],window[1][1],window[0][0],window[0][1],trans_mat);
    line_b_2(g,window[1][0],window[1][1],window[1][0],window[0][1],trans_mat);
    line_b_2(g,window[0][0],window[0][1],window[1][0],window[0][1],trans_mat);
    line_b_2(g,window[0][0],window[1][1],window[1][0],window[1][1],trans_mat);
}
int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;

int getcode(int x,int y,int window[][]){
	int code = 0;
	//Perform Bitwise OR to get outcode
	if(y > window[0][1]) code |=TOP;
	if(y < window[1][1]) code |=BOTTOM;
	if(x < window[0][0]) code |=LEFT;
	if(x > window[1][0]) code |=RIGHT;
	return code;
}

private void cohen_suderland(Graphics g,int window[][],int x1,int y1,int x2,int y2)
{
    
    
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ];
    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    int outcode1=getcode(x1,y1,window);
    System.out.println(outcode1);
    
    int outcode2=getcode(x2,y2,window);
    int accept = 0; 	//decides if line is to be drawn
    System.out.println(outcode2);
    while(true)
    {
		float m =(float)(y2-y1)/(x2-x1);
		//Both points inside. Accept line
		if(outcode1==0 && outcode2==0){ 
			accept = 1;
			break;
		}
		//AND of both codes != 0.Line is outside. Reject line
		else if((outcode1 & outcode2)!=0){
                     break;
		}else{
			int x=0,y=0;
			int temp;
			//Decide if point1 is inside, if not, calculate intersection
			if(outcode1==0) 
				temp = outcode2;
			else 
				temp = outcode1;
			//Line clips top edge
                        System.out.println("value of temp" + temp);
			if((temp & TOP)==TOP){
				x = x1+ (int)((window[0][1]-y1)/m);
				y = window[0][1];
                                System.out.println("top");                            
			}
			else if((temp & BOTTOM)==BOTTOM){ 	//Line clips bottom edge
				x = x1+ (int)((window[1][1]-y1)/m);
				y = window[1][1];
                                
                                System.out.println("bottom");
			}else if((temp & LEFT)==LEFT){ 	//Line clips left edge
				
                                y = y1+ (int)((window[0][0]-x1)*m);
				x = window[0][0];
                                System.out.println("left");
			}else if((temp & RIGHT)==RIGHT){ 	//Line clips right edge
				y = y1+ (int)((window[1][0]-x1)*m);
				x = window[1][0];
                                
                                System.out.println("right"+x+y);
			}
			//Check which point we had selected earlier as temp, and replace its co-ordinates
			if(temp == outcode1){ 
				x1 = x;
				y1 = y;
                                
				outcode1 = getcode(x1,y1,window);
                                System.out.println("outcode1"+outcode1+" "+x+" "+y);
			}else{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2,y2,window);
                                System.out.println("outcode2"+outcode2);
			}
		}
	}
    g.setColor(Color.red);
    if(accept==1)
        line_b_2(g,x1,y1,x2,y2,trans_mat);
    
    
    
    
    
    
}



































int count_jump=1;
private void jump_robot(Graphics g)
{
    if(count_jump==1)
    {
    Robot(g,0,0,0,-90,90,0,0);
    }
    else if(count_jump==2)
    {
    Robot(g,0,2,0,20,-20,-10,10);
    }
    else if(count_jump==3)
    {
    Robot(g,0,4,0,40,-40,-20,20);
    }
    else if(count_jump==4)
    {
    Robot(g,0,6,0,90,-90,-60,60);
    }
    else if(count_jump==5)
    {
    Robot(g,0,4,0,40,-40,-20,20);
    }
    else if(count_jump==6)
    {
    Robot(g,0,2,0,20,-20,-10,10);
    }
    else if(count_jump==7)
    {
    Robot(g,0,0,0,-90,90,0,0);
    }
    else
    {
        
    count_jump=0;    
    }
    count_jump =count_jump+1;
    
    
}



int count_walk=1;
private void move_robot(Graphics g)
{
    if(count_walk==1)
    {
    Robot(g,c,0,0,-90,90,0,0);
    }
    else if(count_walk==2)
    {
    Robot(g,c,0,15,-90,50,-20,0);
    }
    else if(count_walk==3)
    {
    Robot(g,c+4,0,0,-90,90,0,20);
    }
    else if(count_walk==4)
    {
    Robot(g,c+4,0,-15,-50,90,0,0);
    }
    else
    {
        
    c=c+4;
    if (c>50)
    {
        c=-c;
    }
    
    count_walk=0;    
    }
    count_walk =count_walk+1;
    
    
}


private void Body(Graphics g,int x,int y,int theta)
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    trans_mat=make_trans_mat(x,y,theta,-x,-y,1,1);
    drawRect1(g,-10+x,-10+y,20,20,trans_mat);
    ellipse_mid_upper(g,0+x,10+y,4,4,trans_mat);
    ellipse_mid(g,10+x,6+y,4,4,trans_mat);
    ellipse_mid(g,-10+x,6+y,4,4,trans_mat);
    ellipse_mid_lower(g,-6+x,-10+y,4,4,trans_mat);
    ellipse_mid_lower(g,6+x,-10+y,4,4,trans_mat);

}
private void left_hand(Graphics g,int x,int y,int theta)
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    trans_mat=make_trans_mat(x,y,theta,-x,-y,1,1);
    drawRect1(g,4+x,-1+y,10,2,trans_mat);
    drawRect1(g,15+x,-2+y,4,4,trans_mat);


}
private void right_hand(Graphics g,int x,int y,int theta)
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    trans_mat=make_trans_mat(x,y,theta,-x,-y,1,1);
    drawRect1(g,-14+x,-1+y,10,2,trans_mat);
    drawRect1(g,-19+x,-2+y,4,4,trans_mat);


}
private void right_leg(Graphics g,int x,int y,int theta)
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    trans_mat=make_trans_mat(x,y,theta,-x,-y,1,1);
    drawRect1(g,-1+x,-14+y,2,10,trans_mat);
    drawRect1(g,-3+x,-16+y,6,2,trans_mat);


}
private void left_leg(Graphics g,int x,int y,int theta)
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    trans_mat=make_trans_mat(x,y,theta,-x,-y,1,1);
    drawRect1(g,-1+x,-14+y,2,10,trans_mat);
    drawRect1(g,-3+x,-16+y,6,2,trans_mat);


}
private void face(Graphics g,int x,int y,int theta)
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    trans_mat=make_trans_mat(x,y,theta,-x,-y,1,1);

    drawRect1(g,-1+x,4+y,2,4,trans_mat);
    drawRect1(g,-4+x,8+y,8,8,trans_mat);
    setPixel(g,-2+x,13+y,trans_mat);
    setPixel(g,2+x,13+y,trans_mat);
    line_b_2(g,-2+x,10+y,2+x,10+y,trans_mat);


}



private void Robot(Graphics g,int x,int y,int theta_f,int theta_rh,int theta_lh,int theta_ll,int theta_rl)
{
    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ;
    Body(g,x,y,0);
    right_hand(g,-10+x,6+y,theta_rh);
    left_hand(g,10+x,6+y,theta_lh);
    right_leg(g,-6+x,-10+y,theta_rl);
    left_leg(g,6+x,-10+y,theta_ll);
    face(g,0+x,10+y,theta_f);






}


private double[][] make_trans_mat(double x,double y,double theta,double inv_x,double inv_y,double scale_x,double scale_y)
{
    double [ ] [ ] transl_mat = new double [ 3 ] [ 3 ] ; //create memory space for entire matrix
    double [ ] [ ] rot_mat = new double [ 3 ] [ 3 ] ; //create memory space for entire matrix
    double [ ] [ ] inv_transl_mat = new double [ 3 ] [ 3 ] ; //create memory space for entire matrix
    double [ ] [ ] scaling_mat = new double [ 3 ] [ 3 ] ; //create memory space for entire matrix

    double [ ] [ ] trans_mat = new double [ 12 ] [ 3 ] ; //create memory space for entire matrix

    transl_mat=translation_mat(x,y);
    rot_mat=rotation_mat(theta);
    inv_transl_mat=translation_mat(inv_x,inv_y);
    scaling_mat=scaling_mat(scale_x,scale_y);

    int i;
    int j;
    for (i = 0; i < 12; i++)
    { // aRow
        if(i<3)
        {
            for (j = 0; j < 3; j++) { // bColumn
                    trans_mat[i][j]=transl_mat[i][j];
            }
        }
        else if(i>=3 && i<6)
        {
            for (j = 0; j < 3; j++) { // bColumn
                    trans_mat[i][j]=rot_mat[i-3][j];
            }
        }
        else if(i>=6 && i<9)
        {
            for (j = 0; j < 3; j++) { // bColumn
                   trans_mat[i][j]= inv_transl_mat[i-6][j];
            }
        }
        else if(i>=9 && i<12)
        {
            for (j = 0; j < 3; j++)
            { // bColumn
                   trans_mat[i][j]= scaling_mat[i-9][j];
            }
        }

    }
    return trans_mat;
}







private void setPixel(Graphics m,int x,int y,double trans_mat[][])
{
    int height =getHeight();
    int width =getWidth();
    int OriginX=(getX()+width)/2;
    int OriginY=(getY()+height)/2;
    int i =0;
    int j =0;
    double [ ] [ ] input_mat = new double [ 3 ] [ 1 ] ;
    double [ ] [ ] result_mat = new double [ 3 ] [ 1 ] ;
    double [ ] [ ] transl_mat = new double [ 3 ] [ 3 ] ;
    double [ ] [ ] rot_mat = new double [ 3 ] [ 3 ] ;
    double [ ] [ ] inv_transl_mat = new double [ 3 ] [ 3 ] ;
    double [ ] [ ] scaling_mat = new double [ 3 ] [ 3 ] ;
    for (i = 0; i < 12; i++)
    { // aRow
        if(i<3)
        {
            for (j = 0; j < 3; j++) { // bColumn
                    transl_mat[i][j]=trans_mat[i][j];
            }
        }
        else if(i>=3 && i<6)
        {
            for (j = 0; j < 3; j++) { // bColumn
                    rot_mat[i-3][j]=trans_mat[i][j];
            }
        }
        else if(i>=6 && i<9)
        {
            for (j = 0; j < 3; j++) { // bColumn
                    inv_transl_mat[i-6][j]=trans_mat[i][j];
            }
        }
        else if(i>=9 && i<12)
        {
            for (j = 0; j < 3; j++) { // bColumn
                    scaling_mat[i-9][j]=trans_mat[i][j];
            }
        }
    }







    int x_start,y_start;
    input_mat=make_matrix(x,y);
    result_mat=matrix_multiply(inv_transl_mat,input_mat);
    result_mat=matrix_multiply(rot_mat,result_mat);
    result_mat=matrix_multiply(transl_mat,result_mat);
    result_mat=matrix_multiply(scaling_mat,result_mat);

    x=(int)result_mat[0][0];
    y=(int)result_mat[1][0];


    x_start=OriginX+r*x;
    y_start=OriginY-r*(y+1);
    m.fillRect(x_start,y_start,r,r);


}



private void drawRect1(Graphics r,int x_1, int y_1, int width, int height,double trans_mat[][])
{
    line_b_2(r,x_1,y_1,x_1,y_1+height,trans_mat);
    line_b_2(r,x_1,y_1,x_1+width,y_1,trans_mat);
    line_b_2(r,x_1+width,y_1,x_1+width,y_1+height,trans_mat);
    line_b_2(r,x_1,y_1+height,x_1+width,y_1+height,trans_mat);
}


private void drawQuad1(Graphics r,int x[],int y[],double trans_mat[][])
{
    line_b_2(r,x[0],y[0],x[1],y[1],trans_mat);
    line_b_2(r,x[1],y[1],x[2],y[2],trans_mat);
    line_b_2(r,x[2],y[2],x[3],y[3],trans_mat);
    line_b_2(r,x[0],y[0],x[3],y[3],trans_mat);
}

private double[][] make_matrix(int x, int y){
    double [ ] [ ] cor_mat = new double [ 3 ] [ 1 ] ;
    cor_mat[0][0]=(double)x;
    cor_mat[1][0]=(double)y;
    cor_mat[2][0]=1;
    return cor_mat;
}
private double[][] matrix_multiply(double[][] x, double[][] y){

        int aRows = x.length;
        int aColumns = x[0].length;
        int bRows = y.length;
        int bColumns = y[0].length;

        if (aColumns != bRows) {
            throw new IllegalArgumentException("A:Rows: " + aColumns + " did not match B:Columns " + bRows + ".");
        }

        double[][] C = new double[aRows][bColumns];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 1; j++) {
                C[i][j] = 0.00000;
            }
        }

        for (int i = 0; i < aRows; i++) { // aRow
            for (int j = 0; j < bColumns; j++) { // bColumn
                for (int k = 0; k < aColumns; k++) { // aColumn
                    C[i][j] += x[i][k] * y[k][j];
                }
            }
        }


    return C;
}

Planet one = new Planet();
Planet two = new Planet();
Planet three = new Planet();
Planet four = new Planet();
Planet five = new Planet();
Planet six = new Planet();
Planet seven  = new Planet();
Planet eight = new Planet();
Planet nine = new Planet();


int count=1;
private void solar_system(Graphics g)
{
    double [ ] [ ] trans_mat = new double [ 9 ] [ 3 ] ;

    count=count+1;
    g.setColor(Color.LIGHT_GRAY);
    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    ellipse_mid(g,0,0,30,4,trans_mat);
    g.setColor(Color.red);
    one.elliptical_path(g,0,0,30,4,3,trans_mat);



    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,60,8,trans_mat);
    if(count%2==0)
    {
    g.setColor(Color.orange);
    two.elliptical_path(g,0,0,60,8,6,trans_mat);
    }

    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,90,12,trans_mat);
    g.setColor(Color.blue);
    three.elliptical_path(g,0,0,90,7,6,trans_mat);

    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,120,16,trans_mat);
    g.setColor(Color.GREEN);
    four.elliptical_path(g,0,0,120,16,7,trans_mat);


    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,150,20,trans_mat);
    if(count%3==0)
    {
    g.setColor(Color.YELLOW);
    five.elliptical_path(g,0,0,150,20,4,trans_mat);
    }

    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,180,24,trans_mat);
    g.setColor(Color.white);
    six.elliptical_path(g,0,0,180,24,5,trans_mat);


    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,210,28,trans_mat);
    g.setColor(Color.white);
    seven.elliptical_path(g,0,0,210,28,3,trans_mat);


    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,240,32,trans_mat);
    g.setColor(Color.yellow);
    eight.elliptical_path(g,0,0,240,32,4,trans_mat);

    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    g.setColor(Color.LIGHT_GRAY);
    ellipse_mid(g,0,0,280,36,trans_mat);
    g.setColor(Color.red);
    nine.elliptical_path(g,0,0,280,36,6,trans_mat);










    g.setColor(Color.yellow);
    trans_mat=make_trans_mat(0,0,0,0,0,1,1);
    circle(g,0,0,7,trans_mat);
    make_delay(20);

}

private double[][] translation_mat(double x,double y)
{
    double [ ] [ ] trans_mat = new double [ 3 ] [ 3 ] ; //create memory space for entire matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                trans_mat[i][j] = 0;
        }
    }
       // Fill the matrix with user input and compute average
    trans_mat[0][0]=1;
    trans_mat[1][1]=1;
    trans_mat[2][2]=1;
    trans_mat[0][2]=x;
    trans_mat[1][2]=y;
    return trans_mat;
}

private double[][] scaling_mat(double sX,double sY)
{
    double [ ] [ ] scale_mat = new double [ 3 ] [ 3 ] ; //create memory space for entire matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                scale_mat[i][j] = 0;
        }
    }
       // Fill the matrix with user input and compute average
    scale_mat[0][0]=sX;
    scale_mat[1][1]=sY;
    scale_mat[2][2]=1;
    return scale_mat;
}

private double[][] rotation_mat(double theta)
{
    double [ ] [ ] rot_mat = new double [ 3 ] [ 3 ] ; //create memory space for entire matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                rot_mat[i][j] = 0;
        }
    }
       // Fill the matrix with user input and compute average
    rot_mat[0][0]=Math.cos(Math.toRadians(theta));
    rot_mat[1][1]=Math.cos(Math.toRadians(theta));
    rot_mat[0][1]=Math.sin(Math.toRadians(theta));
    rot_mat[1][0]=-Math.sin(Math.toRadians(theta));
    rot_mat[2][2]=1;

    return rot_mat;
}




private void make_delay(int time)
{
    try
{
    Thread.sleep(time);
}
catch(InterruptedException ex)
{
    Thread.currentThread().interrupt();
}
    repaint();
}

public class Planet
{

int type =1;
int px_1,py_1,x_1,y_1,p_1;
int Rx2_1;
int Ry2_1;
int twoRx2_1;
int twoRy2_1;
int flag1_setp;
int flag2_setp;
int set_initial;

void elliptical_path(Graphics m,int center_x,int center_y,int Rx, int Ry,int rad, double trans_mat[][])
{
    if((type==1 || type==3)&& set_initial==0)
    {
        x_1=0;
        y_1=Ry;
        flag1_setp=0;
        flag2_setp=0;
        Rx2_1=Rx*Rx;
        Ry2_1=Ry*Ry;
        twoRx2_1=2*Rx2_1;
        twoRy2_1=2*Ry2_1;
        px_1=0;
        py_1=twoRx2_1*y_1;
        set_initial=1;
    }
    else if((type==2 || type==4)&& set_initial==0)
    {
        x_1=0;
        y_1=Rx;
        flag1_setp=0;
        flag2_setp=0;
        Rx2_1=Ry*Ry;
        Ry2_1=Rx*Rx;
        twoRx2_1=2*Rx2_1;
        twoRy2_1=2*Ry2_1;
        px_1=0;
        py_1=twoRx2_1*y_1;
        set_initial=1;
    }

    if(type>4)
    {
       type=1;
    }

    if(px_1 < py_1)
    {

    if (flag1_setp==0)
    {

    float h=(Ry2_1-(Rx2_1*Ry)+(Rx2_1/4));
    p_1=Round(h);
    flag1_setp=1;
    //make_planet(m,center_x,center_y,x_1,y_1,type);

    }

      x_1++;
      px_1+=twoRy2_1;
          if (p_1<0)
              p_1+=Ry2_1+px_1;
          else
          {
              y_1--;
              py_1 -=twoRx2_1;
              p_1+=Ry2_1+px_1-py_1;
          }

    make_planet(m,center_x,center_y,rad,x_1,y_1,type,trans_mat);
    }
    else if(y_1>0)
    {

       if(flag2_setp==0)
       {
         float h=(Ry2_1*(x_1+1/2)*(x_1+1/2)+Rx2_1*(y_1-1)*(y_1-1)-Rx2_1*Ry2_1);
         p_1=Round(h);
         flag2_setp=1;
        }
        y_1--;
        py_1-=twoRx2_1;
        if(p_1>0){
            p_1+=Rx2_1-py_1;
            }
        else{
            x_1++;
            px_1+=twoRy2_1;
            p_1+=Rx2_1-py_1+px_1;

        }

    make_planet(m,center_x,center_y,rad,x_1,y_1,type,trans_mat);

    }
    else
    {
        type++;
        x_1=0;
        y_1=Ry;
        px_1=0;
        py_1=twoRx2_1*y_1;
        flag1_setp=0;
        flag2_setp=0;
        set_initial=0;
    }







}
void make_planet(Graphics g,int center_x,int center_y,int r,int x,int y,int type,double trans_mat[][])
{
    if(type==1)
    {
    circle(g,center_x+x,center_y+y,r,trans_mat);
    }
    else if(type==2)
    {
    circle(g,center_x+y,center_y-x,r,trans_mat);
    }
    else if(type==3)
    {
    circle(g,center_x-x,center_y-y,r,trans_mat);

    }
    else if(type==4)
    {
    circle(g,center_x-y,center_y+x,r,trans_mat);
    }

}




}






private void make_face(Graphics g,int emotion,int x ,int y,double trans_mat[][])
{
    circle(g,x,y,16,trans_mat);
    int x_eye_left=x+6;
    int y_eye_left=y+3;
    int x_eye_right=x-6;
    int y_eye_right=y+3;

    if (emotion==7)
    {
        line_b_2(g,x_eye_left-3,y_eye_left,x_eye_left+3,y_eye_left,trans_mat);
        line_b_2(g,x_eye_right-3,y_eye_right,x_eye_right+3,y_eye_right,trans_mat);
    }
    else if(emotion!=0)
    {

    circle(g,x_eye_left,y_eye_left,2,trans_mat);
    circle(g,x_eye_right,y_eye_right,2,trans_mat);
    }
    if ( emotion==1)
      {
          line_b_2(g,x_eye_left-2,y_eye_left+7,x_eye_left+3,y_eye_left+4,trans_mat);
          line_b_2(g,x_eye_right-3,y_eye_right+4,x_eye_right+2,y_eye_right+7,trans_mat);
          ellipse_mid_lower(g,x,y-6,7,3,trans_mat);

        }
    else if(emotion==2)
    {
        line_b_2(g,x_eye_left-2,y_eye_left+5,x_eye_left+2,y_eye_left+7,trans_mat);
        line_b_2(g,x_eye_right-2,y_eye_right+7,x_eye_right+2,y_eye_right+5,trans_mat);
        ellipse_mid_upper(g,x,y-8,6,4,trans_mat);

    }
    else if(emotion==3)
    {
        line_b_2(g,x_eye_left-3,y_eye_left+3,x_eye_left+3,y_eye_left+7,trans_mat);
        line_b_2(g,x_eye_right-3,y_eye_right+7,x_eye_right+3,y_eye_right+3,trans_mat);
        ellipse_mid_upper(g,x,y-8,8,4,trans_mat);

    }
    else if(emotion==4)
    {
        line_b_2(g,x_eye_left-3,y_eye_left+3,x_eye_left+3,y_eye_left+7,trans_mat);
        line_b_2(g,x_eye_right-3,y_eye_right+7,x_eye_right+3,y_eye_right+3,trans_mat);
        ellipse_mid_lower(g,x,y-6,7,3,trans_mat);

    }
    else if ( emotion==5)
      {
          line_b_2(g,x_eye_left-2,y_eye_left+7,x_eye_left+3,y_eye_left+4,trans_mat);
          line_b_2(g,x_eye_right-3,y_eye_right+4,x_eye_right+2,y_eye_right+7,trans_mat);
          ellipse_mid_upper(g,x,y-8,8,4,trans_mat);

        }
    else if ( emotion==6)
      {
          line_b_2(g,x_eye_left-2,y_eye_left+7,x_eye_left+3,y_eye_left+4,trans_mat);
          line_b_2(g,x_eye_right-3,y_eye_right+4,x_eye_right+2,y_eye_right+7,trans_mat);
          ellipse_mid(g,x,y-8,3,4,trans_mat);

        }
    else if(emotion==7)
    {
        line_b_2(g,x_eye_left-2,y_eye_left+7,x_eye_left+3,y_eye_left+4,trans_mat);
        line_b_2(g,x_eye_right-3,y_eye_right+4,x_eye_right+2,y_eye_right+7,trans_mat);
        ellipse_mid_upper(g,x,y-8,8,4,trans_mat);

    }



}





private void ellipse_mid(Graphics m,int center_x,int center_y,int Rx, int Ry,double trans_mat[][])
{
    int Rx2=Rx*Rx;
    int Ry2=Ry*Ry;
    int twoRx2=2*Rx2;
    int twoRy2=2*Ry2;
    int p;
    int x=0;
    int y=Ry;
    int px=0;
    int py=twoRx2*y;
    set_ellipse_coord(m,center_x,center_y,x,y,trans_mat);
    float h=(Ry2-(Rx2*Ry)+(Rx2/4));
    p=Round(h);


    /*region1*/
    while (px < py)
    { x++;
      px+=twoRy2;
          if (p<0)
              p+=Ry2+px;
          else
          {
              y--;
              py -=twoRx2;
              p+=Ry2+px-py;
          }

    set_ellipse_coord(m,center_x,center_y,x,y,trans_mat);
    }
    h=(Ry2*(x+1/2)*(x+1/2)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
    p=Round(h);
    while(y>0)
    {
        y--;
        py-=twoRx2;
        if(p>0){
            p+=Rx2-py;
            }
        else{
            x++;
            px+=twoRy2;
            p+=Rx2-py+px;

        }

    set_ellipse_coord(m,center_x,center_y,x,y,trans_mat);

    }
}





private void ellipse_mid_lower(Graphics m,int center_x,int center_y,int Rx, int Ry,double trans_mat[][])
{
    int Rx2=Rx*Rx;
    int Ry2=Ry*Ry;
    int twoRx2=2*Rx2;
    int twoRy2=2*Ry2;
    int p;
    int x=0;
    int y=Ry;
    int px=0;
    int py=twoRx2*y;
    set_half_lower_ellipse_coord(m,center_x,center_y,x,y,trans_mat);
    float h=(Ry2-(Rx2*Ry)+(Rx2/4));
    p=Round(h);


    /*region1*/
    while (px < py)
    { x++;
      px+=twoRy2;
          if (p<0)
              p+=Ry2+px;
          else
          {
              y--;
              py -=twoRx2;
              p+=Ry2+px-py;
          }

    set_half_lower_ellipse_coord(m,center_x,center_y,x,y,trans_mat);
    }
    h=(Ry2*(x+1/2)*(x+1/2)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
    p=Round(h);
    while(y>0)
    {
        y--;
        py-=twoRx2;
        if(p>0){
            p+=Rx2-py;
            }
        else{
            x++;
            px+=twoRy2;
            p+=Rx2-py+px;

        }

    set_half_lower_ellipse_coord(m,center_x,center_y,x,y,trans_mat);

    }
}
private void ellipse_mid_upper(Graphics m,int center_x,int center_y,int Rx, int Ry,double trans_mat[][])
{
    int Rx2=Rx*Rx;
    int Ry2=Ry*Ry;
    int twoRx2=2*Rx2;
    int twoRy2=2*Ry2;
    int p;
    int x=0;
    int y=Ry;
    int px=0;
    int py=twoRx2*y;
    set_half_upper_ellipse_coord(m,center_x,center_y,x,y,trans_mat);
    float h=(Ry2-(Rx2*Ry)+(Rx2/4));
    p=Round(h);


    /*region1*/
    while (px < py)
    { x++;
      px+=twoRy2;
          if (p<0)
              p+=Ry2+px;
          else
          {
              y--;
              py -=twoRx2;
              p+=Ry2+px-py;
          }

     set_half_upper_ellipse_coord(m,center_x,center_y,x,y,trans_mat);
    }
    h=(Ry2*(x+1/2)*(x+1/2)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
    p=Round(h);
    while(y>0)
    {
        y--;
        py-=twoRx2;
        if(p>0){
            p+=Rx2-py;
            }
        else{
            x++;
            px+=twoRy2;
            p+=Rx2-py+px;

        }

    set_half_upper_ellipse_coord(m,center_x,center_y,x,y,trans_mat);

    }
}


private void set_circle_coord(Graphics g,int center_x,int center_y,int x,int y,double trans_mat[][])
{
    setPixel(g,center_x+x,center_y+y,trans_mat);
    setPixel(g,center_x+x,center_y-y,trans_mat);
    setPixel(g,center_x-x,center_y+y,trans_mat);
    setPixel(g,center_x-x,center_y-y,trans_mat);
    setPixel(g,center_x+y,center_y+x,trans_mat);
    setPixel(g,center_x+y,center_y-x,trans_mat);
    setPixel(g,center_x-y,center_y+x,trans_mat);
    setPixel(g,center_x-y,center_y-x,trans_mat);


}









private void set_ellipse_coord(Graphics g,int center_x,int center_y,int x,int y,double trans_mat[][])
{
    setPixel(g,center_x+x,center_y+y,trans_mat);
    setPixel(g,center_x+x,center_y-y,trans_mat);
    setPixel(g,center_x-x,center_y+y,trans_mat);
    setPixel(g,center_x-x,center_y-y,trans_mat);

}
private void set_half_upper_ellipse_coord(Graphics g,int center_x,int center_y,int x,int y,double trans_mat[][])
{
    setPixel(g,center_x+x,center_y+y,trans_mat);
    setPixel(g,center_x-x,center_y+y,trans_mat);

}
private void set_half_lower_ellipse_coord(Graphics g,int center_x,int center_y,int x,int y,double trans_mat[][])
{
    setPixel(g,center_x+x,center_y-y,trans_mat);
    setPixel(g,center_x-x,center_y-y,trans_mat);

}




private void circle(Graphics m,int center_x,int center_y,int rad,double trans_mat[][])
{
    int x=0;
    int y=rad;
    int p=1-rad;
    set_circle_coord(m,center_x,center_y,x,y,trans_mat);
    while (x<y)
    {
        x++;
        if(p<0)
        {
            p+=2*x+1;

        }
        else
        {
            y--;
            p+=2*(x-y)+1;
        }
        set_circle_coord(m,center_x,center_y,x,y,trans_mat);
    }
}


private void make_grid(Graphics g)
{
       int height =getHeight();
       int width =getWidth();
       int OriginX=(getX()+width)/2;
       int OriginY=(getY()+height)/2;

       Color color1 = new Color(0,0,0);
       Color color2 = new Color(200,200,200);
       Color color3=new Color(0,0,200);
       Color color4=new Color(0,200,200);

       setBackground(color1);
       g.setColor(color4);





       g.drawString(actionMessage,10,50);

       //g.drawRect(100,200,130,140);
       //g.drawOval(100, 100, 100, 100);

       for (int i=0;i<width/2;i=i+r)
          {
              g.setColor(color2);
              g.drawLine(OriginX-i, 0, OriginX-i, height);
          }
       for (int i=0;i<width/2;i=i+r)
          {
              g.setColor(color2);
              g.drawLine(OriginX+i, 0, OriginX+i, height);
          }

       for (int i=0;i<height/2;i=i+r)
          {
              g.setColor(color2);
              g.drawLine(0, OriginY-i, width,OriginY-i);
          }

       for (int i=0;i<height/2;i=i+r)
          {
              g.setColor(color2);
              g.drawLine(0, OriginY+i, width,OriginY+i);
          }
      g.setColor(color3);
      g.drawLine(OriginX, 0, OriginX,height);
      g.drawLine(0, OriginY, width,OriginY);
      g.setColor(Color.yellow);
      g.drawString("Y-axis",OriginX+10, 50);
      g.drawString("X-axis",width-50,OriginY+10 );

}



private int Round(float a)
{
    int b;
    b=(int)(a+0.5);
    return b;
}



private void line_b_2(Graphics r,int x_start,int y_start,int x_end,int y_end,double trans_mat[][])
{
    float del_x=x_end-x_start;
    float del_y=y_end-y_start;
    int flag=0;
    float m=-1;

    if (del_x != 0)
    {
     m=Math.abs(del_y/del_x);
    }



    if (m>0 && m<=1)
    {
     System.out.println("hello");
     int x_l,x_r,y_l,y_r;
     if (x_start<x_end)
        {
            x_l=x_start;
            y_l=y_start;
            x_r=x_end;
            y_r=y_end;
        }
        else
        {
            x_l=x_end;
            y_l=y_end;
            x_r=x_start;
            y_r=y_start;
        }
    del_x=x_r-x_l;
    del_y=y_r-y_l;
    if (del_y>0)
    {
        System.out.println("hello");
        float p=2*del_y-del_x;
        float two_del_y=2*del_y;
        float two_dxdy=2*(del_y-del_x);
        setPixel(r,x_l,y_l,trans_mat);
        while (x_l < x_r)
        {

            x_l=x_l+1;
            if (p<0)
            {
                p+=two_del_y;

            }
            else
            {
                y_l++;
                p+=two_dxdy;
            }
            setPixel(r,x_l,y_l,trans_mat);
         }
    }
    else
    {
        y_r=y_l+Math.abs((int)del_y);
        del_y=y_r-y_l;
        float p=2*del_y-del_x;
        float two_del_y=2*del_y;
        float two_dxdy=2*(del_y-del_x);
        setPixel(r,x_l,y_l,trans_mat);
        while (x_l < x_r)
        {

            x_l=x_l+1;
            if (p<0)
            {

                p+=two_del_y;

            }
            else
            {
                y_l--;
                p+=two_dxdy;
            }
            setPixel(r,x_l,y_l,trans_mat);
         }
    }

    }
    if (m>1)
    {
     System.out.println("hello");
     int x_u,x_d,y_u,y_d;
     if (y_start<y_end)
        {
            x_d=x_start;
            y_d=y_start;
            x_u=x_end;
            y_u=y_end;
        }
        else
        {
            x_d=x_end;
            y_d=y_end;
            x_u=x_start;
            y_u=y_start;
        }
    del_x=x_u-x_d;
    del_y=y_u-y_d;
    if (del_x>0)
    {
        System.out.println("hello");
        float p=2*del_x-del_y;
        float two_del_x=2*del_x;
        float two_dxdy=2*(del_x-del_y);
        setPixel(r,x_d,y_d,trans_mat);
        while (y_d < y_u)
        {

            y_d=y_d+1;
            if (p<0)
            {
                p+=two_del_x;

            }
            else
            {
                x_d++;
                p+=two_dxdy;
            }
            setPixel(r,x_d,y_d,trans_mat);
         }
    }
    else
    {
        x_u=x_d+Math.abs((int)del_x);
        del_x=x_u-x_d;
        float p=2*del_x-del_y;
        float two_del_x=2*del_x;
        float two_dxdy=2*(del_x-del_y);
        setPixel(r,x_d,y_d,trans_mat);
        while (y_d < y_u)
        {

            y_d=y_d+1;
            if (p<0)
            {
                p+=two_del_x;

            }
            else
            {
                x_d--;
                p+=two_dxdy;
            }
            setPixel(r,x_d,y_d,trans_mat);
         }

     }
    }
    if (m==0)
    {
       int x_l,x_r,y_l,y_r;
     if (x_start<x_end)
        {
            x_l=x_start;
            y_l=y_start;
            x_r=x_end;
            y_r=y_end;
        }
        else
        {
            x_l=x_end;
            y_l=y_end;
            x_r=x_start;
            y_r=y_start;
        }
       while (x_l<=x_r){

           setPixel(r,x_l,y_l,trans_mat);
           x_l=x_l+1;
       }

    }
    if (m==-1)
    {
        int x_u,x_d,y_u,y_d;
     if (y_start<y_end)
        {
            x_d=x_start;
            y_d=y_start;
            x_u=x_end;
            y_u=y_end;
        }
        else
        {
            x_u=x_end;
            y_u=y_start;
            x_d=x_start;
            y_d=y_end;
        }

       while (y_d<=y_u){

           setPixel(r,x_d,y_d,trans_mat);
           y_d=y_d+1;
       }

    }
}




private float Eq(int x,float m,float c)
{
    float y=m*(float)x+c;
    return y;

}

//end of program









































/*
private void Line_Midpoint(Graphics r,int x_start,int y_start,int x_end,int y_end)
{
    float m=(y_end-y_start)/(float)(x_end-x_start);
    float c=y_start-m*x_start;
    setPixel(r,x_start,y_start);
    if(x_start>x_end){
    while (x_start<x_end)
    {
         x_start++;
         float y_q=Eq(x_start,m,c);
         if (y_q>(y_start+1/2))
         {
             setPixel(r,x_start,y_start+1);
             y_start=y_start+1;
         }
         else{
             setPixel(r,x_start,y_start);
         }
    }
    }
    else{
    while (x_end<x_start)
    {
         x_end++;
         float y_q=Eq(x_end,m,c);
         if (y_q>(y_end+1/2))
         {
             setPixel(r,x_end,y_end+1);;
             y_end=y_end+1;
         }
         else{
             setPixel(r,x_end,y_end);
         }
    }


    }
    }













private void Paint_car(Graphics r,int x_1, int y_1, int size)
    {
       int height =getHeight();
       int width =getWidth();
       int OriginX=(getX()+width)/2;
       int OriginY=(getY()+height)/2;
       int car_height = size*3;
       int car_width = size*3*3;
       int car_ts= size*1;   //trapezium longer side
       int car_inner_ts= size*2;  //trapezium shorter side
       int car_h_ext=size*2;
       int wheel_size=size*1;
       int x[] = { x_1+car_ts , x_1+car_width-car_ts , x_1+car_width-car_inner_ts,x_1+car_inner_ts};
       int y[] = { y_1+car_height, y_1+car_height , y_1+car_height+car_h_ext, y_1+car_height+car_h_ext};


       drawRect1(r,x_1,y_1,car_width,car_height);
       r.setColor(Color.green);
       drawRect1(r,x_1+wheel_size,y_1-wheel_size,wheel_size,wheel_size);

       drawRect1(r,(x_1+car_width-2*wheel_size),y_1-wheel_size,wheel_size,wheel_size);
       //r.setColor(Color.yellow);
       drawQuad1(r,x,y);
    }
      private void Line_midpoint(Graphics r,int x_start,int y_start,int x_end,int y_end)
{
    int del_x=x_end-x_start;
    int del_y=y_end-y_start;
    int steps,k;
    float x_increment,y_increment,x=x_start,y=y_start;
    if(Math.abs(del_x)>Math.abs(del_y))
     steps=Math.abs(del_x);
    else
     steps=Math.abs(del_x);
    x_increment = del_x/(float)steps;
    y_increment = del_y/(float)steps;
    //r.drawLine(x_start,y_start ,x_start ,y_start);
    setPixel(r,x_start,y_start);
    for (k=0;k<steps;k++)
    {
        x+=x_increment;
        y+=y_increment;
        setPixel(r,Round(x),Round(y));
        //r.drawLine(Round(x),Round(y),Round(x),Round(y));

    }

}

 */

}





    // TODO overwrite start(), stop() and destroy() methods

