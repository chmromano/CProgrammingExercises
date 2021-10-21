#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NMR "N."
#define ADDR "Address"
#define PWD "Password"

#define OPTIONS_PROMPT "Choose an option:\n1. Open existing file\n2. Create new file\n3. Quit\n"
#define FILE_ERROR_MSG printf("There was an error opening the file.\n")
#define MEM_CHECK(x) if(x == NULL){printf("There was an error allocating memory. Quitting program...");exit(1);}

typedef struct entry_ {
    int addr_len;
    char *addr;
    int pwd_len;
    char *pwd;
} ENTRY;

typedef enum {
    NO_OPTION, OPEN_EXISTING, CREATE_NEW, QUIT
} OPTION;

ENTRY *init_entries();

OPTION option_select(FILE **file);

ENTRY *new_entry(ENTRY *entry_array);

void print_entries(char *addr, ENTRY *entry_array);

ENTRY *read_entries(FILE *file);

void write_entries(ENTRY *entry_array, FILE *file);

bool input_integer(int *input);

char *input_string();

int main() {

    OPTION chosen_option = NO_OPTION;

    while (chosen_option != QUIT) {

        ENTRY *entry_array;
        FILE *working_file = NULL;
        printf("Welcome. %s", OPTIONS_PROMPT);

        chosen_option = option_select(&working_file);

        if (chosen_option == CREATE_NEW) {
            entry_array = init_entries();
        } else if (chosen_option == OPEN_EXISTING) {
            entry_array = read_entries(working_file);
        }

        while (chosen_option == CREATE_NEW || chosen_option == OPEN_EXISTING) {

            printf("What would you like to do?\n");
            int chosen_operation;
            while (input_integer(&chosen_operation) == false) printf("Invalid characters.\n");
            switch (chosen_operation) {
                case 1:
                    entry_array = new_entry(entry_array);
                    break;
                case 2:
                    print_entries("*", entry_array);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    chosen_option = NO_OPTION;
                    write_entries(entry_array, working_file);
                    break;
                case 6:
                    chosen_option = NO_OPTION;
                    free(entry_array);
                    break;
                default:
                    break;
            }
        }

        fclose(working_file);
    }

    /*
    FILE *my_file;
    my_file = fopen("image.jpg", "rb");

    if (my_file == NULL) {
        printf("There was an error opening the file.");
    } else {

        unsigned char *array;
        array = NULL;

        unsigned char buffer;

        int i;
        for (i = 1; fread(&buffer, 1, 1, my_file) != 0; i++) {
            array = (unsigned char *) realloc(array, sizeof(unsigned char) * i);
            if (array == NULL) {
                printf("There was an error allocating memory. Ending program.");
                exit(1);
            }
            array[i - 1] = buffer;
        }

        for (int j = 0; j < i; j++) {
            printf("%c", array[j]);
        }

        free(array);
        fclose(my_file);
    }*/

    return 0;
}

ENTRY *init_entries() {
    ENTRY *entry_array;
    entry_array = malloc(sizeof(ENTRY));
    MEM_CHECK(entry_array)
    entry_array->addr_len = 0;
    entry_array->pwd_len = 0;
    return entry_array;
}

OPTION option_select(FILE **file) {

    char *file_name;

    OPTION option = NO_OPTION;

    int choice_main;
    while (input_integer(&choice_main) == false) printf("Invalid characters.\n");

    switch (choice_main) {
        case 1:
            printf("Enter file to open: ");
            file_name = input_string();
            *file = fopen(file_name, "rb");
            if (*file == NULL) {
                FILE_ERROR_MSG;
            } else {
                option = OPEN_EXISTING;
            }
            free(file_name);
            break;
        case 2:
            printf("Enter file name: ");
            file_name = input_string();
            *file = fopen(file_name, "wb");
            if (*file == NULL) {
                FILE_ERROR_MSG;
            } else {
                option = CREATE_NEW;
            }
            free(file_name);
            break;
        case 3:
            option = QUIT;
            printf("Quitting program...");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return option;
}

bool delete_entry(char *addr, ENTRY *entry_array) {

}

char *encrypt(char *pwd, int pwd_len) {
    char *master_buffer;
    int master_index = 0;
    int pwd_index = 0;

    printf("Enter master password: ");
    master_buffer = input_string();

    pwd = malloc(sizeof(char) * pwd_len);
    MEM_CHECK(pwd)

    while (pwd_index < pwd_len) {

        pwd[pwd_index] = (char) (pwd[pwd_index] ^ master_buffer[master_index]);

        pwd_index++;
        master_index++;
        if (master_index > (int) strlen(master_buffer)) master_index = 0;
    }

    free(master_buffer);
    return pwd;
}

ENTRY *new_entry(ENTRY *entry_array) {
    int i;
    for (i = 0; (entry_array + i)->addr_len != 0; i++);
    printf("\n\n%d\n\n", i);
    entry_array = realloc(entry_array, sizeof(ENTRY) * (i + 2));
    MEM_CHECK(entry_array)

    (entry_array + (i + 1))->addr_len = 0;
    (entry_array + (i + 1))->pwd_len = 0;

    //entry_array[i + 1] = entry_array[i];

    printf("Enter website address: ");
    (entry_array + i)->addr = input_string();
    (entry_array + i)->addr_len = (int) strlen((entry_array + i)->addr) + 1;

    printf("Enter password: ");
    char *pwd_buffer;
    pwd_buffer = input_string();
    (entry_array + i)->pwd_len = (int) strlen(pwd_buffer);
    (entry_array + i)->pwd = encrypt(pwd_buffer, (entry_array + i)->pwd_len);

    free(pwd_buffer);

    return entry_array;
}

ENTRY *read_entries(FILE *file) {
    ENTRY entry_buffer;
    ENTRY *entry_array;
    entry_array = NULL;

    for (int i = 0; fread(&entry_buffer, sizeof(ENTRY), 1, file) != 0; i++) {
        entry_array = realloc(entry_array, sizeof(ENTRY) * (i + 1));
        MEM_CHECK(entry_array)

        (entry_array + i)->addr_len = entry_buffer.addr_len;
        (entry_array + i)->pwd_len = entry_buffer.pwd_len;

        (entry_array + i)->addr = malloc(sizeof(char) * (entry_array + i)->addr_len);
        MEM_CHECK((entry_array + i)->addr)
        fread((entry_array + i)->addr, sizeof(char), (entry_array + i)->addr_len, file);

        (entry_array + i)->pwd = malloc(sizeof(char) * (entry_array + i)->pwd_len);
        MEM_CHECK((entry_array + i)->pwd)
        fread((entry_array + i)->pwd, sizeof(char), (entry_array + i)->pwd_len, file);
    }

    return entry_array;
}

void print_entries(char *addr, ENTRY *entry_array) {
    int array_len;
    for (array_len = 0; (entry_array + array_len)->addr_len != 0; array_len++);
    printf("Array lengths: %d\n", array_len);

    if (array_len == 0) {
        printf("No passwords stored.\n");
    } else {

        int longest_index = strlen(NMR);
        int longest_addr = strlen(ADDR);
        int longest_pwd = strlen(PWD);

        for (int i = 0; i < array_len; i++) {

            int digits = 0;
            int temp_index = i;
            while (temp_index != 0) {
                temp_index = temp_index / 10;
                digits++;
            }
            if (digits > longest_index) longest_index = digits;
            digits = 0;

            if ((entry_array + i)->addr_len > longest_addr) longest_addr = (entry_array + i)->addr_len;
            if ((entry_array + i)->pwd_len > longest_pwd) longest_pwd = (entry_array + i)->pwd_len;
        }

        printf("%-*s | %-*s | %-*s\n", longest_index, NMR, longest_addr, ADDR, longest_pwd, PWD);

        for (int i = 0; i < array_len; i++) {
            printf("%-*d | %-*s | \n", longest_index, i + 1, longest_addr, (entry_array + i)->addr);
        }
    }
}

void write_entries(ENTRY *entry_array, FILE *file) {
    for (int i = 0; (entry_array + i)->addr != NULL; i++) {
        fwrite((entry_array + i), sizeof(ENTRY), 1, file);
        fwrite((entry_array + i)->addr, sizeof(char), (entry_array + i)->addr_len, file);
        free((entry_array + i)->addr);
        fwrite((entry_array + i)->pwd, sizeof(char), (entry_array + i)->pwd_len, file);
        free((entry_array + i)->pwd);
    }
    free(entry_array);
}


bool input_integer(int *input) {
    bool success = true;
    int ch;
    if (scanf("%d", input) != 1 || ((ch = getchar()) != '\n' && ch != EOF)) {
        while ((ch = getchar()) != '\n' && ch != EOF);
        success = false;
    }
    return success;
}

char *input_string() {
    char *string;
    bool success = false;
    while (success == false) {
        int allocated = 0;

        string = malloc(sizeof(char));
        MEM_CHECK(string)
        string[0] = '\0';

        bool read_string = true;
        while (read_string == true) {
            int character = getchar();
            if (character == '\n' || character == '\r' || character == '\f') {
                read_string = false;
            } else {
                allocated++;
                string = realloc(string, (allocated + 1) * sizeof(char));
                MEM_CHECK(string)
                string[allocated - 1] = (char) character;
                string[allocated] = '\0';
            }
        }

        if (strlen(string) == 0) {
            free(string);
            printf("Enter valid file name: ");
        } else {
            success = true;
        }
    }

    return string;
}