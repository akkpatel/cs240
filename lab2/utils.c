/**
 * Test if {ch} is a letter (a - z or A - Z).
 * Return 1 if yes, otherwise 0.
 */
int isAlpha(char ch) {
  /* FILL IN HERE */
	if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'){
		return 1;
	}
	else{
		return 0;
	}
}

/**
 * Return the length of the zero terminated string {s}.
 * The \0 character is not counted, e.g. the length of "abc" is 3.
 */
int strLen(char* s) {
  /* FILL IN HERE */
   int len;
    for (len = 0; *s != '\0'; s++,len++){
	}
    return len;
}

/**
 * Compare the first {n} characters of string {s1} and {s2}.
 * If identical, return 1. Otherwise return 0.
 */
int strNCmp(char* s1, char* s2, int n) {
  /* FILL IN HERE */


	int i;
	if(strlen(s1)==strlen(s2)){
		return 1;
	}
	if(*s1=='\0' && *s2=='\0'){
		return 1;
	}
	for(i=0;i<n;i++){
		if((s1+i)==(s2+i)){
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
}

/**
 * Replace every character of {s} with a white space.
 * {len} indicates the length of {s}.
 */
void spaceOut(char* s, int len) {
  /* FILL IN HERE */
	int i;
	for(i=0;i!=len;i++,s++){
		*s=32;
	}
}