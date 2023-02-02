write the code for practical for my wt assignement 

5. Write a Java applet to display the Application Program screen i.e. calculator and other.
 Here is a basic Java Applet code to display a calculator:
```
import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class CalculatorApplet extends Applet implements ActionListener {
  Button b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, add, sub, mul, div, equal, clear;
  TextField tf;
  double a=0, b=0, result=0;
  int operator=0;

  public void init() {
    tf = new TextField();
    tf.setBounds(30, 40, 280, 30);
    add(tf);

    b1 = new Button("1");
    b1.setBounds(40, 100, 50, 40);
    add(b1);
    b1.addActionListener(this);

    b2 = new Button("2");
    b2.setBounds(110, 100, 50, 40);
    add(b2);
    b2.addActionListener(this);

    b3 = new Button("3");
    b3.setBounds(180, 100, 50, 40);
    add(b3);
    b3.addActionListener(this);

    b4 = new Button("4");
    b4.setBounds(40, 170, 50, 40);
    add(b4);
    b4.addActionListener(this);

    b5 = new Button("5");
    b5.setBounds(110, 170, 50, 40);
    add(b5);
    b5.addActionListener(this);

    b6 = new Button("6");
    b6.setBounds(180, 170, 50, 40);
    add(b6);
    b6.addActionListener(this);

    b7 = new Button("7");
    b7.setBounds(40, 240, 50, 40);
    add(b7);
    b7.addActionListener(this);

    b8 = new Button("8");
    b8.setBounds(110, 240, 50, 40);
    add(b8);
    b8.addActionListener(this);

    b9 = new Button("9");
    b9.setBounds(180, 240, 50, 40);
    add(b9);
    b9.addActionListener(this);

    b0 = new Button("0");
    b0.setBounds(110, 310, 50, 40);
    add(b0);
    b0.addActionListener(this);

    add = new Button("+");
    add.setBounds(250, 100, 50, 40);
    add(add);
    add.addActionListener(this);

    sub = new Button("-");
    sub.setBounds(250, 170, 50, 40);
    add(sub);
    sub.addActionListener(this);

    mul = new Button("*");
    mul.setBounds(250, 240, 50, 40);
    add(mul);
    mul.addActionListener(this);

    div = new Button("/");
    div.setBounds(250, 310, 50, 40);
    add(div);
    div.addActionListener(this);

    equal = new Button("=");
    equal.setBounds(180, 310, 50, 40);
    add(equal);
    equal.addActionListener(this);

    clear = new Button("Clear");
    clear.setBounds(40, 310, 80, 40);
    add(clear);
    clear.addActionListener(this);

    setLayout(null);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == b1) {
      tf.setText(tf.getText().concat("1"));
    }
    if (e.getSource() == b2) {
      tf.setText(tf.getText().concat("2"));
    }
    if (e.getSource() == b3) {
      tf.setText(tf.getText().concat("3"));
    }
    if (e.getSource() == b4) {
      tf.setText(tf.getText().concat("4"));
    }
    if (e.getSource() == b5) {
      tf.setText(tf.getText().concat("5"));
    }
    if (e.getSource() == b6) {
      tf.setText(tf.getText().concat("6"));
    }
    if (e.getSource() == b7) {
      tf.setText(tf.getText().concat("7"));
    }
    if (e.getSource() == b8) {
      tf.setText(tf.getText().concat("8"));
    }
    if (e.getSource() == b9) {
      tf.setText(tf.getText().concat("9"));
    }
    if (e.getSource() == b0) {
      tf.setText(tf.getText().concat("0"));
    }
    if (e.getSource() == add) {
      a = Double.parseDouble(tf.getText());
      operator = 1;
      tf.setText("");
    }
    if (e.getSource() == sub) {
      a = Double.parseDouble(tf.getText());
      operator = 2;
      tf.setText("");
    }
    if (e.getSource() == mul) {
      a = Double.parseDouble(tf.getText());
      operator = 3;
      tf.setText("");
    }
    if (e.getSource() == div) {
      a = Double.parseDouble(tf.getText());
      operator = 4;
      tf.setText("");
    }
    if (e.getSource() == equal) {
      b = Double.parseDouble(tf.getText());
      switch (operator) {
        case 1:
          result = a + b;
          break;
        case 2:
          result = a - b;
          break;
        case 3:
          result = a * b;
          break;
        case 4:
          result = a / b;
          break;
        default:
          result = 0;
      }
      tf.setText("" + result);
    }
    if (e.getSource() == clear) {
      tf.setText("");
    }
  }
}
```
/*
 
This code is a Java applet that implements a calculator. The code imports necessary libraries, defines a class `CalculatorApplet` that extends the `Applet` class and implements the `ActionListener` interface. 

The class has several instance variables: 
- `Button` variables for the calculator buttons
- `TextField` for the display
- `double` variables `a`, `b`, and `result` to store operands and results
- `int` operator to store the operation type

The `init()` method sets up the calculator UI by creating the buttons and text field, setting their positions and adding them to the applet. 

The `actionPerformed()` method listens to button clicks and performs the corresponding actions: 
- When a number button is clicked, it concatenates the corresponding digit to the display text. 
- When an operator button is clicked, it stores the current display value in `a` and sets the operator type. 
- When the equal button is clicked, it performs the calculation based on the operator type and stores the result in the display. 
- When the clear button is clicked, it clears the display text.
*/
