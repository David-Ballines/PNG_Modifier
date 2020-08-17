# PNG Modifier

Wrote a class which can take in a .PNG file and make modify it according to the user. It uses HSLAPixel, PNG, RGB_HSL, and lodepng classes that were given to me during data structures. Improved on an existing class project.

## Getting Started

To use the program, place the .PNG file you wish to modify in the same folder as the source code, make sure the image file has the .png extension. After the files are in desired location run the following commands in bash inside the folder where the files are located and replace [filename] with the name of the image file you want to alter.
```bash
make
./images
[filename].png
```
The program will prompt you to pick from 13 different modifications. To pick one of the modifications enter a number into the bash console. To exit the program you will have to enter 14 into the bash console. One finished a new .PNG file will be created inside the folder with the name "new_" + the name of the original filename.

### Prerequisites

Requires the clang++, libc++abi and. libc++ libraries. They can be installed by running the following commands in bash.
```bash
sudo apt-get update; sudo apt-get install clang-6.0 libc++abi-dev libc++-dev git gdb make
sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-6.0 100
sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-6.0 100
sudo update-alternatives --install /usr/bin/llvm-symbolizer llvm-symbolizer /usr/bin/llvm-symbolizer-6.0 100
```
To read more about clang++ follow the link https://clang.llvm.org/index.html.


### Installing

Download the c++ files and folder into the desired destination.

