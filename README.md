# Movie Information Management System

## Description

This project is a command-line program designed to manage and analyze movie data from a text file. The program reads a file named `movie.txt`, which contains movie data with columns separated by semi-colons (`;`). The data is decomposed into two dynamic arrays: `Budget` and `Name`, each holding different aspects of movie information. The program supports various operations for managing and querying this data through a user-driven menu.

## Project Structure

### Data Structures

1. **Budget Struct**
   - `int budget`: Budget of the movie
   - `int year`: Release year of the movie
   - `char *title`: Title of the movie
   - `char *titletype`: Type of the movie (e.g., Feature, Short)
   - `char *top250`: Rank in IMDb Top 250 (if any)

   ```c
   struct Budget {
       int budget;
       int year;
       char *title;
       char *titletype;
       char *top250;
   };
   ```

2. **Name Struct**
   - `char **genre`: Array of genres
   - `char *title`: Title of the movie
   - `char **directors`: Array of directors
   - `char *mustsee`: Indicates if the movie is a must-see
   - `double rating`: IMDb rating of the movie
   - `double score`: User rating score
   - `char *url`: URL of the movie's page

   ```c
   struct Name {
       char **genre;
       char *title;
       char **directors;
       char *mustsee;
       double rating;
       double score;
       char *url;
   };
   ```

### Program Functionality

1. **Reading the File**
   - The program takes the file name as a command-line argument.
   - Each row of the file is read, and information is split based on semi-colons (`;`).
   - Movies are stored in dynamic arrays `Budget` and `Name`.

2. **Sorting**
   - The `Budget` array is sorted in descending order by year. If years are the same, it is sorted by budget in descending order.

3. **Operations Menu**
   The program supports the following operations through a user-driven menu:

   1. **List of Budget Array**: Displays the contents of the `Budget` array.
   2. **List of Name Array**: Displays the contents of the `Name` array.
   3. **List of Genres**: Lists all genres available in the dataset.
   4. **List of Movies Through the Years**: Lists movies sorted by their release years.
   5. **List of Movies Through the Scores**: Lists movies sorted by their scores.
   6. **All Information of a Single Movie**: Displays detailed information about a specific movie.
   7. **Frequency of Genres**: Shows how often each genre appears in the dataset.
   8. **Exit**: Terminates the program.

   If the user enters an invalid option or performs an operation that has already been completed, an error message will be displayed and the menu will reappear.

## Compilation and Execution

1. **Compile the Program**
   ```bash
   gcc -o movie_manager movie_manager.c
   ```

2. **Run the Program**
   ```bash
   ./movie_manager movie.txt
   ```

   Replace `movie.txt` with the path to your data file.

## Example File

An example of the `movie.txt` file format:

```
100000000;2022;The Great Movie;Feature;10;Action,Adventure;John Doe,Jane Smith;Yes;8.5;7.9;http://example.com
200000000;2021;Another Movie;Feature;5;Drama;Alice Johnson,Bob Brown;No;7.4;8.1;http://example.com
```

## Notes

- Ensure that the input file (`movie.txt`) is formatted correctly with semi-colon-separated values.
- Strings are dynamically allocated, and proper memory management is crucial to avoid leaks.

## Contact

For any questions or issues, please [contact!](mailto:melekncci@gmail.com).
```
