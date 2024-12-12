# Huffman Algorithm (C++ Console Application)

![**Workflow Diagram (Image)**](hufffman.png) 

### Project Report
[**Project Report (PDF)**](project-report.pdf)

## Table of Contents

1. [Project Overview](#project-overview)
2. [Technologies Used](#technologies-used)
3. [Features and Capabilities](#features-and-capabilities)
4. [Process Workflow](#process-workflow)
5. [Outcomes and Achievements](#outcomes-and-achievements)
6. [How to Run](#how-to-run)
7. [Skills Demonstrated](#skills-demonstrated)

---

## Project Overview

This project implements the **Huffman Algorithm** to compress data, thereby minimizing memory usage and optimizing system performance. The application supports both manual data input and file-based data processing, showcasing the effectiveness of the algorithm in real-world scenarios. By reconstructing the original data from its compressed form, the program ensures accuracy and transparency in its operations.

---

## Technologies Used

- **Programming Language**: C++
- **Development Environment**: Console Application

---

## Features and Capabilities

### Data Input Options
1. **Manual Input**: Users can directly type or paste the text to be compressed.
2. **File Input**: Users can load data from a `.txt` file for processing.

### Data Processing
- Displays the original data alongside its uncompressed (ASCII) memory representation.
- Compresses the data using the Huffman Algorithm and displays the result.
- Reconstructs the original data from the compressed format for validation.

### Output
- **Console Display**: Provides a detailed overview of the process, including original, compressed, and reconstructed data.
- **File Generation**: Saves separate `.txt` files for both uncompressed and compressed data.

---

## Process Workflow

1. **Algorithm Implementation**
   - The Huffman Algorithm is implemented to generate an optimal prefix code for data compression.
   - The original data is encoded and stored in a compressed format.

2. **File Handling**
   - Users can load data from a file, process it, and save the results to new files.
   - Manual data entry is also supported, enabling greater flexibility.

3. **User Interface**
   - The console-based interface allows users to interact with the program intuitively, displaying all critical information during processing.

4. **Validation**
   - The application verifies the accuracy of compression by reconstructing the original data from the compressed format.

---

## Outcomes and Achievements

- **Memory Optimization**: Successfully reduced memory usage by compressing data using the Huffman Algorithm.
- **Practical Implementation**: Translated theoretical knowledge of data compression into a functional application.
- **Hands-on Experience**: Gained expertise in algorithm development, file handling, and system resource optimization.

---

## How to Run

1. **Clone the Repository**
   ```bash
   git clone https://github.com/your-repository/huffman-algorithm
   ```

2. **Navigate to the Project Directory**
   ```bash
   cd huffman-algorithm
   ```

3. **Compile the Code**
   Use a C++ compiler like `g++` to compile the application:
   ```bash
   g++ -o huffman huffman.cpp
   ```

4. **Run the Application**
   ```bash
   ./huffman
   ```

5. **Provide Input**
   - Manually type or paste the data to be compressed.
   - Or, load a `.txt` file as input.

6. **View Output**
   - Observe the compression and decompression process in the console.
   - Check the generated `.txt` files for compressed and uncompressed data.

---

## Skills Demonstrated

- **C++ Programming**: Designed and implemented the Huffman Algorithm for data compression.
- **File Handling**: Managed data input and output via `.txt` files.
- **Algorithm Development**: Translated theoretical concepts into a functional application.
- **Console-Based UI Design**: Enhanced user experience with a clear and intuitive interface.
