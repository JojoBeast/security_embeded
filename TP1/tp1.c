#include <stdio.h>


// racourcis clavier 

/*

option + maj + L = |
option + N = ~

*/


// Introduction pour les exercices

/*

Chaque chiffre hexadécimal représente 4 bits, donc 8 chiffres hexadécimaux représentent 32 bits (4 octets).
Dans l'exemple `0x12AB5678` :
- Chaque octet(bytes) est constitué de deux chiffres hexadécimaux.
- Les octets (bytes) sont, de gauche à droite : `0x12`, `0xAB`, `0x56`, et `0x78`.
- L'octet (bytes) de poids faible (least significant byte) est le dernier, soit `0x78`.
Cela signifie que les 8 bits = octets = bytes les moins significatifs sont représentés par les deux derniers chiffres hexadécimaux.

*/


// Table de vérité pour les opérateurs AND (`&`) et OR (`|`) :

/*

| Bit de gauche | Bit de droite | Résultat `AND` (`&)` | Résultat `OR` (`|`) |
|---------------|---------------|---------------------|---------------------|
|       0       |       0       |          0          |          0          |
|       0       |       1       |          0          |          1          |
|       1       |       0       |          0          |          1          |
|       1       |       1       |          1          |          1          |

Exemple des opérations en binaire :

  a = 1101   (13 en décimal)
  b = 1010   (10 en décimal)

1) Opération AND (a & b) :
   1101   (a)
&  1010   (b)
---------
   1000   (résultat = 8 en décimal)

Explication bit par bit :
- 1 & 1 = 1
- 1 & 0 = 0
- 0 & 1 = 0
- 1 & 0 = 0

2) Opération OR (a | b) :
   1101   (a)
|  1010   (b)
---------
   1111   (résultat = 15 en décimal)

Explication bit par bit :
- 1 | 1 = 1
- 1 | 0 = 1
- 0 | 1 = 1
- 1 | 0 = 1

*/


// Q2
unsigned int get_least_significant_byte(unsigned int x) {
    return x & 0xFF;
}

//Q3
unsigned int unchanged_last_byte(unsigned int x){
return ~x & 0xFFFFFF00 | (x & 0xFF);
}

//Q4
unsigned int all_except_least_bytes(unsigned int x){
    return x & 0xFFFFFF00 | 0xFF;
}

//Q5
unsigned int replace_least_bytes(unsigned int x, unsigned int y){
    return x & 0xFFFFFF00 | y & 0xFF;
}

//Q6

/*
Représentation de b décalé :
Initialement, b est 0xAB, ce qui est équivalent à 00000000 00000000 00000000 10101011 en binaire (sur 32 bits).
Lorsque nous faisons (b << 16), nous décalons ces 8 bits (10101011) de 16 positions vers la gauche.
Le résultat de ce décalage est : 00000000 10101011 00000000 00000000, soit en hexadécimal 0x00AB0000.
Cela permet de placer la valeur de b à la position correcte dans le nombre de 32 bits pour remplacer l'octet cible de x.
*/

unsigned int place_bytes(unsigned int x,int i,unsigned char z){
return (x & ~(0xFF << i*8)) | (z << i*8);

}

//7

//8

//9

int main() {

    //Q2
    unsigned int x = 0x87654321;
    unsigned int lsb = get_least_significant_byte(x);
    printf("Le byte le moins significatif de x = 0x%x est : 0x%08x\n", x, lsb);

    //Q3
    unsigned int last = unchanged_last_byte(x);
    printf("le complement de x et les  dernies bytes ne change pas x = 0x%x est :  y = 0x%08x\n",x,last);

    //Q4
    unsigned int one = all_except_least_bytes(x);
    printf("les dernies bytes a 1 (FF) 0x%x est :  0x%08x\n",x,one);

    //Q5
    unsigned int y = 0x76543210;
    unsigned int replace = replace_least_bytes(x,y);
    printf("les bytes de x et les dernies bytes de y\n. x = 0x%x , y = 0x%x , z = 0x%x\n",x,y,replace);
    
    //Q6
    int i = 3;
    unsigned char lettre = 0xAA;
    unsigned int choix = place_bytes(x,i,lettre);
    printf(" x = 0x%x :  bytes potision %x remplacer par 0x%x , ans : 0x%x\n",x,i,lettre,choix);



    return 0;


}
