/*

 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* clipping windows not generalised after + or - operations for all orientations....do it later! */
import java.applet.Applet;
import java.awt.*;
import java.util.Scanner;
import java.lang.*;

/**
 *
 * @author SANDIPAN
 */

class window
{
  int xwmin, xwmax, ywmin, ywmax;
  int selected;
  
  window(int xmin, int xmax, int ymin, int ymax, int s)
  {
    xwmin = xmin;
    xwmax = xmax;
    ywmin = ymin;
    ywmax = ymax;
    selected = s;
  }

};



class myLine
    {
      int a1, a2, b1, b2, in, out, draw=2;
      int[] clipbits = {0, 0, 0, 0, 0, 0, 0, 0};
      int[] p1 = new int[4];
      float m;
      
      myLine(int x1, int y1, int x2, int y2)
      {
         a1 = x1;
         a2 = x2;
         b1 = y1;
         b2 = y2;
         m = (float)(y2-y1)/(float)(x2-x1);
         System.out.println("M= "+m);
      }
      public void setbits(int xmin, int xmax, int ymin, int ymax)
      {
        in=1;
        out=0;
        int i, j;
        System.out.println(a1+", "+b1+", "+a2+", "+b2);
       
        for(i=0;i<8;i++)
            clipbits[i] = 0;
        if(a1<xmin)
            clipbits[0] = 1;
        if(a1>xmax)
            clipbits[1] = 1;
        if(b1<ymin)
            clipbits[2] = 1;
        if(b1>ymax)
            clipbits[3] = 1;
        if(a2<xmin)
            clipbits[4] = 1;
        if(a2>xmax)
            clipbits[5] = 1;
        if(b2<ymin)
            clipbits[6] = 1;
        if(b2>ymax)
            clipbits[7] = 1;
        
        
        
        for(j=0;j<8;j++)
          { if(clipbits[j]==1)
              {
                in=0;
                System.out.println("hi");
                break;
              }
          }
        if(in==1)
         {         System.out.println(a1+" "+b1+" "+a2+" "+b2);
           System.out.println("hello");
           p1[0] = a1;
           p1[1] = b1;
           p1[2] = a2;
           p1[3] = b2;
           draw = 1;
           System.out.println(p1[0]+" "+p1[1]+" "+p1[2]+" "+p1[3]);
          }       
        
        for(i=0, j=4; i<4; i++,j++)
        {
          if((clipbits[i]==1)&&(clipbits[j]==1))
          {
             out = 1;
             break;
          }
        }
        if (out==1)
        { draw = 0;
          
        }
        
       if(draw==2)
         
       {   System.out.println("got here"+out++);
       } 
      
      }
      
      public void clipper(int xmin, int xmax, int ymin, int ymax)
      {
        if(clipbits[0] == 1)
        {
          b1 = b1+Math.round(m*(xmin-a1));
          a1 = xmin;
          System.out.println("got here");
        }
        
        else if(clipbits[1] == 1)
        {
          b1 = b1+Math.round(m*(xmax-a1));
          a1 = xmax;     
          System.out.println("got here");
        }
        
        else if(clipbits[2] == 1)
        {
          a1 = a1+Math.round((ymin-b1)/m);
          b1 = ymin;
          System.out.println("got here");
        }
        
        else if(clipbits[3] == 1)
        {
          a1 = a1+Math.round((ymax-b1)/m);
          b1 = ymax;        
          System.out.println("got here");
        }
        
        else if(clipbits[4] == 1)
        {
          b2 = b2+Math.round(m*(xmin-a2));
          a2 = xmin;
          System.out.println("got here");
        }
        
        else if(clipbits[5] == 1)
        {
          b2 = b2+Math.round(m*(xmax-a2));
          a2 = xmax;       
          System.out.println("got here");
        }
        
        else if(clipbits[6] == 1)
        {
          a2 = a2+Math.round((ymin-b2)/m);
          b2 = ymin;
          System.out.println("got here");
        }
        
        else if(clipbits[7] == 1)
        {
          a2 = a2+Math.round((ymax-b2)/m);
          b2 = ymax;        
          System.out.println("got here");
        }      
      
        System.out.println(a1+" "+b1+" "+a2+" "+b2);
      }
    };


public class multiclip extends multiClipButton 

{
             int x1, y1, x2, y2;
             int k, iter, dx, dy;
             int choice;
             float slope;

             

    
    public void init() 
    {
       
       Color myblack = new Color(0,0,0);
       setBackground(myblack);
     /*  Scanner SC=new Scanner(System.in);
       System.out.println("\n Enter clipping window coordinates:");
       System.out.println("\n xwmin: ");
       xwmin = SC.nextInt();
       System.out.println("\n xwmax: ");
       xwmax = SC.nextInt();
       System.out.println("\n ywmin: ");
       ywmin = SC.nextInt();
       System.out.println("\n ywmax: ");
       ywmax = SC.nextInt();
*/
        
       Button clip1 = new Button("Clip line(s) with +");
       add(clip1);
       Button clip2 = new Button("Clip line(s) with -");
       add(clip2);
       clip1.addActionListener(this);
       clip2.addActionListener(this);
       
    }

    
    public void paint(Graphics g)
    {
       int originX = (getX()+getWidth())/2;
       int originY = (getY()+getHeight())/2;
       int screenw = getWidth();
       int screenh = getHeight();
       int cell = 10;
       int overlap = 1;              //change a1, b1, a2, b2 inside loop if u change the line
       int m, n, p, q;
       System.out.println("xc="+originX+"yc="+originY);
       
       g.setColor(Color.CYAN);    
       
       
       Color axisColor = new Color(0,0,200);
       g.setColor(axisColor);
       g.drawLine(0, originY, screenw, originY);
       g.drawLine(originX, 0, originX, screenh);
    
       Color gridColor = new Color(150, 150, 150);
       g.setColor(gridColor);
       for (int i=originX+cell; i<=screenw; i=i+cell)
          g.drawLine(i, 1, i, screenh);
       for (int i=originX-cell; i>=1; i=i-cell)
          g.drawLine(i, 1, i, screenh);
       for (int j=originY+cell; j<=screenh; j=j+cell)
          g.drawLine(1, j, screenw, j);
       for (int j=originY-cell; j>=1; j=j-cell)
          g.drawLine(1, j, screenw, j);


       int[] p2 = new int[500];
       m = -25;
       n = 20;
       p = 60;
       q = -10;
       myLine l = new myLine(m, n, p, q);

       if (overlap==0)
      {
       int numOfWindows = 3;
       window[] w = new window[3];
       w[0] = new window(-25, 5, -15, 25, 0);
       w[1] = new window(40, 55, -15, 30, 1);
       w[2] = new window(15, 36, -5, 15, 1);
       
       drawWin(w[0].xwmin, w[0].xwmax, w[0].ywmin, w[0].ywmax, w[0].selected, g);
       drawWin(w[1].xwmin, w[1].xwmax, w[1].ywmin, w[1].ywmax, w[1].selected, g);
       drawWin(w[2].xwmin, w[2].xwmax, w[2].ywmin, w[2].ywmax, w[2].selected, g);

      

  
       int i, k=0, last_k=0;
       
       
       if(c==0)
       {        
           g.setColor(Color.RED);           
           drawline(m, n, p, q, g);
       }
       
       else if(c==1)
       { 
        g.setColor(Color.RED);
        for(i=0;i<numOfWindows;i++)
           { System.out.println("i="+i);
             System.out.println(l.a1+", "+l.b1+", "+l.a2+", "+l.b2);
             l.draw = 2;
             if (w[i].selected == 0)
                 continue;    
             l.setbits(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);
             while(l.draw==2)
           {
             l.clipper(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);
             l.setbits(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);

           }
       
           if(l.draw==1)
            { for(k=last_k;k<last_k+4;k++)
             p2[k] = l.p1[k%4];
            }
           last_k = k; 
 
           l.a1 = m;
           l.b1 = n;
           l.a2 = p;
           l.b2 = q;

            }
        
         for(i=0;i<last_k;i++)
             System.out.println("p2 = "+p2[i]+" ");
         for(k=0; k<last_k; k=k+4)
             drawline(p2[k], p2[k+1], p2[k+2], p2[k+3], g);
       }
    }
    else
     {
       int numOfWindows = 2;
       window[] w = new window[2];
       w[0] = new window(-25, 5, -15, 30, 1);
       w[1] = new window(-10, 20, -5, 20, 1);
       
       int i, k=0, last_k=0;
       
       
       if(c==0)
       {   
           drawWin(w[0].xwmin, w[0].xwmax, w[0].ywmin, w[0].ywmax, w[0].selected, g);
           drawWin(w[1].xwmin, w[1].xwmax, w[1].ywmin, w[1].ywmax, w[1].selected, g); 
           g.setColor(Color.RED);           
           drawline(m, n, p, q, g);
       }
       
       else if(c==1)
       {
        g.setColor(Color.GREEN);
        drawline(w[0].xwmin, w[0].ywmax, w[0].xwmax, w[0].ywmax, g);
        drawline(w[0].xwmax, w[0].ywmax, w[0].xwmax, w[1].ywmax, g);
        drawline(w[0].xwmax, w[1].ywmax, w[1].xwmax, w[1].ywmax, g);
        drawline(w[1].xwmax, w[1].ywmax, w[1].xwmax, w[1].ywmin, g);
        drawline(w[1].xwmax, w[1].ywmin, w[0].xwmax, w[1].ywmin, g);
        drawline(w[0].xwmax, w[1].ywmin, w[0].xwmax, w[0].ywmin, g);
        drawline(w[0].xwmax, w[0].ywmin, w[0].xwmin, w[0].ywmin, g);
        drawline(w[0].xwmin, w[0].ywmin, w[0].xwmin, w[0].ywmax, g);


        g.setColor(Color.RED);
        for(i=0;i<numOfWindows;i++)
           { System.out.println("i="+i);
             System.out.println(l.a1+", "+l.b1+", "+l.a2+", "+l.b2);
             l.draw = 2;
             if (w[i].selected == 0)
                 continue;    
             l.setbits(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);
             while(l.draw==2)
           {
             l.clipper(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);
             l.setbits(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);

           }
       
           if(l.draw==1)
            { for(k=last_k;k<last_k+4;k++)
             p2[k] = l.p1[k%4];
            }
           last_k = k; 
 
           l.a1 = m;
           l.b1 = n;
           l.a2 = p;
           l.b2 = q;

            }
        
         for(i=0;i<last_k;i++)
             System.out.println("p2 = "+p2[i]+" ");
         for(k=0; k<last_k; k=k+4)
             drawline(p2[k], p2[k+1], p2[k+2], p2[k+3], g);
       }


       else if(c==2)
       { 
        g.setColor(Color.GREEN);
        drawline(w[0].xwmin, w[0].ywmax, w[0].xwmax, w[0].ywmax, g);
        drawline(w[0].xwmax, w[0].ywmax, w[0].xwmax, w[1].ywmax, g);
        drawline(w[0].xwmax, w[1].ywmax, w[1].xwmin, w[1].ywmax, g);
        drawline(w[1].xwmin, w[1].ywmax, w[1].xwmin, w[1].ywmin, g);
        drawline(w[1].xwmin, w[1].ywmin, w[0].xwmax, w[1].ywmin, g);
        drawline(w[0].xwmax, w[1].ywmin, w[0].xwmax, w[0].ywmin, g);
        drawline(w[0].xwmax, w[0].ywmin, w[0].xwmin, w[0].ywmin, g);
        drawline(w[0].xwmin, w[0].ywmin, w[0].xwmin, w[0].ywmax, g);
        
        
        int[] p3 = new int[10];
        int[] p4 = new int[10];
        int p3emp = 1, p4emp = 1;
        g.setColor(Color.RED);
        for(i=0;i<numOfWindows;i++)
           { System.out.println("i="+i);
             System.out.println(l.a1+", "+l.b1+", "+l.a2+", "+l.b2);
             l.draw = 2;
             if (w[i].selected == 0)
                 continue;    
             l.setbits(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);
             while(l.draw==2)
           {
             l.clipper(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);
             l.setbits(w[i].xwmin, w[i].xwmax, w[i].ywmin, w[i].ywmax);

           }
       
           if(l.draw==1)
            { for(k=0;k<4;k++)
               { if(i==0)
                   p3[k] = l.p1[k];
                 else
                   p4[k] = l.p1[k];
               }
            }
           last_k = k; 
           
           l.a1 = m;
           l.b1 = n;
           l.a2 = p;
           l.b2 = q;

            }
        for(k=0;k<10;k++)
        {
          if(p3[k]!=0)
          { p3emp = 0;
            break;
          }
        }
        for(k=0;k<10;k++)
        {
          if(p4[k]!=0)
          { p4emp = 0;
            break;
          }
        }

        System.out.println(p3[0]+"p3 "+p3[1]+" "+p3[2]+" "+p3[3]);        
        System.out.println(p4[0]+"p4 "+p4[1]+" "+p4[2]+" "+p4[3]);        
        System.out.println("p3emp = "+p3emp+"p4emp= "+p4emp);
         if ((p3emp!=0)||(p4emp!=0))
        {  

         if (p4emp==1)
         {
           for(k=0;k<4;k++)
               p2[k] = p3[k];
           drawline(p2[0], p2[1], p2[2], p2[3], g);

         }
         else if (p3emp==1)
             System.out.println("do nothing");
        }  
         
         else if((p4[0]>=w[0].xwmax)||(p4[2]>=w[0].xwmax))
         {
           p2[0] = p3[0];
           p2[1] = p3[1];
           p2[2] = p4[0];
           p2[3] = p4[1];
           drawline(p2[0], p2[1], p2[2], p2[3], g);
         }
         else if ((p4[0]<=w[0].xwmax)||(p4[2]<=w[0].xwmax))
         {
           p2[0] = p3[0];
           p2[1] = p3[1];
           p2[2] = p4[0];
           p2[3] = p4[1];
           drawline(p2[0], p2[1], p2[2], p2[3], g);

           p2[4] = p4[2];
           p2[5] = p4[3];
           p2[6] = p3[2];
           p2[7] = p3[3];
           drawline(p2[4], p2[5], p2[6], p2[7], g);
           
           for (i=0;i<8;i++)
               System.out.println("p2= "+p2[i]);

         }
             
       
       
       }
       
       
       }
   
    
    
} 
    
    public void drawWin(int x1, int x2, int y1, int y2, int s, Graphics g)
    {
      if(s==1)
          g.setColor(Color.GREEN);
      else
          g.setColor(Color.GRAY);
       
      drawline(x1, y2, x2, y2, g);
      drawline(x2, y2, x2, y1, g);
      drawline(x2, y1, x1, y1, g);
      drawline(x1, y1, x1, y2, g);
    
    
    }
    
    public void setLPixel(int x, int y, Graphics g)
    { int cell = 10;
      int xpos, ypos;
      int originX = (getX()+getWidth())/2;
      int originY = (getY()+getHeight())/2;         
      xpos = originX+cell*x;
      ypos = originY-cell*y;
      g.fillRect(xpos, ypos, cell, cell);
    }
    
    

    public void drawline(int x1, int y1, int x2, int y2, Graphics g)
    {   
        int dx, dy, p, p_inc_lower, p_inc_upper, x, y, xend, yend;
        dx = Math.abs((x2 - x1));
        dy = Math.abs((y2 - y1));
       // x = x1;
      //  y = y1;
        float slope;
        slope = (float)(y2-y1)/(float)(x2-x1);
        System.out.println("m="+slope);
       
     
        if(slope>=0 && slope <= 1)               //working
        {   p = 2*dy - dx;
            p_inc_lower = 2*dy;
            p_inc_upper = 2*(dy-dx);
            
             if(x1>x2)
           {
             x = x2;
             y = y2;
             xend = x1;
       
           }
        
            else
          {
             x = x1;
             y = y1;
             xend = x2;
         
           } 
            setLPixel(x, y, g); 
        
        
          while(x<xend)
          {  
             x = x+1;
             if (p < 0)
               p += p_inc_lower;
             else
             {   
                 y = y+1;                    // change to y-- for y2-y1 < 0
                 p += p_inc_upper;
             }
           
             setLPixel(x, y, g);          
        
           }
       
        }
       
        else if (slope<0 && slope >= -1)        //working
        {
            p = 2*dy - dx;
            p_inc_lower = 2*dy;
            p_inc_upper = 2*(dy-dx);
            
             if(x1>x2)
           {
             x = x2;
             y = y2;
             xend = x1;
       
           }
        
            else
          {
             x = x1;
             y = y1;
             xend = x2;
         
           } 
            setLPixel(x, y, g);
            
          while(x<xend)
          {  
           x = x+1;
           if (p < 0)
               p += p_inc_lower;
           else
           {   
               y = y-1;                    // change to y-- for y2-y1 < 0
               p += p_inc_upper;
           }
           
           setLPixel(x, y, g);
        
        
           }
      
        }
       
        else if (slope<-1)
        { 
           if(y1>y2)
          {
           x = x2;
           y = y2;
           yend = y1;
       
        }
        
        else
        {
           x = x1;
           y = y1;
           yend = y2;
         
        } 
           p = 2*dx - dy;
            p_inc_lower = 2*dx;
            p_inc_upper = 2*(dx-dy);
            
           
           setLPixel(x, y, g);
           
            while(y<yend)
          {  
           y = y+1;
           if (p < 0)
               p += p_inc_lower;
           else
           {   
               x = x-1;                    // change to y-- for y2-y1 < 0
               p += p_inc_upper;
           }
           
            setLPixel(x, y, g);        
        
           }
      
        }
       
        else if (slope>1)
        {
           if(y1>y2)
          {
           x = x2;
           y = y2;
           yend = y1;
       
          }
        
          else
          {
           x = x1;
           y = y1;
           yend = y2;
         
          } 
            p = 2*dx - dy;
            p_inc_lower = 2*dx;
            p_inc_upper = 2*(dx-dy);
            
           setLPixel(x, y, g);
           
          while(y<yend)
          {  
           y = y+1;
           if (p < 0)
               p += p_inc_lower;
           else
           {   
               x = x+1;                    // change to y-- for y2-y1 < 0
               p += p_inc_upper;
           }
           
           setLPixel(x, y, g);
        
        
           }
      
        }
                   
    }
}