<h3> Buffer Overflow </h3>
<b>-> This repo contains things related to Buffer Overflow only (mostly stack based). </b></br> 
-> For examples/references/code etc all the testing is done on ubuntu 32|64-bit machine unless otherwise stated.
</br>
</br>
<b> Ques : But why now ? </b></br>
Ans : Beause basics are important and moreover though there are many protections available in the compiler to stop from buffer overflow attacks such as Stack Canary , ASLR, DEP etc this doesn't necessarily means that they cannot be bypassed.
</br>
</br>

<b> Ques : What do we try to achieve in Buffer Overflow? </b></br>
<b> Ans &nbsp; : </b> The way buffer Overflow works is by redirecting the code execution flow to a custom shellcode (which is obv present somewhere in the memory), this flow redirection is done using registers such as IP(Instruction pointer), SP(Stack Pointer) etc and once the flow is modified our custom shellcode is executed and hence Code Execution is achieved.
<hr>
<b>[*] Resources </b>
</br>
</br>
&nbsp; ->  Do Stack buffer overflow good <a href="https://www.youtube.com/watch?v=renR0Aj2YzI">Presentation(youtube)</a> : <a href="https://github.com/justinsteven/dostackbufferoverflowgood"> Presentation material(github)</a>
</br>
&nbsp; ->  LiveOverflow <a href="http://liveoverflow.com/blog/index.html"> Blog on Buffer overflow</a> 
</br>
&nbsp; ->  <a href="https://gcc.gnu.org/git/?p=gcc.git;a=blob;f=libssp/ssp.c;h=536fb917a49f4305d3c6e2b773a02239a25e4738;hb=HEAD"> libssp : Library responsible for detecting stack smashing</a> 
</br>
&nbsp; ->  <a href="http://www.cis.syr.edu/~wedu/Teaching/IntrCompSec/LectureNotes_New/Buffer_Overflow.pdf"> Buffer Overflow notes</a> 
</br>
