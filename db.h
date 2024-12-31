#ifndef __DF_H_
#define __DF_H_

enum ino_type {
	DIREC,
	REG
};

struct inode_obj {
	unsigned long int ino;
	char *path;
	enum ino_type type;
};

void create_db(char *dbfile);

#endif
