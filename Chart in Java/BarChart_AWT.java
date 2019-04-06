import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;
import org.jfree.ui.ApplicationFrame;
import org.jfree.ui.RefineryUtilities;

import java.sql.*;

public class BarChart_AWT extends ApplicationFrame
{
   public BarChart_AWT( String applicationTitle , String chartTitle )
   {
      super( applicationTitle );
      JFreeChart barChart = ChartFactory.createBarChart(
         chartTitle,
         "Batch(Year)",
         "Average Percentage",
         createDataset(),
         PlotOrientation.VERTICAL,
         true, true, false);

      ChartPanel chartPanel = new ChartPanel( barChart );
      chartPanel.setPreferredSize(new java.awt.Dimension( 560 , 367 ) );
      setContentPane( chartPanel );
   }
   private CategoryDataset createDataset( )
   {
       ResultSet rs;
       PreparedStatement smt;
       int tot,min,maxx,i,avg=0,cnt;
       final DefaultCategoryDataset dataset =
      new DefaultCategoryDataset( );
       try{
Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
Connection con=DriverManager.getConnection("jdbc:odbc:SchoolManagement");
//Getting min. year
smt=con.prepareStatement("select min(YEAR) from Result");
rs=smt.executeQuery();
rs.next();
min=rs.getInt(1);
//getting max. year
smt=con.prepareStatement("select max(YEAR) from Result");
rs=smt.executeQuery();
rs.next();
maxx=rs.getInt(1);

//System.out.println(maxx+"\n");
for(i=min;i<=maxx;i++)
{
    tot=0;cnt=0;
smt=con.prepareStatement("select * from Result where Year=?");
smt.setString(1,i+"");
rs=smt.executeQuery();
while(rs.next())
{
    cnt++;
    tot+=rs.getInt("TOTAL");
}
if(cnt!=0){
      dataset.addValue(tot/cnt,"Year",i+"");
}
}

con.close();
}//try
catch(Exception ee){System.out.println(ee);}
return dataset;
   }
   public static void main( String[ ] args )
   {
      BarChart_AWT chart = new BarChart_AWT("Performance Analysis","Batchwise Performance Analysis");
      chart.pack( );
      RefineryUtilities.centerFrameOnScreen( chart );
      chart.setVisible( true );
   }
}
