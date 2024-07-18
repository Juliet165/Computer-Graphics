# Computer Graphics Applications

This repository contains various computer graphics applications developed for different laboratory works. Each application demonstrates specific algorithms and methods in computer graphics using different programming languages and frameworks.

## Table of Contents

1. [Lab 1: Color Models](https://github.com/Juliet165/Computer-Graphics/tree/master/LAB_1)
2. [Lab 2: Reading Information from Graphic Files](https://github.com/Juliet165/Computer-Graphics/tree/master/LAB_2)
3. [Lab 3: Basics of Digital Image Processing](https://github.com/Juliet165/Computer-Graphics/tree/master/LAB_3)
4. [Lab 4: Line and Curve Clipping Algorithms](https://github.com/Juliet165/Computer-Graphics/tree/master/LAB_4)
5. [Lab 5: Line and Polygon Clipping Algorithms](https://github.com/Juliet165/Computer-Graphics/tree/master/LAB_5)
6. [Lab 6: 3D Visualization Methods and Algorithms](https://github.com/Juliet165/Computer-Graphics/tree/master/LAB_6)

## Lab 1: Color Models

### Description
This application demonstrates various color models and allows users to convert between them.

### Technologies Used
- **Programming Language**: C++
- **Framework**: Qt 5.15.2

### Features
- Select and display colors using different models.
- Convert between RGB, CMYK, and other color models.
- Real-time update of color components.

### Files
- `colors.cpp`
- `colors.h`
- `main.cpp`

## Lab 2: Reading Information from Graphic Files

### Description
This application reads and displays information from various graphic files.

### Technologies Used
- **Programming Language**: C++
- **Framework**: Qt 5.15.2

### Features
- Display file path and information.
- Multiple file selection.
- Show file properties like size, DPI, color depth, and compression.

### Files
- `widget.cpp`
- `widget.h`
- `main.cpp`

## Lab 3: Basics of Digital Image Processing

### Description
This application implements basic digital image processing techniques.

### Technologies Used
- **Programming Language**: Python 3.10

### Libraries
- OpenCV
- Skimage
- Tkinter
- PIL

### Features
- Global thresholding.
- Adaptive thresholding.
- Linear contrast enhancement.
- Pixel-wise operations (negative, squaring, constant multiplication).

## Lab 4: Line and Curve Clipping Algorithms

### Description
This application demonstrates rasterization algorithms for lines and curves.

### Technologies Used
- **Programming Language**: C++
- **Framework**: Qt 5.15.2

### Features
- Step-by-step algorithm.
- DDA algorithm.
- Bresenham's algorithm.
- Circle Bresenham's algorithm.

### Files
- `widget.cpp`
- `widget.h`
- `main.cpp`

## Lab 5: Line and Polygon Clipping Algorithms

### Description
This application demonstrates clipping algorithms for lines and polygons.

### Technologies Used
- **Programming Language**: Python 3.10

### Libraries
- Tkinter
- Matplotlib

### Features
- Cohen-Sutherland algorithm.
- Cyrus-Beck algorithm for convex polygons.

## Lab 6: 3D Visualization Methods and Algorithms

### Description
This application visualizes 3D objects and applies transformations.

### Technologies Used
- **Programming Language**: C++
- **Framework**: Qt 5.14.2

### Libraries
- QMainWindow
- QtOpenGL
- QOpenGLFunctions
- QOpenGLWidget
- QColorDialog

### Features
- Display a 3D letter "K".
- Change the color of the 3D object.
- Apply scaling transformations.

### Files
- `widget.cpp`
- `widget.h`
- `main.cpp`

---

## Installation and Usage

### Prerequisites

- For C++ applications: Qt 5.15.2 or Qt 5.14.2 (depending on the lab)
- For Python applications: Python 3.10 and the required libraries (OpenCV, Skimage, Tkinter, PIL, Matplotlib)

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/Juliet165/Computer-Graphics.git
    cd Computer-Graphics
    ```

2. Follow the instructions in each lab's directory to install dependencies and run the application.
