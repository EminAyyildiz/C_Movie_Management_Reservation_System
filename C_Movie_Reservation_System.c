#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAX_MOVIES 100
#define MAX_TITLE_LENGTH 50



struct movie {
    char title[MAX_TITLE_LENGTH];
    int num_seats;
    int reserved_seats;
};

struct movie movies[MAX_MOVIES];
int num_movies = 0;

void add_movie() {
    if (num_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached...\n");
        return;
    }

    printf("Movie Title : ");
    scanf("%s", movies[num_movies].title);

    printf("Total number of seats : ");
    scanf("%d", &movies[num_movies].num_seats);

    movies[num_movies].reserved_seats = 0;

    printf("The Movie is being added to the system. Please wait... \n");
    sleep(1.5);
    num_movies++;

    printf("Movie added.\n");
}

void reserve_seat() {
    int i, num_seats;
    char movie_title[MAX_TITLE_LENGTH];
    
    printf("Movie Title : ");
    scanf("%s", movie_title);
    
    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, movie_title) == 0) {
            printf("Number of Seats to be Reserved : ");
            scanf("%d", &num_seats);
            
            if (movies[i].reserved_seats + num_seats <= movies[i].num_seats) {
                printf("You are being directed to the payment page...Please wait...\n");
                sleep(1.5);
                int payment_method;
                char card_number[50];
                char card_pass[50];
                
                printf("Please select the payment method \n1- Credit Card \n2- CASH\n---> ");
                scanf("%d",&payment_method);
                if (payment_method == 1) {
                    printf("Please enter your card number : \n");
                    scanf("%s",card_number);
                    printf("Please enter your card pass : \n");
                    scanf("%s",card_pass);
                    if (strlen(card_number)>=16 && strlen(card_pass)>=4){
                        printf("Processing payment please wait....\n");
                        sleep(1.5);
                        printf("The payment transaction was successful. Thank you. \n");
                        movies[i].reserved_seats += num_seats;
                        printf("%d seat reserved.\n", num_seats);
                    }
                    else{
                        printf("Wrong card number or password...");
                        return reserve_seat();
                        
                    }
                }
                
                    else if (payment_method == 2) {
                    printf("Your money is being counted... Please wait. \n");
                    sleep(2);
                    printf("The payment transaction was successful. Thank you. \n");
                    movies[i].reserved_seats += num_seats;
                    printf("%d seat reserved.\n", num_seats);
                    
                    
                } else {
                    printf("Invalid payment method. Please try again. \n");
                    return reserve_seat();
                }
            } else {
                printf("Sorry, there are not enough empty seats.\n");
                
            }
            return;
        }
    }
    
    printf("The Specified Movie could not be Found.\n");
}
    
void show_movies() {
    int i;

    if (num_movies == 0) {
        printf("There is no movie yet.\n");
        return;
    }
    printf("Listing all movies... please wait..\n");
    sleep(1.5);
    printf("Movies : \n");

    for (i = 0; i < num_movies; i++) {
        printf("%s (%d/%d)\n", movies[i].title, movies[i].reserved_seats, movies[i].num_seats);
    }
}

void delete_movie() {
    int i, j;
    char movie_title[MAX_TITLE_LENGTH];

    printf("The movie title you want to delete : ");
    scanf("%s", movie_title);

    for (i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, movie_title) == 0) {
            for (j = i; j < num_movies - 1; j++) {
                movies[j] = movies[j + 1];
            }
            printf("The movie is being deleted... Please wait..\n");
            sleep(1.5);
            num_movies--;
            printf("Movie deleted.\n");
            return;
        }
    }

    printf("The specified movie could not be found.\n");
}

int main() {
    printf("*** Written by Emin Ayyıldız *** \n");
    int choice;

    do {
        printf("\n*** MENU *** \n\n");
        printf("1. Add Movie\n");
        printf("2. Show Movies\n");
        printf("3. Reserve Seat\n");
        printf("4. Delete Movie\n");
        printf("0. Exit\n");
        printf("Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie();
                break;
            case 2:
                show_movies();
                
                break;
            case 3:
                reserve_seat();
                break;
            case 4:
                delete_movie();
                break;
            case 0:
                printf("Exiting....Please wait...\n");
                sleep(1.5);
                printf("BYE BYE...\n");
                break;
            default:
                printf("Invalid Choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
