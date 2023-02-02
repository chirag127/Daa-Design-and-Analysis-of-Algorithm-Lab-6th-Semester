complete the following practical for my wt assignement 

3. Write programs using Java script for Web Page to display browsers information.


```
<!DOCTYPE html>
<html>
<head>
<script>
function getBrowserInfo() {
  var ua = navigator.userAgent, tem,
  M = ua.match(/(opera|chrome|safari|firefox|msie|trident(?=\/))\/?\s*(\d+)/i) || [];
  if(/trident/i.test(M[1])){
    tem=  /\brv[ :]+(\d+)/g.exec(ua) || [];
    return 'IE '+(tem[1] || '');
  }
  if(M[1]=== 'Chrome'){
    tem= ua.match(/\bOPR\/(\d+)/)
    if(tem!= null) return 'Opera '+tem[1];
  }
  M= M[2]? [M[1], M[2]]: [navigator.appName, navigator.appVersion, '-?'];
  if((tem= ua.match(/version\/(\d+)/i))!= null) M.splice(1, 1, tem[1]);
  return M.join(' ');
}
</script>
</head>
<body>

<p id="browserInfo"></p>

<script>
document.getElementById("browserInfo").innerHTML =
"Browser name: " + getBrowserInfo();
</script>

</body>
</html>
```
/*
 

1. `<!DOCTYPE html>`: This line declares the document type as HTML5.

2. `<html>`: This tag begins the HTML document.

3. `<head>`: This tag begins the head section of the document, which contains metadata about the document.

4. `<script>`: This tag begins a JavaScript section of the document.

5. `function getBrowserInfo()`: This line declares a function named `getBrowserInfo` in JavaScript.

6. `var ua = navigator.userAgent, tem,`: This line declares a variable named `ua` and sets its value to the `userAgent` property of the `navigator` object, which contains information about the user's browser. The `tem` variable is declared but not assigned a value.

7. `M = ua.match(/(opera|chrome|safari|firefox|msie|trident(?=\/))\/?\s*(\d+)/i) || [];`: This line declares a variable named `M` and sets its value to the result of a regular expression match on the `ua` variable. The regular expression tests for the presence of one of several browser names, followed by an optional "/" and a version number. If the match fails, an empty array is returned.

8. `if(/trident/i.test(M[1]))`: This line tests whether the first element of the `M` array (the matched browser name) is "trident" (ignoring case).

9. `tem=  /\brv[ :]+(\d+)/g.exec(ua) || [];`: If the previous test is true, this line declares a variable named `tem` and sets its value to the result of a regular expression match on the `ua` variable. The regular expression tests for the presence of the string "rv" followed by a version number. If the match fails, an empty array is returned.

10. `return 'IE '+(tem[1] || '');`: If the previous test is true, this line returns the string "IE" followed by the version number (if any) extracted from the `tem` variable.

11. `if(M[1]=== 'Chrome')`: This line tests whether the first element of the `M` array (the matched browser name) is "Chrome".

12. `tem= ua.match(/\bOPR\/(\d+)/)`: If the previous test is true, this line declares a variable named `tem` and sets its value to the result of a regular expression match on the `ua` variable. The regular expression tests for the presence of the string "OPR/" followed by a version number.

13. `if(tem!= null) return 'Opera '+tem[1];`: If the previous test is true, this line returns the string "Opera" followed by the version number extracted from the `tem` variable.

14. `M= M[2]? [M[1], M[2]]: [navigator.appName, navigator.appVersion, '-?'];`: This line sets the value of the `M` variable to either an array containing the matched browser name and version number (if present), or an array containing the `appName` and `appVersion` properties of the `navigator` object, and a placeholder string.

15. `if((tem= ua.match(/version\/(\d+)/i))!= null) M.splice(1, 1, tem[1]);`: This line tests for the presence of the string "version/" followed by a version number in the `ua` variable. If the test is true, the second element of the `M` array is replaced with the version number extracted from the `tem` variable.

16. `return M.join(' ');`: This line returns the `M` array as a string, with elements separated by a space.

17. `</script>`: This tag ends the JavaScript section of the document.

18. `<body>`: This tag begins the body section of the document, which contains the content of the document.

19. `<p id="browserInfo"></p>`: This line creates a paragraph element with an ID of "browserInfo".

20. `<script>`: This tag begins another JavaScript section of the document.

21. `document.getElementById("browserInfo").innerHTML =
"Browser name: " + getBrowserInfo();`: This line sets the inner HTML of the paragraph element with ID "browserInfo" to the string "Browser name: " followed by the result of calling the `getBrowserInfo` function.

22. `</script>`: This tag ends the JavaScript section of the document.

23. `</body>`: This tag ends the body section of the document.

24. `</html>`: This tag ends the HTML document.
*/
