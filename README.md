The Optimistic File System
==========================
*The Optimistic File System (OptFS) is Linux ext4 variant that implements
Optimistic Crash Consistency, a new approach to crash consistency in journaling
file systems. OptFS improves performance for many workloads, sometimes by an
order of magnitude. OptFS provides strong consistency, equivalent to data
journaling mode of ext4.*

 For technical details, please read the [SOSP
 2013](http://sigops.org/sosp/sosp13/) paper [Optimistic Crash
 Consistency](http://www.cs.wisc.edu/adsl/Publications/optfs-sosp13.pdf).
 Please [cite this
 publication](http://research.cs.wisc.edu/adsl/Publications/optfs-sosp13.bib)
 if you use this work.

Please feel free to [contact me](http://cs.wisc.edu/~vijayc) with
any questions.

#### Description

The code is comprised of two parts:

* The modified Linux 3.2 kernel.

* The OptFS file-system module.

OptFS is referenced in the code as ext4bf (barrier-free version of ext4). The
module can be found at fs/ext4bf/.

#### Compiling and installing the kernel
* From the root kernel folder (where this README is found), do as root:

<pre>make -j4 && make modules && make modules_install && make install</pre>

* Fix up grub (/etc/default/grub) as required.

#### Compiling and loading the OptFS module
* Create /mnt/mydisk

* Navigate to fs/ext4bf folder.

* Make the file system (on /dev/sdb1) using:

<pre>sh mk-big.sh</pre>

   Warning: this creates a file system on /dev/sdb1, erasing all previous
   content. The drive has to be big enough to contain a 16 GB journal.

* Compile and load the module using
   
  <pre>sh load.sh</pre>

   This will result in an OptFS file system on /dev/sdb1, mounted at
   /mnt/mydisk.

#### Caveats 

This version of the code provides only *eventual durability*: every OptFS
(ext4bf) fsync() call behaves likes an osync(). Therefore, any unmodified
application running on ext4bf behaves as if every fsync() was replaced by an
osync(). This allows you to take any application and run it on OptFS to
determine the maximum performance you could potentially get. 

Note that the code is provided "as is": compiling and running the code will
require some tweaking based on the operating system environment. The file
system is only meant as a prototype and not meant for production use in any
way.
