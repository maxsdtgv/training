#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string>
#include <iostream>

int send_uart(int fd)   /* I - Serial port file */
{
  char buffer[255];  /* Input buffer */
  char *bufptr;      /* Current char in buffer */
  int  nbytes;       /* Number of bytes read */
  size_t  sz;        /* Number of tries so far */
  char comm_a[25];
//  for (tries = 0; tries < 3; tries ++)
//  {
   /* send an AT command followed by a CR */
   strcpy(comm_a,  "AT\r");
   sz = strlen(comm_a);
   write(fd, comm_a, sz);
// if (write(fd, "AT\r", 3) < 3)
//   continue;

   /* read characters into our string buffer until we get a CR or NL */
   // bufptr = buffer;
   //std::cout << "Buffer = " << buffer;
   //while ((nbytes = read(fd, bufptr, buffer + sizeof(buffer) - bufptr - 1)) > 0)
   //{
   // bufptr += nbytes;
   // if (bufptr[-1] == '\n' || bufptr[-1] == '\r')
   //   break;
   //}

   /* nul terminate the string and see if we got an OK response */
   // *bufptr = '\0';

   // if (strncmp(buffer, "OK", 2) == 0)
   //   return (0);
//  }

  return (-1);
}

int main(int argc,char** argv)
{
        struct termios tio;
        struct termios stdio;
        struct termios old_stdio;
        int tty_fd;
        char in_buff[50];
        unsigned char c='D';
        tcgetattr(STDOUT_FILENO,&old_stdio);

        printf("Please start with %s /dev/ttyUSB0 B921600 (for example)\n",argv[0]);
        memset(&stdio,0,sizeof(stdio));
        stdio.c_iflag=0;
        stdio.c_oflag=0;
        stdio.c_cflag=0;
        stdio.c_lflag=0;
        stdio.c_cc[VMIN]=1;
        stdio.c_cc[VTIME]=0;
        tcsetattr(STDOUT_FILENO,TCSANOW,&stdio);
        tcsetattr(STDOUT_FILENO,TCSAFLUSH,&stdio);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);       // make the reads non-blocking

        memset(&tio,0,sizeof(tio));
        tio.c_iflag=0;
        tio.c_oflag=0;
        tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
        tio.c_lflag=0;
        tio.c_cc[VMIN]=1;
        tio.c_cc[VTIME]=5;

        tty_fd=open(argv[1], O_RDWR | O_NONBLOCK);
        cfsetospeed(&tio,argv[2]);            // out baudrate
        cfsetispeed(&tio,argv[2]);            // in baudrate

        tcsetattr(tty_fd,TCSANOW,&tio);
        while (c != 'q')
        {
            if (read(tty_fd,&c,1) > 0) {

                write(STDOUT_FILENO,&c,1);
            } // if new data is available on the serial port, print it out

            if (read(STDIN_FILENO,&c,1) > 0) {     // if new data is available on the console, send it to the serial port
                if (c == 'y') {
                    c = 0;
                    send_uart(tty_fd);
                }
                else {
                write(tty_fd,&c,1);
                }
        }
        }

//        init_modem(tty_fd);


        close(tty_fd);
        tcsetattr(STDOUT_FILENO,TCSANOW,&old_stdio);

        return EXIT_SUCCESS;
}
