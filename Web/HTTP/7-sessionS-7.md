
<h3>SESSION IDs</h3>

&nbsp; -> Just a unique identifier/token to verify a user and it's session.</br>
&nbsp; -> Authenticated as well as anonymous users can be provided sessionId </br>
&nbsp; -> Stored on server (whereas cookies are stored in client's browser)</br>
&nbsp; -> Should be </br>
<ul>
<li> &nbsp; Non-bruteforcable</li>
<li> &nbsp; Random name & Random value (so that an attacker doesn't understand)</li>
<li> &nbsp; Long </li>
<li> &nbsp; Should timeout and not recycle</li>
<li> &nbsp; <b>MUST use over HTTPS </b> bcoz if attacker gets hands over sessionId, he could do things with it </li>
<li> &nbsp; should not be derived from any username|password etc. </li>
</ul>
