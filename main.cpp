#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
int main(int argc, char *argv[]){
    int c;
    float val;
    int show_help, do_list, do_all, do_create, do_value;
    char *file, *arr;
    struct option longOpts[] = {
		{"help", no_argument, 0, 'h'},
		{"list", required_argument, 0, 'l'},
        {"all", no_argument, 0, 'a'},
        {"create", required_argument, 0, 'c'},
        {"value", required_argument, 0, 'V'},
        
        {0, 0, 0, 0}
    };

    while ((c = getopt_long(argc, argv, "ahc:V:l:o::", longOpts, NULL)) != -1){
        switch (c){
			case 'h':
                show_help = 1;
                break;
			case 'l':
                do_list = 1;
                arr = optarg;
                break;
            case 'a':
                do_all = 1;
                break;
            case 'c':
                do_create = 1;
                file = optarg;
                break;
            case 'V':
                do_value = 1;
                val = atof(optarg);
                break;
            default:
                break;

        }
    }

    if (show_help == 1)
        printf("Arg: Help\n");
    if (do_all == 1)
        printf("Arg: All\n");
    if (do_create == 1)
        printf("Arg: Create file - %s\n", file);
    if (do_value == 1)
        printf("Arg: Value = %f\n", val);
    if (do_list == 1){
        printf("Arg: Array = [");
        arr = strtok(arr, ",");
        while (1){
            printf("%f", atof(arr));
            arr = strtok(NULL, ",");
            if (arr != NULL)
                printf(", ");
            else
                break;
        }
        printf("]\n");
    }
}