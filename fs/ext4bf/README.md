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

The ext4bf module
=================
This module contains the ext4bf (ext4-barrierfree) module. This replaces two
modules in the original ext4 file system: ext4 and jbd2.   
