write the code for practical for my wt assignement 

12. Design and implement a simple shopping cart example with session tracking API.
 Here is a basic example of a shopping cart using Flask and session tracking:

```
from flask import Flask, session, redirect, url_for, escape, request

app = Flask(__name__)
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'

@app.route('/')
def index():
    if 'cart' not in session:
        session['cart'] = []
    return '''
        <h1>Shopping Cart</h1>
        <ul>
            {items}
        </ul>
        <form action="/add" method="post">
            <input type="text" name="item">
            <input type="submit" value="Add to Cart">
        </form>
        <a href="/clear">Clear Cart</a>
    '''.format(
        items='\n'.join(
            '<li>{}</li>'.format(item)
            for item in session['cart']
        )
    )

@app.route('/add', methods=['POST'])
def add():
    item = request.form['item']
    session['cart'].append(item)
    return redirect(url_for('index'))

@app.route('/clear')
def clear():
    session.clear()
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
```
/*


- `from flask import Flask, session, redirect, url_for, escape, request`: imports the Flask class and several functions from the flask module. `session` is used for session tracking, `redirect` is used to redirect the user to a different URL, `url_for` generates URLs for a given endpoint, `escape` escapes HTML characters in strings, and `request` is used to access incoming request data.

- `app = Flask(__name__)`: creates a new Flask application instance. `__name__` is a special variable in Python that is set to the name of the current module.

- `app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'`: sets the secret key for the Flask application. The secret key is used to secure the session data.

- `@app.route('/')`: sets the route for the index function. When the user visits the root URL, the index function will be executed.

- `def index():`: defines the index function.

- `if 'cart' not in session:`: checks if the `cart` key is in the session data. If it is not, the session data is initialized with an empty list.

- `session['cart'] = []`: sets the `cart` key in the session data to an empty list.

- `return '''...'''.format(...`: returns an HTML string that is formatted with data from the session. The HTML string contains a heading, an unordered list of items in the cart, a form for adding items to the cart, and a link for clearing the cart.

- `items='\n'.join(...`: generates a string of HTML list items from the items in the cart.

- `@app.route('/add', methods=['POST'])`: sets the route for the add function. The add function will be executed when the user submits the form for adding items to the cart. The `methods` argument specifies that the route only accepts POST requests.

- `def add():`: defines the add function.

- `item = request.form['item']`: gets the value of the `item` field from the submitted form data.

- `session['cart'].append(item)`: adds the item to the cart in the session data.

- `return redirect(url_for('index'))`: redirects the user to the index page.

- `@app.route('/clear')`: sets the route for the clear function. The clear function will be executed when the user visits the `/clear` URL.

- `def clear():`: defines the clear function.

- `session.clear()`: clears the session data.

- `return redirect(url_for('index'))`: redirects the user to the index page.

- `if __name__ == '__main__':`: checks if the script is being run as the main module.

- `app.run(debug=True)`: runs the Flask application in debug mode. Debug mode provides additional error information and allows the application to be restarted automatically when changes are made to the code.
*/
