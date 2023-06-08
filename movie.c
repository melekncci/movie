#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Budget {
    int budget;
    int year;
    char *title;
    char *titletype;
    char *top250;
};

struct Name {
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    double rating;
    double score;
    char *url;
    double runtime;
    int genreNum;
    int directorNum;
};

struct Budget *budgetArray = NULL;
struct Name *nameArray = NULL;
int numMovies = 0;

void parseMovieInfo(char *line) {
    char *token = strtok(line, ";");

    struct Name name;
    struct Budget budget;
    budget.budget = atoi(token);

    token = strtok(NULL, ";");
    budget.title = strdup(token);
    name.title = strdup(budget.title);
  
    token = strtok(NULL, ";");
    budget.titletype = strdup(token);

    name.directors = NULL;
    token = strtok(NULL, ";");
    char *tempToken = token;
  
    token = strtok(NULL, ";");
    name.rating = atof(token);

    token = strtok(NULL, ";");
    name.runtime = atof(token);
  
    token = strtok(NULL, ";");
    budget.year = atoi(token);

    token = strtok(NULL, ";");
    char *tempToken2 = token;
  
    token = strtok(NULL, ";");
    name.score = atof(token);
  
    token = strtok(NULL, ";");
    name.mustsee = strdup(token);

    token = strtok(NULL, ";");
    budget.top250 = strdup(token);

    token = strtok(NULL, ";");
    name.url = strdup(token);

    char *directorsToken = strtok(tempToken, ",");
    int directorsCount = 0;
    while (directorsToken != NULL) {
        name.directors = realloc(name.directors, (directorsCount + 1) * sizeof(char *));
        name.directors[directorsCount] = strdup(directorsToken);
        directorsToken = strtok(NULL, ",");
        directorsCount++;
    }
    name.directorNum = directorsCount;
  
    name.genre = NULL;
    char *genreToken = strtok(tempToken2, ",");
    int genreCount = 0;
    while (genreToken != NULL) {
        name.genre = realloc(name.genre, (genreCount + 1) * sizeof(char *));
        name.genre[genreCount] = strdup(genreToken);
        genreToken = strtok(NULL, ",");
        genreCount++;
    }
    name.genreNum = genreCount;
  
    budgetArray = realloc(budgetArray, (numMovies + 1) * sizeof(struct Budget));
    budgetArray[numMovies] = budget;

    nameArray = realloc(nameArray, (numMovies + 1) * sizeof(struct Name));
    nameArray[numMovies] = name;

    numMovies++;
}

void printBudgetArray() {
    printf("Budget Array:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Budget: %d, Year: %d, Title: %s, Type: %s, Top 250: %s\n",
            budgetArray[i].budget, budgetArray[i].year, budgetArray[i].title,
            budgetArray[i].titletype, budgetArray[i].top250);
    }
    printf("\n");
}

void printNameArray() {
    printf("Name Array:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s, Must See: %s, Rating: %.2f, Score: %.2f, URL: %s\n",
            nameArray[i].title, nameArray[i].mustsee, nameArray[i].rating,
            nameArray[i].score, nameArray[i].url);
        printf("Genres:");
        for (int j = 0; j < nameArray[i].genreNum; j++) {
            printf("%s\n", nameArray[i].genre[j]);
        }
        printf("Directors:");
        for (int j = 0; j < nameArray[i].directorNum; j++) {
            printf("%s\n", nameArray[i].directors[j]);
        }      
    }
    printf("\n");
}

void listGenres() {
    printf("Genres:\n");
    for (int i = 0; i < numMovies; i++) {
        for (int j = 0; j < nameArray[i].genreNum; j++) {
            printf("%s\n", nameArray[i].genre[j]);
        }
    }
    printf("\n");
}

void listMoviesThroughYears() {
    printf("Movies Through the Years:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%d: %s\n", budgetArray[i].year, budgetArray[i].title);
    }
    printf("\n");
}

void listMoviesThroughScores() {
    printf("Movies Through the Scores:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%.2f: %s\n", nameArray[i].score, nameArray[i].title);
    }
    printf("\n");
}

void printMovieInfo(int index) {
    printf("Movie Information:\n");
    printf("Budget: %d, Year: %d, Title: %s, Type: %s, Top 250: %s\n",
        budgetArray[index].budget, budgetArray[index].year, budgetArray[index].title,
        budgetArray[index].titletype, budgetArray[index].top250);
    printf("Title: %s, Must See: %s, Rating: %.2f, Score: %.2f, URL: %s\n",
        nameArray[index].title, nameArray[index].mustsee, nameArray[index].rating,
        nameArray[index].score, nameArray[index].url);
    printf("Genres:\n");
    for (int i = 0; i < nameArray[index].genreNum; i++) {
        printf("%s\n", nameArray[index].genre[i]);
    }
    printf("Directors:\n");
    for (int i = 0; i < nameArray[index].directorNum; i++) {
        printf("%s\n", nameArray[index].directors[i]);
    }
    printf("\n");
}

void printGenreFrequency() {
    printf("Genre Frequency:\n");
    // Count the frequency of genres
    int genreCount = 0;
    char **genres = NULL;
    int *frequency = NULL;

    for (int i = 0; i < numMovies; i++) {
        for (int j = 0; j < nameArray[i].genreNum; j++) {
            int exists = 0;
            for (int k = 0; k < genreCount; k++) {
                if (strcmp(genres[k], nameArray[i].genre[j]) == 0) {
                    frequency[k]++;
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                genreCount++;
                genres = realloc(genres, genreCount * sizeof(char *));
                genres[genreCount - 1] = strdup(nameArray[i].genre[j]);

                frequency = realloc(frequency, genreCount * sizeof(int));
                frequency[genreCount - 1] = 1;
            }
        }
    }

    // Print the genre frequency
    for (int i = 0; i < genreCount; i++) {
        printf("%s: %d\n", genres[i], frequency[i]);
    }

    // Free allocated memory
    for (int i = 0; i < genreCount; i++) {
        free(genres[i]);
    }
    free(genres);
    free(frequency);

    printf("\n");
}

void freeMemory() {
    for (int i = 0; i < numMovies; i++) {
        free(budgetArray[i].title);
        free(budgetArray[i].titletype);
        free(budgetArray[i].top250);
        free(nameArray[i].title);
        free(nameArray[i].mustsee);
        free(nameArray[i].url);
        for (int j = 0; j < nameArray[i].genreNum; j++) {
            free(nameArray[i].genre[j]);
        }
        free(nameArray[i].genre);
        for (int j = 0; j < nameArray[i].directorNum; j++) {
            free(nameArray[i].directors[j]);
        }
        free(nameArray[i].directors);
    }
    free(budgetArray);
    free(nameArray);
}

int main(int argc, char *argv[]) {
  
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char line[500];
    int control = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        if (control == 0) {
          control++;
          continue;
        }
        parseMovieInfo(line);
    }

    fclose(file);

    int choice;
    do {
        printf("Menu:\n");
        printf("1. List of budget array\n");
        printf("2. List of name array\n");
        printf("3. List of genres\n");
        printf("4. List of the Movie Through the Years\n");
        printf("5. List of the Movie Through the Scores\n");
        printf("6. All Information of a Single Movie\n");
        printf("7. Frequency of the Genres\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printBudgetArray();
                break;
            case 2:
                printNameArray();
                break;
            case 3:
                listGenres();
                break;
            case 4:
                listMoviesThroughYears();
                break;
            case 5:
                listMoviesThroughScores();
                break;
            case 6: {
                int index;
                printf("Enter the index of the movie: ");
                scanf("%d", &index);
                if (index >= 0 && index < numMovies) {
                    printMovieInfo(index);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            }
            case 7:
                printGenreFrequency();
                break;
            case 8:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

    freeMemory();

    return 0;
}
