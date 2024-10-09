# COMP133 Final Project - Student Records Management

## Project Overview
This project involves creating a C program to manage and process student records based on data read from a file. The program will use parallel arrays to store student IDs, names, and scores, and provide functionalities such as sorting and querying the data based on various attributes.

## Key Features
- **Data Handling**: Read student data from a specified file and store it using parallel arrays.
- **Grade Calculation**: Compute final grades based on weighted scores of assignments, quizzes, exams, and practicals.
- **Sorting and Display**: Provide options to sort and display data by ID, name, or scores.
- **Querying**: Allow querying of individual student scores by ID or name.
- **Persistence**: Option to save sorted or queried results to a new file as specified by the user.

## Functional Requirements
1. **Read Data**: Prompt for a file name and read student records from the file.
2. **Compute Grades**: Automatically calculate the final grade for each student when reading the data.
3. **User Menu**:
   - Sort by student ID.
   - Sort by name.
   - Sort by score in descending order.
   - Display score by student ID.
   - Display score by student name.
   - Exit program.
4. **Loop Menu**: Continuously display the menu until the exit option is selected.

## Implementation Details
- **Arrays**: Use parallel arrays to manage IDs (integers), names (2D char array), and scores (doubles).
- **Maximum Records**: Handle up to 1,000 student records.
- **Full Name Length**: Assume a maximum of 50 characters for student names.

## Program Flow
1. **Initialization**: Initialize arrays and variables for storing student data.
2. **Data Input**: Ask the user for the input file name and load data into arrays.
3. **Data Processing**: Calculate final grades as data is read.
4. **User Interaction**: Display menu and perform actions based on user choice.
5. **Data Output**: Allow the user to save data after any sorting or querying operation.

