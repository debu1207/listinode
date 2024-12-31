#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "util.h"

int print_inodes = 0;
int print_stats = 0;

void show_usage() {
	printf("%s usage: \n", __FILE__);
}

void show_inodes(char *dir) {
        printf("Listing inodes in the directory; %s\n", dir);
        printf("%-15s %s\n", "Inode Number", "File Name");
	show_dir_files(dir);
}

int main(int argc, char** argv) {                                                                        
        char *dir;                                                                                 
	int opt;
                                                                                                         
        if (argc < 2) {                                                                                  
                perror("Please give directory path to get inodes.");                                     
                exit(1);                                                                                 
        }                                                                                                

	while ((opt = getopt(argc, argv, "ps:")) != -1 ) {
		switch(opt) {
			case 'p':
				dir = argv[argc - 1];
				print_inodes = 1;
				break;
			case 's':
				print_stats = 1;
				break;
			case '?':
				fprintf(stderr, "Invalid arguments");
				show_usage();
				return 1;
			default:
				abort();
		}
	}

	if (print_inodes)
		show_inodes(dir);
	if (print_stats && print_inodes)
		print_stat();

        return 0;
}
