/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package assignment1;

import java.applet.*;
import java.awt.*;
import java.math.*;


/**
 *
 * @author student
 */
public class Grid_display extends Applet {
             
    /**
     * Initialization method that will be called after the applet is loaded into
     * the browser.
     */
    public void init() {
        
        //setBackground(Color.red);
         int height =this.getHeight();
         int width =this.getWidth();
         int OriginX=(this.getX()+width)/2; 
         int OriginY=(this.getY()+height)/2;        
        
        // TODO start asynchronous download of heavy resources
    }
public void paint(Graphics g)
    {
       Color color1 = new Color(0,0,0);
       Color color2 = new Color(200,200,200);
       Color color3=new Color(0,0,200);
       setBackground(color1);
        
        
        
       int height =getHeight();
       int width =getWidth();
       int OriginX=(getX()+width)/2; 
       int OriginY=(getY()+height)/2;
       
       int r=20;
       //g.drawRect(100,200,130,140);
       //g.drawOval(100, 100, 100, 100);
       g.setColor(color3);
       g.drawLine(OriginX, 0, OriginX,height);
       g.drawLine(0, OriginY, width,OriginY);
       
       for (int i=0;i<width/2;i=i+r)
          {
              g.setColor(color2);
              g.drawLine(OriginX+i, 0, OriginX+i, height);
          }
       for (int i=0;i<height;i=i+r)
          {
              g.setColor(color2);
              g.drawLine(0, i, width,i);
          }
               
       
       
      g.setColor(Color.green);   
      g.fillOval( (OriginX-50),(OriginY-50), 100, 100 );
      g.setColor(Color.red);
      g.fillOval( (OriginX-25),(OriginY-25), 50, 50 );
      

       
       
       
       
       
       
    }
       
              
 
    }

    // TODO overwrite start(), stop() and destroy() methods

