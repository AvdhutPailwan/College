package com.database_connectivity;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Database {
	private final String url = "jdbc:postgresql://localhost/asp_salemaster";
	private final String user = "Avdhut@TYB22";
	private final String password = "pass123";
	private Connection conn = null;

	public void connect() throws SQLException {
		this.conn = DriverManager.getConnection(url, user, password);
		System.out.println("Connected to the PostgreSQL server successfully.");
	}

	public void create() throws SQLException {

		PreparedStatement pstm1 = conn.prepareStatement(
				"create table clientMaster(client_no varchar(6),name  varchar(20),city  varchar(15),pincode  integer,state varchar(15),bal_due numeric(10,2),primary key(client_no))");
		PreparedStatement pstm2 = conn.prepareStatement(
				"create table productMaster(product_no varchar(10),prodName varchar(20),profit_percent  integer,unit_measure varchar(10),qty_on_hand integer,Reoder_lvl integer,sell_price integer,cost_price integer,primary key(product_no ))");
		PreparedStatement pstm3 = conn.prepareStatement(
				"create table productOrderMaster(product_no varchar(10),client_no varchar(6),orderQty  integer,primary key(product_no,client_no ))");

		pstm1.executeUpdate();
		pstm2.executeUpdate();
		pstm3.executeUpdate();
	}

	public void closeConnection() throws SQLException {
		this.conn.close();
	}

	public void insert() throws SQLException{
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
	}

}
