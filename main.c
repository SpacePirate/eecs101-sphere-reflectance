#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ROWS 480
#define COLS 640
#define DEGREES(radians) ((radians) * 57.29577951308232087679815481410517033240)
#define RADIANS(degrees) ((degrees) * 0.017453292519943295769236907684886127134)

void clear(unsigned char image[][COLS]);
void DIP(double S[3], double r, double a, double m, char *fname);
void header( int row, int col, unsigned char head[32] );
void save_image(unsigned char image[][COLS], char *fname);
double mag(double v[3]);

int main()
{
    double S[3] = {0.0, 0.0, 1.0};
    /* a */
    DIP(S, 50.0, 0.5, 1.0, "image_a.ras");
    /* d */
    DIP(S, 10.0, 0.5, 1.0, "image_d.ras");
    /* e */
    DIP(S, 100.0, 0.5, 1.0, "image_e.ras");
    /* f */
    DIP(S, 50.0, 0.1, 1.0, "image_f.ras");
    /* g */
    DIP(S, 50.0, 1.0, 1.0, "image_g.ras");
    /* h */
    DIP(S, 50.0, 0.5, 0.1, "image_h.ras");
    /* i */
    DIP(S, 50.0, 0.5, 10000, "image_i.ras");
    /* b */
    S[0] = S[1] = S[2] = 1/pow(3,0.5);
    DIP(S, 50.0, 0.5, 1.0, "image_b.ras");
    /* c */
    S[0] = 1;
    S[1] = S[2] = 0;
    DIP(S, 50.0, 0.5, 1.0, "image_c.ras");
    return 0;
}

void clear( unsigned char image[][COLS] )
{
    int    i,j;
    for ( i = 0 ; i < ROWS ; i++ )
        for ( j = 0 ; j < COLS ; j++ ) image[i][j] = 0;
}

void save_image(unsigned char image[][COLS], char *fname)
{
    int i;
    unsigned char head[32];
    FILE  *fp;
    
    /* Save it into a ras image */
    /* Open the file */
    if (!( fp = fopen( fname, "wb" )))
      fprintf( stderr, "error: could not open %s\n", fname ), exit(1);
      
    /* Create a header */
    header(ROWS, COLS, head);
    
    /* Write the header */
    fwrite( head, 4, 8, fp );
     
    /* Write the image */
    for ( i = 0; i < ROWS; i++ )
        fwrite( image[i], 1, COLS, fp );
    
    /* Close the file */
    fclose( fp );

}

void DIP(double S[3], double r, double a, double m, char *fname)
{
    int x, y;
    int p, q;
    unsigned char image[ROWS][COLS];
    double N[3], V[3], H[3], temp[3];
    double Hmag;
    double L, Ll, Ls;
    double alpha;
    
    /* Direction to camera */
    V[0] = 0.0;
    V[1] = 0.0;
    V[2] = 1.0;
    
    /* Angular Bisector vector */
    temp[0] = V[0] + S[0];
    temp[1] = V[1] + S[1];
    temp[2] = V[2] + S[2];
    Hmag = mag(temp);
    H[0] = (V[0]+S[0])/Hmag;
    H[1] = (V[1]+S[1])/Hmag;
    H[2] = (V[2]+S[2])/Hmag;
            
    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            /* Center the image */
            p = x - COLS/2;
            q = y - ROWS/2;
            
            /* Unit Normal Vector */
            N[0] = p/r;
            N[1] = -q/r;
            N[2] = (pow(r*r - p*p - q*q, 0.5))/r;
            
            Ll = (S[0]*N[0] + S[1]*N[1] + S[2]*N[2]);
            
            if (Ll < 0 )
            {
                image[y][x] = 0;
                continue;
            }
  
            alpha = acos(N[0]*H[0] + N[1]*H[1] + N[2]*H[2]);
            Ls = exp(-pow((alpha/m),2));
            L = (a * Ll) + ((1-a)*Ls);
           
            /* Max L value is always 1 */
            image[y][x] = 255*L;
        }
    }
    
    save_image(image, fname);
}

double mag(double v[3])
{
    return pow(v[0]*v[0] + v[1]*v[1] + v[2]*v[2], 0.5);
}

void header( int row, int col, unsigned char head[32] )
{
    int *p = (int *)head;
    char *ch;
    int num = row * col;

    /* Choose little-endian or big-endian header depending on the machine. Don't modify this */
    /* Little-endian for PC */
    
    *p = 0x956aa659;
    *(p + 3) = 0x08000000;
    *(p + 5) = 0x01000000;
    *(p + 6) = 0x0;
    *(p + 7) = 0xf8000000;

    ch = (char*)&col;
    head[7] = *ch;
    ch ++; 
    head[6] = *ch;
    ch ++;
    head[5] = *ch;
    ch ++;
    head[4] = *ch;

    ch = (char*)&row;
    head[11] = *ch;
    ch ++; 
    head[10] = *ch;
    ch ++;
    head[9] = *ch;
    ch ++;
    head[8] = *ch;
    
    ch = (char*)&num;
    head[19] = *ch;
    ch ++; 
    head[18] = *ch;
    ch ++;
    head[17] = *ch;
    ch ++;
    head[16] = *ch;
    
/*
    // Big-endian for unix
    *p = 0x59a66a95;
    *(p + 1) = col;
    *(p + 2) = row;
    *(p + 3) = 0x8;
    *(p + 4) = num;
    *(p + 5) = 0x1;
    *(p + 6) = 0x0;
    *(p + 7) = 0xf8;
*/
}
