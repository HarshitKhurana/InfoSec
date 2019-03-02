
<h3> SHELLCODE </h3>

</br>
<b>Ques:</b> What is Shellcode ? </br>
<b>Ans: </b> A Shellcode is basically a list of carefully crafted instructions that can be executed once the code is injected into a running application to gain shell over it (not necessary though now a days, earlier only used for that purpose)</br>
</br>
<ul>
<li type=0> In the <a href="./stackSmashing.md">previous example/Intro</a> we had the `dangerousFunction` present inside the code, which wont be the case almost ever(untill someone does not intentionally wants to add a backdoor).</br></li> 
<li type=0> This post would be primarily about writing your own code which you can inject inside the executable and then call it after getting buffer overflow.</br></li> 
<li type=0> For this blog , the example exploitable code is as : </br></li> 

```bash
user@PC-Name:~# cat exploitUsingShellCode.c

```

<li type=0> Before writing our shellcode , things to keep in mind: </br></li> 
&nbsp; -> Cannot use `null character` in shellcode because shellcode will be places in char array, for which null is end of string.</br>
&nbsp; -> Address of binary which will spawn shell (Ex : `/bin/bash`) gets fixed when you compile shellCode which might not work across diff machines, For this we can use </i><b>relative addressing</b></i></br>
&nbsp; </br>
<li type=0> Writing our shellcode in C</br></li> 
<li type=0> </br></li> 
</ul>
