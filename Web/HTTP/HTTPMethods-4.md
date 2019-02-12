<h3> HTTP Methods </h3>

<a href="./Web-Methods-Nmap.md"> Using Nmap for HTTP Method testing Web... </a>

&nbsp; -> HTTP defines a set of request methods to indicate the desired action to be performed for a given resource. Although they can also be nouns, these request methods are sometimes referred as HTTP verbs. Each of them implements a different semantic, but some common features are shared by a group of them: e.g. a request method can be safe, idempotent, or cacheable(these 3 are the classification of HTTP request method).

<h4> [*] GET </h4> 
 &nbsp; -> The GET method requests a representation of the specified resource. Requests using GET should only retrieve data.
 </br>
 &nbsp; -> Parameters in the URL
 </br>

<h4> [*]  HEAD  </h4> 
 &nbsp; -> The HEAD method asks for a response identical to that of a GET request, but without the response body.
 </br>

<h4> [*]  POST </h4> 
 &nbsp; -> It isused to submit an entity to the specified resource, often causing a change in state or side effects on the server + data in message body.
 </br>

<h4> [*]  PUT </h4> 
 &nbsp; -> The PUT method is used to store in URI.
 </br>

<h4> [*]  DELETE  </h4> 
 &nbsp; -> The DELETE method deletes the specified resource.
 </br>

<h4> [*]  CONNECT </h4> 
 &nbsp; -> The CONNECT method establishes a tunnel to the server identified by the target resource.
 </br>

<h4> [*]  OPTIONS </h4> 
 &nbsp; -> The OPTIONS method is used to list the methods supported by the URL. (often blocked as this can help in RECON about target)
 </br>

<h4> [*]  TRACE </h4> 
 &nbsp; -> Simply echo's back the client request help in ensuring that the path is cool and working.
 </br>

<h4> [*]  PATCH </h4> 
 &nbsp; -> The PATCH method is used to apply partial modifications to a resource.
 </br>
 </br>
<b>EXAMPLES : </b>
 </br>
&nbsp; <p> <b>1. OPTIONS </b>request on google.com </p>

```bash
curl -v -X OPTIONS http://google.com

* Rebuilt URL to: google.com/
*   Trying 172.217.166.14...
* Connected to google.com (172.217.166.14) port 80 (#0)
> OPTIONS / HTTP/1.1
> Host: google.com
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 405 Method Not Allowed
< Allow: GET, HEAD
< Date: Mon, 11 Feb 2019 09:56:23 GMT
< Content-Type: text/html; charset=UTF-8
< Server: gws
< Content-Length: 1592
< X-XSS-Protection: 1; mode=block
< X-Frame-Options: SAMEORIGIN
< 
<!DOCTYPE html>
<html lang=en>
  <meta charset=utf-8>
  <meta name=viewport content="initial-scale=1, minimum-scale=1, width=device-width">
  <title>Error 405 (Method Not Allowed)!!1</title>
  <style>
    *{margin:0;padding:0}html,code{font:15px/22px arial,sans-serif}html{background:#fff;color:#222;padding:15px}body{margin:7% auto 0;max-width:390px;min-height:180px;padding:30px 0 15px}* > body{background:url(//www.google.com/images/errors/robot.png) 100% 5px no-repeat;padding-right:205px}p{margin:11px 0 22px;overflow:hidden}ins{color:#777;text-decoration:none}a img{border:0}@media screen and (max-width:772px){body{background:none;margin-top:0;max-width:none;padding-right:0}}#logo{background:url(//www.google.com/images/branding/googlelogo/1x/googlelogo_color_150x54dp.png) no-repeat;margin-left:-5px}@media only screen and (min-resolution:192dpi){#logo{background:url(//www.google.com/images/branding/googlelogo/2x/googlelogo_color_150x54dp.png) no-repeat 0% 0%/100% 100%;-moz-border-image:url(//www.google.com/images/branding/googlelogo/2x/googlelogo_color_150x54dp.png) 0}}@media only screen and (-webkit-min-device-pixel-ratio:2){#logo{background:url(//www.google.com/images/branding/googlelogo/2x/googlelogo_color_150x54dp.png) no-repeat;-webkit-background-size:100% 100%}}#logo{display:inline-block;height:54px;width:150px}
</style>
<a href=//www.google.com/><span id=logo aria-label=Google></span></a>
<p><b>405.</b> <ins>That’s an error.</ins>
<p>The request method <code>OPTIONS</code> is inappropriate for the URL <code>/</code>. 
<ins>That’s all we know.</ins> ## GOOGLE DOES NOT ALLOW OPTIONS

```

</br>
&nbsp; <p> <b>2. GET </b>request on google.com </p>

```bash
curl -v -X GET google.com

Note: Unnecessary use of -X or --request, GET is already inferred.
* Rebuilt URL to: google.com/
*   Trying 172.217.160.238...
* Connected to google.com (172.217.160.238) port 80 (#0)
> GET / HTTP/1.1
> Host: google.com
> User-Agent: curl/7.47.0
> Accept: */*
> 
< HTTP/1.1 301 Moved Permanently
< Location: http://www.google.com/
< Content-Type: text/html; charset=UTF-8
< Date: Mon, 11 Feb 2019 10:04:39 GMT
< Expires: Wed, 13 Mar 2019 10:04:39 GMT
< Cache-Control: public, max-age=2592000
< Server: gws
< Content-Length: 219
< X-XSS-Protection: 1; mode=block
< X-Frame-Options: SAMEORIGIN
< 
<HTML><HEAD><meta http-equiv="content-type" content="text/html;charset=utf-8">
<TITLE>301 Moved</TITLE></HEAD><BODY>
<H1>301 Moved</H1>
The document has moved
<A HREF="http://www.google.com/">here</A>.
</BODY></HTML>
* Connection #0 to host google.com left intact
```
&nbsp; <p> <b>3. HEAD </b>request on google.com </p>

```bash
curl -v -X HEAD google.com

Warning: Setting custom HTTP method to HEAD with -X/--request may not work the 
Warning: way you want. Consider using -I/--head instead.
* Rebuilt URL to: google.com/
*   Trying 172.217.160.238...
* Connected to google.com (172.217.160.238) port 80 (#0)
> HEAD / HTTP/1.1            # Making request to server      : Type of request
> Host: google.com           # Making request to server      : Requesting host
> User-Agent: curl/7.47.0    # Making request to server      : Requesting via program
> Accept: */*                # Making request to server      : content-type that the client understands
> 
< HTTP/1.1 301 Moved Permanently          # Response from server  : Reponse code
< Location: http://www.google.com/        # Response from server  : indicates the URL to redirect a page to (for 3XX)
< Content-Type: text/html; charset=UTF-8  # Response from server  : content-type that server understands     
< Date: Mon, 11 Feb 2019 10:03:51 GMT     # Response from server  : Server time  
< Expires: Wed, 13 Mar 2019 10:03:51 GMT  # Response from server  : date/time after which the response is considered stale.
< Cache-Control: public, max-age=2592000  # Response from server  : directives for caching mechanisms in both requests and responses       
< Server: gws                             # Response from server  : software used by the origin server to handle the request.
< Content-Length: 219                     # Response from server  : size of the entity body in the message, in bytes
< X-XSS-Protection: 1; mode=block         # Response from server  : if a potential XSS detected, then browser will prevent rendering of the page       
< X-Frame-Options: SAMEORIGIN             # Response from server  : the page can be in a frame as long as the site including it in the frame is the same as the one serving the page.
< 
```

<h3>NOTE : </h3> 

  &nbsp; -> While testing always look forward and test for all available HTTP request Methods for a particular resource.
