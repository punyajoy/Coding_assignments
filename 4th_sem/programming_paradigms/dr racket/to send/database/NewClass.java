import java.sql.*;

public class NewClass
{
    
    public static void main(String[] args)
    {
        try
        {
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
            String msAccessDBName = "G:\\TUTORIAL\\PROGRAMMING PARADIGM\\java_DB\\database\\MYDB.accdb";
            String dbURL = "jdbc:odbc:Driver={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=" + msAccessDBName + ";DriverID=22";
            //String database = 
              //"jdbc:odbc:Driver={Microsoft Access Driver (*.mdb)};DBQ=myDB.mdb;";
            //Connection conn = DriverManager.getConnection(database, "", "");
            Connection conn = DriverManager.getConnection(dbURL);
            Statement s = conn.createStatement();
            
            // create a table
            String tableName = "myTable";
            String createTable = "CREATE TABLE " + tableName + 
                                 " (id Integer, name Text(32))";
            s.execute(createTable); 
            
            
            
            
            // enter value into table
            for(int i=1; i<=25; i++)
            {
              String addRow = "INSERT INTO " + tableName + " VALUES ( " + 
                     Integer.toString(i) + ", 'Text Value " + 
                     Integer.toString(i) + "')";
              s.execute(addRow);
            }
            
            
            
            
            // Fetch table
            String selTable = "SELECT * FROM " + tableName;
            s.execute(selTable);
            
            ResultSet rs = s.getResultSet();
            while((rs!=null) && (rs.next()))
            {
                System.out.println(rs.getString(1) + " : " + rs.getString(2));
            }
            
          /* //update
            int value=10;
            int target=500;
            String updateRow = "UPDATE " + tableName + " SET" +" id=" +Integer.toString(target)+ " WHERE" +" id="+ Integer.toString(value);
            s.execute(updateRow); */
            
            //delete
            int value1=9;
            String deleteRow = "DELETE FROM " + tableName +" WHERE"+ " id="+ Integer.toString(value1);
            System.out.println(deleteRow);
            s.execute(deleteRow);
            
            
           // drop the table
            
             String dropTable = "DROP TABLE " + tableName;
               s.execute(dropTable);
                    
            
            
            // close and cleanup
            s.close();
            conn.close();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
    }
}
    
    
