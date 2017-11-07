#include <iostream>  /* Header that defines the standard input/output stream objects */
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
using namespace std;


/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 */
int openPort(void)
{
  int fd; /* File descriptor for the port */
  fd = open("/dev/ttyXRUSB1", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
                perror("open_port: Unable to open /dev/ttyXRUSB1 - ");
                }
           else {
                fcntl(fd, F_SETFL, 0);
                }
  return (fd);
}





int main() 
{
    cout << "Hello, World!";
    return 0;
}
