#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to apply the kernel to the image
void applyKernel(const vector<vector<int>>& image, const vector<vector<int>>& kernel, vector<vector<int>>& newImage) {
    int rows = image.size();
    int cols = image[0].size();

    for (int i = 0; i <= rows - 3; ++i) {
        for (int j = 0; j <= cols - 3; ++j) {
            int sum = 0;

            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    sum += image[i + x][j + y] * kernel[x][y];
                }
            }

            newImage[i][j] = sum;
        }
    }
}

int main() {
   

   // string outputImageFile = argv[3];

    ifstream inputImageStream("oimge.txt");
    ifstream kernelStream("sharpen_kernel");

    if (inputImageStream.is_open() && kernelStream.is_open()) {
        cout << "Unable to open input files." << endl;
        return 1;
    }

    int rows, cols;
    inputImageStream >> rows >> cols;

    vector<vector<int>> image(rows, vector<int>(cols));
    vector<vector<int>> newImage(rows - 2, vector<int>(cols - 2)); // New image dimensions after applying kernel

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inputImageStream >> image[i][j];
        }
    }

    vector<vector<int>> kernel(3, vector<int>(3));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            kernelStream >> kernel[i][j];
        }
    }

    inputImageStream.close();
    kernelStream.close();

    auto start = high_resolution_clock::now();

    applyKernel(image, kernel, newImage);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    ofstream outputImageStream("output.txt");
    if (!outputImageStream.is_open()) {
        cout << "Unable to open output file." << endl;
        return 1;
    }

    outputImageStream << (rows - 2) << " " << (cols - 2) << "\n";
    for (int i = 0; i < rows - 2; ++i) {
        for (int j = 0; j < cols - 2; ++j) {
            outputImageStream << newImage[i][j] << " ";
        }
        outputImageStream << "\n";
    }

    outputImageStream.close();

    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
