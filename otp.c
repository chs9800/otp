/**************************************
*   OTP Encryption / decryption Tool  *
*                          Ver:0.0.1  *
*   2013.08.12 Athena9800             *
**************************************/
#include <stdio.h>
#include <ctype.h>
#define NG -1
#define OK 1
char *StrToLower(char *s);
char *StrToUpper(char *s);
char *decode(char *s, char *otpkey);
char *encode(char *s, char *otpkey);
int main(int argc,char *argv[]);
int isStrAlpha(char *s)
{
    char *p;                     /* 作業用ポインタ */
    for (p = s; *p; p++){         /* pがヌルでなければ */
        if(isalpha(*p)==0){
	    //printf("%c\n",*p);
	    return NG;
	}
    }
    return OK;
}
char *encode(char *s, char *otpkey)
{
    char *p;                     /* 作業用ポインタ */
    for (p = s; *p; p++){         /* pがヌルでなければ */
        *p = (((*p - 65) + (*otpkey - 65)) % 26)+65;
	*otpkey++;
    }        
    return (s);                  
}
char *decode(char *s, char *otpkey)
{
    char *p;                     /* 作業用ポインタ */
    for (p = s; *p; p++){         /* pがヌルでなければ */
        *p = (((*p - 65) - (*otpkey - 65)) % 26);
	if(*p<0){
	    *p+=26;
	}
	*p+=65;
	*otpkey++;
    }
    return (s);                  
}
  /* 文字列中の英大文字を小文字に変換 */
char *StrToLower(char *s)
{
    char *p;                    
    for (p = s; *p; p++)        
        *p = tolower(*p);        
    return (s);                  
}
  /* 文字列中の英小文字を大文字に変換 */
char *StrToUpper(char *s)
{
    char *p;                    
    for (p = s; *p; p++)         
        *p = toupper(*p);        
    return (s);                  
}
int main(int argc,char *argv[])
{
    if(argc<4){
	printf("Usage： otp.o <option> <text> <OPT Key>\n");
	printf("<option>\n  -d decode.\n  -e encode\n");
	printf("<Sample>\n  otp.o -d GOFUT ZKUJF\n  otp.o -e HELLO ZKUJF\n");
	return NG;
    }
    if(isStrAlpha(argv[2]) != OK){
	printf("ERROR->%s",argv[2]);
	return NG;
    }
    StrToUpper(argv[2]);
    if(strcmp(argv[1],"-d")==0)/*decode*/
    {
	printf("Encrypted String: %s\n", argv[2]);
	printf("OTP key: %s\n", argv[3]);
        printf("Original: %s\n", decode(argv[2],argv[3]));
    }else{/*encode*/
	printf("Original: %s\n", argv[2]);
	printf("OTP\tkey: %s\n", argv[3]);
	printf("Encrypted String: %s\n", encode(argv[2],argv[3]));
    }
    return OK;
}
