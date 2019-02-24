
<h3> ASLR : Address Space Layout Randomisation </h3>
<hr>
<b> Ques : What is ASLR ? </b> 
</br> 
<b> Ans &nbsp; : Address Space Layout Randomisation </b> is a security mechanism that helps protecting(by making it difficult to find address) against code execution via Memory Corruption ( like bufferOverflow ) attacks by randomizing the address space of the code i.e it randomizes the address of the system executables loaded. </br>What it does is simple, a binary is loaded at a different base address in memory upon restart (or reboot for OS dlls). It also randomizes the base addresses for memory segments like the heap and the stack. This makes it harder for attackers to guess the correct address.
</br>
</br>

<b> [*] How to Disable ASLR : </br> </b>
```bash

# Value can be: 
#             0 – No randomization. Everything is static.
#             1 – Conservative randomization. Shared libraries, stack, mmap(), VDSO and heap are randomized.
#             2 – Full randomization. In addition to elements listed in the previous point, memory managed through brk() is also randomized.

echo $value | sudo tee /proc/sys/kernel/randomize_va_space 
# The above line will disable ASLR for the current session i.e untill the machine is rebooted.

# To disable ASLR permanently i.e across reboots
echo $value | sudo tee /etc/sysctl.d/01-disable-aslr.conf
sudo sysctl -p
```

</br>
<b> [*] Example </br> </b>
-> Simple  <i>"/bin/ls"</i> linux binary, when <b>ASLR enabled(default)</b>.</br>

```bash
root@PC-Name:/# ldd /bin/ls
  linux-gate.so.1 =>  (0xf7fb5000)
  libselinux.so.1 => /lib/i386-linux-gnu/libselinux.so.1 (0xf7f84000)
  libacl.so.1 => /lib/i386-linux-gnu/libacl.so.1 (0xf7f7b000)
  libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xf7dca000)
  libpcre.so.3 => /lib/i386-linux-gnu/libpcre.so.3 (0xf7d8c000)
  libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0xf7d87000)
  /lib/ld-linux.so.2 (0xf7fb7000)
  libattr.so.1 => /lib/i386-linux-gnu/libattr.so.1 (0xf7d80000)

root@PC-Name:/# ldd /bin/ls
  linux-gate.so.1 =>  (0xf7fa3000)                  
  libselinux.so.1 => /lib/i386-linux-gnu/libselinux.so.1 (0xf7f72000)
  libacl.so.1 => /lib/i386-linux-gnu/libacl.so.1 (0xf7f69000)
  libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xf7db8000)
  libpcre.so.3 => /lib/i386-linux-gnu/libpcre.so.3 (0xf7d7a000)
  libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0xf7d75000)
  /lib/ld-linux.so.2 (0xf7fa5000)
  libattr.so.1 => /lib/i386-linux-gnu/libattr.so.1 (0xf7d6e000)

# Different libraries/modules are loaded at different addresses.
```

</br>
-> Simple <i>"/bin/ls"</i> linux binary, when <b>ASLR disabled</b>.</br>

```bash
root@PC-Name:~# echo 0 > /proc/sys/kernel/randomize_va_space 
root@PC-Name:~# ldd /bin/bash
  linux-gate.so.1 =>  (0xf7fda000)
  libtinfo.so.5 => /lib/i386-linux-gnu/libtinfo.so.5 (0xf7faa000)
  libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0xf7fa5000)
  libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xf7df4000)
  /lib/ld-linux.so.2 (0xf7fdc000)

root@PC-Name:~# ldd /bin/bash
  linux-gate.so.1 =>  (0xf7fda000)
  libtinfo.so.5 => /lib/i386-linux-gnu/libtinfo.so.5 (0xf7faa000)
  libdl.so.2 => /lib/i386-linux-gnu/libdl.so.2 (0xf7fa5000)
  libc.so.6 => /lib/i386-linux-gnu/libc.so.6 (0xf7df4000)
  /lib/ld-linux.so.2 (0xf7fdc000)
root@ctf_docker:~# 

# Different libraries/modules are loaded at same addresses.

```

</br>
<b> [*] How to Bypass ASLR : </br> </b>
</br>
<ul>
<li>Direct RET overwrite - </br> &emsp; &emsp; Often processes with ASLR will still load non-ASLR modules, allowing you to just run your shellcode via a jmp esp.<br> </li>

 <li>Partial EIP overwrite - </br>&emsp; &emsp; Only overwrite part of EIP, or use a reliable information disclosure in the stack to find what the real EIP should be, then use it to calculate your target. We still need a non-ASLR module for this though.</br></li>

 <li>NOP spray - </br> &emsp; &emsp; Create a big block of NOPs to increase chance of jump landing on legit memory. Difficult, but possible even when all modules are ASLR-enabled. Won't work if DEP is switched on though.</br></li>

 <li>Bruteforce - </br> &emsp; &emsp; If you can try an exploit with a vulnerability that doesn't make the program crash, you can bruteforce 256 different target addresses until it works.(Won't work if DEP is switched on though.)</br></li>

<li><a href="http://www.cs.ucr.edu/~nael/pubs/micro16.pdf">Jump over ASLR, Using branch Predictors </a></br></li>
</ul>
</br>
<b> [*] NOTE: </br> </b>
</br>
&emsp; -> ASLR alone can be very easily bypassed but when used alongside DEP (Data execution Prevention) adds a much stronger security layer.
</br>
