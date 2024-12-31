#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_DPATH_LEN 256

int direc_no = 0;
int file_no = 0;

void print_info(char *dname, char *fname, unsigned long int ino) {
	printf("%-15lu %s/%s\n", ino, dname, fname);
}

void show_dir_files(char *path) {
	DIR *dir;
	struct dirent *ent;

	dir = opendir(path);

	if (dir == NULL)
		return;

	while ((ent = readdir(dir)) != NULL) {
		if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..")) {
			char *dpath = malloc(MAX_DPATH_LEN);
			dpath = memset(dpath, 0, MAX_DPATH_LEN);
			dpath = strcpy(dpath, path);
			print_info(dpath, ent->d_name, ent->d_ino);
			if (ent->d_name[0] != '/')
				strcat(dpath, "/");
			strcat(dpath, ent->d_name);
			direc_no++;
			show_dir_files(dpath);
		}
		else if (ent->d_type == DT_REG) {
			file_no++;
			print_info(path, ent->d_name, ent->d_ino);
		}
	}
	closedir(dir);
}

void print_stat() {
	printf("\nTotal directories: %d\nTotal files: %d\n", direc_no, file_no);
}

