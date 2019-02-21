<h3>HEADERS ? </h3>

&nbsp; ->  HTTP headers allow the client and the server to pass additional information with the request or the response. An HTTP header consists of its case-insensitive name followed by a colon ' : ', then by its value (without line breaks) </br>

&nbsp; Example :

```bash
# Terminal 1
nc -lvp 8080   # accepting requests on port 8080
```

```bash
# Terminal 2
curl localhost:8080   # Making an HTTP GET request on port 8080
```

```bash
# Terminal 1 output

GET / HTTP/1.1            # Request method + version of HTTP
Host: localhost:8080      # It contains the host we are trying to resolve + port.
User-Agent: curl/7.47.0   # Program used to make the request (usually web browsers)
Accept: */*   # It tells the content-type that the client understands (json, MIME , text/html etc)

```


