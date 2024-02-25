#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c, delta, x1, x2, x0;

	printf("Saisissez succivement les variables de a b et c\n");

	scanf("%d %d %d", &a, &b, &c);
	printf("L'équation saisie est : %dx2 + %dx + %d = 0\n", a, b, c);

	if (a==0){
		if (b==0 && c == 0){
			printf("L'équation %dx2 + %d + %d = 0 est toujours vrai car a=0, b=0 et c=0");
		}else if (b!=0 )
		{
			/* code */
		}
		
	}
	return 0;
}
