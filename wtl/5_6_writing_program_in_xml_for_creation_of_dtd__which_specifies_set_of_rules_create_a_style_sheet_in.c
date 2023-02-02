write the codes in c following practical for my daa assignement 

6. Writing program in XML for creation of DTD, which specifies set of rules. Create a style sheet in CSS/ XSL & display the document in internet explorer.
 Here's a sample XML file with a DTD:

```
<!DOCTYPE note [
  <!ELEMENT note (to,from,heading,body)>
  <!ELEMENT to (#PCDATA)>
  <!ELEMENT from (#PCDATA)>
  <!ELEMENT heading (#PCDATA)>
  <!ELEMENT body (#PCDATA)>
]>

<note>
  <to>John</to>
  <from>Jane</from>
  <heading>Reminder</heading>
  <body>Don't forget to buy milk today.</body>
</note>
```

Here's a sample CSS style sheet:

```
note {
  font-family: Arial;
  font-size: 12pt;
}

to, from, heading, body {
  display: block;
  margin-bottom: 10px;
}

to {
  font-weight: bold;
}

from {
  font-style: italic;
}

heading {
  font-size: 14pt;
  font-weight: bold;
}
```

To display the document in Internet Explorer, you'll need to save the XML and CSS files to your computer, then open the XML file in Internet Explorer. The browser should automatically apply the styles defined in the CSS file.
