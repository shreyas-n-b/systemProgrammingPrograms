#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
int main() 
{
    char filename[100];
    struct stat info;
    printf("Enter system file path: ");
    scanf("%s", filename);
    // Use stat() to obtain file metadata
    if (stat(filename, &info) == -1) 
   {
        perror("stat");
        return 1;
    }
    printf("\n----- FILE INFORMATION -----\n");
    // File size
    printf("File Size      : %ld bytes\n", info.st_size);
    // Owner and group (numeric values only)
    printf("Owner UID      : %d\n", info.st_uid);
    printf("Group GID      : %d\n", info.st_gid);
    // Permissions (octal)
    printf("Permissions    : %o\n", info.st_mode & 0777);
    // Last modification time
    printf("Last Modified  : %s", ctime(&info.st_mtime));
    // File type identification
    if (S_ISREG(info.st_mode))
        printf("File Type      : Regular File\n");
    else if (S_ISDIR(info.st_mode))
        printf("File Type      : Directory\n");
    // else if (S_ISLNK(info.st_mode))
    //     printf("File Type      : Symbolic Link\n");
    else
        printf("File Type      : Other\n");
    return 0;
}
