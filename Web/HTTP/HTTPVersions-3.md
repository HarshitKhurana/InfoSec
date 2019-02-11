<h3>HTTP Versions Basic Diff </h3>

<h4> [*] HTTP 1.0 </h4>
&nbsp; -> Server closes the connection after evvery request.</br>
&nbsp; -> The number of connections could vary based on the browser and server will close the connection after each request.</br>


<h4> [*] HTTP 1.1 </h4>
&nbsp; -> Server does not close the connection i.e the server re-use the sam connection for all requests which finally increase response time of server i.e decreases the overheads for connection request and disconnection. </br>

<h4> [*] HTTP 2.0 </h4>
&nbsp; -> Only available with HTTPS. </br>
&nbsp; -> Support for request multiplexing i.e HTTP/2 can send multiple requests for data in parallel over a single TCP connection. This is the most advanced feature of the HTTP/2 protocol because it allows you to download web files asynchronously from one server. </br>
&nbsp; -> The server can push data to client without the client requesting it HTTP2.- Server Push (for resource the clients gonna need soon), Websockets support , those resources can be cached by the client and reuse that from cache.</br>
