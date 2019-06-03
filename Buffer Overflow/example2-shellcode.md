
<h3> SHELLCODE </h3>
<hr>

</br>
<b>Ques:</b> What is <b>Shellcode</b> ? </br>
<b>Ans: </b> A Shellcode is basically a list of carefully crafted instructions that can be executed once the code is injected into a running application to gain shell over it (not necessary though now a days, earlier only used for that purpose)</br>
</br>
<ul>
<li type=0> In the <a href="./stackSmashing.md">previous example/Intro</a> we had the <b>dangerousFunction()</b> present inside the code, which wont be the case almost ever(untill someone does not intentionally wants to add a backdoor).</br></li> 
<li type=0> This post would be primarily about writing your own code which you can inject inside the executable and then call it after getting buffer overflow.</br></li> 
<li type=0> For this blog , the example exploitable code is as : </br></li> 

```bash
user@PC-Name:~# cat exploitUsingShellCode.c

#include<stdio.h>
#include<stdlib.h>

void getInput() {
  char ans[12];
  printf("String is at : %p\n",ans);
  gets(ans);
  printf("String is at : %p\n",ans);
  puts(ans);
}

int main(){
  getInput();
}

```

</ul>
<h4>[*] Our ShellCode</h4>
<ul>
<li type=0> What do we want to achieve shellcode </br></li> 
&nbsp; &nbsp; 1.<a href="example1-shellcode.md" target="_blank"> Simply spawning a shell(not reverse)</a></br></li> 
&nbsp; &nbsp; 2.<a href="example2-shellcode.md" target="_blank"> Reverse shell - shellcode</a></br></li> 
</ul>

<h4>[*] Note </h4>
<ul>
<li type=1> <b>Smaller the size of shellcode the better it is</b>, as the input size might be less (place where shellcode will be injected)</br>
<li type=1> Cannot use <b>null character</b> in shellcode because shellcode will be places in char array, for which null is end of string.</br></li>
<li type=1> Address of binary which will spawn shell (Ex : </b>/bin/bash</b>) gets fixed when you compile shellCode which might not work across diff machines, For this we can use </i><b>relative addressing</b></i></br> </li>
<li type=1> You dont always need to write shellcode for <b>reverse shell</b> as it is usually much bigger in size because of sockets involvement.</br>
<li type=1> If the application is already running over socket or there is some way to interact with the application(built into application itself), then instead of getting a reverse shell, just spawn a shell using the interactive pipeline and redirect the input/output, it would drastically reduce the size of the shell.</br>
<li type=1> </br>
</ul>
