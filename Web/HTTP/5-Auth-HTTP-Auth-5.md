<h3> HTTP AUTH </h3>

<h4>[*] HTTP Response Codes</h4>
<ul>
<li><b> 1XX </b> : <i> HOLD ON </i></li>
<li><b> 2XX </b> : <i> Request Successful : Here you go </i></li>
<li><b> 3XX </b> : <i> Go There : Redrect</i></li>
<li><b> 4XX </b> : <i> Client fucked up : Client Req Error </i></li>
<li><b> 5XX </b> : <i> Server fucked up : Server Side Error </i></li>
</ul>

<h4>[*] Authenticcation </h4>
&nbsp; -> HTTP only supports 2 types of authentication.
</br>
&nbsp; &nbsp;  &nbsp; 1. <b> Basic Authentication</b>
</br>
&nbsp; &nbsp;  &nbsp; 2. <b> Digest Authentication</b>
</br>
</br>
&nbsp; 1. <b> Basic Authentication</b> 
<ul>
&nbsp; &nbsp; <li type=0>Client asks for a protected resource ,server says since it is a protected resource you need to submit username + password in order to access it, client then further re-requests the resource using the username + password combination , if the server validates the username password combination then 200 is returns or else Unauthorized page is returned(developer created) 4XX.
&nbsp; &nbsp;<li> Encoded in base64
&nbsp; &nbsp;<li> The server will respond with 401(Unauthorized) or 200(Ok).
&nbsp; &nbsp;<li> Since there is on upper limit on number of tries therefore we can easily bruteforce it.
</li></ul>
<ul>  &nbsp; &nbsp;<li> <b>ATTACK </b></li>  </ul>
&nbsp; &nbsp; &nbsp; -> Using Nmap for bruteforcing HTTP Basic Authentication</br></br>

```bash
user@PcName:~$ cat usersList.txt
admin
admin3
administrator
user
user1

user@PcName:~$ cat passwordList.txt
admin
admin3
administrator
user
user1
admin1

# executing nmap NSE script for bruteforcing

user@PcName:~$ nmap -p 80 --script http-brute --script-args 'http-brute.hostname=192.168.1.100,http-brute.method=POST,http-brute.path=/Path/to/BruteForce/onServer,userdb=./usersList.txt,passdb=./passwordList.txt' -n -v 192.168.1.100

```
</br>
&nbsp; 2. <b> Digest Authentication</b> <ul>
&nbsp; &nbsp; <li type=0> The way it works is by sending the hash of the password rather than the base64 encoding the password and sending it. <b>PASSWORD IS NOT SEND IN DIGEST AUTH , RATHER ITS HASH IS</b>
&nbsp; &nbsp; <li type=0> <a href="https://tools.ietf.org/html/rfc2617"> Refer to RFC 2617</a> for how this actually works .

</br>
</br>
  &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <b>RFC 2069</b>
</br>

```bash
    # This will be looped untill the client successfully authenticates with right creds or it leaves the pacge.
    # Client requested server without creds or first request , server response then ->
         HTTP/1.1 401 Unauthorized                            # Server returned unauth on client req  
         WWW-Authenticate: Digest                             # Server returned unauth on client req
                 qop="auth,auth-int",                         # Server returned unauth on client req
                 realm="testrealm@host.com",                  # A.  Server returned (this will be used as it is in the next request which the client will send)       
                 nonce="dcd98b7102dd2f0e8b11d0f600bfb0c093",  # B.  Server returned (this will be used as it is in the next request which the client will send) 
                 opaque="5ccc069c403ebaf9f0171e9517f40e41"    # c.  Server returned (this will be used as it is in the next request which the client will send)

         # HashX : md5(username:realm:password)      # only for explaination 
         # HashY : md5(method:uri)      # only for explaination 

   # This md5 thing is done by the browser itself & it should not be seen in wireshark (but obv visible in burp)
         Authorization: Digest username="Mufasa",             # Client sending request to server  # Username to authenticate with in plain text.
                 realm="testrealm@host.com",                  # Client sending request to server  ( this is the exact value , see above : `A` )      
                 nonce="dcd98b7102dd2f0e8b11d0f600bfb0c093",  # Client sending request to server  ( this is the exact value , see above : `B` )          
                 uri="/dir/index.html",                       # Client sending request to server        
                 qop=auth,                                  
                 nc=00000001,                                 # Client sending request to server    
                 cnonce="0a4f113b",                           # Client sending request to server      
                 response="6629fae49393a05397450978507c4ef1", # Client sending request to server :  Created as : md5(HashX:Nonce:HashY)
                 opaque="5ccc069c403ebaf9f0171e9517f40e41"    # Client sending request to server ( this is the exact value , see above : `C` )             
# The value of HashX and HashY will be same for every client if they are using same creds + on same path.
# Since nonce is diff for every client thus the final response will be diff for everyone, client

## After the server has validated this request then it returns 200 else 401
```
</br>
  &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; <b>RFC 2617</b>
<li> Adds additional security by adding <b> Client side Nonces</b> which helps prevent choosen plaintext attacks.
<li> Adds <b>QOP : Quality of Production</b></br>
  &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; 1.<b> auth </b>: For authentication</br>
  &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; &nbsp; 2.<b> auth-int </b>: For authentication and integrity (Not supported)
<li> It adds 2 more headers i.e cnonce( Client nonce) , NonceCount (a counter) and QOP with the server's response, which is used in calculating the new response which would need to be sent to server for auth.
</br>

```bash
HASHX  # Same as RFC 2069 
HASHY  # Same as RFC 2069
response = md5(HashX : server-Nonce : NonceCount : Client-Nonce : QOP : HashY)
```
</li>
</ul>
