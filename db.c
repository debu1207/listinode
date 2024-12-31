#include <stdlib.h>
#include "db.h"

void create_db(char *dbfile, struct inode_obj *db, int num_ino) {
	int fd;
	
	fd = open(dbfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Error opening file for writing");
		return 1;
	}

	/* Writing array of inode_obj structs to the file */
	if (write(fd, db, sizeof(db)) != sizeof(db)) {
		perror("Error writing to file");
		return 1;
	}
	/* close fd */
	close(fd);
}
