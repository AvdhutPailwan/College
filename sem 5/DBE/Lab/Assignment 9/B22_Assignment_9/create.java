import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class create {
	public static void main(String[] args) throws IOException {

		// Load the PostgreSQL JDBC driver class
		try {
			Class.forName("org.postgresql.Driver");
		} catch (ClassNotFoundException cnfe) {
			System.out.println("Could not find the JDBC driver!");
			System.exit(1);
		}

		// Enter the connection details
		String hostname = "localhost"; // If PostgreSQL is running on some other machine enter the IP address of the
										// machine here
		String username = "Avdhut@TYB22"; // Enter your PostgreSQL username
		String password = "pass123"; // Enter your PostgreSQL password
		String dbName = "asp_salemaster"; // Enter the name of the database that has the university tables.
		String connectionUrl = "jdbc:postgresql://" + hostname + "/" + dbName;
		Connection conn = null;

		// Connect to the database
		try {
			conn = DriverManager.getConnection(connectionUrl, username, password);
			System.out.println("Connected successfullly");
		} catch (SQLException sqle) {
			System.out.println("Connection failed");
			System.out.println(sqle);

			System.exit(1);
		}
		try {

			PreparedStatement pstm1 = conn.prepareStatement(
					"create table clientMaster(client_no varchar(6),name  varchar(20),city  varchar(15),pincode  integer,state varchar(15),bal_due numeric(10,2),primary key(client_no))");
			PreparedStatement pstm2 = conn.prepareStatement(
					"create table productMaster(product_no varchar(10),prodName varchar(20),profit_percent  integer,unit_measure varchar(10),qty_on_hand integer,Reoder_lvl integer,sell_price integer,cost_price integer,primary key(product_no ))");
			PreparedStatement pstm3 = conn.prepareStatement(
					"create table productOrderMaster(product_no varchar(10),client_no varchar(6),orderQty  integer,primary key(product_no,client_no ))");

			pstm1.executeUpdate();
			pstm2.executeUpdate();
			pstm3.executeUpdate();

		} catch (SQLException sqle) {
			System.out.println(sqle);
			System.exit(1);
		}

	}

}
