#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "functions.h"

using namespace cv;
using namespace std;

int main() {

	// load image
	Mat original = imread("D:\\images\\lorem_sample.png");
	imshow("Original", original);

	// convert original image to binary: only white or black
	Mat binary;
	imageToBinary(original, binary);
	imshow("Binary", binary);
	// imwrite("D:\\images\\border_text_binary.png", binary);

	// extract lines
	vector<textLine> lines;
	extractLinesFromImage(binary, lines);

	// extract characters from lines
	vector<character> characters;
	extractCharactersFromLines(binary, lines, characters);

	// cut off blank spaces from the top and bottom of the characters
	vector<character> cleanCharacters;
	cutOffBlankSpacesFromCharacters(binary, characters, cleanCharacters);

	// resize characters to 32x32 or 64x64
	vector<Mat> resizedCharacters;
	charactersToMats(binary, cleanCharacters, resizedCharacters);
	// charactersToMats(binary, cleanCharacters, resizedCharacters, Size(64, 64));

	// save images
	saveCharacters(resizedCharacters, "D:\\images\\task4");

	// wait
	waitKey();

	return 0;
}