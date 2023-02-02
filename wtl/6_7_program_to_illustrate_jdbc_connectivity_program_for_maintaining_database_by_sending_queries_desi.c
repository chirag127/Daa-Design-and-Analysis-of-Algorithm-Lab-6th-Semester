write the code for practical for my wt assignement 

7. Program to illustrate JDBC connectivity. Program for maintaining database by sending queries. Design and implement a simple servlet book query with the help of JDBC & SQL. Create MS Access Database, Create on ODBC link, Compile & execute JAVA JDVC Socket.
 
```
import java.sql.*;

public class JDBCExample {
   // JDBC driver name and database URL
   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
   static final String DB_URL = "jdbc:mysql://localhost/dbname";

   //  Database credentials
   static final String USER = "username";
   static final String PASS = "password";

   public static void main(String[] args) {
   Connection conn = null;
   Statement stmt = null;
   try{
      // Register JDBC driver
      Class.forName("com.mysql.jdbc.Driver");

      // Open a connection
      System.out.println("Connecting to database...");
      conn = DriverManager.getConnection(DB_URL,USER,PASS);

      // Execute a query
      System.out.println("Creating statement...");
      stmt = conn.createStatement();
      String sql;
      sql = "SELECT id, first, last, age FROM Employees";
      ResultSet rs = stmt.executeQuery(sql);

      // Extract data from result set
      while(rs.next()){
         //Retrieve by column name
         int id  = rs.getInt("id");
         int age = rs.getInt("age");
         String first = rs.getString("first");
         String last = rs.getString("last");

         //Display values
         System.out.print("ID: " + id);
         System.out.print(", Age: " + age);
         System.out.print(", First: " + first);
         System.out.println(", Last: " + last);
      }
      // Clean-up environment
      rs.close();
      stmt.close();
      conn.close();
   }catch(SQLException se){
      //Handle errors for JDBC
      se.printStackTrace();
   }catch(Exception e){
      //Handle errors for Class.forName
      e.printStackTrace();
   }finally{
      //finally block used to close resources
      try{
         if(stmt!=null)
            stmt.close();
      }catch(SQLException se2){
      }// nothing we can do
      try{
         if(conn!=null)
            conn.close();
      }catch(SQLException se){
         se.printStackTrace();
      }//end finally try
   }//end try
   System.out.println("Goodbye!");
}//end main
}//end JDBCExample
```
/*


1. `import java.sql.*`: This line imports the java.sql package, which contains the classes needed for JDBC (Java Database Connectivity). 

2. `public class JDBCExample`: This line declares the class `JDBCExample` with public access. 

3. `static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";`: This line declares a constant string variable `JDBC_DRIVER` and sets its value to the MySQL JDBC driver class name.

4. `static final String DB_URL = "jdbc:mysql://localhost/dbname";`: This line declares a constant string variable `DB_URL` and sets its value to the URL of the database to connect to.

5. `static final String USER = "username";`: This line declares a constant string variable `USER` and sets its value to the username for the database.

6. `static final String PASS = "password";`: This line declares a constant string variable `PASS` and sets its value to the password for the database.

7. `public static void main(String[] args)`: This line declares the `main` method that is the entry point of the program.

8. `Connection conn = null;`: This line declares a `Connection` object `conn` and initializes it to `null`.

9. `Statement stmt = null;`: This line declares a `Statement` object `stmt` and initializes it to `null`.

10. `try{`: This line starts a try block.

11. `Class.forName("com.mysql.jdbc.Driver");`: This line loads the MySQL JDBC driver class.

12. `conn = DriverManager.getConnection(DB_URL,USER,PASS);`: This line creates a connection to the database using the `DriverManager` class and the `getConnection` method.

13. `stmt = conn.createStatement();`: This line creates a `Statement` object `stmt` from the `Connection` object `conn`.

14. `String sql;`: This line declares a string variable `sql`.

15. `sql = "SELECT id, first, last, age FROM Employees";`: This line sets the value of `sql` to a SELECT statement to retrieve data from the `Employees` table.

16. `ResultSet rs = stmt.executeQuery(sql);`: This line executes the SELECT statement and stores the result in a `ResultSet` object `rs`.

17. `while(rs.next()){`: This line starts a while loop that continues as long as there are more rows in the `ResultSet` `rs`.

18. `int id  = rs.getInt("id");`: This line retrieves the value of the `id` column as an integer and stores it in the variable `id`.

19. `int age = rs.getInt("age");`: This line retrieves the value of the `age` column as an integer and stores it in the variable `age`.

20. `String first = rs.getString("first");`: This line retrieves the value of the `first` column as a string and stores it in the variable `first`.

21. `String last = rs.getString("last");`: This line retrieves the value of the `last` column as a string and stores it in the variable `last`.

22. `System.out.print("ID: " + id);`: This line outputs the value of the `id` variable.

23. `System.out.print(", Age: " + age);`: This line outputs the value of the `age` variable.

24. `System.out.print(", First: " + first);`: This line outputs the value of the `first` variable.

25. `System.out.println(", Last: " + last);`: This line outputs the value of the `last` variable.

26. `rs.close();`: This line closes the `ResultSet` `rs`.

27. `stmt.close();`: This line closes the `Statement` `stmt`.

28. `conn.close();`: This line closes the `Connection` `conn`.

29. `}catch(SQLException se){`: This line starts a catch block to handle `SQLException`s.

30. `se.printStackTrace();`: This line outputs the stack trace of the `SQLException` `se`.

31. `}catch(Exception e){`: This line starts a catch block to handle other exceptions.

32. `e.printStackTrace();`: This line outputs the stack trace of the exception `e`.

33. `finally{`: This line starts a finally block.

34. `if(stmt!=null)`: This line checks if the `Statement` `stmt` is not `null`.

35. `stmt.close();`: This line closes the `Statement` `stmt`.

36. `if(conn!=null)`: This line checks if the `Connection` `conn` is not `null`.

37. `conn.close();`: This line closes the `Connection` `conn`.

38. `System.out.println("Goodbye!");`: This line outputs the string "Goodbye!".

39. `}//end finally try`: This line ends the finally block.

40. `}//end try`: This line ends the try block.

41. `}//end main`: This line ends the `main` method.

42. `}//end JDBCExample`: This line ends the `JDBCExample` class.
*/
