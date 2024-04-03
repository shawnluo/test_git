
#include "test.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <vector>
#include "stb_image.h"
#include "stb_image_write.h"

struct Pixel {
    uint8_t r, g, b;
};

// Convolution kernel (example: edge detection)
int kernel[3][3] = {
    { -1, -1, -1 },
    { -1,  8, -1 },
    { -1, -1, -1 }
};

int main() {
    // Read the JPEG image
    int imageWidth, imageHeight, imageChannels;
    std::vector<uint8_t> originalPixels = stbi_load("input.jpg", &imageWidth, &imageHeight, &imageChannels, STBI_rgb);
    if (!originalPixels.size()) {
        std::cerr << "Error: Unable to open or decode the image file." << std::endl;
        return 1;
    }

    // Perform convolution on pixel data
    std::vector<Pixel> modifiedPixels; // Store modified pixel data

    // Apply convolution kernel
    // (This is a simplified example, actual implementation may vary)
    // For each pixel in the image...
    for (int y = 0; y < imageHeight; ++y) {
        for (int x = 0; x < imageWidth; ++x) {
            int sumR = 0, sumG = 0, sumB = 0;

            // Apply convolution kernel to surrounding pixels
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    // Ensure boundary conditions
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < imageWidth && ny >= 0 && ny < imageHeight) {
                        // Apply convolution
                        sumR += originalPixels[(ny * imageWidth + nx) * 3] * kernel[i + 1][j + 1];
                        sumG += originalPixels[(ny * imageWidth + nx) * 3 + 1] * kernel[i + 1][j + 1];
                        sumB += originalPixels[(ny * imageWidth + nx) * 3 + 2] * kernel[i + 1][j + 1];
                    }
                }
            }

            // Clamp the values to [0, 255]
            sumR = std::min(std::max(sumR, 0), 255);
            sumG = std::min(std::max(sumG, 0), 255);
            sumB = std::min(std::max(sumB, 0), 255);

            // Save modified pixel
            modifiedPixels.push_back({static_cast<uint8_t>(sumR), static_cast<uint8_t>(sumG), static_cast<uint8_t>(sumB)});
        }
    }

    // Write the modified pixel data back to a new JPEG file
    if (!stbi_write_jpg("output.jpg", imageWidth, imageHeight, 3, modifiedPixels.data(), 100)) {
        std::cerr << "Error: Unable to write the modified image file." << std::endl;
        return 1;
    }

    // Free original pixel data
    stbi_image_free(originalPixels.data());

    std::cout << "Image processing completed successfully. Modified image saved as 'output.jpg'." << std::endl;

    return 0;
}
