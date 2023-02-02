complete the following practical for my wt assignement 

9. Assume four users user1, user2, user3 and user4 having the passwords pwd1, pwd2, pwd3 and pwd4 respectively. Write a servlet for doing the following. Create a Cookie and add these four user id’s and passwords to this Cookie. 2. Read the user id and passwords entered in the Login form and authenticate with the values available in the cookies.

Here is a sample servlet to fulfill the requirements:

```
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class LoginServlet extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {

    response.setContentType("text/html");
    PrintWriter out = response.getWriter();

    String user = request.getParameter("user");
    String pwd = request.getParameter("pwd");

    // Create a cookie for each user and password
    Cookie user1Cookie = new Cookie("user1", "pwd1");
    Cookie user2Cookie = new Cookie("user2", "pwd2");
    Cookie user3Cookie = new Cookie("user3", "pwd3");
    Cookie user4Cookie = new Cookie("user4", "pwd4");

    // Add cookies to response
    response.addCookie(user1Cookie);
    response.addCookie(user2Cookie);
    response.addCookie(user3Cookie);
    response.addCookie(user4Cookie);

    // Authenticate user and password
    if (user.equals("user1") && pwd.equals("pwd1") ||
        user.equals("user2") && pwd.equals("pwd2") ||
        user.equals("user3") && pwd.equals("pwd3") ||
        user.equals("user4") && pwd.equals("pwd4")) {
      RequestDispatcher rd = request.getRequestDispatcher("welcome.html");
      rd.forward(request, response);
    } else {
      out.print("Sorry, username or password error!");
      RequestDispatcher rd = request.getRequestDispatcher("index.html");
      rd.include(request, response);
    }
  }
}
```
/*


1. `import java.io.*;`: Imports the `java.io` package, which contains classes for input and output operations.

2. `import javax.servlet.*;`: Imports the `javax.servlet` package, which contains classes and interfaces for servlets.

3. `import javax.servlet.http.*;`: Imports the `javax.servlet.http` package, which contains classes and interfaces for HTTP servlets.

4. `public class LoginServlet extends HttpServlet`: Defines a class named `LoginServlet`, which extends the `HttpServlet` class. This means that `LoginServlet` is a subclass of `HttpServlet` and inherits its methods.

5. `public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException`: Overrides the `doPost` method of the `HttpServlet` class. This method is called when the client submits a form using the HTTP POST method. The `HttpServletRequest` and `HttpServletResponse` objects are passed as arguments, which represent the request and response, respectively.

6. `response.setContentType("text/html");`: Sets the content type of the response to `text/html`, which indicates that the response is an HTML document.

7. `PrintWriter out = response.getWriter();`: Creates a `PrintWriter` object `out` and associates it with the response. This allows the servlet to write content to the response.

8. `String user = request.getParameter("user");`: Gets the value of the `user` parameter from the request and stores it in a `String` variable named `user`.

9. `String pwd = request.getParameter("pwd");`: Gets the value of the `pwd` parameter from the request and stores it in a `String` variable named `pwd`.

10. `Cookie user1Cookie = new Cookie("user1", "pwd1");`: Creates a `Cookie` object named `user1Cookie` with the name `user1` and value `pwd1`.

11. `Cookie user2Cookie = new Cookie("user2", "pwd2");`: Creates a `Cookie` object named `user2Cookie` with the name `user2` and value `pwd2`.

12. `Cookie user3Cookie = new Cookie("user3", "pwd3");`: Creates a `Cookie` object named `user3Cookie` with the name `user3` and value `pwd3`.

13. `Cookie user4Cookie = new Cookie("user4", "pwd4");`: Creates a `Cookie` object named `user4Cookie` with the name `user4` and value `pwd4`.

14. `response.addCookie(user1Cookie);`: Adds the `user1Cookie` to the response.

15. `response.addCookie(user2Cookie);`: Adds the `user2Cookie` to the response.

16. `response.addCookie(user3Cookie);`: Adds the `user3Cookie` to the response.

17. `response.addCookie(user4Cookie);`: Adds the `user4Cookie` to the response.

18. `if (user.equals("user1") && pwd.equals("pwd1") || user.equals("user2") && pwd.equals("pwd2") || user.equals("user3") && pwd.equals("pwd3") || user.equals("user4") && pwd.equals("pwd4"))`: Checks if the `user` and `pwd` values match any of the four user-password combinations.

19. `RequestDispatcher rd = request.getRequestDispatcher("welcome.html");`: If the user and password are valid, creates a `RequestDispatcher` object named `rd` and associates it with the `welcome.html` page.

20. `rd.forward(request, response);`: Forwards the request and response to the `welcome.html` page.

21. `out.print("Sorry, username or password error!");`: If the user and password are not valid, writes the error message to the response.

22. `RequestDispatcher rd = request.getRequestDispatcher("index.html");`: Creates a `RequestDispatcher` object named `rd` and associates it with the `index.html` page.

23. `rd.include(request, response);`: Includes the `index.html` page in the response.
*/
