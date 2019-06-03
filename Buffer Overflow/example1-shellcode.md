
<h2> ShellCode (No Sockets) </h2>

<ul>
<li type=0> In the <a href="./stackSmashing.md">previous example/Intro</a> we had the <b>dangerousFunction()</b> present inside the code, which wont be the case almost ever(untill someone does not intentionally wants to add a backdoor).</br></li> 
<li type=0> This post would be primarily about writing your own code which you can inject inside the executable and then call it after getting buffer overflow.</br></li> 
</ul>
</br>
<h4>[*] Exploit Me </h4>
<ul>
<li type=0> For this post , the example code which we will be going to exploit is : </br></li> 

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
</br>
<h4>[*] Our ShellCode</h4>
<ul>
<li type=0> In this example we will simply be spawning a shell using the STDIN only and not sockets i.e bind or reverse shell</br></li> 
</ul>

