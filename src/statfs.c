#define _GNU_SOURCE
#include <sys/vfs.h>
#include "python-statfs.h"

int python_statfs(const char * file, struct python_statfs * buf, unsigned int len) {
	unsigned int nmemb = len / sizeof(long);
	struct statfs64 tmp;
	if (statfs64(file, &tmp)) return -1;
	if (nmemb < 11) return 0;
	buf->f_type = tmp.f_type;
	buf->f_bsize = tmp.f_bsize;
	buf->f_blocks = tmp.f_blocks;
	buf->f_bfree = tmp.f_bfree;
	buf->f_bavail = tmp.f_bavail;
	buf->f_files = tmp.f_files;
	buf->f_ffree = tmp.f_ffree;
	int * fsid = (void *) &tmp.f_fsid;
	buf->f_fsid = fsid[0] + (((long) fsid[1]) << 32);
	buf->f_namelen = tmp.f_namelen;
	buf->f_frsize = tmp.f_frsize;
	buf->f_flags = tmp.f_flags;
	return 11 * sizeof(long);
}
