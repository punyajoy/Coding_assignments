/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package boundaryfillalgorithm;

/**
 *
 * @author Soumen Kaity
 */


import java.awt.*;
public class Grid
{
    private int x1,x2,y1,y2;
    public int bh=5,bw=5;
    private int max_width,max_height,min_width,min_height;
    private Graphics g;

    
    
    public void setData(int max_width,int max_height,int min_width,int min_height,Graphics g)
    {
        this.max_height=max_height;
        this.max_width=max_width;
        this.min_height=min_height;
        this.min_width=min_width;
        this.g=g;
    }
    public void drawHorizontal()
    {
        g.setColor(Color.BLACK);
        x1=min_width;
        x2=max_width;
        y1=min_height;
        y2=min_height;
        //draw horizontal lines
        while(y1<=max_height)
        {
            y1=y1+bh;
            y2=y1;
            g.drawLine(x1,y1,x2,y2);

        }
    }
    public void drawVertical()
    {
        g.setColor(Color.BLACK);
        //draw vertical lines
        x1=min_width;
        x2=min_width;
        y1=min_height;
        y2=max_height;

        while(x1<=max_width)
        {
            x1=x1+bw;
            x2=x1;
            g.drawLine(x1,y1,x2,y2);
        }
    }
}


