#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int average = round((image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue) / 3.0);

            // Gán giá trị trung bình cho tất cả các thành phần màu
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagecopy[height][width];
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Swap pixels
            imagecopy[i][j].rgbtRed = image[i][width - j-1].rgbtRed;
            imagecopy[i][j].rgbtGreen = image[i][width - j-1].rgbtGreen;
            imagecopy[i][j].rgbtBlue = image[i][width - j-1].rgbtBlue;
        }
    }

     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Swap pixels
            image[i][j].rgbtRed = imagecopy[i][j].rgbtRed;
            image[i][j].rgbtGreen = imagecopy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = imagecopy[i][j].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];

// Lặp qua từng pixel trong ảnh
for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        // Biến lưu tổng giá trị màu và số pixel liên quan
        int sumRed = 0, sumGreen = 0, sumBlue = 0;
        int numPixels = 0;

        // Lặp qua ô lân cận (3x3 ô xung quanh pixel hiện tại)
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int ni = i + di;
                int nj = j + dj;

                // Kiểm tra pixel lân cận có nằm trong giới hạn ảnh không
                if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                {
                    sumRed += image[ni][nj].rgbtRed;
                    sumGreen += image[ni][nj].rgbtGreen;
                    sumBlue += image[ni][nj].rgbtBlue;
                    numPixels++;
                }
            }
        }

        // Tính giá trị trung bình và gán vào bản sao
        copy[i][j].rgbtRed = round((float)sumRed / numPixels);
        copy[i][j].rgbtGreen = round((float)sumGreen / numPixels);
        copy[i][j].rgbtBlue = round((float)sumBlue / numPixels);
    }
}

// Sao chép giá trị từ `copy` vào `image`
for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        image[i][j] = copy[i][j];
    }
}
}

// Detect edges
// Apply Sobel operator to detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy the original image to store the results
    RGBTRIPLE copy[height][width];

    // Define Sobel kernels
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize Sobel sums
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0;
            float Gy_red = 0, Gy_green = 0, Gy_blue = 0;

            // Loop through the 3x3 grid around the current pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int new_i = i + di;
                    int new_j = j + dj;

                    // Check if the neighboring pixel is within bounds
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        RGBTRIPLE pixel = image[new_i][new_j];

                        // Update Gx and Gy values for each color channel
                        Gx_red   += pixel.rgbtRed * Gx[di + 1][dj + 1];
                        Gx_green += pixel.rgbtGreen * Gx[di + 1][dj + 1];
                        Gx_blue  += pixel.rgbtBlue * Gx[di + 1][dj + 1];

                        Gy_red   += pixel.rgbtRed * Gy[di + 1][dj + 1];
                        Gy_green += pixel.rgbtGreen * Gy[di + 1][dj + 1];
                        Gy_blue  += pixel.rgbtBlue * Gy[di + 1][dj + 1];
                    }
                }
            }

            // Calculate the magnitude of the gradient for each color channel
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Cap the values at 255
            copy[i][j].rgbtRed = red > 255 ? 255 : red;
            copy[i][j].rgbtGreen = green > 255 ? 255 : green;
            copy[i][j].rgbtBlue = blue > 255 ? 255 : blue;
        }
    }

    // Copy the processed pixels back to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
}
