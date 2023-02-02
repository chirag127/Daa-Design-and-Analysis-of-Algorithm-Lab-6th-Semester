write the codes in c following practical for my daa assignement 

3. Write programs using Java script for Web Page to display browsers information.
 To display browser information in a web page using JavaScript, use the following code:

```
<script>
  document.write("Browser CodeName: " + navigator.appCodeName);
  document.write("<br>");
  document.write("Browser Name: " + navigator.appName);
  document.write("<br>");
  document.write("Browser Version: " + navigator.appVersion);
  document.write("<br>");
  document.write("Cookies Enabled: " + navigator.cookieEnabled);
  document.write("<br>");
  document.write("Platform: " + navigator.platform);
  document.write("<br>");
  document.write("User-agent header: " + navigator.userAgent);
</script>
```
