umount /mnt/mydisk
modprobe -r ext4bf
make
make modules_install
echo "Loading module"
modprobe ext4bf
echo "Mounting fs"
mount -t ext4bf -o nodelalloc,nobarrier,nouser_xattr,noacl,data=journal  /dev/sdb1 /mnt/mydisk
echo "Fs contents"
ls /mnt/mydisk/
