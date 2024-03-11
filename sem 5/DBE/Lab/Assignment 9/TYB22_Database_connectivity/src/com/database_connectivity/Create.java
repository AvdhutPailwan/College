package com.database_connectivity;
import java.io.IOException;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Create{
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
	    	PreparedStatement pstm1= conn.prepareStatement("create table clientMaster(client_no varchar(6),name  varchar(20),city  varchar(15),pincode  integer,state varchar(15),bal_due numeric(10,2),primary key(client_no))");
	    	PreparedStatement pstm2= conn.prepareStatement("create table productMaster(product_no varchar(10),prodName varchar(20),profit_percent  integer,unit_measure varchar(10),qty_on_hand integer,Reoder_lvl integer,sell_price integer,cost_price integer,primary key(product_no ))");
	    	PreparedStatement pstm3= conn.prepareStatement("create table productOrderMaster(product_no varchar(10),client_no varchar(6),orderQty  integer,primary key(product_no,client_no ))");

	    	pstm1.executeUpdate();
	    	pstm2.executeUpdate();
	    	pstm3.executeUpdate();
	    	
	    	conn.close();
	    }catch (SQLException err) {
	           System.out.println(err.getMessage());
	    }
	}	
	
}
