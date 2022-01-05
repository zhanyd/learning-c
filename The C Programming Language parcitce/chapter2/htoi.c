/*
	编写函数htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀0x或0X）
	转换成与之等价的整形值。

	字符串中允许包含的数字包括：0~9、a~f以及A~F。
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXLINE 1000

void getline(char s[]);

int main() {

	char s[MAXLINE];

	getline(s);

	printf("s = %s ", s);

	int sum,i;
	int number = 0;
	for(i = 0; i < strlen(s); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			number = s[i] - '0';
		} else {
			number = lower(s[i]);
			printf("number = %s ", number);
			number = 10 + s[i] - 'a';
			printf("number = %d ", number);
		}
		sum = sum + number * pow(16, strlen(s) - i - 1);
	}

	printf("sum = %d ", sum);
}


int lower(int c) {
	if(c >= 'A' && c <= 'Z') {
		return c + 'a' - 'A';
	}
	else {
		return c;
	}
}


void getline(char s[]) {
	int c, i;

	for(i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;	
	}

	if(c == '\n') {
		i++;
	}

	s[i] = '\0';
}