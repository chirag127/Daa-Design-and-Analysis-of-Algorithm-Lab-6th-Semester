
<%@ page import="java.sql.*" %>
<%
String userName = request.getParameter("username");
String password = request.getParameter("password");

Class.forName("com.mysql.jdbc.Driver");
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "root");
Statement stmt = con.createStatement();
ResultSet rs;

// Insert user details
if (request.getParameter("register") != null) {
  String name = request.getParameter("name");
  String email = request.getParameter("email");
  String query = "INSERT INTO users (name, email, username, password) VALUES ('" + name + "', '" + email + "', '" + userName + "', '" + password + "')";
  stmt.executeUpdate(query);
}

// Authenticate user
if (request.getParameter("login") != null) {
  String query = "SELECT * FROM users WHERE username = '" + userName + "' AND password = '" + password + "'";
  rs = stmt.executeQuery(query);
  if (rs.next()) {
    session.setAttribute("username", userName);
    response.sendRedirect("welcome.jsp");
  } else {
    out.println("Invalid username or password");
  }
}
%>

<html>
<head>
  <title>Registration Form</title>
</head>
<body>
  <%
  if (session.getAttribute("username") == null) {
  %>
    <h3>Registration Form</h3>
    <form action="index.jsp" method="post">
      Name: <input type="text" name="name"><br>
      Email: <input type="email" name="email"><br>
      Username: <input type="text" name="username"><br>
      Password: <input type="password" name="password"><br>
      <input type="submit" name="register" value="Register">
    </form>

    <h3>Login Form</h3>
    <form action="index.jsp" method="post">
      Username: <input type="text" name="username"><br>
      Password: <input type="password" name="password"><br>
      <input type="submit" name="login" value="Login">
    </form>
  <%
  } else {
  %>
    <h3>Welcome, <%= session.getAttribute("username") %></h3>
  <%
  }
  %>
</body>
</html>
```
/*


1. `<%@ page import="java.sql.*" %>`: This line imports the java.sql package to use the SQL classes and interfaces.

2. `String userName = request.getParameter("username");`: This line retrieves the value of the `username` parameter from the request object and stores it in the `userName` variable.

3. `String password = request.getParameter("password");`: This line retrieves the value of the `password` parameter from the request object and stores it in the `password` variable.

4. `Class.forName("com.mysql.jdbc.Driver");`: This line loads the MySQL JDBC driver class.

5. `Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "root");`: This line creates a connection to the MySQL database `mydb` on `localhost` at port `3306` using the `root` username and password.

6. `Statement stmt = con.createStatement();`: This line creates a `Statement` object to execute SQL statements.

7. `ResultSet rs;`: This line declares a `ResultSet` object to store the results of a SELECT query.

8. `if (request.getParameter("register") != null) {...}`: This block of code checks if the `register` parameter is present in the request. If it is, the user details (name, email, username, password) are inserted into the `users` table.

9. `if (request.getParameter("login") != null) {...}`: This block of code checks if the `login` parameter is present in the request. If it is, the code executes a SELECT query to retrieve the user details from the `users` table and checks if the username and password match. If they do, the user is redirected to the `welcome.jsp` page. If not, an error message is displayed.

10. `if (session.getAttribute("username") == null) {...}`: This block of code checks if the `username` attribute is present in the session. If it is not, the registration and login forms are displayed. If it is, a welcome message is displayed with the username.
*/
