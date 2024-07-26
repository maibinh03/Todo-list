#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *task;
    int completed; //1 = true, 0 = false
} Task;

Task *tasks = NULL;
int length = 0;

void addTask(const char *task) {
    tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task));
    if (tasks == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    tasks[length].task = (char *)malloc(strlen(task) + 1);
    if (tasks[length].task == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    tasks[length].completed = 0;
    strcpy(tasks[length].task, task);

    length++;
    printf("Task added\n");
}

void showTask() {
    char status;
    for (int i = 0; i < length; i++) {
        if (tasks[i].completed == 1) {
            status = 'f';
        } else {
            status = 'd';
        }
        printf("%d. %s [%c]\n", i + 1, tasks[i].task, status);
    }
}

void markAsCompleted(int index) {
    if (index <= length && index > 0) {
        tasks[index - 1].completed = 1;
        printf("Task finished!\n");
    } else {
        printf("Invalid index\n");
    }
}

void deleteTask(int index) {
    if (index <= length && index > 0) {
        free(tasks[index - 1].task);

        for (int i = index - 1; i < length - 1; i++) {
            tasks[i] = tasks[i + 1];
        }

        length--;
        tasks = (Task *)realloc(tasks, length * sizeof(Task));
        if (tasks == NULL && length > 0) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Task deleted!")
    } else {
        printf("Invalid index\n");
    }
}

void editTask(int index, const char* editText) {
    if (index <= length && index > 0) {
        char *editedTask = (char *)realloc(tasks[index - 1].task, strlen(editText) + 1);
        if (editedTask == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        } else {
            tasks[index - 1].task = editedTask;
            strcpy(tasks[index - 1].task, editText);
            printf("Task updated!\n");
        }
    } else {
        printf("Invalid index\n");
    }
}

int main() {
    int running = 1;
    int choice;
    int indexInput;
    char taskInput[256]; // Allocate fixed size buffer for taskInput

    printf("\nOption\n");
    printf("1. Add\n");
    printf("2. List\n");
    printf("3. Mark as completed\n");
    printf("4. Edit\n");
    printf("5. Delete\n");
    printf("6. Exit\n");

    while (running) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: 
                printf("Enter task: ");
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0';
                addTask(taskInput);
                break;

            case 2: 
                showTask();
                break;

            case 3: 
                printf("Enter index: ");
                scanf("%d", &indexInput);
                markAsCompleted(indexInput);
                break;

            case 4: 
                printf("Enter index: ");
                scanf("%d", &indexInput);
                getchar();

                printf("Enter task: ");
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0';
                editTask(indexInput, taskInput);
                break;

            case 5: 
                printf("Enter index: ");
                scanf("%d", &indexInput);
                deleteTask(indexInput);
                break;

            case 6:
                running = 0;
                break;

            default:
                printf("Wrong choice!\n");
                break;
        }
    }

    // Free remaining tasks
    for (int i = 0; i < length; i++) {
        free(tasks[i].task);
    }
    free(tasks);

    return 0;
}
