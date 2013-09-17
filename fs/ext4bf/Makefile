#
# Makefile for the linux journaling routines.
#

obj-m += jbdbf.o ext4bf.o

jbdbf-objs := transaction.o commit.o recovery.o checkpoint.o revoke.o journal.o 

ext4bf-objs     := balloc.o bitmap.o dir.o file.o fsync.o ialloc.o inode.o page-io.o \
                ioctl.o namei.o super.o symlink.o hash.o resize.o extents.o \
                ext4bf_jbdbf.o migrate.o mballoc.o block_validity.o move_extent.o \
                mmp.o indirect.o \
                xattr.o xattr_user.o xattr_trusted.o\
                acl.o \
                xattr_security.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

modules_install:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules_install

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
