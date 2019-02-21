
<h3> Web-Methods-Nmap </h3>

&nbsp; -> Using NMAP for HTTP method Testing.</br>
&nbsp; -> Various nse modules are present in nmap to help us on this. </br>
&nbsp; -> This mechanism of changing the request method in HTTP to fetch different options is called <b>Verb Tampering</b></br>
&nbsp; -> To find NSE scripts </br>

```bash
locate *.nse
```
</br>
&nbsp; EXAMPLE : 
</br>

```bash
nmap --script=http-methos.nse <Host_or_IP_to_scan> -n -p 80

# -n : No dns resolution
# -p : Port

```
NOTE : This will only work if the <b>OPTIONS</b> method is enabled on the server.


