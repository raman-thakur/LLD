#include <bits/stdc++.h>
using namespace std;

#include <string>
#include <map>
using namespace std;

class HTTPheader {
public:
    // required
    string url;

    // optional
    string method;
    map<string, string> headers;
    map<string, string> queryParams;
    string body;
    int timeout;

private:
    HTTPheader(string url, string method,
               const map<string, string>& headers,
               const map<string, string>& queryParams,
               string body, int timeout)
        : url(url), method(method), headers(headers),
          queryParams(queryParams), body(body), timeout(timeout) {}

public:
    class Builder {
    public:
        string url;

        // optional
        string method;
        map<string, string> headers;
        map<string, string> queryParams;
        string body;
        int timeout = 0;

        Builder(string url) : url(url) {}

        Builder* setMethod(const string& method) {
            this->method = method;
            return this;
        }

        Builder* addHeader(const string& key, const string& val) {
            this->headers.insert({key, val});
            return this;
        }

        Builder* addQueryParam(const string& key, const string& val) {
            this->queryParams.insert({key, val});
            return this;
        }

        Builder* addTimeout(int timeout) {
            this->timeout = timeout;
            return this;
        }

        Builder* addPayload(const string& body) {
            this->body = body;
            return this;
        }

        HTTPheader* build() {
            return new HTTPheader(url, method, headers, queryParams, body, timeout);
        }
    };
};



int main()
{
    HTTPheader::Builder *builder = new HTTPheader::Builder("google.com");
    HTTPheader* header = builder->setMethod("GET")
                            ->addHeader("jwtKey","bhvebewfbehf")
                            ->addHeader("APIKey","21515asd12")
                            ->addTimeout(30)->build();

    cout<<header->method;
    return 0;
}