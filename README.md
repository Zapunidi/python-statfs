Python bindings for statfs
==========================

On Linux, the statfs(2) system call provides information about the file system
type of the mountpoint containing the given path. statfs(2) is not in POSIX.

However, the Python standard library only provides bindings for the POSIX
statvfs(3) function. This function returns much the same information as
statfs(2), except it lacks the file system type.

The `python-statfs` package provides a `statfs` module with a `statfs` function.

Installation:

	pip install https://github.com/Mortal/python-statfs/releases/download/v0.0.2/statfs-0.0.2-py2.py3-none-manylinux1_x86_64.whl

Example usage:

	>>> import statfs
	>>> statfs.statfs("/tmp")
	Statfs(type=16914836, bsize=4096, blocks=4092618, bfree=4087672, bavail=4087672, files=4092618, ffree=4092531, fsid=0, namelen=255, frsize=4096, flags=38)
	>>> statfs.statfs("/tmp").type == statfs.TMPFS_MAGIC
	True

Build:

    python3 setup.py bdist_wheel