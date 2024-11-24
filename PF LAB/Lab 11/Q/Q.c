#include <stdio.h>
#include <string.h>

typedef struct p {
    char name[20];
    char team[20];
} player;

typedef struct bowl {
    char type[10]; // Seemer, pacer, spinner, or N/A
    char arm[6];   // Left or right
    player ply;
} bowl;

typedef struct b {
    char type[15];   // Top order, middle order, lower order
    char handed[10]; // Lefty or righty
    bowl ply2;
} bat;

FILE *ptr;

void create() {
    ptr = fopen("lab11.txt", "w");
    if (ptr == NULL) {
        printf("Error: Could not create the file.\n");
        return;
    }
    printf("File created successfully.\n");
    fclose(ptr);
}

void write() {
    bat players[5] = {
        {"lower order", "lefty", {"pacer", "right", {"Naseem Shah", "Pakistan"}}},
        {"top order", "righty", {"spinner", "left", {"Shaheen Afridi", "Pakistan"}}},
        {"middle order", "lefty", {"seemer", "right", {"Mohammad Amir", "Pakistan"}}},
        {"top order", "righty", {"N/A", "N/A", {"Babar Azam", "Pakistan"}}},
        {"lower order", "lefty", {"N/A", "N/A", {"Shadab Khan", "Pakistan"}}}
    };

    ptr = fopen("lab11.txt", "w");
    if (ptr == NULL) {
        printf("Error: Could not open the file for writing.\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        fprintf(ptr,
                "Name: %s | Team: %s | Bat type: %s | Handed: %s | Bowl Type: %s | Arm: %s\n",
                players[i].ply2.ply.name, players[i].ply2.ply.team, players[i].type,
                players[i].handed, players[i].ply2.type, players[i].ply2.arm);
    }

    fclose(ptr);
    printf("Data written successfully.\n");
}

void read() {
    ptr = fopen("lab11.txt", "r");
    if (ptr == NULL) {
        printf("Error: Could not open the file for reading.\n");
        return;
    }

    char ch;
    printf("File contents:\n");
    while ((ch = fgetc(ptr)) != EOF) {
        putchar(ch);
    }
    fclose(ptr);
}

void update() {
    bat updatedPlayer = {"top order", "righty", {"seemer", "left", {"Imad Wasim", "Pakistan"}}};

    ptr = fopen("lab11.txt", "a");
    if (ptr == NULL) {
        printf("Error: Could not open the file for updating.\n");
        return;
    }

    fprintf(ptr,
            "Name: %s | Team: %s | Bat type: %s | Handed: %s | Bowl Type: %s | Arm: %s\n",
            updatedPlayer.ply2.ply.name, updatedPlayer.ply2.ply.team, updatedPlayer.type,
            updatedPlayer.handed, updatedPlayer.ply2.type, updatedPlayer.ply2.arm);

    fclose(ptr);
    printf("Data updated successfully (appended).\n");
}


int main()
{
    create();
    write();
    read();
    update();
    read();
    return 0;
}
