#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

// URL parameters ko read karne ke liye helper function
string getQueryParam(const string& query, const string& key) {
    size_t pos = query.find(key + "=");
    if (pos == string::npos) return "";
    size_t start = pos + key.length() + 1;
    size_t end = query.find("&", start);
    if (end == string::npos) {
        return query.substr(start);
    }
    return query.substr(start, end - start);
}

int main() {
    // 1. Web server ko batao ki hum JSON send kar rahe hain (HTTP Header)
    cout << "Content-Type: application/json\r\n\r\n";

    // 2. Query String receive karo (Browser se aane wala data)
    char* queryString = getenv("QUERY_STRING");

    if (queryString != NULL) {
        string qStr = queryString;
        string strNum1 = getQueryParam(qStr, "num1");
        string strNum2 = getQueryParam(qStr, "num2");

        if (!strNum1.empty() && !strNum2.empty()) {
            double n1 = stod(strNum1);
            double n2 = stod(strNum2);
            double sum = n1 + n2;

            // 3. Output in JSON format
            cout << "{\"status\": \"success\", \"result\": " << sum << "}";
            return 0;
        }
    }

    // Error Handling
    cout << "{\"status\": \"error\", \"message\": \"Invalid parameters\"}";
    return 0;
}
