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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            // Update pixel with sepia values
            if (sepiaRed >= 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen >=255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue >=255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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
