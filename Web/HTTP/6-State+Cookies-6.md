
<h3>STATE + COOKIES</h3>

&nbsp; -> HTTP Server is stateless i.e it does not retain state or previous request from any client which also means that for 2 diff pages the user must need to authenticate seperately. </br>
&nbsp; -> Now since from a user-perspective it would be very cumberome to type username+password on every page thus comes in `cookies`.</br>
&nbsp; -> Cookies(plain text ID like thing) are used for state management with user preferences.</br>
&nbsp; -> Cookies are stored on client side and individual cookie size cannot exceed 4K (whereas sesison ids are stored on the server).</br>
&nbsp; -> These cookies one set are now send with each request from client to server and it's response. </br>
&nbsp; -> Cookies are basically name-value pairs , in addition to which it contains some attributes. </br>
&nbsp; -> Cookies can be set over specific paths too. </br>

```bash
Set-Cookie: <name>=<value> .... # Can be multiple 
[; expires = <expiryDate>] # other attributes associated with the cookies. # browser  will delete this cookie when that date is reached
[; domain = <domain_name>] # other attributes associated with the cookies. 
[; path = </customPath >]  # other attributes associated with the cookies. 


# Incase the expires attribute is not present ==> The cookie is server cookie i.e browser should delete it as soon as the user closes browser. # IMP
alternate to expires is max-age (time in seconds once the client recieves the cookie)

[ secure ]   # Use over https only.
[ httponly ] # Dont allow client side JS to use cookie 

```
