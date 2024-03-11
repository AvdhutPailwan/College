import java.io.IOException;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Connect {
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

		// Connect to the database
		try {
			DriverManager.getConnection(connectionUrl, username, password);
			System.out.println("Connected successfullly");
		} catch (SQLException sqle) {
			System.out.println("Connection failed");
			System.out.println(sqle);

			System.exit(1);
		}

	}

}
