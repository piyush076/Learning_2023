#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int logId;
    char sensorId[10];
    float temperature;
    int humidity;
    int lightIntensity;
    char timestamp[9];
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void extractLogEntries(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (line[0] == '\n' || line[0] == '\r') {
            continue; // Skip empty lines
        }

        char *token;
        token = strtok(line, ",");
        
        logEntries[numEntries].logId = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].sensorId, token);

        token = strtok(NULL, ",");
        logEntries[numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[numEntries].lightIntensity = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[numEntries].timestamp, token);

        numEntries++;
    }

    fclose(file);
}

void displayLogEntries() {
    printf("Log Entries:\n");
    printf("------------------------------------------------------------------\n");
    printf("Log ID   Sensor ID   Temperature   Humidity   Light Intensity   Timestamp\n");
    printf("------------------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        printf("%-8d %-11s %-13.2f %-9d %-18d %-9s\n", entry.logId, entry.sensorId,
               entry.temperature, entry.humidity, entry.lightIntensity, entry.timestamp);
    }

    printf("------------------------------------------------------------------\n");
}

int main() {
    const char *filename = "data.csv";

    extractLogEntries(filename);
    displayLogEntries();

    return 0;
}
