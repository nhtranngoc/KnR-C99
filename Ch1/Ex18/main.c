#include <stdio.h> 

#define MAXLINE 1000

int getline(char s[], int lim);

int main() {
	int len, i;
	char line[MAXLINE];

	while((len = getline(line, MAXLINE)) > 0) {
		if(len > 1) {
			for(i = len - 1; line[i] == ' ' || line[i] == '\t' || line[i] == '\n'; --i) {
				line[++i] = '\n';
			}
			line[++i] = '\0';
			printf("%s", line);
		}
	}

	return 0;
}

int getline(char s[], int lim) {
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if(c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}