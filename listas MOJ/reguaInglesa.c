#include <stdio.h>

void controlRegua(int n) {

    if (n == 0) {
        return;
    }
    else
    {
        controlRegua(n - 1);
        
            printf(".");
        for (int i = 0; i < n; i++)
        {
            printf("-");
        }
            printf("\n");
        
        controlRegua(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    controlRegua(n);


    for(int i =0; i < 5; i++){
        int controlRegua =1; 
    }
    
    return 0;
}