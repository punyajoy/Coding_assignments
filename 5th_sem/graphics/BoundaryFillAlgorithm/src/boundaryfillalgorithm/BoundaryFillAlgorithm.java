/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package boundaryfillalgorithm;

import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.util.*;
import java.io.*;
import javax.imageio.ImageIO;

/**
 *
 * @author Soumen Kaity
 */
public class BoundaryFillAlgorithm extends Applet implements ActionListener
{
    private int zoomlevel=15;
    private int clip=0;
    private Button zoom_in,zoom_out,fillb,polb,cirb;
    private Grid obj;
    private Line line;
    private Circle circle;
    int fill = 0,pol = 0, cir = 0;
    BufferedImage screen;
    Graphics bufferGraphics;
    public void init()
    {
        setSize(1366, 662);
        setBackground(Color.WHITE);
        screen = new BufferedImage(1366,662,BufferedImage.TYPE_INT_RGB);
        bufferGraphics = screen.getGraphics();
        
        obj = new Grid();
        line = new Line();
        circle = new Circle();
        
//        zoom_in = new Button("ZOOM IN");
//        zoom_out = new Button("ZOOM OUT");
        fillb = new Button("FILL");
        polb = new Button("POLYGON");
        cirb = new Button("CIRCLE");
        
//        add(zoom_in);
//        add(zoom_out);
        add(fillb);
        add(polb);
        add(cirb);
        
//        zoom_in.addActionListener(this);
//        zoom_out.addActionListener(this);
        fillb.addActionListener(this);
        polb.addActionListener(this);
        cirb.addActionListener(this);
        
    }
    public void paint(Graphics g)
    {
        Graphics temp=g;
        g=bufferGraphics;
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, 1366, 662);
        //draw grid
        obj.setData(getWidth(),getHeight(),getX(),getY(),g);
        obj.drawHorizontal();
        obj.drawVertical();
        
        
        int x1 = 145, y1 = 56;
        int x2 = 110, y2 = 50;
        
        if(pol == 1)
        {
            //draw complete polygon
            line.setData(100,60,160,80,getX(),getY(), obj.bw, obj.bh, g);
            line.draw();
            line.setData(160,80,165,65,getX(),getY(), obj.bw, obj.bh, g);
            line.draw();
            line.setData(165,65,145,50,getX(),getY(), obj.bw, obj.bh, g);
            line.draw();
            line.setData(145,50,140,50,getX(),getY(), obj.bw, obj.bh, g);
            line.draw();
            line.setData(140,50,100,60,getX(),getY(), obj.bw, obj.bh, g);
            line.draw();
            
            g.setColor(Color.RED);
            floodfill(x1, y1, getX(), getY(), obj.bw, obj.bh, g);
        }
        if(cir == 1)
        {
            circle.setData(15, getX()+500, getY()+300, obj.bw, obj.bh, g);
            circle.draw();
            
            g.setColor(Color.RED);
            floodfill(x2, y2, getX(), getY(), obj.bw, obj.bh, g);
        }
        temp.drawImage(screen, 0, 0, null);
       
    }

    @Override
    public void actionPerformed(ActionEvent e) 
    {
//        if(e.getSource()==zoom_in)
//        {
//            if(zoomlevel<25)
//            {
//                obj.bh+=2;
//                obj.bw+=2;
//                zoomlevel++;
//            }
//        }
//        if(e.getSource()==zoom_out)
//        {
//            if(zoomlevel>6)
//            {
//                obj.bh-=2;
//                obj.bw-=2;
//                zoomlevel--;
//            }
//        }
        if(e.getSource()==fillb)
        {
            fill = 1 - fill;
        }
        if(e.getSource()==polb)
        {
            pol = 1 - pol;
        }
        if(e.getSource()==cirb)
        {
            cir = 1 - cir;
        }
        repaint();
    }

    public void floodfill(int x, int y, int origin_x, int origin_y, int bw, int bh, Graphics g){
        if (fill == 1)
        {
            if (screen.getRGB(origin_x+x*bw+bw/2,origin_y+y*bh+bh/2) != Color.BLUE.getRGB() && screen.getRGB(origin_x+x*bw+bw/2,origin_y+y*bh+bh/2) != Color.RED.getRGB())
            {
                g.fillRect(origin_x+(int)x*bw, origin_y+(int)y*bh, bw, bh);

                floodfill(x+1,y,origin_x,origin_y,bw,bh,g);
                floodfill(x,y+1,origin_x,origin_y,bw,bh,g);
                floodfill(x-1,y,origin_x,origin_y,bw,bh,g);
                floodfill(x,y-1,origin_x,origin_y,bw,bh,g);
            }
            else
                return;
        }
        else if(fill == 0)
        {
            if (screen.getRGB(origin_x+x*bw+bw/2,origin_y+y*bh+bh/2) == Color.BLUE.getRGB())
            {
                g.fillRect(origin_x+(int)x*bw, origin_y+(int)y*bh, bw, bh);

                floodfill(x+1,y,origin_x,origin_y,bw,bh,g);
                floodfill(x,y+1,origin_x,origin_y,bw,bh,g);
                floodfill(x-1,y,origin_x,origin_y,bw,bh,g);
                floodfill(x,y-1,origin_x,origin_y,bw,bh,g);
            }
            else
                return;
        }
            
    }
}
