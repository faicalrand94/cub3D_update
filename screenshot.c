# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
#include "cub.h"
#pragma pack(push, 1)
struct my_BITMAPFILEHEADER {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct my_BITMAPINFOHEADER {
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack(pop)

void screeen(t_data *vrs)
{
    if(sizeof(struct my_BITMAPFILEHEADER) != 14 &&
        sizeof(struct my_BITMAPINFOHEADER) != 40)
    {
        printf("bitmap structures not packed properly\n");
        return ;
    }

    //only width and height can be changed in this code:
    int width = vrs->win_width;
    int height = vrs->win_height;

    int bitcount = 24;//<- 24-bit bitmap
    int width_in_bytes = ((width * bitcount + 31) / 32) * 4;    //for padding
    uint32_t imagesize = width_in_bytes * height;   //total image size

    struct my_BITMAPFILEHEADER filehdr = { 0 };
    struct my_BITMAPINFOHEADER infohdr = { 0 };

    memcpy(&filehdr, "BM", 2);//bitmap signature
    filehdr.bfSize = 54 + imagesize;//total file size
    filehdr.bfOffBits = 54; //sizeof(filehdr) + sizeof(infohdr)

    infohdr.biSize = 40; //sizeof(infohdr)
    infohdr.biPlanes = 1; //number of planes is usually 1
    infohdr.biWidth = width;
    infohdr.biHeight = height;
    infohdr.biBitCount = bitcount;
    infohdr.biSizeImage = imagesize;

    //prepare pixel data:
    int x;
    int y = 0;
    unsigned char* buf = malloc(imagesize);
    for(int row = height - 1; row >= 0; row--)
    {
        for(int col = 0; col < width; col++)
        {
            x = vrs->frame[y * vrs->win_width+ col];
            buf[row * width_in_bytes + col * 3 + 0] = (x & 0x000000ff);//blue
            buf[row * width_in_bytes + col * 3 + 1] = (x & 0x0000ff00) >> 8;//red
            buf[row * width_in_bytes + col * 3 + 2] = (x & 0x00ff0000) >> 16;//green
        }
        y++;
    }
    int fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IWUSR | S_IRUSR);

    write(fd, &filehdr, sizeof(filehdr));
    write(fd, &infohdr, sizeof(infohdr));
    write(fd, (char*)buf, imagesize);
    //fwrite(&filehdr, sizeof(filehdr), 1, fout);
    //fwrite(&infohdr, sizeof(infohdr), 1, fout);
    // fwrite((char*)buf, 1, imagesize, fout);
    close(fd);
    free(buf);
}