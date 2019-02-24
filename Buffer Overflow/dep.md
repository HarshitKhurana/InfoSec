
<h3>DEP : Data Execution Prevention </h3>
<hr>
<b> Ques : What is DEP ? </b> 
</br>
<b> Ans &nbsp; : Data execution prevention (DEP) </b> is a security feature within operating system that prevents applications from executing code from a non-executable memory location. DEP is a hardware and software enforced technology designed to secure against memory-based code exploits.

&nbsp; -> It belongs to a category known as : <i><strong> Executable space protection </strong></i> the way these works is by marking memory regions as non-executable, such that an attempt to execute machine code in these regions will cause an exception.</br> 
&nbsp; -> These may or may not use hardware features such as the NX/XD bit (no-execute/Execute Disable bit)</br> 

</br>
<b> Ques : How does it work ? </b> </br>
<b> Ans &nbsp; : </b> The way buffer Overflow works is by redirecting the code execution flow to a custom shellcode (which is obv present somewhere in the memory), this flow redirection is done using registers such as IP(Instruction pointer), SP(Stack Pointer) etc and once the flow is modified our custom shellcode is executed and hence Code Execution is achieved.</br>
Now what <b>DEP</b> does is that it routinely scans the memory heaps and stacks for actions of loading data into the memory. The hardware enforced DEP mechanism uses the CPU to mark all memory locations that are flagged with an attribute value for non-execution(our custom shellcode is somewhere here only). Once an abnormality is detected in these locations in terms of code execution, an exception is sent to the primary OS security mechanism. Software enforced DEP only checks for an exception within the functions table of the primary application. This provides protection against security esploits like buffer overflow.

</br>
</br>
<b> [*] How to disable DEP </br> </b>
-> Keep in mind that the NX/XD (Non-Executable/Execute Disable) bit must be set in the CPU in order to use DEP(hardware type)</br>
-> To temporarily disable DEP in linux</br>

```bash
sysctl -w kernel.exec-shield=0
```
-> To permanently disable DEP in linux</br>
```bash
echo "kernel.exec-shield=0" | sudo tee -a /etc/sysctl.conf
sudo sysctl -p
```
</br>
<b> [*] ByPassing DEP </br> </b>
<ul>
<li type=1> Bypassing DEP using <a href="https://bytesoverbombs.io/bypassing-dep-with-rop-32-bit-39884e8a2c4a">Return Oriented Programming</a>.</li>
<li type=1> Bypassing DEP using Ret2libc which belongs to ROP only.</li>
<li type=1> Ex : <a href="https://reboare.github.io/bof/linux-stack-bof-3.html"> Buffer Overflow using ret2libc and ROP chaining</a> </li>
<li type=1> Compile your code as 

```bash
gcc myVulnerableCode.c -o myVulnerableCode -z execstack
```

 It will set stack to executable. <b>LOL (you wish the developer did it)</b></li>
</ul>

</br>
<b> [*] NOTE: </br> </b>
&emsp; -> DEP alone can be bypassed but when used alongside <a href="./aslr.md" target="_blank">ASLR (address-space layout randomisation)</a>adds a much stronger security layer.</br>
&emsp; -> DEP is used by default in Ubuntu via the NX/XD bit if the CPU supports it, or emulated via memory segmentation if the CPU does not support it. 
</br>
&emsp; -> More about <a href="https://support.microsoft.com/en-sg/help/875352/a-detailed-description-of-the-data-execution-prevention-dep-feature-in">DEP (Windows blog)</a>. 
</br>
