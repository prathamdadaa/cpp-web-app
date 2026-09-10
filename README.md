# C++ Web Application

HTML, CSS, JavaScript (Frontend) aur C++ CGI (Backend) ka se bana ek simple web app.

## Project Structure
- `index.html` - Frontend UI
- `cgi-bin/server.cpp` - C++ Backend logic
- `css/` & `js/` - Frontend assets

## How to Run
1. Install Apache2 with CGI module enabled.
2. Compile C++ file: `g++ cgi-bin/server.cpp -o /usr/lib/cgi-bin/server.cgi`
3. Place `index.html` in `/var/www/html/`.
