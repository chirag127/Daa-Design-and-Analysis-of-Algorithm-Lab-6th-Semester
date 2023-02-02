write the code for practical for my wt assignement 

10. Install a database (Mysql or Oracle). Create a table which should contain at least the following fields: name, password, email-id, phone number Write a java program/servlet/JSP to connect to that database and extract data from the tables and display them. Insert the details of the users who register with the web site, whenever a new user clicks the submit button in the registration page.
 Here's the code for a Java Servlet that connects to a MySQL database, extracts data from a table, and displays it:

```
import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class DisplayDataServlet extends HttpServlet {
  public void doGet(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {
    response.setContentType("text/html");
    PrintWriter out = response.getWriter();
    out.println("<html><body>");

    try {
      Class.forName("com.mysql.jdbc.Driver");
      Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/database_name", "user", "password");
      Statement stmt = conn.createStatement();
      ResultSet rs = stmt.executeQuery("SELECT name, password, email_id, phone_number FROM table_name");
      out.println("<table border=1>");
      out.println("<tr><th>Name</th><th>Password</th><th>Email ID</th><th>Phone Number</th></tr>");
      while (rs.next()) {
        out.println("<tr><td>" + rs.getString("name") + "</td><td>" + rs.getString("password") + "</td><td>" + rs.getString("email_id") + "</td><td>" + rs.getString("phone_number") + "</td></tr>");
      }
      out.println("</table>");
      out.println("</html></body>");
      rs.close();
      stmt.close();
      conn.close();
    } catch (Exception e) {
      out.println("Error: " + e.getMessage());
    }

    out.close();
  }
}
```

And here's the code for inserting a new user's details into the table when they submit the registration form:

```
import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class RegisterServlet extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {
    String name = request.getParameter("name");
    String password = request.getParameter("password");
    String email_id = request.getParameter("email_id");
    String phone_number = request.getParameter("phone_number");

    try {
      Class.forName("com.mysql.jdbc.Driver");
      Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/database_name", "user", "password");
      Statement stmt = conn.createStatement();
      stmt.executeUpdate("INSERT INTO table_name (name, password, email_id, phone_number) VALUES ('" + name + "', '" + password + "', '" + email_id + "', '" + phone_number + "')");
      stmt.close();
      conn.close();
    } catch (Exception e) {
      response.sendError(500, e.getMessage());
    }

    response.sendRedirect("/display");
  }
}
```
/*


```
import java.io.*;
```
This line imports the `java.io` package, which contains classes for input/output operations.

```
import java.sql.*;
```
This line imports the `java.sql` package, which contains classes for connecting to and working with databases.

```
import javax.servlet.*;
import javax.servlet.http.*;
```
These two lines import the `javax.servlet` and `javax.servlet.http` packages, which contain classes for building web applications using servlets.

```
public class DisplayDataServlet extends HttpServlet {
```
This line defines a new servlet class called `DisplayDataServlet`, which extends the `HttpServlet` class. This means that `DisplayDataServlet` is a subclass of `HttpServlet` and inherits all of its methods and properties.

```
  public void doGet(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {
```
This line defines the `doGet` method, which is called whenever a GET request is made to the servlet. The `HttpServletRequest` and `HttpServletResponse` objects are passed as arguments, which represent the request and response respectively. The `throws` clause declares that the method may throw a `ServletException` or an `IOException`.

```
    response.setContentType("text/html");
```
This line sets the content type of the response to "text/html", which means that the response will contain HTML content.

```
    PrintWriter out = response.getWriter();
```
This line gets a `PrintWriter` object from the response, which is used to write the HTML content of the response.

```
    out.println("<html><body>");
```
This line writes the opening tags for an HTML document to the response.

```
    try {
      Class.forName("com.mysql.jdbc.Driver");
```
This line loads the MySQL JDBC driver class, which is used to connect to a MySQL database.

```
      Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/database_name", "user", "password");
```
This line creates a `Connection` object by calling the `getConnection` method of the `DriverManager` class. The method is passed three arguments: the URL of the database, the username, and the password.

```
      Statement stmt = conn.createStatement();
```
This line creates a `Statement` object from the `Connection` object, which is used to execute SQL statements.

```
      ResultSet rs = stmt.executeQuery("SELECT name, password, email_id, phone_number FROM table_name");
```
This line executes a SELECT statement using the `Statement` object and gets a `ResultSet` object, which contains the results of the query.

```
      out.println("<table border=1>");
      out.println("<tr><th>Name</th><th>Password</th><th>Email ID</th><th>Phone Number</th></tr>");
```
These two lines write the opening tags for a table and a table row to the response. The table row contains the headers for the table columns.

```
      while (rs.next()) {
        out.println("<tr><td>" + rs.getString("name") + "</td><td>" + rs.getString("password") + "</td><td>" + rs.getString("email_id") + "</td><td>" + rs.getString("phone_number") + "</td></tr>");
      }
```
This line uses a `while` loop to iterate over the `ResultSet` object and write a table row for each row in the results. The `rs.getString` method is used to get the values of the `name`, `password`, `email_id`, and `phone_number` columns for each row.

```
      out.println("</table>");
      out.println("</html></body>");
```
These two lines write the closing tags for the table and the HTML document to the response.

```
      rs.close();
      stmt.close();
      conn.close();
```
These three lines close the `ResultSet`, `Statement`, and `Connection` objects, which are no longer needed.

```
    } catch (Exception e) {
      out.println("Error: " + e.getMessage());
    }
```
This `catch` block catches any exceptions that may be thrown during the execution of the code and writes an error message to the response.

```
    out.close();
```
This line closes the `PrintWriter` object, which is used to write the response.

---

```
public class RegisterServlet extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {
    String name = request.getParameter("name");
    String password = request.getParameter("password");
    String email_id = request.getParameter("email_id");
    String phone_number = request.getParameter("phone_number");
```
This code defines a new servlet class called `RegisterServlet`, which extends the `HttpServlet` class and implements the `doPost` method. The `doPost` method is called whenever a POST request is made to the servlet. The method gets the values of the `name`, `password`, `email_id`, and `phone_number` parameters from the request.

```
    try {
      Class.forName("com.mysql.jdbc.Driver");
      Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/database_name", "user", "password");
      Statement stmt = conn.createStatement();
      stmt.executeUpdate("INSERT INTO table_name (name, password, email_id, phone_number) VALUES ('" + name + "', '" + password + "', '" + email_id + "', '" + phone_number + "')");
      stmt.close();
      conn.close();
    } catch (Exception e) {
      response.sendError(500, e.getMessage());
    }
```
This code is similar to the code in the `DisplayDataServlet` class, but instead of executing a SELECT statement, it executes an INSERT statement to insert a new row into the table with the values of the `name`, `password`, `email_id`, and `phone_number` parameters. If an exception is thrown during the execution of the code, a 500 Internal Server Error response is sent with the error message.

```
    response.sendRedirect("/display");
  }
}
```
This line sends a redirect response to the client, which causes the client's browser to request the "/display" URL.
*/
