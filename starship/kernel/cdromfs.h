
#ifndef CDROMFS_H
#define CDROMFS_H

#include "kernel/types.h"

#define CDROMFS_BLOCK_SIZE 2048

struct cdrom_volume {
	int root_sector;
	int root_length;
	int total_sectors;
};

struct cdrom_dirent {
	int sector;
};

int cdrom_init();

#endif
