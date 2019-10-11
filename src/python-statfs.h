struct python_statfs {
    long f_type;     /* Type of filesystem (see below) */
    long f_bsize;    /* Optimal transfer block size */
    unsigned long f_blocks;  /* Total data blocks in filesystem */
    unsigned long f_bfree;   /* Free blocks in filesystem */
    unsigned long f_bavail;  /* Free blocks available to
                                unprivileged user */
    unsigned long f_files;   /* Total file nodes in filesystem */
    unsigned long f_ffree;   /* Free file nodes in filesystem */
    long f_fsid;     /* Filesystem ID */
    long f_namelen;  /* Maximum length of filenames */
    long f_frsize;   /* Fragment size (since Linux 2.6) */
    long f_flags;    /* Mount flags of filesystem
                        (since Linux 2.6.36) */
    long f_spare[4]; /* Padding bytes reserved for future use */
};

int python_statfs(const char * file, struct python_statfs * buf, unsigned int len);
