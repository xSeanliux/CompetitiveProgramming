int genius_distinguisher (uint64_t value) {
     uint64_t jizz;
     uint64_t *add = &jizz;
     for(int i = -64; i < 64; i++){
         if(*(add + i) == value){
             if((*(add + i + 1) == value + 1) || (*(add + i - 1) == value + 1)){
                 return 0;
             } 
             if((*(add + i + 1) == value - 1) || (*(add + i - 1) == value - 1)){
                 return 1;
             }
         }
     }
}

