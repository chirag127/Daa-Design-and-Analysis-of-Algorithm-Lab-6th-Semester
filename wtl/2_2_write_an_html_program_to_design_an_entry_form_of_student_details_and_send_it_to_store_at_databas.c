complete the following practical for my wt assignement 

2. Write an HTML program to design an entry form of student details and send it to store at database server like SQL, Oracle or MS Access.
 Here is an example of an HTML form for student details:

```
<form action="submit_student_details.php" method="post">
  <label for="first_name">First Name:</label>
  <input type="text" id="first_name" name="first_name"><br><br>

  <label for="last_name">Last Name:</label>
  <input type="text" id="last_name" name="last_name"><br><br>

  <label for="student_id">Student ID:</label>
  <input type="text" id="student_id" name="student_id"><br><br>

  <label for="email">Email:</label>
  <input type="email" id="email" name="email"><br><br>

  <input type="submit" value="Submit">
</form>
```

This form can be sent to a PHP script (submit_student_details.php) to store the data in a database like SQL, Oracle or MS Access.
/*


```
<form action="submit_student_details.php" method="post">
```
- This line starts a form and specifies the action to be taken when the form is submitted. The `action` attribute specifies the URL of the script that will process the form data, in this case, `submit_student_details.php`. The `method` attribute specifies the HTTP method to be used when submitting the form data, in this case, `post`.

```
  <label for="first_name">First Name:</label>
  <input type="text" id="first_name" name="first_name"><br><br>
```
- This line creates a label for the first name input field, and the next line creates a text input field for the first name. The `label` element has a `for` attribute that specifies which form element the label is associated with, in this case, the input field with `id` "first_name". The input field has a `type` attribute set to "text", which specifies that it is a text input field. The `id` and `name` attributes are used to identify the input field.

```
  <label for="last_name">Last Name:</label>
  <input type="text" id="last_name" name="last_name"><br><br>
```
- Similar to the first name input field, this line creates a label for the last name input field, and the next line creates a text input field for the last name.

```
  <label for="student_id">Student ID:</label>
  <input type="text" id="student_id" name="student_id"><br><br>
```
- Similar to the first and last name input fields, this line creates a label for the student ID input field, and the next line creates a text input field for the student ID.

```
  <label for="email">Email:</label>
  <input type="email" id="email" name="email"><br><br>
```
- Similar to the previous input fields, this line creates a label for the email input field, and the next line creates an email input field for the email. The input field has a `type` attribute set to "email", which specifies that it is an email input field.

```
  <input type="submit" value="Submit">
```
- This line creates a submit button for the form. The `type` attribute is set to "submit", which specifies that it is a submit button. The `value` attribute specifies the text that will be displayed on the button.

```
</form>
```
- This line ends the form.
*/
