package com.database_connectivity;

import java.io.IOException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
public class Select {
	public static void main(String[] args) throws IOException{

		//Load the PostgreSQL JDBC driver class
	    try{
	        Class.forName("org.postgresql.Driver");
	    } catch (ClassNotFoundException cnfe){
	        System.out.println("Could not find the JDBC driver!");
	        System.exit(1);
	    }

	    Database db = new Database();
	    var conn = db.connect();
	    try {
	       	       
	        PreparedStatement pstmt3=conn.prepareStatement("select * from department");
            
            ResultSet rs = pstmt3.executeQuery();

            while(rs.next()){
                   String title = rs.getString("dept_name");
                   System.out.println(title);
                   String title1 = rs.getString("building");                           
                   System.out.println(title1);
                   int title2 = rs.getInt("budget");                           
                   System.out.println(title2);
            }
            
            conn.close();
	    } catch (SQLException sqle) {
	           System.out.println(sqle);
	           System.exit(1);
	    }
	
	}	
	
}
