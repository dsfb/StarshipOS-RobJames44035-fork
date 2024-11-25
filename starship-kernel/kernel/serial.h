
#ifndef SERIAL_H
#define SERIAL_H

void serial_init();

char serial_read(int port_no);
void serial_write(int port_no, char a);

int serial_device_probe( int unit, int *blocksize, int *nblocks, char *info );
int serial_device_read( int unit, void *data, int length, int offset );
int serial_device_write( int unit, const void *data, int length, int offset );

#endif
