import java.applet.Applet;
import java.awt.*;
import java.util.Scanner;
import java.lang.*;


public class view extends viewButton 
{
    int x1, y1, x2, y2;
   
    int k, iter, dx, dy;
    int choice, cell = 10;
    float slope,sx,sy;
    int xwmin = 10, xwmax = 60, ywmin = 15, ywmax = 65, xvmin = 70, xvmax = 105, yvmin = 5, yvmax = 25;

    public void init()
    {
       Color myblack = new Color(0,0,0);
       setBackground(myblack);
        
       Button copy = new Button("Copy object(s)");
       add(copy);
       copy.addActionListener(this);
       copy.addActionListener(this);

    }

    public void paint(Graphics g)
    {
       int originX = getX();
       int originY = (getY()+getHeight());
       int screenw = getWidth();
       int screenh = getHeight();
       System.out.println("xc="+originX+"yc="+originY);
              
       
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
       
       
       g.setColor(Color.GREEN);
       drawline(xwmin, ywmax, xwmax, ywmax, g);
       drawline(xwmax, ywmax, xwmax, ywmin, g);
       drawline(xwmax, ywmin, xwmin, ywmin, g);
       drawline(xwmin, ywmin, xwmin, ywmax, g);
       
       g.setColor(Color.RED);
       drawline(xvmin, yvmax, xvmax, yvmax, g);
       drawline(xvmax, yvmax, xvmax, yvmin, g);
       drawline(xvmax, yvmin, xvmin, yvmin, g);
       drawline(xvmin, yvmin, xvmin, yvmax, g);   
       
       g.setColor(Color.BLUE);
       circle(35, 35, 15, g);   
       
       sx = (float)(xvmax-xvmin)/(float)(xwmax-xwmin);
       sy = (float)(yvmax-yvmin)/(float)(ywmax-ywmin);
       System.out.println("sx="+sx+"sy= "+sy);
       
    }
    
    public void setLPixel(int x, int y, Graphics g)
    { 
      int xpos, ypos;
      int originX = getX();
      int originY = getY()+getHeight();         
      xpos = originX+cell*x;
      ypos = originY-cell*y;
      g.fillRect(xpos, ypos, cell, cell);
    }
   

    
    public void setCPixel(int x, int y,Graphics g)
    { 
      int xpos, xnew, ynew, ypos, xnewpos, ynewpos;
      int originX = getX();
      int originY = (getY()+getHeight());
      
      if(flag==0)
      {
      xpos = originX+cell*x;
      ypos = originY-cell*y;
      g.fillRect(xpos, ypos, cell, cell);  
      }
      
      else
      {
        xpos = originX+cell*x;
        ypos = originY-cell*y;
        g.fillRect(xpos, ypos, cell, cell);  
      
        xnew = xvmin + (int)((x - xwmin)*sx);
        ynew = yvmin + (int)((y - xwmin)*sy);
        xnewpos = originX+cell*xnew;
        ynewpos = originY-cell*ynew;
        g.fillRect(xnewpos, ynewpos, cell, cell);  
        System.out.println("x="+ xnew+"y="+ynew);
      }
      
    }
    
    
    public void circleplot(int xc, int yc, int x, int y, Graphics g)
    {
      setCPixel(xc+x, yc+y, g);
      setCPixel(xc-x, yc+y, g);
      setCPixel(xc+x, yc-y, g);
      setCPixel(xc-x, yc-y, g);
      setCPixel(xc+y, yc+x, g);
      setCPixel(xc-y, yc+x, g);
      setCPixel(xc+y, yc-x, g);
      setCPixel(xc-y, yc-x, g);
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
    
    

    
    public void circle(int xcorr, int ycorr, int r, Graphics g)
    {  
       
       
       int x = 0;
       int y = r;
       int p = 1-r;
       
       circleplot(xcorr, ycorr, x, y, g);
        
       while(x<y)
       {
         x = x+1;
         if (p<0)
             p = p+2*x+1;
         else
         {
           y = y-1;
           p = p+2*x+1-2*y;
         }
       circleplot(xcorr, ycorr, x, y, g);
       }
   
    }    
}
