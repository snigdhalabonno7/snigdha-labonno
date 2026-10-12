import java.sql.*;

public class DBJava
{
	public static void main(String[] args) throws Exception
	{
		// System.out.println("Database Connection and Query Execution!!");
		String sql = "select ename from emp where empno = 7369";
		String url = "jdbc:oracle:thin:@localhost:1521:XE";
		String username = "scott";
		String password = "tiger";
		Connection con = DriverManager.getConnection(url, username, password);
		Statement st = con.createStatement();
		ResultSet rs = st.executeQuery(sql);
		rs.next();
		System.out.println(rs.getString("ename"));
	}
}