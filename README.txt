Program for changing image contrast and brightness.


Takes in 4 parameters:
- input_image_file_name
- output_image_file_name
- alpha	(Controls contrast. Takes in value between 1.0 and 3.0)
- beta	(Controls brightness. Takes in value between 0 and 100)

For example: ./ContrastBrightness lena.jpg lenaRemastered.jpg 2.2 50


Coded by: Rafal Mossakowski
Language: C++
Based on: http://docs.opencv.org/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html