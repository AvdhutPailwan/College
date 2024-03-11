package com.database_connectivity;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
	        Class.forName("org.postgresql.Driver");
	    } catch (ClassNotFoundException cnfe){
	        System.out.println("Could not find the JDBC driver!");
	        System.exit(1);
	    }
		
		Database db = new Database();
		try {
			db.connect();
			db.create();
			db.insert();
			db.closeConnection();
		} catch (Exception e) {
			System.out.println(e.getMessage());
			System.exit(0);
		}
		
	}

}
