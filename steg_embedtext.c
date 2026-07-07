#include <stdio.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

//Print a full byte
void print_binary(uint8_t value) {
	for(int i = 7; i >= 0; i--) {

		printf("%d", (value >> i) & 1);

	}
	printf("\n");

}



int main() {

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
		return 1;
	}


	//printf("Image size: %d x %d\n", width, height);
	//printf("Channels  : %d\n\n", channels);


	unsigned char red   = image[0];
	unsigned char green = image[1];
	unsigned char blue  = image[2];

	//Hiding text in an image

	char message[] = "<3 I love you! Soo much! <3";
	int image_index = 0;

	for (int i = 0; message[i] != '\0'; i++) {
		for (int bit = 7; bit >= 0; bit--) {
			int secretBit = (message[i] >> bit) & 1;

			image[image_index] = (image[image_index] & 0xFE) | secretBit;
			image_index += 1;

		}
	}


	//////////////////////
	// Saving the image //
	//////////////////////

	stbi_write_png(
		"output.png",
		width,
		height,
		channels,
		image,
		width * channels
	);


	stbi_image_free(image);


	return 0;

}
