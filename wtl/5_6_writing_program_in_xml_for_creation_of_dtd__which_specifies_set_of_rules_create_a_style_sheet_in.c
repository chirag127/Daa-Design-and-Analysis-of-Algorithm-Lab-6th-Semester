write the code for practical for my wt assignement 

6. Writing program in XML for creation of DTD, which specifies set of rules. Create a style sheet in CSS/ XSL & display the document in internet explorer.
 Here's a sample XML code with a DTD and CSS stylesheet:

```
<?xml version="1.0"?>
<!DOCTYPE note [
  <!ELEMENT note (to, from, heading, body)>
  <!ELEMENT to (#PCDATA)>
  <!ELEMENT from (#PCDATA)>
  <!ELEMENT heading (#PCDATA)>
  <!ELEMENT body (#PCDATA)>
]>

<note>
  <to>John</to>
  <from>Jane</from>
  <heading>Reminder</heading>
  <body>Don't forget to pick up milk on the way home.</body>
</note>
```

```
note {
  display: block;
  border: 1px solid black;
  padding: 10px;
  width: 500px;
}

to, from, heading, body {
  display: block;
  margin-bottom: 10px;
}

to {
  font-weight: bold;
}

heading {
  font-size: larger;
}
```

This code can be viewed in Internet Explorer by saving it as an .xml file and opening it in the browser. The stylesheet will be applied to the document, and the note will be displayed with a border and padding, with each element styled as specified in the CSS.
/*
 

1. `<?xml version="1.0"?>`: This line declares that the document is an XML document and specifies the version of XML used.

2. `<!DOCTYPE note [`: This line starts the declaration of a Document Type Definition (DTD). A DTD is a set of rules that defines the structure and elements of an XML document. The `note` in the declaration is the root element of the document.

3. `<!ELEMENT note (to, from, heading, body)>`: This line defines the structure of the `note` element. It specifies that the `note` element must contain `to`, `from`, `heading`, and `body` elements in that order.

4. `<!ELEMENT to (#PCDATA)>`, `<!ELEMENT from (#PCDATA)>`, `<!ELEMENT heading (#PCDATA)>`, `<!ELEMENT body (#PCDATA)>`: These lines define the structure of the `to`, `from`, `heading`, and `body` elements. They specify that these elements must contain parsed character data (#PCDATA).

5. `<note>`: This line starts the `note` element, which is the root element of the document.

6. `<to>John</to>`, `<from>Jane</from>`, `<heading>Reminder</heading>`, `<body>Don't forget to pick up milk on the way home.</body>`: These lines define the `to`, `from`, `heading`, and `body` elements and their content.

7. `note {`: This line starts the definition of a CSS stylesheet for the `note` element.

8. `display: block;`: This line specifies that the `note` element should be displayed as a block-level element.

9. `border: 1px solid black;`: This line specifies that the `note` element should have a 1 pixel wide black border.

10. `padding: 10px;`: This line specifies that the `note` element should have a 10 pixel padding on all sides.

11. `width: 500px;`: This line specifies that the width of the `note` element should be 500 pixels.

12. `to, from, heading, body {`: This line starts the definition of a CSS stylesheet for the `to`, `from`, `heading`, and `body` elements.

13. `display: block;`: This line specifies that the `to`, `from`, `heading`, and `body` elements should be displayed as block-level elements.

14. `margin-bottom: 10px;`: This line specifies that the `to`, `from`, `heading`, and `body` elements should have a 10 pixel margin at the bottom.

15. `font-weight: bold;`: This line specifies that the text in the `to` element should be bold.

16. `font-size: larger;`: This line specifies that the text in the `heading` element should be larger than the surrounding text.
*/
