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
import java.util.*;
import java.math.*;
/**
 *
 * @author Soumen Kaity
 */
public class Circle
{
    private int  xc,yc,r,origin_x,origin_y;
    private Graphics g;
    private int bw,bh;
    
    public void setData(int r,int orix, int oriy, int bw,int bh, Graphics g)
    {
        origin_x=orix;
        origin_y=oriy;
        this.bw=bw;
        this.bh=bh;
        
        this.r=r;
        
        this.g=g;
    }
    public void draw()
    {
        g.setColor(Color.BLUE);
        int p = 1-r;
        int x1 = 0;
        int y1 = r;
        do
        {
            g.fillRect(origin_x+(int)y1*bw, origin_y+(int)x1*bw, bw, bh);
            g.fillRect(origin_x+(int)x1*bw, origin_y+(int)y1*bw, bw, bh);
            g.fillRect(origin_x+(int)x1*bw, origin_y-(int)y1*bw, bw, bh);
            g.fillRect(origin_x+(int)y1*bw, origin_y-(int)x1*bw, bw, bh);
            g.fillRect(origin_x-(int)y1*bw, origin_y-(int)x1*bw, bw, bh);
            g.fillRect(origin_x-(int)x1*bw, origin_y-(int)y1*bw, bw, bh);
            g.fillRect(origin_x+(int)x1*bw, origin_y-(int)y1*bw, bw, bh);
            g.fillRect(origin_x-(int)x1*bw, origin_y+(int)y1*bw, bw, bh);
            g.fillRect(origin_x-(int)y1*bw, origin_y+(int)x1*bw, bw, bh);
            
            
            x1++;
            if(p<0)
            {
                p=p+2*x1+1;
            }
            else
            {
                y1--;
                p=p+2*(x1-y1)+1;
            }
            
        } while (x1<=y1);
        
    }
}
