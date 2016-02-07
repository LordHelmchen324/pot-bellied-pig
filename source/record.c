#include <stdio.h>
#include <stdbool.h>

#include "containers.h"



void loadRecord(World *world){
    
    
    FILE *recordFile = NULL;
    recordFile = fopen(world -> recordPath, "r");
    
    world -> record = 0;
    if(recordFile != NULL)
        fscanf(recordFile, "%u", &(world -> record));
    
    fclose(recordFile);
    
    
    
    return;
}



bool checkRecord(World *world, Character *player){
    
    
    if(player -> weight > world -> record)
        return true;
    
    
    
    return false;
}



void saveRecord(World *world, Character *player){
    
    
    //no record
    if(world -> record >= player -> weight){
        
        
        
    } else if(world -> record < player -> weight){
        
        FILE *recordFile = NULL;
        recordFile = fopen(world -> recordPath, "w");
        
        if(recordFile != NULL){
            
            fprintf(recordFile, "%u", player -> weight);
            fclose(recordFile);
            
        }
        
        printf("You broke the record!\n");
        
    }
    
    
    
    return;
}