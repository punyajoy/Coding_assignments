import java.applet.Applet;
import java.awt.Button;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
 
/*
<applet code="HandleActionEventExample" width=200 height=200>
</applet>
*/
 
public class multiClipButton extends Applet implements ActionListener

{       int c = 0;
 
        String actionMessage="";
       
        public void init(){
               
        }
       
        public void paint(Graphics g){
                g.drawString(actionMessage,10,50);
        }
       
        public void actionPerformed(ActionEvent ae){
               
                /*
                 * Get the action command using
                 * String getActionCommand() method.
                 */
               
                String action = ae.getActionCommand();
                
                
                 if(action.equals("Clip line(s) with +"))
                 {
                     c = 1;
                     repaint();
                 }
                 else if (action.equals("Clip line(s) with -"))
                 {
                     c = 2;
                     repaint();
                 }
        }
}