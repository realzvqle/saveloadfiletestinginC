#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define STRING_SIZE 50




bool save_file(char* filename, void* data, size_t data_size, size_t count){
    FILE* fp = fopen(filename, "wb");
    if(!fp){
        return false;
    }
    fwrite(data, data_size, count, fp);
    fclose(fp);
    return true;
}


bool read_file(char* filename, void* data, size_t data_size, size_t count){
    FILE* fp = fopen(filename, "rb");
    if(!fp){
        return false;
    }
    fread(data, data_size, count, fp);
    fclose(fp);
    return true;
}


struct dummy{
    int id;
    char* string;
    char* array[2];
};


int main(int argc, char* argv[]){
    if(argc < 2){
        return -1;
    }
    struct dummy dum;
    if(strcmp(argv[1], "w") == 0){
        dum.id = 2;
        dum.string = "h";
        dum.array[0] = "hh";
        dum.array[1] = "hhh";
        bool save = save_file("idk.sav", &dum, sizeof(struct dummy), 1);
        if(!save){
            perror("failed at writing string\n");
            return -1;
        }
       
        return 0;
    }
    else if(strcmp(argv[1], "r") == 0){
        bool save = read_file("idk.sav", &dum, sizeof(struct dummy), 1);
        if(!save){
            perror("failed at reading string\n");
            return -1;
        }
        printf("Saved File had %d id and %s string | array 0 i %s, array 1 is %s", dum.id, dum.string, dum.array[0], dum.array[1]);
        return 0;
    }
    else{
        printf("Unknown Command\n");
        return 0;
    }

}