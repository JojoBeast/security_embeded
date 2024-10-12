// Produire le .s : gcc -O1 -S swap.c -o swap.s
// lire un .O : objdump -d swap.o en assembleur

void decode1(long *xp, long *yp, long *zp) {
    long temp1 = *xp;  // Sauvegarder la valeur de *xp
    long temp2 = *yp;  // Sauvegarder la valeur de *yp
    long temp3 = *zp;  // Sauvegarder la valeur de *zp

    *yp = temp1;       // *yp = *xp
    *zp = temp2;       // *zp = *yp
    *xp = temp3;       // *xp = *zp
}
