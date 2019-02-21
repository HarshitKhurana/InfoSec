
<h3> HTTPS Using SSL</h3>

&nbsp; -> Since HTTP is plaintext : thus an be eavesdropped or data can be sniffed , thus encrypt the data</br> 
&nbsp; -> To encrypt SSL is used which internally relies on public-key crypto and creates a tunnel inside which although data flows.</br> 
&nbsp; -> Usually runs on Port 443 but can be run on any other.</br> 
&nbsp; -> <a href="https://www.websecurity.symantec.com/security-topics/how-does-ssl-handshake-work#h2">SSL Working</a></br> 
&nbsp; -> Client sends a list of available cipher suites that it's browsers supports  </br> 
&nbsp; -> The server responds with the corresponding cipher suites that the server choses for encryption from the list sent by client. </br> 
&nbsp; -> Along with it the server also sends it's certificate for the browser client to verify (the browser client verifies the signature in this certificate).</br> 
&nbsp; -> Once this is done the encrypted channel is set up & the secure communication begins.</br> 
&nbsp; -> Just Remember <b> only the key exchange and server verification is done using public key crypto, rest of the data encryption that is being transferred is encrypted using private key generated only.</b></br> 
&nbsp; -> self-signed certificates can be used for MITM.</br> 
