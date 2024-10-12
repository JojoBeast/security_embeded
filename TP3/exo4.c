long decode2(long x, long y, long z){
long tmp;
z = z -y;
tmp = z;
tmp = tmp << 63;
tmp = tmp >> 63;
z = z*x;
tmp ^=z;
return tmp;

}Question 6. Switch
In the C function that follows, we have omitted the body of the switch statement. In the C code, the
case labels did not span a contiguous range, and some cases had multiple labels.
void switch_omitted (long x, long *dest) {
 long val = 0;
 switch (x) {
 // body with cases
 }
 *dest = val;
}
In compiling the function, gcc generates the assembly code:
//x in %rdi
switch_omitted :