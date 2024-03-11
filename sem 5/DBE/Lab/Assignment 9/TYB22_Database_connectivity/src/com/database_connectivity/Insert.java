package com.database_connectivity;
import java.io.IOException;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Insert{
	public static void main(String[] args) throws IOException{

		try{
	        Class.forName("org.postgresql.Driver");
	    } catch (ClassNotFoundException cnfe){
	        System.out.println("Could not find the JDBC driver!");
	        System.exit(1);
	    }
		
		Database db = new Database();
	    var conn = db.connect();
	    try {	      
	        PreparedStatement pstmt1=conn.prepareStatement("insert into clientMaster values('0001','Ivan','Bombay',400054,'Maharashtra',15000),('0002','Vandana','Madras',780001,'Tamilnadu',0),('0003','Pramada','Bombay',400057,'Maharashtra',5000),('0004','Basu','Bombay',400056,'Maharashtra',0),('0005','Ravi','Delhi',100001,'Null',2000),('0006','Rukmini','Bombay',400050,'Maharashtra',0)");
	        pstmt1.executeUpdate();
	    	PreparedStatement pstmt2=conn.prepareStatement("insert into productMaster values"
	    			+ "('P00001','1.44floppies',5,'piece',100,20,525,500),"
	    			+ "('P03453','Monitors',6,'piece',10,3,12000,11200),"
	    			+ "('P06734','Mouse',5,'piece',20,5,1050,500),"
	    			+ "('P07865','1.22 floppies',5,'piece',100,20,525,500),"
	    			+ "('P07868','Keyboards',2,'piece',10,3,3150,3050),"
	    			+ "('P07885','CD Driv',2.5,'piece',10,3,5250,5100),"
	    			+ "('P07965','540 HDD',4,'piece',10,3,8400,8000),"
	    			+ "('P07975','1.44 Drive',5,'piece',10,3,1050,1000),"
	    			+ "('P08865','1.22 Drive',5,'piece',2,3,1050,1000)");
	        pstmt2.executeUpdate();
	        PreparedStatement pstmt3=conn.prepareStatement("insert into  productOrderMaster values"
	    			+ "('P00001','0001',5),"
	    			+ "('P00001','0004',7),"
	    			+ "('P00001','0006',4),"
	    			+ "('P06734','0003',2),"
	    			+ "('P06734','0005',2),"
	    			+ "('P07965','0006',1),"
	    			+ "('P07965','0002',1),"
	    			+ "('P07885','0004',1)");
	        pstmt3.executeUpdate();
	        
	        conn.close();
	    }catch (SQLException err) {
	           System.out.println(err.getMessage());
	    }
	
	}	
	
}
