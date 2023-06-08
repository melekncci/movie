# movie

Description: 

Write a complete program achieving all the tasks below.
The program takes a single argument as the name of the file to be read. A sample file is attached (movie.txt). The program reads this file which has labeled columns separated by semi-colon (;). Every row of this text file includes information about a movie. You are asked to read every row as a string and decompose the given information (separated by semi-colon). 
Hint: you can search int main(int argc, char *argv[]) properties. For seperating lines learn and use strtok function. 
The program should keep the movies in two dynamic arrays whose nodes are named as Budget and Name. 

In Budget, there should be five components; budget and year are kept as integers, and the name, title,titletype and top250 are stored as strings. 
struct Budget
{
      int budget;
      int year;
      char *title;
      char *titletype;
      char *top250;
};
In Name there should be seven fields; genre and directors are stored as string arrays (note that these can have more than one string and these are seperated by comma),  title, mustsee, url are stored as string and score, rating are stored as double. 
struct Name
{
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    double rating;
    double score;
    char *url;
};

In the Budget array, elements are inserted and kept in descending order by year. If years are the same, it should keep elements according to their budget in descending order. If these two values are the same, you can choose an arbitrary order among them. There should be exactly the same number of elements in these lists as the number of lines in the file.
The program should keep the all strings (can be of arbitrary length) in dynamically allocated strings.
The number of movies in the Movies.txt file is unknown.
The program should support 7 different operations. Therefore, there should be a menu like the one below. The program should be terminated if and only if the user enters "8" as input. If an entry is invalid or the previously requested action has been taken, the menu should appear repeatedly. If the menu appears due to an invalid entry, there should also be an error message.
7 Operations as follows:
1.	List of budget array
2.	List of name array
3.	List of genres
4.	List of the Movie Through the Years
5.	List of the Movie Through the Scores
6.	All Information of a Single Movie
7.	Frequecy of the Genres
8.	Exit

