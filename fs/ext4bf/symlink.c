/*
 *  linux/fs/ext4bf/symlink.c
 *
 * Only fast symlinks left here - the rest is done by generic code. AV, 1999
 *
 * Copyright (C) 1992, 1993, 1994, 1995
 * Remy Card (card@masi.ibp.fr)
 * Laboratoire MASI - Institut Blaise Pascal
 * Universite Pierre et Marie Curie (Paris VI)
 *
 *  from
 *
 *  linux/fs/minix/symlink.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 *
 *  ext4bf symlink handling code
 */

#include <linux/fs.h>
#include "jbdbf.h"
#include <linux/namei.h>
#include "ext4bf.h"
#include "xattr.h"

static void *ext4bf_follow_link(struct dentry *dentry, struct nameidata *nd)
{
	struct ext4bf_inode_info *ei = EXT4_I(dentry->d_inode);
	nd_set_link(nd, (char *) ei->i_data);
	return NULL;
}

const struct inode_operations ext4bf_symlink_inode_operations = {
	.readlink	= generic_readlink,
	.follow_link	= page_follow_link_light,
	.put_link	= page_put_link,
	.setattr	= ext4bf_setattr,
#ifdef CONFIG_EXT4_FS_XATTR
	.setxattr	= generic_setxattr,
	.getxattr	= generic_getxattr,
	.listxattr	= ext4bf_listxattr,
	.removexattr	= generic_removexattr,
#endif
};

const struct inode_operations ext4bf_fast_symlink_inode_operations = {
	.readlink	= generic_readlink,
	.follow_link	= ext4bf_follow_link,
	.setattr	= ext4bf_setattr,
#ifdef CONFIG_EXT4_FS_XATTR
	.setxattr	= generic_setxattr,
	.getxattr	= generic_getxattr,
	.listxattr	= ext4bf_listxattr,
	.removexattr	= generic_removexattr,
#endif
};
