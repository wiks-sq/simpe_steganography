#include <stdio.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void main()
{
	int width;
        int height;
        int channels;

        char image_file[30];
        printf("Enter image name: \n");
        scanf("%s", image_file);

        unsigned char *image = stbi_load(
                image_file,
                &width,
                &height,
                &channels,
                0
        );

        //If image doesn't exist
        if (image == NULL) {
                printf("Failed to load image\n");
                return;
        }


    int image_index = 0;

    while (1)
    {
        unsigned char c = 0;

        // Read one character (8 bits)
        for (int bit = 7; bit >= 0; bit--)
        {
            int hiddenBit = image[image_index] & 1;

            c |= hiddenBit << bit;

            image_index++;
        }

        // Stop at null terminator
        if (c == '\0')
            break;

        printf("%c", c);
    }

    printf("\n");

    stbi_image_free(image);
}
