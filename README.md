# C - Library

## Matrix Library  

`src/mat`  

**example** : Matrix Multiplication   
```c
#include "mat/mat.h"

int main() {
    Mat a = {
            .rows = 2,
            .cols = 3,
            .data = (float[6]){1, 2, 3 , 4, 5, 6}
    };

    mat_print(a);
    
    return 0;
}
```

**output** :  
```bash
 1 2 3
 4 5 6
```

