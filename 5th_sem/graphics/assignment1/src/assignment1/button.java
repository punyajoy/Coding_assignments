/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
 
/**
 *
 * @author Punyajoy Saha
 */
public class button extends Applet implements ActionListener{
 
        String actionMessage="";
        int r=10;
        int s=1;
        int m=0;
        int emotion=0;
        public void init(){
                //create Buttons
                Button Button1 = new Button("Ok");
                Button Button2 = new Button("Cancel");
               
                //add Buttons
                add(Button1);
                add(Button2);
               
                //set action listeners for buttons
                Button1.addActionListener(this);
                Button2.addActionListener(this);
        }
       
        public void paint(Graphics g){
                g.drawString(actionMessage,10,50);
        }
       
        public void actionPerformed(ActionEvent ae){
               
                /*s
                 * Get the action command using
                 * String getActionCommand() method.
                 */
               
                String action = ae.getActionCommand();
               
                if(action.equals("Zoom in"))
                {actionMessage = "Zoom in";
                          r=r+1;
                          s=s+1;
                }
                else if(action.equals("Zoom out"))
                {actionMessage = "Zoom out";
                if (r>1){
                   r=r-1;
                 }
                if (s>1){
                   s=s-1;
                 }
                }
                else if(action.equals("move_left"))
                {
                    m=m-5;
                }
                else if(action.equals("move_right"))
                {
                    m=m+5;
                }
                else if(action.equals("copy"))
                {
                    emotion=1;
                }
                else if(action.equals("upset"))
                {
                    emotion=2;
                }
                else if(action.equals("angry"))
                {
                    emotion=3;
                }
                else if(action.equals("cunning"))
                {
                    emotion=4;
                }
                else if(action.equals("fear"))
                {
                    emotion=5;
                }
                else if(action.equals("surprise"))
                {
                    emotion=6;
                }
                else if(action.equals("sad"))
                {
                    emotion=7;
                }
                
                       
                
                
                repaint();
        }
}