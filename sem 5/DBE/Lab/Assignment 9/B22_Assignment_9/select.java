import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class select {
	public static void main(String[] args) throws IOException {

		try {
			Class.forName("org.postgresql.Driver");
		} catch (ClassNotFoundException cnfe) {
			System.out.println("Could not find the JDBC driver!");
			System.exit(1);
		}

		String hostname = "localhost";
		String username = "Avdhut@TYB22";
		String password = "pass123";
		String dbName = "asp_salemaster";
		String connectionUrl = "jdbc:postgresql://" + hostname + "/" + dbName;
		Connection conn = null;

		try {
			conn = DriverManager.getConnection(connectionUrl, username, password);
			System.out.println("Connected successfullly");
		} catch (SQLException sqle) {
			System.out.println("Connection failed");
			System.out.println(sqle);
			System.exit(1);
		}

		try {
			// i) Find out the names of all the clients.
			PreparedStatement pstmt1 = conn.prepareStatement("select name from clientmaster;");
			ResultSet rs1 = pstmt1.executeQuery();
			while (rs1.next()) {
				System.out.println(rs1.getString("name"));
			}

			// ii) List all the clients who are located in Bombay.
			PreparedStatement pstmt2 = conn.prepareStatement("select name from clientmaster where city='Bombay';");
			ResultSet rs2 = pstmt2.executeQuery();
			while (rs2.next()) {
				System.out.println(rs2.getString("name"));
			}

			// iii) Find the product whose selling price is greater than 2000 and less than
			// or equal to 5000.
			PreparedStatement pstmt3 = conn.prepareStatement(
					"select prodName from productmaster where sell_price > 2000 and sell_price <= 5000;");
			ResultSet rs3 = pstmt3.executeQuery();
			while (rs3.next()) {
				System.out.println(rs3.getString("prodName"));
			}

			// iv) Change the selling price of 1.44 floppy drive to Rs.1150.00
			PreparedStatement pstmt4 = conn
					.prepareStatement("update productmaster set sell_price = 1150 where prodName = '1.44 floppy';");
			try{
				pstmt4.executeQuery();
			}catch(Exception e){
				System.out.println(e.getMessage());
			}

			// v) Calculate the average price of all the products.
			PreparedStatement pstmt5 = conn.prepareStatement("select avg(sell_price) as average from productmaster;");
			ResultSet rs5 = pstmt5.executeQuery();
			while (rs5.next()) {
				System.out.println(rs5.getString("average"));
			}

			// vi) Count no. of clients from each city.
			PreparedStatement pstmt6 = conn
					.prepareStatement("select city,count(city) from clientmaster group by city;");
			ResultSet rs6 = pstmt6.executeQuery();
			while (rs6.next()) {
				System.out.print(rs6.getString("city") + " ");
				System.out.println(rs6.getString("count"));
			}

			// vii) List the products in sorted order of their description.
			PreparedStatement pstmt7 = conn.prepareStatement("select * from productmaster order by prodName;");
			ResultSet rs7 = pstmt7.executeQuery();
			while (rs7.next()) {
				System.out.print(rs7.getString("product_no") + " ");
				System.out.print(rs7.getString("prodName") + " ");
				System.out.print(rs7.getString("profit_percent") + " ");
				System.out.print(rs7.getString("unit_measure") + " ");
				System.out.print(rs7.getString("qty_on_hand") + " ");
				System.out.print(rs7.getString("Reoder_lvl") + " ");
				System.out.print(rs7.getString("sell_price") + " ");
				System.out.println(rs7.getString("cost_price"));
			}

			// viii) Find out the product names which has been ordered by Clientno 0004
			PreparedStatement pstmt8 = conn.prepareStatement(
					"select prodName from productmaster where product_no in (select product_no from productOrderMaster where client_no = '4');");
			ResultSet rs8 = pstmt8.executeQuery();
			while (rs8.next()) {
				System.out.println(rs8.getString("prodName"));
			}

			// ix) Find out the names of clients who have purchased P00001 product.
			PreparedStatement pstmt9 = conn.prepareStatement(
					"select name from clientmaster where client_no in (select client_no from productOrderMaster where product_no = 'P00001');");
			ResultSet rs9 = pstmt9.executeQuery();
			while (rs9.next()) {
				System.out.println(rs9.getString("name"));
			}

		} catch (SQLException sqle) {
			System.out.println(sqle);
			System.exit(1);
		}

	}

}
