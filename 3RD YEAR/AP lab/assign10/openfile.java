
import java.applet.AppletContext;
import java.awt.Graphics;
import java.net.URL;

import javax.swing.JApplet;

public class openfile extends JApplet {

  public void paint(Graphics g) {
    AppletContext ac = getAppletContext();
    try {
      URL url = getCodeBase();
      ac.showDocument(url);
    } catch (Exception e) {
      showStatus("Exception: " + e);
    }
    g.drawString("ShowDocument Applet", 10, 25);
  }
}

