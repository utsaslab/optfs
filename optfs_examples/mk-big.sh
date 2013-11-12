umount /mnt/mydisk
mkfs.ext4 -j -J size=1024 -E lazy_itable_init=0,lazy_journal_init=0 /dev/sdb1
